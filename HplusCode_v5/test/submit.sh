ls crabConfig*.py >& submit_list 
if [ -f my_submit_log.txt ]
then 
   rm my_submit_log.txt
fi
while read p; do
  crab submit -c $p >>my_submit_log.txt
  echo "********************************************" >>my_submit_log.txt
done <submit_list
