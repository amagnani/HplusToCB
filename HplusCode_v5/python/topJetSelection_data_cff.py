import FWCore.ParameterSet.Config as cms
from PhysicsTools.HplusCode_v5.variables_cfg import isjerup, isjerdown, isjesup, isjesdown

print( 'isJERup ' ,  isjerup)
print( 'isJERdown ', isjerdown)
print( 'isJESup ',   isjesup)
print( 'isJESdown ', isjesdown)
###
## JETS SELECTIONS
##
from PhysicsTools.HplusCode_v5.userDataJetsProducer_cfi import *
goodJets = topJetsPF.clone(
src = 'goodPatJetsPFlow',
cut =  
'pt > 25 & abs(eta)<2.4',
muonsSrc ='tightMuons',
isJERup    = isjerup,
isJERdown  = isjerdown,
isJESup    = isjesup,
isJESdown  = isjesdown,
isData       = True,
removeOverlap= False
 )
kinfitJets = topJetsPF.clone(
src = 'goodPatJetsPFlow',
cut =  
'pt > 24 & abs(eta)<2.4',
muonsSrc ='tightMuons',
isJERup    = isjerup,
isJERdown  = isjerdown,
isJESup    = isjesup,
isJESdown  = isjesdown,
isData       = True,
removeOverlap= False
 )
loosebJets = topJetsPF.clone(
src = 'goodPatJetsPFlow',
cut =  
'pt > 25 & abs(eta)<2.4 &'
'bDiscriminator("combinedSecondaryVertexBJetTags") > 0.244 ',
muonsSrc ='tightMuons',
isJERup    = isjerup,
isJERdown  = isjerdown,
isJESup    = isjesup,
isJESdown  = isjesdown,
isData       = True,
removeOverlap= False
)

bJets = topJetsPF.clone(
src = 'goodPatJetsPFlow',
cut =  
'pt > 25 & abs(eta)<2.4 & '
'bDiscriminator("combinedSecondaryVertexBJetTags") > 0.679 ',
muonsSrc ='tightMuons',
isJERup    = isjerup,
isJERdown  = isjerdown,
isJESup    = isjesup,
isJESdown  = isjesdown,
isData       = True,
removeOverlap= False
)

##
## MET SELECTIONS
##
from PhysicsTools.HplusCode_v5.userDataMETsProducer_cfi import *
goodMETs = topMETsPF.clone(
metsSrc ='patMETsPFlow',
jetsSrc ='goodPatJetsPFlow',
isJERup    = isjerup,
isJERdown  = isjerdown,
isJESup    = isjesup,
isJESdown  = isjesdown,
isData     = True
)

topJetSelection = cms.Sequence(
goodJets *
kinfitJets *
loosebJets *
bJets *
goodMETs 
)
