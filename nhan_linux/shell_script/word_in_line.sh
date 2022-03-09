#!/bin/sh
echo “Chuong trinh dem so tu cua tap tin $1”
n=0
while read line
do
for wd in $line
do
n=$(($n + 1))
done
done < $1
echo “Tong so tu cua tap tin $1 la : $n”
exit 0

