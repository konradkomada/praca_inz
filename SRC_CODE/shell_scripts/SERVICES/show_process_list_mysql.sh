#!/bin/sh

mysql --defaults-extra-file=/usr/local/directadmin/conf/my.cnf -e "show processlist;"
