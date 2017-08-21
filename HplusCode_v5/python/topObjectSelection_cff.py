import FWCore.ParameterSet.Config as cms
## ---
##
## MUONS SELECTIONS
##
## ---
 
from PhysicsTools.PatAlgos.selectionLayer1.muonSelector_cfi import *
from PhysicsTools.HplusCode_v5.myMuonDzSelector_cfi import *
tightMuons = myPatMuons.clone(
src = 'selectedPatMuonsPFlow',

cut = 'isGlobalMuon & isPFMuon & '
      'globalTrack.normalizedChi2 < 10.0 &'      
      'globalTrack.hitPattern.numberOfValidMuonHits > 0 &'
      'innerTrack.hitPattern.numberOfValidPixelHits > 0 &' 
      'numberOfMatchedStations > 1 &'
      'pt > 25. &'
      'abs(eta) < 2.1  &'      
      'abs(dB) < 0.2 &'
      'innerTrack.hitPattern.trackerLayersWithMeasurement > 5 & '      
      #'(pfIsolationR04.sumChargedHadronPt + max(0., pfIsolationR04.sumNeutralHadronEt + pfIsolationR04.sumPhotonEt - 0.5 * pfIsolationR04.sumPUPt) ) / pt < 0.12',
      #for QCD data drive estimation 
      '(pfIsolationR04.sumChargedHadronPt + max(0., pfIsolationR04.sumNeutralHadronEt + pfIsolationR04.sumPhotonEt - 0.5 * pfIsolationR04.sumPUPt) ) / pt < 0.30',
dzCut = cms.double(0.5)
      
)
vetoMuons = selectedPatMuons.clone(
src = 'selectedPatMuonsPFlow',
cut =
'(isGlobalMuon || isTrackerMuon || isPFMuon) &'
'(pfIsolationR04.sumChargedHadronPt + max(0., pfIsolationR04.sumNeutralHadronEt + pfIsolationR04.sumPhotonEt - 0.5 * pfIsolationR04.sumPUPt) ) / pt < 0.3'
)
##
## ELECTRONS SELECTIONS
##
from PhysicsTools.PatAlgos.selectionLayer1.electronSelector_cfi import *
vetoElecs = selectedPatElectrons.clone(
src = 'selectedPatElectronsPFlow',
cut =
'abs(gsfTrack.dxy) < 0.04 &'
'abs(gsfTrack.dz) < 0.2 &'
'(chargedHadronIso + max(0., neutralHadronIso + photonIso - 0.5 * puChargedHadronIso) ) / pt < 0.2 &' # iso04
'(isEB & '
        'abs(sigmaIetaIeta) < 0.01 &'
        'abs(deltaEtaSuperClusterTrackAtVtx) < 0.007 &'
        'abs(deltaPhiSuperClusterTrackAtVtx) < 0.8 '
                                        ') '
' ||'
' (isEE &'
        'abs(sigmaIetaIeta) < 0.03 & '
        'abs(deltaEtaSuperClusterTrackAtVtx) < 0.01 &'
        'abs(deltaPhiSuperClusterTrackAtVtx) < 0.7 '
	                                ') '
)


###
## JETS SELECTIONS
##
from PhysicsTools.PatAlgos.selectionLayer1.jetSelector_cfi import *
goodJets = selectedPatJets.clone(
src = 'goodPatJetsPFlow',
cut =  
'pt > 25 & abs(eta)<2.4'
)
ttJets = selectedPatJets.clone(
src = 'goodPatJetsPFlow',
cut =  
'pt > 20 & abs(eta)<2.4'
)
kinfitJets = selectedPatJets.clone(
src = 'goodPatJetsPFlow',
cut =  
'pt > 24 & abs(eta)<2.4'
)
loosebJets = selectedPatJets.clone(
src = 'goodPatJetsPFlow',
cut =
'pt > 25 & abs(eta)<2.4 & '
'bDiscriminator("combinedSecondaryVertexBJetTags") > 0.244 '
)

bJets = selectedPatJets.clone(
src = 'goodPatJetsPFlow',
cut =
'pt > 25 & abs(eta)<2.4 & '
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
ttJets *
kinfitJets *
loosebJets *
bJets *
vetoElecs *
vetoMuons *
tightMuons
)
