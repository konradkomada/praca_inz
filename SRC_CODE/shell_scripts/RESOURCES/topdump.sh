#!/bin/sh

path=/root/TOPDUMP
mkdir -p ${path}

for i in $(seq 1 5); do
data=$(/bin/date +%Y-%m-%d-%H-%M-%S)
/usr/bin/top -n 1 > ${path}/top_${data}.txt
sleep 10
done

