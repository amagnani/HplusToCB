from WMCore.Configuration import Configuration
config = Configuration()

config.section_("General")
config.General.requestName = 'Run2012C-22Jan2013-v1_HplusToCBar_Step4_June16-t3'
config.General.workArea = 'crab_project'

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'ttbsm_slim_def_cfg.py'

config.section_("Data")
config.Data.inputDataset = '/SingleMu/Run2012C-22Jan2013-v1/AOD'
config.Data.inputDBS = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader'
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = 30
config.Data.lumiMask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions12/8TeV/Reprocessing/Cert_190456-208686_8TeV_22Jan2013ReReco_Collisions12_JSON.txt'
config.Data.runRange = '200244-203742' 
config.Data.publication = True
config.Data.publishDBS = 'https://cmsweb.cern.ch/dbs/prod/phys03/DBSWriter'
config.Data.outputDatasetTag = 'Run2012C-22Jan2013-v1_HplusToCBar_Step4_June16'

config.section_("Site")
config.Site.storageSite = 'T2_IT_Pisa'
config.Site.blacklist = ['T3_US_UMiss']
