#!/bin/sh

emails=email@admina.pl
hdd=sda
func=hdd-usage
infopath=/root/info
treshold=70
interval=1

#nie edytowac ponizej
host=$(/bin/hostname)
my_pid=$(echo $$)
script_name=$(echo $0 | grep -o '[^/]*$')

if  /bin/ps ax | /bin/grep ${script_name} | /bin/grep -v grep | /bin/grep -v ${my_pid} ; then
        #/bin/echo "Inny proces: ${script_name} jest juz uruchomiony, nic nie robie"
        exit
else
        for i in $(seq 1 11); do #co 5 sekund
                hdd_usage=$(/usr/bin/iostat -d -x ${hdd} 5 2 | /bin/grep ${hdd} | /usr/bin/tail -n 1 | /usr/bin/awk '{print $14}')
                /bin/echo "${hdd_usage}" > ${infopath}/${func}.txt #zapisuje do pliku
                #echo "${hdd_usage}" #wyswietla na ekran
                #powiadomienie emailem jesli przekroczy limit
                int_hdd_usage=$(/bin/echo ${hdd_usage} | /usr/bin/cut -f1 -d,)
                if [ "${int_hdd_usage}" -gt "${treshold}" ]; then
                        data=$(/bin/date "+%Y-%m-%d %H:%M:%S")
                        /bin/echo "${data} Avg ${hdd} usage > ${treshold}" | /usr/bin/mail -s "${data} Avg ${hdd} usage > ${treshold}" ${emails}
                fi
                #sleep ${interval}
    