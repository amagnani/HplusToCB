import FWCore.ParameterSet.Config as cms

topJetsPF = cms.EDProducer(
    "SingleTopJetsProducer",
    muonsSrc = cms.InputTag("selectedPatMuons"),
    src = cms.InputTag("selectedPatJets"),
    cut = cms.string('pt >  20 & abs(eta) < 5.'),
    #puFullDiscriminant = cms.InputTag("puJetMva","fullDiscriminant"),
    #puFullID  = cms.InputTag("puJetMva","fullId"),
    #puChargedDiscriminant = cms.InputTag("puJetMvaChs","fullDiscriminant"),
    #puChargedID  = cms.InputTag("puJetMvaChs","fullId"),
    #puIDVariables  = cms.InputTag("puJetId"),
    removeOverlap = cms.untracked.bool(False),
    isData = cms.untracked.bool(False),
    isJERup = cms.untracked.bool(False),
    isJERdown = cms.untracked.bool(False),
    isJESup = cms.untracked.bool(False),
    isJESdown = cms.untracked.bool(False),
    JESUncertaintiesPath = cms.FileInPath("PhysicsTools/HplusCode_v5/data/Summer13_V5_DATA_UncertaintySources_AK5PFchs.txt")
)
