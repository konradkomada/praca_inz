#!/bin/sh

ip=XXX.XXX.XXX.XXX
dst=domena-serwera.pl
func=ping
infopath=/root/info
emails=email@admina.pl
host=$(/bin/hostname)
nerror=$(/bin/${func} -c 3 ${ip})
ncheck=$(echo $?)

if [ "${ncheck}" -ne "0" ]; then
        echo "${nerror}" | mail -s "Na serwerze ${host} wykryto b³¹d: ${func} ${ip} ${dst}" ${emails}
        mkdir -p ${infopath}; echo "${nerror}" > ${infopath}/${func}-${dst}
fi