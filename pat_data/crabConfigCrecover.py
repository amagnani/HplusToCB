from WMCore.Configuration import Configuration
config = Configuration()

config.section_("General")
config.General.requestName = 'Run2012C-22Jan2013-v1_HplusToCBar_Step4_June16-reco'
config.General.workArea = 'crab_project'

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'ttbsm_slim_def_cfg.py'

config.section_("Data")
config.Data.inputDataset = '/SingleMu/Run2012C-22Jan2013-v1/AOD'
config.Data.inputDBS = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader'
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = 10
config.Data.lumiMask = 'my_lumi_mask_differenceC.json'
config.Data.publication = True
config.Data.publishDBS = 'https://cmsweb.cern.ch/dbs/prod/phys03/DBSWriter'
config.Data.outputDatasetTag = 'Run2012C-22Jan2013-v1_HplusToCBar_Step4_June16reco'

config.section_("Site")
config.Site.storageSite = 'T2_IT_Pisa'
config.Site.blacklist = ['T3_US_UMiss']
