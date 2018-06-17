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
/sbin/ip6tables -F
/sbin/ip6tables -X
/sbin/ip6tables -F -t filter
/sbin/ip6tables -X -t filter

# Zabezpieczenie przed przyjmowaniem pakietow ICMP redirect (moga zmienic nasza tablice routingu)
echo "0" > /proc/sys/net/ipv6/conf/all/accept_redirects > /dev/null 2>&1

if [ "$1" = "stop" ]
then
#Otwarcie firewalla (akceptacja wszystkich pakietow)
	/sbin/ip6tables -P INPUT ACCEPT
	/sbin/ip6tables -P FORWARD ACCEPT
	/sbin/ip6tables -P OUTPUT ACCEPT
echo "1" > /proc/sys/net/ipv6/conf/all/accept_redirects > /dev/null 2>&1
	exit
fi

# Domyslna polityka bezpieczenstwa dla filtrow
/sbin/ip6tables -P INPUT DROP
/sbin/ip6tables -P FORWARD DROP
/sbin/ip6tables -P OUTPUT ACCEPT

# Dozwolony ruch na interfejsie lo (potrzebne do działania wielu lokalnych usług)
/sbin/ip6tables -A INPUT -i lo -j ACCEPT

#PING
/sbin/ip6tables -A INPUT -p ipv6-icmp -j ACCEPT

#Dozwolone nasze sieci
/sbin/ip6tables -A INPUT -s 2000:5b0:100:abc::2/64 -j ACCEPT
/sbin/ip6tables -A INPUT -s 2001:5b0:100:abcd::1/64 -j ACCEPT

if [ "${hostname}" = "${server_main}" ]; then
/sbin/ip6tables -A INPUT -s 2000:55a0:50:d00::abc/56 -j ACCEPT
fi

if [ "${hostname}" = "${server_sec}" ]; then
/sbin/ip6tables -A INPUT -s 2000:55a0:00:100::abc/64 -j ACCEPT
fi

# Blokada ident
#/sbin/ip6tables -A INPUT -p tcp --dport 113 -j REJECT --reject-with icmpv6-port-unreachable

# Ochrona przed atakami
/sbin/ip6tables -A INPUT -p icmpv6 --icmpv6-type echo-request -m limit --limit 10/s -j LOG --log-prefix "Ping6: "
/sbin/ip6tables -A INPUT -p icmpv6 --icmpv6-type echo-request -m limit --limit 10/s -j ACCEPT # Ping of death
/sbin/ip6tables -A INPUT -p icmpv6 --icmpv6-type echo-request -j REJECT

/sbin/ip6tables -A INPUT -m conntrack --ctstate NEW -p tcp --tcp-flags SYN,RST,ACK,FIN,URG,PSH ACK -j LOG --log-prefix "ACK scan: "
/sbin/ip6tables -A INPUT -m conntrack --ctstate NEW -p tcp --tcp-flags SYN,RST,ACK,FIN,URG,PSH ACK -j DROP # Metoda ACK (nmap -sA)

/sbin/ip6tables -A INPUT -m conntrack --ctstate NEW -p tcp --tcp-flags SYN,RST,ACK,FIN,URG,PSH FIN -j LOG --log-prefix "FIN scan: "
/sbin/ip6tables -A INPUT -m conntrack --ctstate NEW -p tcp --tcp-flags SYN,RST,ACK,FIN,URG,PSH FIN -j DROP # Skanowanie FIN (nmap -sF)

/sbin/ip6tables -A INPUT -m conntrack --ctstate NEW -p tcp --tcp-flags SYN,RST,ACK,FIN,URG,PSH PSH -j LOG --log-prefix "Xmas scan: "
/sbin/ip6tables -A INPUT -m conntrack --ctstate NEW -p tcp --tcp-flags SYN,RST,ACK,FIN,URG,PSH FIN,URG,PSH -j DROP # Metoda Xmas Tree (nmap -sX)

#/sbin/ip6tables -A INPUT -m conntrack --ctstate INVALID -p tcp ! --tcp-flags SYN,RST,ACK,FIN,PSH,URG SYN,RST,ACK,FIN,PSH,URG -j LOG --log-prefix "Null scan: "
/sbin/ip6tables -A INPUT -m conntrack --ctstate INVALID -p tcp ! --tcp-flags SYN,RST,ACK,FIN,PSH,URG SYN,RST,ACK,FIN,PSH,URG -j DROP # Skanowanie Null (nmap -sN)

# Ochrona przed DoS (SYN FLOOD)
/sbin/ip6tables -N syn-flood
/sbin/ip6tables -A INPUT -p tcp --syn -j syn-flood
/sbin/ip6tables -A syn-flood -m limit --limit 100/s --limit-burst 150 -j RETURN
/sbin/ip6tables -A syn-flood -m limit --limit 100/s --limit-burst 150 -j LOG --log-prefix "SYN-flood: "
/sbin/ip6tables -A syn-flood -j DROP

# Dozwolony ruch - związany z istniejacymi polaczeniami
/sbin/ip6tables -A INPUT -m state --state ESTABLISHED,RELATED -j ACCEPT

#IPSET - masowo blokowane adresy IPV6
if [ "${hostname}" = "${server_main}" ]; then
/sbin/ip6tables -I INPUT -m set --match-set denyset_ipv6 src -j DROP
fi

if [ "${hostname}" = "${server_sec}" ]; then
for ipaddress in $(egrep -h -v -E "^#|^$" ${path_ipv6_local}/${full}); do 
/sbin/ip6tables -I INPUT -s ${ipaddress} -j DROP
done
fi

#Dozwolony ruch (porty)
if [ "${hostname}" = "${server_main}" ]; then
/sbin/ip6tables -A INPUT -m state --state NEW -m multiport -p tcp --dports 20,21,22,25,53,80,110,143,443,465,587,993,995,2222 -j ACCEPT
/sbin/ip6tables -A INPUT -p udp --dport 53 -j ACCEPT
fi

if [ "${hostname}" = "${server_sec}" ]; then
/sbin/ip6tables -A INPUT -m state --state NEW -m multiport -p tcp --dports 22,53 -j ACCEPT
/sbin/ip6tables -A INPUT -p udp --dport 53 -j ACCEPT
fi

