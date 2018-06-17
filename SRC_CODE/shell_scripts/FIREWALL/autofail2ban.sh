#!/bin/sh

hostname=$(/bin/hostname)
local_ipv4_ips="(1.1.1.1|2.2.2.2)"
local_ipv6_ips="(2000:45d0:32:b00::abc|2000:55d0:33:300::abc)"

path_ipv4_local=/root/scripts/firewall/IPV4/BLACK_LISTS_LOCAL
path_ipv6_local=/root/scripts/firewall/IPV6/BLACK_LISTS_LOCAL
path_ipv4_world=/root/scripts/firewall/IPV4/BLACK_LISTS_WORLD
path_ipv6_world=/root/scripts/firewall/IPV6/BLACK_LISTS_WORLD
hand=bruteforce_hand_ip_list.txt
full=bruteforce_full_ip_list.txt
#Lista atakowanych nieistniejacych emaili, na ktore dokonano prob blednego logowania
black_emails_list=black_emails_list.txt
#liczba nieprawidlowych logowan (ze wszystkich logow) po ktorych blokowane jest IP
block_login_qty=99

if [ "${hostname}" = "servea.pl" ]; then
        auto=bruteforce_fail2ban_ip_list.txt
else
        auto=bruteforce_fail2ban_ip_list_other.txt
fi

#IPV4
#Fail2ban - zbieranie IP (ipv4)
/bin/cat /var/log/fail2ban.log /var/log/fail2ban.log.1 \
        | /bin/egrep -E "(\ Ban\ )" \
        | /usr/bin/awk '{print $7}' \
        | /usr/bin/sort | /usr/bin/uniq \
        | /bin/egrep -v -E "${local_ipv4_ips}" \
        > ${path_ipv4_local}/${auto}

/bin/zcat /var/log/fail2ban.log.*.gz \
        | /bin/egrep -E "(\ Ban\ )" \
        | /usr/bin/awk '{print $7}' \
        | /usr/bin/sort \
        | /usr/bin/uniq \
        | /bin/egrep -v -E "${local_ipv4_ips}" \
        >> ${path_ipv4_local}/${auto}

#Exim reject log
if [ -e /var/log/exim ]; then
#echo "exim istnieje"
/bin/cat /var/log/exim/rejectlog /var/log/exim/rejectlog.1 \
        | /bin/grep "login authenticator failed" \
        | /bin/grep "535 Incorrect authentication data" \
        | /bin/egrep -o '[[:digit:]]{1,3}\.[[:digit:]]{1,3}\.[[:digit:]]{1,3}\.[[:digit:]]{1,3}' \
        | /usr/bin/sort \
        | /usr/bin/uniq -c \
        | /usr/bin/awk -v c=$block_login_qty '{if ($1 > c) print $2}' \
        | /bin/egrep -v -E "${local_ipv4_ips}" \
        | /usr/bin/sort \
        >> ${path_ipv4_local}/${auto}

/bin/zcat /var/log/exim/rejectlog.*.gz \
        | /bin/grep " login authenticator failed" \
        | /bin/grep "535 Incorrect authentication data" \
        | /bin/egrep -o '[[:digit:]]{1,3}\.[[:digit:]]{1,3}\.[[:digit:]]{1,3}\.[[:digit:]]{1,3}' \
        | /usr/bin/sort \
        | /usr/bin/uniq -c \
        | /usr/bin/awk -v c=$block_login_qty '{if ($1 > c) print $2}' \
        | /bin/egrep -v -E "${local_ipv4_ips}" \
        | /usr/bin/sort \
        >> ${path_ipv4_local}/${auto}

#Ataki na emaile z listy
for fake_email in $(/bin/cat ${path_ipv4_local}/${black_emails_list}); do
        /bin/cat /var/log/exim/mainlog /var/log/exim/mainlog.1 \
                | /bin/grep ${fake_email} \
                | /bin/egrep -o '[[:digit:]]{1,3}\.[[:digit:]]{1,3}\.[[:digit:]]{1,3}\.[[:digit:]]{1,3}' \
                | /usr/bin/sort \
                | /usr/bin/uniq \
                | /bin/egrep -v -E "${local_ipv4_ips}" \
                >> ${path_ipv4_local}/${auto}
