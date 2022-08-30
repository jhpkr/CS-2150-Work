#!/bin/bash

get_time(){
read -p "enter the exponent for counter.cpp " exponent

if [[ $exponent = "quit" ]] ; then
	exit
else
	for ((i = 1; i <= 5; ++i)); do
		echo "Running iteration $i..."
			RUNNING_TIME=`./a.out "$exponent" | tail -1`
			((sum+="$RUNNING_TIME"))
			echo "$RUNNING_TIME"
	done
	Average=$((sum/5))
	echo "5 iterations took $sum ms"
	echo "Average time was $Average ms"
fi
}
get_time




