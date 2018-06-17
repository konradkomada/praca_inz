#!/bin/sh

ip=2000:5b0:100:abc::2
dst=home_ipv6_router
func=ping6
infopath=/root/info
emails=xunix@xunix.pl
host=$(/bin/hostname)
nerror=$(/bin/${func} -c 3 ${ip})
ncheck=$(echo $?)

if [ "${ncheck}" -ne "0" ]; then
        echo "${nerror}" | mail -s "Na serwerze ${host} wykryto błąd: ${func} ${ip} ${dst}" ${emails}
        mkdir -p ${infopath}; echo "${nerror}" > ${infopath}/${func}-${dst}
fi
