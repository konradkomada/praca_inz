#!/bin/sh

infopath=/root/info
interval=5

#nie edytowac ponizej
host=$(/bin/hostname)
my_pid=$(echo $$)
script_name=$(echo $0 | grep -o '[^/]*$')

/bin/echo "${host}" > ${infopath}/hostname.txt

if  /bin/ps ax | /bin/grep ${script_name} | /bin/grep -v grep | /bin/grep -v ${my_pid} ; then
        #/bin/echo "Inny proces: ${script_name} jest juz uruchomiony, nic nie robie"
        exit
else
        for i in $(seq 1 11); do #co 5 sekund
                cpu_load_01m=$(/usr/bin/snmpwalk -v1 -cpublic localhost .1.3.6.1.4.1.2021.10.1.3.1 | cut -f2 -d'"')
                echo $cpu_load_01m > ${infopath}/cpu-load.txt
                cpu_load_05m=$(/usr/bin/snmpwalk -v1 -cpublic localhost .1.3.6.1.4.1.2021.10.1.3.2 | cut -f2 -d'"')
                echo $cpu_load_05m > ${infopath}/cpu-load_05m.txt
                cpu_load_15m=$(/usr/bin/snmpwalk -v1 -cpublic localhost .1.3.6.1.4.1.2021.10.1.3.3 | cut -f2 -d'"')
                echo $cpu_load_15m > ${infopath}/cpu-load_15m.txt
                cpu_idle=$(/usr/bin/snmpwalk -v1 -cpublic localhost .1.3.6.1.4.1.2021.11.11.0 | cut -f4 -d" ")
                echo $cpu_idle > ${infopath}/cpu-idle.txt
                echo $cpu_idle > ${infopath}/cpu-usage.txt
                ram_used=$(/usr/bin/snmpwalk -v1 -cpublic localhost .1.3.6.1.4.1.2021.4.6.0 | cut -f4 -d" ")
                echo $ram_used > ${infopath}/ram-usage.txt
                sleep ${interval}
        done
fi
