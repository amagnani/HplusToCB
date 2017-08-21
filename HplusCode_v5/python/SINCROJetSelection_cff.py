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
'pt > 10 & abs(eta)<=2.5',
#'pt > 10 & abs(eta)<=5.2',
muonsSrc ='tightMuons',
isJERup    = isjerup,
isJERdown  = isjerdown,
isJESup    = isjesup,
isJESdown  = isjesdown,
removeOverlap= False,
isData=True 
)

bJets = topJetsPF.clone(
src = 'goodPatJetsPFlow',
cut =  
'pt > 10  & abs(eta)<=2.5 & '
#'pt > 10  & abs(eta)<=5.2 & '
'bDiscriminator("combinedSecondaryVertexBJetTags") > 0.679 ',
muonsSrc ='tightMuons',
isJERup    = isjerup,
isJERdown  = isjerdown,
isJESup    = isjesup,
isJESdown  = isjesdown,
removeOverlap= False,
isData=True
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
isJESdown  = isjesdown
)

topSINCROJetSelection = cms.Sequence(
goodJets *
bJets *
goodMETs 
)
