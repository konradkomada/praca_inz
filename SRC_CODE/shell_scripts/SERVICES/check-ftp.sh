#!/bin/sh

IP=127.0.0.1
port=21
service=pure-ftp
#service=proftpd

nc -z -w5 ${IP} ${port}
if [ "$?" -ne "0" ]; then
service ${service} restart
echo "Zrestartowano us³ugê ${service} poniewa¿ nie odpowiada³a"
fi
