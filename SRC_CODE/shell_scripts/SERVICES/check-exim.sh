#!/bin/sh

IP=127.0.0.1
port=25
service=exim

nc -z -w5 ${IP} ${port}
if [ "$?" -ne "0" ]; then
service ${service} restart
echo "Zrestartowano us³ugê ${service} poniewa¿ nie odpowiada³a"
fi
