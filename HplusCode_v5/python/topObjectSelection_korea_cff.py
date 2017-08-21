import FWCore.ParameterSet.Config as cms
## ---
##
## MUONS SELECTIONS
##
## ---
 
from PhysicsTools.PatAlgos.selectionLayer1.muonSelector_cfi import *
from PhysicsTools.HplusCode_v5.myMuonDzSelector_cfi import *
tightMuons = myPatMuons.clone(
src = 'selectedPatMuonsPFlowLoose',

cut = 'isGlobalMuon & isPFMuon & '
      'globalTrack.normalizedChi2 < 10.0 &'      
      'globalTrack.hitPattern.numberOfValidMuonHits > 0 &'
      'innerTrack.hitPattern.numberOfValidPixelHits > 0 &' 
      'numberOfMatchedStations > 1 &'
      'pt > 26. &'
      'abs(eta) < 2.1  &'      
      'abs(dB) < 0.2 &'
      'innerTrack.hitPattern.trackerLayersWithMeasurement > 5 & '      
      #'(pfIsolationR04.sumChargedHadronPt + max(0., pfIsolationR04.sumNeutralHadronEt + pfIsolationR04.sumPhotonEt - 0.5 * pfIsolationR04.sumPUPt) ) / pt < 0.12',
      #for QCD data drive estimation 
      '(pfIsolationR04.sumChargedHadronPt + max(0., pfIsolationR04.sumNeutralHadronEt + pfIsolationR04.sumPhotonEt - 0.5 * pfIsolationR04.sumPUPt) ) / pt < 0.30',
dzCut = cms.double(0.5)
      
)
vetoMuons =  selectedPatMuons.clone(
src = 'selectedPatMuonsPFlowLoose',

cut = 'pt > 10. &'
      'abs(eta) < 2.5  &'      
      #'(pfIsolationR04.sumChargedHadronPt + max(0., pfIsolationR04.sumNeutralHadronEt + pfIsolationR04.sumPhotonEt - 0.5 * pfIsolationR04.sumPUPt) ) / pt < 0.12',
      #for QCD data drive estimation 
      '(pfIsolationR04.sumChargedHadronPt + max(0., pfIsolationR04.sumNeutralHadronEt + pfIsolationR04.sumPhotonEt - 0.5 * pfIsolationR04.sumPUPt) ) / pt < 0.20'
      
)

##
## ELECTRONS SELECTIONS
##
from PhysicsTools.PatAlgos.selectionLayer1.electronSelector_cfi import *
vetoElecs = selectedPatElectrons.clone(
src = 'selectedPatElectronsPFlow',
cut =
'pt > 20. &'
 ' abs(eta) < 2.5 &'
  'electronID("mvaTrigV0") > 0.5 &'
 '(chargedHadronIso+max((neutralHadronIso+photonIso-0.5*puChargedHadronIso),0.0))/et < 0.15'
   ) 

#vetoElecs = selectedPatElectrons.clone(
#src = 'selectedPatElectronsPFlow',
#cut =
#'pt > 30. &'
# ' abs(eta) < 2.5 &'
# '( abs(eta) < 1.4442   |'
# '  abs(superCluster.eta) > 1.5660 ) &'
# 'abs(dB)  <  0.02 &'						 # NB: needs "process.selectedPatElectrons.usePV = false" for PAT tuple production
# 'electronID("mvaTrigV0") > 0.9 &'
# '(dr03TkSumPt+dr03EcalRecHitSumEt+dr03HcalTowerSumEt)/et < 0.1'
#   ) 


###
## JETS SELECTIONS
##
from PhysicsTools.PatAlgos.selectionLayer1.jetSelector_cfi import *
goodJets = selectedPatJets.clone(
src = 'goodPatJetsPFlow',
cut =  
'pt > 30 '
)
kinfitJets = selectedPatJets.clone(
src = 'goodPatJetsPFlow',
cut =  
'pt > 29 '
)
loosebJets = selectedPatJets.clone(
src = 'goodPatJetsPFlow',
cut =
'pt > 30 & '
'bDiscriminator("combinedSecondaryVertexBJetTags") > 0.244 '
)

bJets = selectedPatJets.clone(
src = 'goodPatJetsPFlow',
cut =
'pt > 30 & '
'bDiscriminator("combinedSecondaryVertexBJetTags") > 0.679 '
)

##
## MET SELECTIONS
##
from PhysicsTools.PatAlgos.selectionLayer1.metSelector_cfi import *
goodMETs = selectedPatMET.clone(
src = 'patMETsPFlow',
cut =
#'pt > 20 '
     #for QCD data drive estimation 
'pt > 0 '
)

topObjectSelection = cms.Sequence(
goodMETs *
goodJets *
kinfitJets *
loosebJets *
bJets *
vetoElecs *
vetoMuons *
tightMuons
)
