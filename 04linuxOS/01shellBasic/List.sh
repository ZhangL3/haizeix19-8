#!/bin/bash
if [[ $# -ne 1 ]];then
  echo "Usage: bash List.sh num"
  exit
fi

Cnt=$1

Names=(`cat names`)
Size=${#Names[@]}

function rand(){
  Min=1
  Max=$(( Size - 1 ))
  # 用时间算法的话，只是单次随机
  # Num=`date +%s%N`
  Num=$(( $RANDOM % Size ))
  echo $(( $Num % $Max + $Min ))
}

for i in `seq 1 $Cnt`;do
  RandNum=`rand`
  echo "${Names[${RandNum}]} "
done