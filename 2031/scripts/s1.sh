echo "input two params"

echo $1
echo $2

if [ -z "$2" ]; then
  echo "needs two paramaters"
else
  # re = '^[0=9]+$'
  # if ! [[ $2 =~ $re ]] ; then
  #   echo "error: Not a number" >&2; exit 1
  # fi
  echo `expr $1 + $2`
fi