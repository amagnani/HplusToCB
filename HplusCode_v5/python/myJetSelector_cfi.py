import FWCore.ParameterSet.Config as cms

myPatJets = cms.EDFilter("MyPatJetSelector",
    src = cms.InputTag("patJets"),
    cut = cms.string("")
)
myPatNestedJets = cms.EDFilter("MyPatJetNestedSelector",
    src = cms.InputTag("patJets"),
    cut1 = cms.string(""),
    cut2 = cms.string("")
)
