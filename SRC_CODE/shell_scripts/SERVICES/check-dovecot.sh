#!/bin/sh

IP=127.0.0.1
port=110
service=dovecot

nc -z -w5 ${IP} ${port}
if [ "$?" -ne "0" ]; then
service ${service} restart
echo "Zrestartowano us�ug� ${service} poniewa� nie odpowiada�a"
fi
