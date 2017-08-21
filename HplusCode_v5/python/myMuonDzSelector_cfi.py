import FWCore.ParameterSet.Config as cms

myPatMuons = cms.EDFilter("MyMuonDzSelector",
    src = cms.InputTag("patMuons"),
    cut = cms.string(""),
    dzCut = cms.untracked.double(100)
)
