perl -i.bak -p -e 's/hplus_TTJetsSplit.ini/hplus_TTJetsSplit_massup.ini/ig' runHplus_ttsplit.C
root -l runHplus_ttsplit.C
perl -i.bak -p -e 's/hplus_TTJetsSplit_massup.ini/hplus_TTJetsSplit_massdown.ini/ig' runHplus_ttsplit.C
root -l runHplus_ttsplit.C
perl -i.bak -p -e 's/hplus_TTJetsSplit_massdown.ini/hplus_TTJetsSplit_matchdown.ini/ig' runHplus_ttsplit.C
root -l runHplus_ttsplit.C
perl -i.bak -p -e 's/hplus_TTJetsSplit_matchdown.ini/hplus_TTJetsSplit_matchup.ini/ig' runHplus_ttsplit.C
root -l runHplus_ttsplit.C
perl -i.bak -p -e 's/hplus_TTJetsSplit_matchup.ini/hplus_TTJetsSplit_scaleup.ini/ig' runHplus_ttsplit.C
root -l runHplus_ttsplit.C
perl -i.bak -p -e 's/hplus_TTJetsSplit_scaleup.ini/hplus_TTJetsSplit_scaledown.ini/ig' runHplus_ttsplit.C
root -l runHplus_ttsplit.C
perl -i.bak -p -e 's/hplus_TTJetsSplit_scaledown.ini/hplus_TTJetsSplit_pow.ini/ig' runHplus_ttsplit.C
root -l runHplus_ttsplit.C
perl -i.bak -p -e 's/hplus_TTJetsSplit_pow.ini/hplus_TTJetsSplit_TTnlo.ini/ig' runHplus_ttsplit.C
root -l runHplus_ttsplit.C






















