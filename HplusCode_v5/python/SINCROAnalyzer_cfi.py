import FWCore.ParameterSet.Config as cms

analyzeHplus_ttSignal = cms.EDAnalyzer("SINCROAnalyzer_ttSignal",
sampleFlag=cms.string("MCsignal"),
stepFlag=cms.string("0")


)
