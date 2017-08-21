import FWCore.ParameterSet.Config as cms

analyzeHplus_ttSignal = cms.EDAnalyzer("HplusAnalyzer_ttSignal",
sampleFlag=cms.string("MCsignal"),
stepFlag=cms.string("0")


)
analyzeHplus_dataBkg = cms.EDAnalyzer("HplusAnalyzer_dataBkg",
sampleFlag=cms.string("MCsignal"),
stepFlag=cms.string("0")


)
