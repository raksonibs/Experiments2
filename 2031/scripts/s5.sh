# echo "$1"
# echo "$2"

if [ -z "$2" ]; then
  echo "Error need two files"
else
  if [[ ! -d "$2" && ! -d "$1" && -r "$2" && -f "$1" && -f "$1" && -r "$1" ]]; then
    counter=0
    totalscore=0
    while read p; do
    
    # for i in p would also work and just grab first

      arr=($p)
      #   echo "$word"
      # done
      fail=50
       if [ "$3" == "-F" ]; then
          key=${arr[0]}
          fname=${arr[1]}
          lname=${arr[2]}
          # echo "$parr[1]"
          # echo "Looking for in $parr"
          line=`cat "$2" | grep $key`
          sarr=($line)
          score=${sarr[2]}
          let counter=counter+1
          let totalscore=totalscore+$score

        if [ "$score" -lt "$fail" ]; then 
          echo "$lname, $fname $score" 
        fi
       else

        key=${arr[0]}
        fname=${arr[1]}
        lname=${arr[2]}
        # echo "$parr[1]"
        # echo "Looking for in $parr"
        line=`cat "$2" | grep $key`
        sarr=($line)
        score=${sarr[2]}
        let counter=counter+1
        let totalscore=totalscore+$score

        echo "$lname, $fname $score"
       fi
      

    done < "$1"
    if [ -z "$3" ]; then
      echo "Nothing"
    else
      if [ "$3" == "-F" ]; then
        echo "-F"
      else
        echo "avg"
        num=0
        let num=totalscore/counter
        echo "AVG is $num"
      fi
    fi
  else
    echo "Not readable"
  fi

fi