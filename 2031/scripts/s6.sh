if [ ! -z "$2" ]; then
  if [[ ! -d "$2" && ! -d "$1" && -r "$2" && -r "$1" && -f "$2" && -f "$1" ]]; then 
    totalscore=0
    counter=0
    fail=50
    while read line; do
      # echo "$line"
      linearr=($line)
      fname=${linearr[1]}
      lname=${linearr[2]}
      key=${linearr[0]}
      foundline=`cat "$2" | grep $key`
      # echo "$foundline"
      foundarr=($foundline)

      mark=${foundarr[2]}
      let counter=count+1
      let totalscore=totalscore+mark
      if [ ! -z "$3" ]; then
        if [ "$3" == "-F" ]; then
          if [ "$mark" -lt "$fail" ]; then
            echo "$lname, $fname $mark"
          fi
        else
          echo "$lname, $fname $mark"
        fi
      else
        echo "$lname, $fname $mark"
      fi
    done < "$1"
      if [ ! -z "$3" ]; then
        if [ "$3" == "avg" ]; then
          num=0
          let num=totalscore/counter
          echo "$num"
        fi
      fi
  else
    echo "Not possible"
  fi
else
  echo "Too few args"
fi