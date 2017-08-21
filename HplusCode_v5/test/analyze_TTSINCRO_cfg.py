import FWCore.ParameterSet.Config as cms
process = cms.Process("Prova")

#sample = cms.string("Bkg ")
#sample  =  cms.string("Data")
#sample = cms.string("MCsignal")
sample = cms.string("MCttbar")
flag8b = cms.string("8b")
flag9 = cms.string("9")
flag9b = cms.string("9b")
flag1 = cms.string("1")


#process.MessageLogger.categories.append('TtSemiLeptonicEvent')
#process.MessageLogger.categories.append('TtSemiLepKinFitter')

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1))
#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100))

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
   	#'file:/tmp/amagnani/TTJets.root'
	#'file:/afs/cern.ch/work/a/amagnani/private/ANALYSIS_CODE/CMSSW_5_3_23/src/TopQuarkAnalysis/TopPairBSM/test_private_sample/Step4.root'  
	#'file:/afs/cern.ch/work/a/amagnani/private/HplusDelta/CMSSW_5_3_8_patch1/src/TopQuarkAnalysis/TopPairBSM/test3/Step4.root'     #VECCHIO
	'file:culoA.root', #eventi dati per yeon
	'file:culoA2.root', #eventi dati per yeon
	'file:culoA3.root' #eventi dati per yeon
	#'file:SINCROrigthcutsv22.root'
 	#'file:/afs/cern.ch/work/a/amagnani/private/ANALYSIS_CODE/WORKDIR/CMSSW_5_3_23/src/TopQuarkAnalysis/TopPairBSM/test_background/sincroetacut.root'
 	#'file:/afs/cern.ch/work/a/amagnani/private/ANALYSIS_CODE/WORKDIR/CMSSW_5_3_23/src/TopQuarkAnalysis/TopPairBSM/test_background/Step4sincro52.root'
 	#'file:/afs/cern.ch/work/a/amagnani/private/ANALYSIS_CODE/WORKDIR/CMSSW_5_3_23/src/TopQuarkAnalysis/TopPairBSM/test_background/Step4sincro52_v27.root'
       #'file:/afs/cern.ch/work/a/amagnani/private/ANALYSIS_CODE/TOP/CMSSW_5_3_23/src/TopQuarkAnalysis/TopPairBSM/test_data_reduced/Step4.root'
    )
)

## Define the TFileService
process.TFileService = cms.Service("TFileService",
fileName = cms.string('analyzeSINCROSelection.root')
)

# ----------------------------------------------------------------
## Apply object selection according to TopPAG reference selection
## for ICHEP 2010. This will result in 5 additional collections:
##
## * goodJets
## * vetoElecs
## * vetoMuons
## * looseMuons
## * tightMuons
##
## Have a look ont the cff file to learn more about the exact
## selection citeria.
## ----------------------------------------------------------------
process.load("PhysicsTools.HplusCode_v5.topSINCROLeptonSelection_cff")
process.topSINCROLeptonProduction = cms.Path(
    process.topSINCROLeptonSelection
)

process.load("PhysicsTools.HplusCode_v5.SINCROJetSelection_cff")
process.topSINCROJetProduction = cms.Path(
    process.topSINCROJetSelection
)

## ----------------------------------------------------------------
## Define the steps for the TopPAG reference selection for ICHEP
## 2010. Have a look at the WorkBookHplusCode_v4TopQuarks. These
## are event selections. They make use of the object selections
## applied in the step above.
## ----------------------------------------------------------------
## Trigger bit (HLT_IsoMu24_eta2p1)
from HLTrigger.HLTfilters.hltHighLevel_cfi import *
#from PhysicsTools.PatAlgos.selectionLayer1.muonSelector_cfi import *
if(not globals().has_key("triggerProcessName")):
       triggerProcessName= "HLT"
if(not globals().has_key("triggerPathSelector")):
       triggerPathSelector= "HLT_IsoMu24_eta2p1_v*"
triggerResultsTagString="TriggerResults::"+triggerProcessName


## Vertex requirement
## At least one tight muon
from PhysicsTools.PatAlgos.selectionLayer1.muonCountFilter_cfi import *
process.step0 = countPatMuons.clone(src = 'tightMuons', minNumber = 1)
## Veto on additional muons 
process.step1  = countPatMuons.clone(src = 'tightMuons', maxNumber = 1)
process.step2  = countPatMuons.clone(src = 'vetoMuons' , maxNumber = 1)
## Veto on additional electrons
from PhysicsTools.PatAlgos.selectionLayer1.electronCountFilter_cfi import *
process.step3  = countPatMuons.clone(src = 'vetoElecs' , maxNumber = 0)
## Different jet multiplicity selections

####prima del taglio sui jet ci vuole il fit cinematico
from PhysicsTools.PatAlgos.selectionLayer1.jetCountFilter_cfi import *
#process.step4  = countPatJets.clone(src = 'goodJets'   , minNumber = 4)
#process.step4b = countPatJets.clone(src = 'goodJets'   , minNumber = 2)
#process.step4c = countPatJets.clone(src = 'goodJets'   , minNumber = 3)
#process.step5  = countPatJets.clone(src = 'goodJets'   , minNumber = 4)
#MET cut
from PhysicsTools.PatAlgos.selectionLayer1.metCountFilter_cfi import *
#bJET cut
#process.step6  = countPatMET.clone(src = 'bJets'   , minNumber = 1)
#process.step7  = countPatJets.clone(src = 'bJets'   , minNumber = 2)
#process.step8  = countPatJets.clone(src = 'bJets'   , minNumber = 3)

from PhysicsTools.HplusCode_v5.SINCROAnalyzer_cfi import *
process.analyzeStep0	= analyzeHplus_ttSignal.clone(sampleFlag=sample, stepFlag=flag1)

## ----------------------------------------------------------------
## Define monitoring modules for the event selection. You should
## few this only as an example for an analyses technique including
## full CMSSW features, not as a complete analysis.
## ----------------------------------------------------------------


## ----------------------------------------------------------------
## Define the analysis paths: we define two selection paths to 
## monitor the cutflow according to the TopPAG reference selection
## for ICHEP 2010. All necessary object collections have been pro-
## duced in the cms.Path topObjectProduction before hand. The out-
## put report is switched on to get a quick overview of the number
## number of events after each selection step. 
## ----------------------------------------------------------------

## Switch output report on
process.options   = cms.untracked.PSet(  wantSummary = cms.untracked.bool(True) , SkipEvent = cms.untracked.vstring('ProductNotFound') )
#process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(False) , SkipEvent = cms.untracked.vstring('ProductNotFound') )

    # reduce verbosity
from FWCore.ParameterSet.VarParsing import VarParsing
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32(500000)
  

## Define  event selection path
process.EventSelection = cms.Path(
     process.step0	*
   
     process.step1      *
 
     process.step2      *
 
     process.step3  *    
     process.analyzeStep0 
     

    )
