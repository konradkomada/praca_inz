#!/bin/sh

IP=127.0.0.1
port=53
service=bind9

nc -z -w5 ${IP} ${port}
if [ "$?" -ne "0" ]; then
service ${service} restart
echo "Zrestartowano us�ug� ${service} poniewa� nie odpowiada�a"
fi
