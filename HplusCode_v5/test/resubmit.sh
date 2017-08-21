if [ -f my_resubmit_log.txt ]
then 
   rm my_resubmit_log.txt
fi
while read p; do
  crab resubmit  $p >>my_resubmit_log.txt
  echo "********************************************" >>my_resubmit_log.txt
done <resubmit_list
