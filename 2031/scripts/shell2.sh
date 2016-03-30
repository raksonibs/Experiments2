# set initial
myvar=abc
echo "TEST 1"
echo $myvar
echo ${myvar}
echo {$myvar}
N=`echo "scale=3; 13 / 2" |bc`
echo $N