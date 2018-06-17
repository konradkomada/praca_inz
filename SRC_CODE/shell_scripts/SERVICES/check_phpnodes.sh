#!/bin/sh

emails=admin@domenaadmina.pl
timeout=5
ilosc_nodow=2
address=serwer.pl
node_prefix=fpmnode

if [ -n "$1" ] && [ "$1" = "second" ]; then
        sleep 10
        i=$2
        test=$(/usr/bin/curl --connect-timeout ${timeout} -sL -w "%{http_code}" http://${node_prefix}${i}.${address}/index.php)
        /bin/echo "${test}" | /bin/grep -q '/usr/local/php[0-9]\{2\}/lib/php.ini'
        if [ "$?" -ne "0" ]; then
                data=$(/bin/date "+%Y-%m-%d %H:%M:%S")
                /bin/echo "${data} FPMNODE${i} nie odpowiada po protokole HTTP" | /usr/bin/mail -s "FPMNODE${i} nie odpowiada" ${emails}
        fi
        exit
else
        for i in $(seq 1 ${ilosc_nodow}); do
                test=$(/usr/bin/curl --connect-timeout ${timeout} -sL -w "%{http_code}" http://${node_prefix}${i}.${address}/index.php)
                /bin/echo "${test}" | /bin/grep -q '/usr/local/php[0-9]\{2\}/lib/php.ini'
                if [ "$?" -ne "0" ]; then
                        $0 second ${i} &
                fi
        done
fi
