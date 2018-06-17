#!/bin/sh

#nazwa backupu
name=server
#zdalny użytkownik ssh do backupu
user=root
#funkcja skryptu (okresla rozne nazwy)
func=backup
#ip zdalnego serwera z ktorego pobierane są dane do backupu
ip=192.168.1.1
#listy wykluczenia katalogów w osobnym pliku
exclude=exclude-list.txt
#ścieżka do katalogu a plikami dla server monitor'a
infopath=~/info
#katalog przeznaczenia backupów
destination=/home
#wstaw date w formacie RRRR-MM-DD z dnia z ktorego istnieje ostatni backup do hardlinkowania,
#jeśli backup z dnia poprzedniego nie istnieje pozostaw wartość znmiennej dataminus pusta np:
#dataminus=2015-03-31
dataminus=

#poniżej nie edytowac
fulldatetime=$(/bin/date "+%Y-%m-%d %H:%M:%S")
server=$(hostname -s)
infofile=${func}-${name}
backupdir=${destination}/$(echo ${func} | tr '[:lower:]' '[:upper:]')/$(echo ${name} | tr '[:lower:]' '[:upper:]')
data=$(date +%Y-%m-%d)
[ -z "${dataminus}" ] && dataminus=$(date -d "-1 day" +%Y-%m-%d)
path=${backupdir}/${func}-${name}-${data}
previous=${backupdir}/${func}-${name}-${dataminus}
[ ! -e "${path}" ] && mkdir -p ${path}
[ ! -e "${infopath}" ] && mkdir -p ${infopath}

if [ -e "${previous}" ]; then
        if [ -e "${path}.log" ]; then
                /usr/bin/rsync -avzP --ipv4 --exclude-from ${exclude} --delete-during --delete-excluded --link-dest=${previous} ${user}@${ip}:/* ${path}/ >> ${path}.log
        else
                /usr/bin/rsync -avzP --ipv4 --exclude-from ${exclude} --delete-during --delete-excluded --link-dest=${previous} ${user}@${ip}:/* ${path}/  > ${path}.log
        fi
        echo "Succcess: ${fulldatetime} Backup różnicowy ${name} wykonano na ${server}..." | tee ${infopath}/${infofile}
else
echo "Error: backup z dnia poprzedniego ${name} nie istnieje" | tee ${infopath}/${infofile}.txt
fi