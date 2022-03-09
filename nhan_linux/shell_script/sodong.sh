#!/bin/sh
echo “Chuong trinh dem so dong cua tap tin $1”
n=0
while read line 
do
n=$(($n + 1))
done < $1 
echo “So dong cua tap tin $1 la : $n”
exit 0

