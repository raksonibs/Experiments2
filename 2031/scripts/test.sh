#!/bin/bash

echo "Hello World"

echo -n "Helloer
World"

myvar=abc
echo "Test 1 ====="
echo $myvar

echo $?
echo $$
echo $*
echo $#
echo $0
echo ${v-goodbye}
v=4
echo ${v-goodbye}


echo $a
echo $b
echo $c

let a=15+5
echo $a

N=`echo "scale=13; 13 /3" |bc`
echo $N

set apple banna cherry
echo $1, $2, $3

# returns true
[ $1 != apple ]
echo $?
# returns falss
[ $1 != Toe ]
echo $?

[ -d 'Toe' ]
echo $?

#-a logical AND
#-0 logial ore
#-d is file directory, -f is file file, -r is readable, -w writable, -x exectuaable, -s not empty, -L
# [-w rest.txt -a -w score.txt]

# ["$var" = "rightvalue"] && echo OK

# dir=testnewone
# [ -d $dir ] || mkdir $dir

# # read marks

# # if [ $marks -ge 80 ]; then
# #   grade=A
# # else
# #   grade=D
# # fi
# # echo $grade

# # echo $PWD
# # for SCRIPT in "$PWD/*"
# # do 
# #   # if [ -f $SCRIPT ]; then
# #     echo $SCRIPT
# #     echo
#   # fi 
# done

VAR1="05"
VAR2="5"
printf "%s" "Do they -eq as equal?"
if [ "$VAR1" -eq "$VAR2" ]; then
  echo YES
else
  echo NO 
fi 
printf "%s" "do they = as equals"
if [ "$VAR1" = "$VAR2" ]; then
  echo YES
else
  echo NO 
fi

for filename in *
do 
  echo $filename
done

for i in 10 9 8 7 
do
  echo $i
done 


while read line 
do
  echo line: $line
done < testfile
# this is the file name

# space=`df -h | awk '{print $5}' | grep % | grep -v Use | sort -n | tail -1 | cut -d "%" -f1 -`
space=5
case $space in
[1-6]*)
  Message="All is quiet."
  ;;
[7-8]*)
  Message="Start thinking about cleaning out some stuff.  There's a partition that is $space % full."
  ;;
9[1-8])
  Message="Better hurry with that new disk...  One partition is $space % full."
  ;;
99)
  Message="I'm drowning here!  There's a partition at $space %!"
  ;;
*)
  Message="I seem to be running with an nonexistent amount of disk space..."
  ;;
esac

echo $Message
echo $#

allfiles() {
  for x in $*; do
    if [ ! -f $x ]; then 
      return 1 
    fi 
  done
  return 0
}

allfiles testfile