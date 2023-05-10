#!/bin/bash

read -p "Input Num" Num
case $Num in
  1 )
    echo "1"
    ;;
  2 )
    echo 2
    ;;
  * )
    echo 100
    ;;
esac