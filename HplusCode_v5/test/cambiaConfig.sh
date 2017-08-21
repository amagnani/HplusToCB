ls crabConfig*.py >& cambia_list
while read p; do
perl -i.bak -p -e 's/Jun8JERup/Jun8JERdown/ig' $p
done <cambia_list
