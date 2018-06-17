#!/bin/bash

hostname=$(/bin/hostname)

server_main=serwer
server_sec=serwer2

path_ipv4_local=/root/scripts/firewall/IPV4/BLACK_LISTS_LOCAL
path_ipv6_local=/root/scripts/firewall/IPV6/BLACK_LISTS_LOCAL
path_ipv4_world=/root/scripts/firewall/IPV4/BLACK_LISTS_WORLD
path_ipv6_world=/root/scripts/firewall/IPV6/BLACK_LISTS_WORLD
hand=bruteforce_hand_ip_list.txt
full=bruteforce_full_ip_list.txt
if [ "${hostname}" = "${server_main}" ]; then
	auto=bruteforce_fail2ban_ip_list.txt
else
	auto=bruteforce_fail2ban_ip_list_other.txt
fi

# Czyszczenie regul firewalla
/sbin/iptables -F
/sbin/iptables -X
/sbin/iptables -F -t nat
/sbin/iptables -X -t nat
/sbin/iptables -F -t filter
/sbin/iptables -X -t filter

#włączenie forwardowania w jadrze linux (przydatne na routerach)
#echo 1 > /proc/sys/net/ipv4/ip_forward > /dev/null 2>&1

#załadowanie modulów dla ftp - niezbedne dla polaczen nawiazanych  (przydatne na routerach)
#modprobe ip_conntrack_ftp
#modprobe ip_nat_ftp

# Wylaczamy odpowiedzi icmp (ping)
#echo "1" > /proc/sys/net/ipv4/icmp_echo_ignore_all
# Zabezpieczenie przed atakami: Smurf
echo "1" > /proc/sys/net/ipv4/icmp_echo_ignore_broadcasts > /dev/null 2>&1
# Zabezpieczenie przed pakietami ICMP error
echo "1" > /proc/sys/net/ipv4/icmp_ignore_bogus_error_responses > /dev/null 2>&1
# Rejestrowanie podrobionych pakietow (np: spoofed. source routed. redirects)
echo "1" > /proc/sys/net/ipv4/conf/all/log_martians > /dev/null 2>&1
# Odrzucanie datagramu IP z opcja "source route"
echo "0" > /proc/sys/net/ipv4/conf/all/accept_source_route > /dev/null 2>&1
# Zabezpieczenie przed przyjmowaniem pakietow ICMP redirect (zmiana tablicy rout.)
echo "0" /proc/sys/net/ipv4/conf/all/accept_redirects > /dev/null 2>&1
# Przyjmowanie pakietow zgodnych z tablica routingu
echo "1" /proc/sys/net/ipv4/conf/all/rp_filter > /dev/null 2>&1
#Ochrona przed atakami typu SYN FLOOD
echo "1" > /proc/sys/net/ipv4/tcp_syncookies > /dev/null 2>&1
echo "1" > /proc/sys/net/ipv4/conf/all/log_martians > /dev/null 2>&1

if [ "$1" = "stop" ]
then
#Otwarcie firewalla (akceptacja wszystkich pakietow)
	/sbin/iptables -P INPUT ACCEPT
	/sbin/iptables -P FORWARD ACCEPT
	/sbin/iptables -P OUTPUT ACCEPT
#Powrot do ustawien default
echo "0" > /proc/sys/net/ipv4/icmp_echo_ignore_all > /dev/null 2>&1
echo "0" > /proc/sys/net/ipv4/icmp_echo_ignore_broadcasts > /dev/null 2>&1
echo "0" > /proc/sys/net/ipv4/icmp_ignore_bogus_error_responses > /dev/null 2>&1
echo "0" > /proc/sys/net/ipv4/conf/all/log_martians > /dev/null 2>&1
echo "1" > /proc/sys/net/ipv4/conf/all/accept_source_route > /dev/null 2>&1
echo "1" > /proc/sys/net/ipv4/conf/all/accept_redirects > /dev/null 2>&1
echo "0" > /proc/sys/net/ipv4/conf/all/rp_filter > /dev/null 2>&1
echo "1" > /proc/sys/net/ipv4/tcp_syncookies > /dev/null 2>&1
echo "0" > /proc/sys/net/ipv4/conf/all/log_martians > /dev/null 2>&1
	exit
fi

