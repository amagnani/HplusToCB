from WMCore.Configuration import Configuration
config = Configuration()

config.section_("General")
config.General.requestName = 'TT_matchup_HplusToCBar_Step4'
config.General.workArea = 'crab_project'

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'ttbsm_slim_def_cfg.py'
#config.JobType.maxJobRuntimeMin = 3000

config.section_("Data")
config.Data.inputDataset = '/TTJets_MSDecays_matchingup_TuneZ2star_8TeV-madgraph-tauola/Summer12_DR53X-PU_S10_START53_V19-v2/AODSIM'
config.Data.inputDBS = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
config.Data.publication = True
config.Data.publishDBS = 'https://cmsweb.cern.ch/dbs/prod/phys03/DBSWriter'
config.Data.outputDatasetTag = 'TT_matchup_HplusToCBar_Step4'

config.section_("Site")
config.Site.storageSite = 'T2_IT_Bari'
