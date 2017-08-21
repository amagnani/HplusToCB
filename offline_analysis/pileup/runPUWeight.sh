root -l PUWeight.C
perl -i.bak -p -e 's/hplus_WW.ini/hplus_WZ.ini/ig' PUWeight.C
root -l PUWeight.C
perl -i.bak -p -e 's/hplus_WZ.ini/hplus_ZZ.ini/ig' PUWeight.C
root -l PUWeight.C
perl -i.bak -p -e 's/hplus_ZZ.ini/hplus_DY.ini/ig' PUWeight.C
root -l PUWeight.C
perl -i.bak -p -e 's/hplus_DY.ini/hplus_QCD.ini/ig' PUWeight.C
root -l PUWeight.C
perl -i.bak -p -e 's/hplus_QCD.ini/hplus_t.ini/ig' PUWeight.C
root -l PUWeight.C
perl -i.bak -p -e 's/hplus_t.ini/hplus_tbar.ini/ig' PUWeight.C
root -l PUWeight.C
perl -i.bak -p -e 's/hplus_tbar.ini/hplus_s.ini/ig' PUWeight.C
root -l PUWeight.C
perl -i.bak -p -e 's/hplus_s.ini/hplus_sbar.ini/ig' PUWeight.C
root -l PUWeight.C
perl -i.bak -p -e 's/hplus_sbar.ini/hplus_tW.ini/ig' PUWeight.C
root -l PUWeight.C
perl -i.bak -p -e 's/hplus_tW.ini/hplus_tWbar.ini/ig' PUWeight.C
root -l PUWeight.C
perl -i.bak -p -e 's/hplus_tWbar.ini/hplus_WJets.ini/ig' PUWeight.C
root -l PUWeight.C
perl -i.bak -p -e 's/hplus_WJets.ini/hplus_TTJets.ini/ig' PUWeight.C
root -l PUWeight.C






