#z ostatnich 10 dni
/bin/zcat /var/log/exim/mainlog.?.gz \
                | /bin/grep ${fake_email} \
                | /bin/egrep -o '[[:digit:]]{1,3}\.[[:digit:]]{1,3}\.[[:digit:]]{1,3}\.[[:digit:]]{1,3}' \
                | /usr/bin/sort \
                | /usr/bin/uniq \
                | /bin/egrep -v -E "${local_ipv4_ips}" \
                >> ${path_ipv4_local}/${auto}
done
fi

#Dovecot
/bin/zcat /var/log/syslog.*.gz \
        | /bin/grep dovecot \
        | /bin/grep login \
        | /bin/egrep "(no auth attempts|auth failed)" \
        | /bin/egrep -o 'rip=[[:digit:]]{1,3}\.[[:digit:]]{1,3}\.[[:digit:]]{1,3}\.[[:digit:]]{1,3}' \
        | /usr/bin/cut -f2 -d= \
        | /usr/bin/sort \
        | /usr/bin/uniq -c \
        | /usr/bin/awk -v c=$block_login_qty '{if ($1 > c) print $2}' \
        | /bin/egrep -v -E "${local_ipv4_ips}" \
        | /usr/bin/sort \
        >> ${path_ipv4_local}/${auto}

#Pure-ftp
/bin/zcat /var/log/syslog.*.gz \
        | /bin/grep "Authentication failed for user" \
        | /bin/egrep -o '[[:digit:]]{1,3}\.[[:digit:]]{1,3}\.[[:digit:]]{1,3}\.[[:digit:]]{1,3}' \
        | /usr/bin/sort \
        | /usr/bin/uniq -c \
        | /usr/bin/awk -v c=$block_login_qty '{if ($1 > c) print $2}' \
        | /bin/egrep -v -E "${local_ipv4_ips}" \
        | /usr/bin/sort \
        >> ${path_ipv4_local}/${auto}

#Proftpd
if [ -e /var/log/proftpd ]; then
#echo "proftpd istnieje"
/bin/cat /var/log/proftpd/auth.log \
        | /bin/grep "\"PASS (hidden)\" 530" \
        | /usr/bin/awk '{print $3}' \
        | /usr/bin/sort \
        | /usr/bin/uniq -c \
        | /usr/bin/awk -v c=$block_login_qty '{if ($1 > c) print $2}' \
        | /bin/egrep -v -E "${local_ipv4_ips}" \
        | /usr/bin/sort \
        >> ${path_ipv4_local}/${auto}

/bin/zcat /var/log/proftpd/auth.log.*.gz \
        | /bin/grep "\"PASS (hidden)\" 530" \
        | /usr/bin/awk '{print $3}' \
        | /usr/bin/sort \
        | /usr/bin/uniq -c \
        | /usr/bin/awk -v c=$block_login_qty '{if ($1 > c) print $2}' \
        | /bin/egrep -v -E "${local_ipv4_ips}" \
        | /usr/bin/sort \
        >> ${path_ipv4_local}/${auto}
fi

#Polaczenie IP v4 wprowadzana recznie
/bin/cat ${path_ipv4_local}/${auto} ${path_ipv4_local}/${hand} \
        | /bin/egrep -v -E "${local_ipv4_ips}" \
        | /bin/sed '/^$/d' \
        | /bin/egrep -o '[[:digit:]]{1,3}\.[[:digit:]]{1,3}\.[[:digit:]]{1,3}\.[[:digit:]]{1,3}' \
        | /usr/bin/sort \
        | /usr/bin/uniq \
        > ${path_ipv4_local}/${full}

#IPV6
#Polaczenie IP v6 wprowadzana recznie
/bin/cat ${path_ipv6_local}/${auto} ${path_ipv6_local}/${hand} \
        | /bin/egrep -v -E "${local_ipv6_ips}" \
        | /bin/sed '/^$/d' \
        | /usr/bin/sort \
        | /usr/bin/uniq \
        > ${path_ipv6_local}/${full}
		