# Domyslna polityka bezpieczenstwa dla filtrow
/sbin/iptables -P INPUT DROP
/sbin/iptables -P FORWARD DROP
/sbin/iptables -P OUTPUT ACCEPT

# Dozwolony ruch na interfejsie lo (potrzebne do działania wielu lokalnych usług)
/sbin/iptables -A INPUT -i lo -j ACCEPT

#Dozwolone nasze sieci
#/sbin/iptables -A INPUT -s 91.200.184.0/22 -j ACCEPT
/sbin/iptables -A INPUT -s 1.1.1.1/24 -j ACCEPT

if [ "${hostname}" = "${server_main}" ]; then
/sbin/iptables -A INPUT -s 2.2.2.2 -j ACCEPT
fi

if [ "${hostname}" = "${server_sec}" ]; then
/sbin/iptables -A INPUT -s 3.3.3.3 -j ACCEPT
fi

#Ping diagnostyczny
#/sbin/iptables -A INPUT -p icmp -s 92.222.189.3 -j ACCEPT
/sbin/iptables -A INPUT -p icmp -s 37.187.62.250 -j ACCEPT

# Blokada ident
/sbin/iptables -A INPUT -p tcp --dport 113 -j REJECT --reject-with icmp-port-unreachable 

# Ochrona przed atakami
/sbin/iptables -A INPUT -p icmp --icmp-type echo-request -m limit --limit 2/s -j ACCEPT # Ping of death
/sbin/iptables -A INPUT -p icmp --icmp-type echo-request -j REJECT --reject-with icmp-host-unreachable
/sbin/iptables -A INPUT -m conntrack --ctstate NEW -p tcp --tcp-flags SYN,RST,ACK,FIN,URG,PSH ACK -j DROP # Skan ACK (nmap -sA)
/sbin/iptables -A INPUT -m conntrack --ctstate NEW -p tcp --tcp-flags SYN,RST,ACK,FIN,URG,PSH FIN -j DROP # Skan FIN (nmap -sF)
/sbin/iptables -A INPUT -m conntrack --ctstate NEW -p tcp --tcp-flags SYN,RST,ACK,FIN,URG,PSH FIN,URG,PSH -j DROP # Skan Xmas Tree (nmap -sX)
/sbin/iptables -A INPUT -m conntrack --ctstate INVALID -p tcp ! --tcp-flags SYN,RST,ACK,FIN,PSH,URG SYN,RST,ACK,FIN,PSH,URG -j DROP # Skanowanie Null (nmap -sN)

# Ochrona przed DoS (SYN FLOOD)
/sbin/iptables -N syn-flood
/sbin/iptables -A INPUT -p tcp --syn -j syn-flood
/sbin/iptables -A syn-flood -m limit --limit 100/s --limit-burst 150 -j RETURN
/sbin/iptables -A syn-flood -m limit --limit 100/s --limit-burst 150 -j LOG --log-prefix "SYN-flood: "
/sbin/iptables -A syn-flood -j DROP

# Dozwolony ruch - związany z istniejacymi polaczeniami
/sbin/iptables -A INPUT -m state --state ESTABLISHED,RELATED -j ACCEPT

#IPSET - masowo blokowane adresy IPV4
if [ "${hostname}" = "${server_main}" ]; then
/sbin/iptables -I INPUT -m set --match-set denyset_ipv4 src -j DROP
fi

if [ "${hostname}" = "${server_sec}" ]; then
for ipaddress in $(egrep -h -v -E "^#|^$" ${path_ipv4_local}/${full}); do 
/sbin/iptables -I INPUT -s ${ipaddress} -j DROP
done
fi

#Dozwolony ruch (porty)
if [ "${hostname}" = "${server_main}" ]; then
/sbin/iptables -A INPUT -m state --state NEW -m multiport -p tcp --dports 20,21,22,25,53,80,110,143,443,465,587,993,995,2222 -j ACCEPT
/sbin/iptables -A INPUT -p udp --dport 53 -j ACCEPT
fi

if [ "${hostname}" = "${server_sec}" ]; then
/sbin/iptables -A INPUT -m state --state NEW -m multiport -p tcp --dports 22,53 -j ACCEPT
/sbin/iptables -A INPUT -p udp --dport 53 -j ACCEPT
fi


