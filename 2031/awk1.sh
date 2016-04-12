# awk -f fe_awk.txt emp.txt
# BEGIN{
#   FS="\t"
#   printf("%s\t%s\t%s\n","name" , "Hourly pay", "Numbr of hours")
#      }

#   $3 > 0 { printf("%s\t%d\t%d\t%d\n",$1, $2 , $3 , $2 * $3) }
#   {total=total+ $2 * $3 }


# END {
#   printf("%d employees\n", NR)
#     printf("Total pay is  %d\n", total)
#   printf("Average pay is %f\n", total/NR)
#   }


# awk -F: '
awk '
BEGIN {
  total_employees=0
  total_pay=0
  avg_pay=0
}
{
  pay=$2*$3
  printf("%s\t %f\t %d\t %f\t\n", $1, $2, $3, pay)
  total_pay += pay 
  total_employees++
}
END {
  printf("Total employees %d\n", total_employees)
  printf("Total pay %f\n", total_pay)
  printf("Avg Pay %.3f\n", total_pay/total_employees)
}
' < $1