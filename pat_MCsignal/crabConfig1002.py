from WMCore.Configuration import Configuration
config = Configuration()

config.section_("General")
config.General.requestName = 'TTToHplusBWB_CBbar_M-100_Step43'
config.General.workArea = 'crab_project'

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'ttbsm_slim_def_cfg.py'

config.section_("Data")
config.Data.inputDataset = '/TTToHplusBWB_CBbar_M-100_8TeV-pythia6-tauola/Summer12_DR53X-PU_S10_START53_V19-v2/AODSIM'
config.Data.inputDBS = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
config.Data.publication = True
config.Data.ignoreLocality = True
config.Data.publishDBS = 'https://cmsweb.cern.ch/dbs/prod/phys03/DBSWriter'
config.Data.outputDatasetTag = 'TTToHplusBWB_CBbar_M-100_Step43'

config.section_("Site")
config.Site.storageSite = 'T2_IT_Pisa'
