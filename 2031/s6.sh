if [ -z "$2" ]; then
  if [ ! -d "$2" && ! -d "$1" && -r "$2" && -r "$1" && -f "$2" && -f "$1" ]; then 
    while read line; do
      echo "$line"
    done < "$1"
  else
    echo "Not possible"
  fi
else
  echo "Too few args"
fi