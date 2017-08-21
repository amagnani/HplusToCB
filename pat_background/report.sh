ls crab_project/ >& report_list 

if [ -f my_status_check.txt ]
then 
   rm my_status_check.txt
fi

dirname="crab_project/"
while read p; do
  crab report $dirname$p >>my_report.txt
  echo "********************************************" >>my_report.txt
done <report_list
