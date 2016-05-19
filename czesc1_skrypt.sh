#!/bin/bash
a=(5 -7 2 -3 8 -9 3 -11)
b=(5 7 4 6 4 3 7 13)
c=(-27 13 -8 -24 -6 -28 4 -29)
d=(-15 6 16 -18 11 26 19 29)
e=(6 28 3 -5 -8 17 -18 15)
f=(-7 3 -24 21 6 -10 4 -7)
r=( 1 1 1 0 0 1 0 1 )
out=`g++ -o projekt projekt.cpp`
sleep 2
for ind in `seq 0 7`; do
  out=`./projekt ${a[$ind]} ${b[$ind]} ${c[$ind]} ${d[$ind]} ${e[$ind]} ${f[$ind]}`
  if [ "$out" != "${r[ind]}" ]
  then
    echo "input" ${a[$ind]} ${b[$ind]} ${c[$ind]} ${d[$ind]} ${e[$ind]} ${f[$ind]}
    echo "output actual" $out
    echo "output expected" ${r[$ind]}
  fi
done
