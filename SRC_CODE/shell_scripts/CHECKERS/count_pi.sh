#!/bin/bash

if [ $# -eq 1 ]
then
	Liczba=$1
else
	echo -n "Wprowadź ile razy mam wykonać obliczenia: "
	read Liczba
fi

for((i=0;i<Liczba;i++)); do
	# scale=50 - peecyzja wyświetlania, parametr dla bc
	# seq x x 100 - precyzja obliczeń, im większe tym większa precyzja. Warość 200 zwiększa czas i obciążenie CPU
	(echo -n "scale=50;" && (seq 1 2 100 | xargs -I{} echo '(16*(1/5)^{}/{}-4*(1/239)^{}/{})')) | paste -sd-+ | bc -l
done

