import FWCore.ParameterSet.Config as cms

SINCROPatJets = cms.EDProducer(
    "SINCROJetsProducer",
    muonsSrc = cms.InputTag("selectedPatMuonsPFlow"),
    src = cms.InputTag("selectedPatJetsPFlow"),
    cut = cms.string(' '),
    #puFullDiscriminant = cms.InputTag("puJetMva","fullDiscriminant"),
    #puFullID  = cms.InputTag("puJetMva","fullId"),
    #puChargedDiscriminant = cms.InputTag("puJetMvaChs","fullDiscriminant"),
    #puChargedID  = cms.InputTag("puJetMvaChs","fullId"),
    #puIDVariables  = cms.InputTag("puJetId"),
    removeOverlap = cms.untracked.bool(False),
    isData = cms.untracked.bool(False),
    JESUncertaintiesPath = cms.FileInPath("PhysicsTools/HplusCode_v5/data/Summer13_V5_DATA_UncertaintySources_AK5PFchs.txt")
)
