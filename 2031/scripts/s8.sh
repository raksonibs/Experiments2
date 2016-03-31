m=`date +%m`
cat='test'
# echo "${cat:1:${#cat}-2}"
if [ ! -z "$1" ]; then 
  echo "Changing file name"
  name=`${m:1}`
  file=`${1: -4}`
fi