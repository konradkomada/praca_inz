#!/bin/sh

user=root
ip=192.168.1.1
exclude=exclude-list.txt

data=$(date +%Y-%m-%d)
path=/home/BACKUP/SERVER/backup-server-${data}
mkdir -p ${path}

if [ -e "${path}.log" ]; then
        /usr/bin/rsync -avzP --ipv4 --exclude-from ${exclude} --delete-during ${user}@${ip}:/* ${path}/ >> ${path}.log
else
        /usr/bin/rsync -avzP --ipv4 --exclude-from ${exclude} --delete-during ${user}@${ip}:/* ${path}/  > ${path}.log
fi
