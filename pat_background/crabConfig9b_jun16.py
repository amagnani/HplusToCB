from WMCore.Configuration import Configuration
config = Configuration()

config.section_("General")
config.General.requestName = 'TTZJets_HplusToCBar_Step42'
config.General.workArea = 'crab_project'

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'ttbsm_slim_def_cfg.py'

config.section_("Data")
config.Data.inputDataset = '/TTZJets_8TeV-madgraph_v2/Summer12_DR53X-PU_S10_START53_V7A-v1/AODSIM'
config.Data.inputDBS = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 2
config.Data.publication = True
config.Data.publishDBS = 'https://cmsweb.cern.ch/dbs/prod/phys03/DBSWriter'
config.Data.outputDatasetTag = 'TTZJets_HplusToCBar_Step42'

config.section_("Site")
config.Site.storageSite = 'T2_IT_Pisa'
config.Site.blacklist =   ['T2_ES_IFCA']
