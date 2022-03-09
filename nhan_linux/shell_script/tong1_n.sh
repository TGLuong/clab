#!/bin/sh
echo "chuong trinh tinh tong tu 1 den $1"
index=0
sum=0
while [ $index -lt $1 ]
do
index=$(($index + 1))
sum=$(($sum + $index))
done
echo "tong tu 1 den $1 la $sum"
echo ""
exit 0
