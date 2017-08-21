perl -i.bak -p -e 's/hplus_data.ini/hplus_WW.ini/ig' runHplus_dataBkg.C
root -l runHplus_dataBkg.C
perl -i.bak -p -e 's/hplus_WW.ini/hplus_WZ.ini/ig' runHplus_dataBkg.C
root -l runHplus_dataBkg.C
perl -i.bak -p -e 's/hplus_WZ.ini/hplus_ZZ.ini/ig' runHplus_dataBkg.C
root -l runHplus_dataBkg.C
perl -i.bak -p -e 's/hplus_ZZ.ini/hplus_DY.ini/ig' runHplus_dataBkg.C
root -l runHplus_dataBkg.C
perl -i.bak -p -e 's/hplus_DY.ini/hplus_t.ini/ig' runHplus_dataBkg.C
root -l runHplus_dataBkg.C
perl -i.bak -p -e 's/hplus_t.ini/hplus_tbar.ini/ig' runHplus_dataBkg.C
root -l runHplus_dataBkg.C
perl -i.bak -p -e 's/hplus_tbar.ini/hplus_s.ini/ig' runHplus_dataBkg.C
root -l runHplus_dataBkg.C
perl -i.bak -p -e 's/hplus_s.ini/hplus_sbar.ini/ig' runHplus_dataBkg.C
root -l runHplus_dataBkg.C
perl -i.bak -p -e 's/hplus_sbar.ini/hplus_tW.ini/ig' runHplus_dataBkg.C
root -l runHplus_dataBkg.C
perl -i.bak -p -e 's/hplus_tW.ini/hplus_tWbar.ini/ig' runHplus_dataBkg.C
root -l runHplus_dataBkg.C
perl -i.bak -p -e 's/hplus_tWbar.ini/hplus_WJets.ini/ig' runHplus_dataBkg.C
root -l runHplus_dataBkg.C
perl -i.bak -p -e 's/hplus_WJets.ini/hplus_Wbb.ini/ig' runHplus_dataBkg.C
root -l runHplus_dataBkg.C
perl -i.bak -p -e 's/hplus_Wbb.ini/hplus_Zbb.ini/ig' runHplus_dataBkg.C
root -l runHplus_dataBkg.C
perl -i.bak -p -e 's/hplus_Zbb.ini/hplus_QCD.ini/ig' runHplus_dataBkg.C
root -l runHplus_dataBkg.C
perl -i.bak -p -e 's/hplus_QCD.ini/hplus_TTH.ini/ig' runHplus_dataBkg.C
root -l runHplus_dataBkg.C
perl -i.bak -p -e 's/hplus_TTH.ini/hplus_TTZ.ini/ig' runHplus_dataBkg.C
root -l runHplus_dataBkg.C
perl -i.bak -p -e 's/hplus_TTZ.ini/hplus_TTW.ini/ig' runHplus_dataBkg.C
root -l runHplus_dataBkg.C
perl -i.bak -p -e 's/hplus_TTW.ini/hplus_data.ini/ig' runHplus_dataBkg.C






















