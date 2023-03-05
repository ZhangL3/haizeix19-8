#!/bin/bash

function sqrt() {
  echo "sqrt($1)" | bc
}

function markPrimes() {
  Max_Seed=`sqrt $1`

  for i in `seq 2 $Max_Seed`; do
    if [[ ${a[0]}x != x ]]; then
      continue
    fi
    for (( j = $(( i * i )); j <= $1; j+=i)); do
      a[j]=1
    done
  done
}

function calPrimesSum() {
  Sum=0
  for k in `seq 2 $1`; do
    # echo ${k}: ${a[k]}
    if [[ ${a[k]}x = x ]]; then
      Sum=$(( Sum + k ))
    fi
  done
  echo $Sum
}

markPrimes $1
calPrimesSum $1