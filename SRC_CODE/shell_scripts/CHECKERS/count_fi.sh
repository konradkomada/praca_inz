#!/bin/bash

if [ $# -eq 1 ]
then
	Liczba=$1
else
	echo -n "Wprowadź ile razy mam wykonać obliczenia: "
	read Liczba
fi

for((j=0;j<Liczba;j++)); do
	fib_a=0
	fib_b=1
	for((i=0;i<=90;i++)); do
		fib_n=$((fib_a+fib_b))
		fib_a=${fib_b}
		fib_b=${fib_n}
	done
	echo -n "Liczba fi wynosi: " 
	echo "scale=40; ${fib_b}/${fib_a}" | bc -l
done

