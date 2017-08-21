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
	'file:Step4_ttnew.root'
	#'file:Step4.root'
        #'file:/afs/cern.ch/work/a/amagnani/private/ANALYSIS_CODE/TOP/CMSSW_5_3_23/src/TopQuarkAnalysis/TopPairBSM/test_data_reduced/Step4.root'
    )
)

## Define the TFileService
process.TFileService = cms.Service("TFileService",
fileName = cms.string('analyzePatTopSelection.root')
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

#process.load("PhysicsTools.HplusCode_v5.topObjectSelection_cff")
#process.topObjectProduction = cms.Path(
#    process.topObjectSelection
#)

process.load("PhysicsTools.HplusCode_v5.topLeptonSelection_cff")
process.topLeptonProduction = cms.Path(
    process.topLeptonSelection
)
process.load("PhysicsTools.HplusCode_v5.topJetSelection_cff")
process.topJetProduction = cms.Path(
    process.topJetSelection
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
process.step0  = hltHighLevel.clone(TriggerResultsTag = triggerResultsTagString, HLTPaths = [triggerPathSelector],throw=True)


## Vertex requirement
process.step1  = cms.EDFilter("VertexSelector", src = cms.InputTag("goodOfflinePrimaryVertices"), cut = cms.string("!isFake && ndof > 4 && abs(z) < 24 && position.Rho < 2"), filter = cms.bool(True)) 
## At least one tight muon
from PhysicsTools.PatAlgos.selectionLayer1.muonCountFilter_cfi import *
process.step2 = countPatMuons.clone(src = 'tightMuons', minNumber = 1)
## Veto on additional muons 
process.step3a  = countPatMuons.clone(src = 'tightMuons', maxNumber = 1)
process.step3b  = countPatMuons.clone(src = 'vetoMuons' , maxNumber = 1)
## Veto on additional electrons
from PhysicsTools.PatAlgos.selectionLayer1.electronCountFilter_cfi import *
process.step4  = countPatMuons.clone(src = 'vetoElecs' , maxNumber = 0)
## Different jet multiplicity selections

####prima del taglio sui jet ci vuole il fit cinematico
from PhysicsTools.PatAlgos.selectionLayer1.jetCountFilter_cfi import *
process.step5a = countPatJets.clone(src = 'goodJets'   , minNumber = 1)
process.step5b = countPatJets.clone(src = 'goodJets'   , minNumber = 2)
process.step5c = countPatJets.clone(src = 'goodJets'   , minNumber = 3)
process.step6  = countPatJets.clone(src = 'goodJets'   , minNumber = 4)
#MET cut
from PhysicsTools.PatAlgos.selectionLayer1.metCountFilter_cfi import *
process.step7 = countPatMET.clone(src = 'goodMETs'   , minNumber = 1)
#bJET cut
process.step8a = countPatMET.clone(src = 'bJets'   , minNumber = 1)
process.step8b = countPatMET.clone(src = 'bJets'   , minNumber = 2)
process.step9  = countPatMET.clone(src = 'loosebJets', minNumber = 3)
process.step9b  = countPatMET.clone(src ='bJets'   , minNumber = 3)

## ----------------------------------------------------------------
## Define monitoring modules for the event selection. You should
## few this only as an example for an analyses technique including
## full CMSSW features, not as a complete analysis.
## ----------------------------------------------------------------

#fit cinematico
#from Configuration.AlCa.autoCond import autoCond
#process.GlobalTag.globaltag = autoCond['mc']
## sequences for ttGenEvent and TtSemiLeptonicEvent
process.load("TopQuarkAnalysis.TopEventProducers.sequences.ttGenEvent_cff")
process.load("TopQuarkAnalysis.TopEventProducers.sequences.ttSemiLepEvtBuilder_cff")
## enable additional per-event printout from the TtSemiLeptonicEvent
process.ttSemiLepEvent.verbosity = 13

## choose which hypotheses to produce
from TopQuarkAnalysis.TopEventProducers.sequences.ttSemiLepEvtBuilder_cff import *
addTtSemiLepHypotheses(process, ["kKinFit"])

## change some common parameters
setForAllTtSemiLepHypotheses(process, "maxNJets", -1)
#setForAllTtSemiLepHypotheses(process, "neutrinoSolutionType", 2)
## use b-tagging for hypotheses (neglected for GenMatch)
setForAllTtSemiLepHypotheses(process, "useBTagging", False)
setForAllTtSemiLepHypotheses(process, "minBDiscBJets"    , 0.679)
setForAllTtSemiLepHypotheses(process, "maxBDiscLightJets", 0.679)

#aggiuta mia
setForAllTtSemiLepHypotheses(process, "jets", "kinfitJets")
setForAllTtSemiLepHypotheses(process, "leps", "tightMuons")
setForAllTtSemiLepHypotheses(process, "muons", "tightMuons")
setForAllTtSemiLepHypotheses(process, "mets", "goodMETs")
setForAllTtSemiLepHypotheses(process, "mTop", 172.5)
setForAllTtSemiLepHypotheses(process, "mTopBar", 172.5)
removeTtSemiLepHypGenMatch(process)

## change jet-parton matching algorithm
#process.ttSemiLepJetPartonMatch.algorithm = "unambiguousOnly"
## change constraints used in kinematic fit
#1: Whad-mass, 2: Wlep-mass, 3: thad-mass, 4: tlep-mass, 5: nu-mass, 6: equal t-masses
process.kinFitTtSemiLepEventHypothesis.constraints = [2,3,4]
process.kinFitTtSemiLepEventHypothesis.bTagAlgo ="combinedSecondaryVertexBJetTags"
process.kinFitTtSemiLepEventHypothesis.maxNComb =100
## use object resolutions from a specific config file
from TopQuarkAnalysis.TopObjectResolutions.stringResolutions_etEtaPhi_Fall11_cff import *
process.kinFitTtSemiLepEventHypothesis.udscResolutions = udscResolutionPF.functions
process.kinFitTtSemiLepEventHypothesis.bResolutions    = bjetResolutionPF.functions
process.kinFitTtSemiLepEventHypothesis.lepResolutions  = muonResolution  .functions
process.kinFitTtSemiLepEventHypothesis.metResolutions  = metResolutionPF .functions
process.kinFitTtSemiLepEventHypothesis.metResolutions[0].eta  = "9999"
#--------------------------------------------------------------------------

from PhysicsTools.HplusCode_v5.HplusAnalyzer_cfi import *
process.analyzeStart	= analyzeHplus_ttSignal.clone(sampleFlag=sample, stepFlag=flag1)
process.analyzeStep0	= analyzeHplus_ttSignal.clone(sampleFlag=sample, stepFlag=flag1)
process.analyzeStep1	= analyzeHplus_ttSignal.clone(sampleFlag=sample, stepFlag=flag1)
process.analyzeStep2	= analyzeHplus_ttSignal.clone(sampleFlag=sample, stepFlag=flag1)
process.analyzeStep3a   = analyzeHplus_ttSignal.clone(sampleFlag=sample, stepFlag=flag1)
process.analyzeStep3b   = analyzeHplus_ttSignal.clone(sampleFlag=sample, stepFlag=flag1)
process.analyzeStep4	= analyzeHplus_ttSignal.clone(sampleFlag=sample, stepFlag=flag1)
process.analyzeStep5a   = analyzeHplus_ttSignal.clone(sampleFlag=sample, stepFlag=flag1)
process.analyzeStep5b   = analyzeHplus_ttSignal.clone(sampleFlag=sample, stepFlag=flag1)
process.analyzeStep5c   = analyzeHplus_ttSignal.clone(sampleFlag=sample, stepFlag=flag1)
process.analyzeStep6	= analyzeHplus_ttSignal.clone(sampleFlag=sample, stepFlag=flag1)
process.analyzeStep7	= analyzeHplus_ttSignal.clone(sampleFlag=sample, stepFlag=flag1)
process.analyzeStep8a   = analyzeHplus_ttSignal.clone(sampleFlag=sample, stepFlag=flag1)
process.analyzeStep8b   = analyzeHplus_ttSignal.clone(sampleFlag=sample, stepFlag=flag8b)
process.analyzeStep9	= analyzeHplus_ttSignal.clone(sampleFlag=sample, stepFlag=flag9)
process.analyzeStep9b   = analyzeHplus_ttSignal.clone(sampleFlag=sample, stepFlag=flag9b)

process.makeTtSemiLepEventStep8b = process.makeTtSemiLepEvent
process.makeTtSemiLepEventStep9  = process.makeTtSemiLepEvent
process.makeTtSemiLepEventStep9b = process.makeTtSemiLepEvent

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
#process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(False) )

    # reduce verbosity
from FWCore.ParameterSet.VarParsing import VarParsing
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32(500000)
#process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32(1000)
  

## Define  event selection path
process.EventSelection = cms.Path(
     process.analyzeStart	*
     process.step0	        *
     process.analyzeStep0	*
   
     process.step1      *
 
     process.step2      *
 
     process.step3a     *
 
     process.step3b     *
 
     process.step4      *
     #process.analyzeStep4   *

     process.step5a     *
  
     process.step5b     *
 
     process.step5c     *
     
     process.step6      *
     #process.analyzeStep6   *
 
     process.step8a     *
     #process.analyzeStep8a   *

     process.step8b     *
     #process.makeTtSemiLepEventStep8b   *
     #process.analyzeStep8b  * 

     process.step9      * 
     #process.makeTtSemiLepEventStep9   *
     #process.analyzeStep9  * 
 
     process.step9b      * 
     process.makeTtSemiLepEventStep9b   *
     process.analyzeStep9b   
    )
