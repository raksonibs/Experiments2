awk -F: '
BEGIN {
  mark=0
  avg=0
  count=0
  arr[1024]
  for(i=0;i<1024;i++){
    arr[i] =0
  }
  i=0
}
{
  mark=25*($40/50)
}
END {

}
'