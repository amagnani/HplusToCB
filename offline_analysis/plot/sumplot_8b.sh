root -l drawHplusSys.C\(\"Reco_hMUeta_8b\",\"pythia\",\"muon\ eta\",1,100000,1\)
mv MyCanvas.png 8b_hMUeta.png
root -l drawHplusSys.C\(\"Reco_hMUpt_8b\",\"pythia\",\"muon\ pt\ \(GeV\)\",1,50000,1\)
mv MyCanvas.png 8b_hMUpt.png
root -l drawHplusSys.C\(\"Reco_hJpt_8b\",\"pythia\",\"jets\ pt\ \(GeV\)\",1,1000000,1\)
mv MyCanvas.png 8b_hJpt.png
root -l drawHplusSys.C\(\"Reco_hJeta_8b\",\"pythia\",\"jet\ eta\",1,1000000,1\)
mv MyCanvas.png 8b_hJeta.png
root -l drawHplusSys.C\(\"Reco_hMET_8b\",\"pythia\",\"MET\ \(GeV\)\",1,1000000,1\)
mv MyCanvas.png 8b_hMET.png
#root -l drawHplusSys.C\(\"Reco_hnVertex_8b\",\"pythia\",\"reconstructed\ primary\ vertices\",1,10000,0\)
#mv MyCanvas.png 8b_hnVertex.png
root -l drawHplusSys.C\(\"Reco_hnJet_8b\",\"pythia\",\"#\ jets\",1,100000,1\)
 mv MyCanvas.png 8b_hnJet.png
