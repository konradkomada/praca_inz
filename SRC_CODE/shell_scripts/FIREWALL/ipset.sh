#!/bin/sh

hostname=$(/bin/hostname)

path_ipv4_local=/root/scripts/firewall/IPV4/BLACK_LISTS_LOCAL
path_ipv6_local=/root/scripts/firewall/IPV6/BLACK_LISTS_LOCAL
path_ipv4_world=/root/scripts/firewall/IPV4/BLACK_LISTS_WORLD
path_ipv6_world=/root/scripts/firewall/IPV6/BLACK_LISTS_WORLD
hand=bruteforce_hand_ip_list.txt
full=bruteforce_full_ip_list.txt
if [ "${hostname}" = "servea.pl" ]; then
	auto=bruteforce_fail2ban_ip_list.txt
else
	auto=bruteforce_fail2ban_ip_list_other.txt
fi

if [ "${hostname}" = "servea.pl" ]; then
#ipset destroy denyset...
#echo > /etc/ipset.conf

#Takze w /etc/rc.local
ipset create denyset_ipv4 hash:net family inet -quiet
ipset create denyset_ipv6 hash:net family inet6 -quiet

# Dodanie adresow IPV4 do zestawu blokowanych:
for ipaddress in $(egrep -h -v -E "^#|^$" ${path_ipv4_world}/*.txt); do ipset add denyset_ipv4 $ipaddress -quiet; done
for ipaddress in $(egrep -h -v -E "^#|^$" ${path_ipv4_local}/${full}); do ipset add denyset_ipv4 $ipaddress -quiet; done

# Dodanie adresow IPV6 do zestawu blokowanych:
for ipaddress in $(egrep -h -v -E "^#|^$" ${path_ipv6_world}/*.txt); do ipset add denyset_ipv6 $ipaddress -quiet; done
for ipaddress in $(egrep -h -v -E "^#|^$" ${path_ipv6_local}/${full}); do ipset add denyset_ipv6 $ipaddress -quiet; done

#Zapisanie zestawow blokowanych sieci na stale
ipset save > /etc/ipset.conf
fi

#Restart firewalla

/etc/init.d/firewall_ipv4 stop
sleep 1
/etc/init.d/firewall_ipv4 start
sleep 1
/etc/init.d/firewall_ipv6 stop
sleep 1
/etc/init.d/firewall_ipv6 start

