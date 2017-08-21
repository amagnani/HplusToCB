import FWCore.ParameterSet.Config as cms

topMETsPF = cms.EDProducer("SingleTopMETsProducer",
                         metsSrc = cms.InputTag("patType1CorrectedPFMet"),
                         jetsSrc = cms.InputTag("selectedPatJets"),
                         isData = cms.untracked.bool(False),
                         isJERup = cms.untracked.bool(False),
                         isJERdown = cms.untracked.bool(False),
                         isJESup = cms.untracked.bool(False),
                         isJESdown = cms.untracked.bool(False),
                         JESUncertaintiesPath = cms.FileInPath("PhysicsTools/HplusCode_v5/data/Summer13_V5_DATA_UncertaintySources_AK5PFchs.txt")
                         )
