#!/bin/bash
for i in $*; do
  echo $i
done

for i in `ls`; do
  echo $i
done

for i in `seq 1 10`; do
  echo $i
done

# (()) 内不用取值符 $
for (( i = 0; i < 10; i++ )) do
  echo $i
done
