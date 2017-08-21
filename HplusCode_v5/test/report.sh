ls Jun8/ >& report_list 

if [ -f my_report.txt ]
then 
   rm my_report.txt
fi

dirname="Jun8/"
while read p; do
  crab status $dirname$p >>my_report.txt
  echo "********************************************" >>my_report.txt
done <report_list
