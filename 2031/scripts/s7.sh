#!/bin/sh

# case $# in
# 0)  set `date`; m=$2; y=$6;;
# 1)  m=$1; set `date`; y=$6;;
# 2)  m=$1; y=$2;;
# esac
# jan*|Jan*)  m=1;;
# feb*|Feb*)  m=2;;
# mar*|Mar*)  m=3;;
# apr*|Apr*)  m=4;;
# may*|May*)  m=5;;
# jun*|Jun*)  m=6;;
# jul*|Jul*)  m=7;;
# aug*|Aug*)  m=8;;
# sep*|Sep*)  m=9;;
# oct*|Oct*)  m=10;;
# nov*|Nov*)  m=11;;
# dec*|Dec*)  m=12;;
# [1-9]|10|11|12) ;;
# *)    y=$m;m="";;
# esac
now=$(date +"%m_%d_%Y")
mon=`date +%m`

# if [ ${file: -4} == ".txt" ]

filename="$0"
echo "$now"
echo "${mon:1:${#mon}-1}"