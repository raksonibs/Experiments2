// sed 's/Jon/Jonathan/g' < file
// sed '/PA/p'
// sed '/Karen Evich/c\****cats'
// sed -n 's/[0-9]/\1/p'


// awk -F: '
// BEGIN {
//   mark = 0
// }
// {
//   mark=25*($4/50+15*($5/80))
//   printf("%d %.3f\n", $3, mark)
// }
// END {

// }
// '

#!/bin/sh

awk -F: '
BEGIN {
  mark=0
  avg=0
  count=0
  arr[1024]
  
  for(i=0;i<1024;i++)
  {
    arr[i] = 0
  }
  i=0
}
{
  mark=25*($4/50)+15*($5/80)+15*($6/30)+45*($7/80)
  arr[i] = mark
  i++
  #printf("i:%d\n", i)
  count++
}
END {
  for(i=0;i<count;i++)
  {
    sum += arr[i]
  }
  #printf("sum %d, count %d\n", sum, count)
  avg = sum / count
  printf("%.3f\n", avg)
  
}