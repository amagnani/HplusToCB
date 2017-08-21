ls dirList*.txt >& cambia_list
while read p; do
perl -i.bak -p -e 's/Feb1/Feb26/ig' $p
done <cambia_list
