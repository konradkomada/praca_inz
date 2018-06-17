#!/bin/bash
# ------------------------------------------------------------------
#   Autor: Konrad Komada
#          onekiller.sh
#          Skrypt do zabijania procesów np: php-fpm, które przekraczają limit użycia CPU
#          http://konradkomada.pl
# ------------------------------------------------------------------

#uruchamiac co minute z crona: /etc/crontab
#* * * * * root /root/scripts/onekiller.sh > /dev/null 2>&1

# --- Option processing --------------------------------------------
file1=/tmp/onekiller_1.tmp
file2=/tmp/onekiller_2.tmp
procesy="php-fpm"
log=/var/log/onekiller.log
lfolder=/root/userscpulimit
path=/root/scripts
default_cpu_limit=25

function checking() {
for proces in ${procesy}; do
        ps auwx | awk '{print $3, $2, $1, $11}' | grep ${proces} | head -n 35 | awk '{gsub (/\../,"",$1); if ($1 > 5) print $1,$3"@"$2}' > ${file1}
        if [ -e ${file1} ]; then
                file=$(cat ${file1})
                ilosc=$(echo "${file}" | awk 'NF > 0' | wc -l | awk '{print $1}')
                if [ ${ilosc} -ne 0 ]; then
                        for i in $(seq 1 ${ilosc}); do
                                actual_user_name=$(echo "${file}" | awk '{print $2}' | cut -f 1 -d @ | head -n ${i} | tail -n 1)
                                actual_user_pid=$(echo "${file}" | awk '{print $2}' | cut -f 2 -d @ | head -n ${i} | tail -n 1)
                                actual_user_cpu=$(echo "${file}" | awk '{print $1}' | head -n ${i}  | tail -n 1    | cut -f 1 -d '.')
                                if [ -e ${lfolder}/${actual_user_name} ]; then
                                        conf_user_cpu_limit=$(cat ${lfolder}/${actual_user_name})
                                else
                                        conf_user_cpu_limit=${default_cpu_limit}
                                fi
                                if [ ${actual_user_cpu} -gt ${conf_user_cpu_limit} ]; then
                                        renice -n +19 -p ${actual_user_pid} > /dev/null 2>&1
                                        actual_user_name_pid=$(echo "${file}" | awk '{print $2}')
                                        data=$(date "+%Y-%m-%d %H:%M:%S")
                                        $0 ${actual_user_name_pid} &
                                        echo "${data} PASSED: ${proces} o PID: ${actual_user_pid} USERNAME: ${actual_user_name} BECAUSE USED: ${actual_user_cpu} % CPU" >> ${log}
                                fi
                        done
                fi
        fi
done
}

function killing() {
for proces in ${procesy}; do
        ps auwx | awk '{print $3, $2, $1, $11}' | grep ${proces} | head -n 35 | awk '{gsub (/\../,"",$1); if ($1 > 5) print $1,$3"@"$2}' > ${file2}
        if [ -e ${file2} ]; then
                file=$(cat ${file2})
                ilosc=$(echo "${file}" | awk 'NF > 0' | wc -l | awk '{print $1}')
                if [ ${ilosc} -ne 0 ] ; then
                        for i in $(seq 1 ${ilosc}); do
                                actual_user_name=$(echo "${file}" | awk '{print $2}' | cut -f 1 -d @ | head -n ${i} | tail -n 1)
                                actual_user_pid=$(echo "${file}" | awk '{print $2}' | cut -f 2 -d @ | head -n ${i} | tail -n 1)
                                actual_user_cpu=$(echo "${file}" | awk '{print $1}' | head -n ${i}  | tail -n 1  | cut -f 1 -d '.')
                                old_user_name=$(echo $S1 | cut -f 1 -d @)
                                if [ "${old_user_name}" = "${actual_user_name}" ]; then
                                        old_user_pid=$(echo $S1 | cut -f 2 -d @)
                                        if [ ${old_user_pid} -eq ${actual_user_pid} ] ; then
                                                if [ -e ${lfolder}/${actual_user_name} ]; then
                                                        conf_user_cpu_limit=$(cat ${lfolder}/${actual_user_name})
                                                else
                                                        conf_user_cpu_limit=$default_cpu_limit
                                                fi
                                                if [ ${actual_user_cpu} -gt ${conf_user_cpu_limit} ] ; then
                                                        data=$(date "+%Y-%m-%d %H:%M:%S")
                                                        kill -9 ${old_user_pid}
                                                        echo "${data} KILLED: ${proces} o PID: ${old_user_pid} USERNAME: ${old_user_name} BECAUSE USED: ${actual_user_cpu} % CPU" >> ${log}
                                                fi
                                        fi
                                fi
                        done
                fi
        fi
done
}


if [ -z "$1" ]; then
        for ((j=1; j<=5; j++)); do
                checking
                sleep 10
        done
else
        sleep 9
        S1=$1
        killing
fi