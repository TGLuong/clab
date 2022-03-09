#!/bin/sh
echo “Chuong trinh tinh $1!”
index=0
gt=1
while [ $index -lt $1 ]
do
index=$(($index + 1))
gt=$(($gt * $index))
done
echo “$1!= $gt”
exit 0

