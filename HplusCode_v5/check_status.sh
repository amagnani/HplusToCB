ls crab_project/ >& crab_list 

if [ -f my_status_check.txt ]
then 
   rm my_status_check.txt
fi

dirname="crab_project/"
while read p; do
  crab status $dirname$p >>my_status_check.txt
  echo "********************************************" >>my_status_check.txt
done <crab_list
