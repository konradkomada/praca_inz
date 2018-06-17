#!/bin/sh

func=named-checkconf
infopath=/root/info
emails=email@admina.pl
host=$(/bin/hostname)
nerror=$(/usr/sbin/${func})
ncheck=$(echo $?)

if [ "${ncheck}" -ne "0" ]; then
        echo "${nerror}" | mail -s "Na serwerze ${host} wykryto b³¹d konfiguracji: ${func}" ${emails}
        mkdir -p ${infopath}; echo "${nerror}" > ${infopath}/${func}
fi
