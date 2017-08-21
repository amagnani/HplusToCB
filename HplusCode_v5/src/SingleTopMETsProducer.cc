/*
 *\Author: A. Orso M. Iorio 
 *
 *
 *\version  $Id: SingleTopMETsProducer.cc,v 1.1.2.2 2013/06/21 20:40:25 oiorio Exp $ 
 */

// Single Top producer: produces a top candidate made out of a Lepton, a B jet and a MET

#include "PhysicsTools/PatAlgos/plugins/PATJetProducer.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ParameterSet/interface/FileInPath.h"

#include "DataFormats/Common/interface/ValueMap.h"
#include "DataFormats/Common/interface/Association.h"
#include "DataFormats/Candidate/interface/CandAssociation.h"

#include "DataFormats/JetReco/interface/JetTracksAssociation.h"
#include "DataFormats/BTauReco/interface/JetTag.h"
#include "DataFormats/BTauReco/interface/TrackProbabilityTagInfo.h"
#include "DataFormats/BTauReco/interface/TrackIPTagInfo.h"
#include "DataFormats/BTauReco/interface/TrackCountingTagInfo.h"
#include "DataFormats/BTauReco/interface/SecondaryVertexTagInfo.h"
#include "DataFormats/BTauReco/interface/SoftLeptonTagInfo.h"

#include "DataFormats/Candidate/interface/CandMatchMap.h"
#include "SimDataFormats/JetMatching/interface/JetFlavourMatching.h"

#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/JetReco/interface/JPTJet.h"
#include "DataFormats/JetReco/interface/CaloJet.h"

#include "DataFormats/PatCandidates/interface/JetCorrFactors.h"

#include "FWCore/ParameterSet/interface/ConfigurationDescriptions.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescription.h"
//#include "CMGTools/External/interface/PileupJetIdentifier.h"

//#include "CMGTools/External/interface/PileupJetIdentifier.h"

#include "FWCore/Framework/interface/Selector.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"
#include "PhysicsTools/HplusCode_v5/interface/SingleTopMETsProducer.h"

#include <vector>
#include <memory>

#include "DataFormats/Math/interface/LorentzVector.h"


//using namespace pat;


SingleTopMETsProducer::SingleTopMETsProducer(const edm::ParameterSet& iConfig) 
{
  metsSrc_                 = iConfig.getParameter<edm::InputTag>	( "metsSrc" );
  //metsUnclUpSrc_           = iConfig.getParameter<edm::InputTag>	( "metsUnclUpSrc" );
  //metsUnclDownSrc_         = iConfig.getParameter<edm::InputTag>	( "metsUnclDownSrc" );
  
  isData_                  = iConfig.getUntrackedParameter< bool >	( "isData" ,false);
  isJERup_                  = iConfig.getUntrackedParameter< bool >	( "isJERup" ,false);
  isJERdown_                  = iConfig.getUntrackedParameter< bool >	( "isJERdown" ,false);
  isJESup_                  = iConfig.getUntrackedParameter< bool >	( "isJESup" ,false);
  isJESdown_                  = iConfig.getUntrackedParameter< bool >	( "isJESdown" ,false);
  
  JESUncertaintiesPath_ = iConfig.getParameter< edm::FileInPath >("JESUncertaintiesPath");
  
  jetsSrc_ = iConfig.getParameter<edm::InputTag>("jetsSrc");
  
  produces<std::vector<pat::MET> >();

  jecUnc  = new JetCorrectionUncertainty(*(new JetCorrectorParameters(JESUncertaintiesPath_.fullPath().data(), "Total")));
  

}

void SingleTopMETsProducer::produce(edm::Event & iEvent, const edm::EventSetup & iEventSetup){
  
  
  iEvent.getByLabel(metsSrc_,mets);
  iEvent.getByLabel(jetsSrc_,jets);
   
  std::auto_ptr< std::vector< pat::MET > > initialMETs(new std::vector< pat::MET >(*mets));
  std::auto_ptr< std::vector< pat::Jet > > initialJets(new std::vector< pat::Jet >(*jets));
  std::auto_ptr< std::vector< pat::MET > > finalMETs(new std::vector< pat::MET >);
  

  if(mets->size()!=1)std::cout<<" not exactly 1 met: possible problem in configuration, metx mety not reliable!!!"<<std::endl; 

  
  for(size_t i = 0; i < mets->size(); ++i){
    pat::MET & met = (*initialMETs)[i];
 
     double metx= met.px(), mety= met.py();
     double jer_metx = metx,jer_mety= mety;
 
     double jes_up_metx = metx,jes_up_mety= mety;
     double jes_down_metx = metx,jes_down_mety= mety;
     
     
     if(!isData_){
       
      
       for(size_t j = 0; j < jets->size(); ++j){
       pat::Jet & jet = (*initialJets)[j];
       
       float ptCorr = jet.pt(), genpt=-1;
       if(ptCorr<10)continue;
 
       if(jet.genJet()==0) {
       genpt = ptCorr;
       }
       else genpt = jet.genJet()->pt();
       
  
       float resolScale = resolSF(fabs(jet.eta()),"");
       if (isJERup_)   resolScale = resolSF(fabs(jet.eta()),"up");
       if (isJERdown_) resolScale = resolSF(fabs(jet.eta()),"down");
	
       float smear = 1-std::max((float)(0.0), (float)(ptCorr + (ptCorr - genpt) * resolScale) / ptCorr);
       
      
       jer_metx += (smear*jet.p4()).px();
       jer_mety += (smear*jet.p4()).py();
       
       
       ptCorr = (jet.p4()*(1-smear)).pt();
       float eta = (jet.p4()*(1-smear)).eta();
       float jphi = (jet.p4()*(1-smear)).phi();
       
       jecUnc->setJetPt(ptCorr);
       jecUnc->setJetEta(eta);
       
       float unc = jecUnc->getUncertainty(true);
       
       jes_up_metx -= (ptCorr * cos(jphi)) * unc; 
       jes_down_metx -= -(ptCorr * cos(jphi)) * unc; 
       
     }
     
 
     } //end if data
 
     reco::Candidate::LorentzVector originalP4(met.p4());
     reco::Candidate::LorentzVector jerP4(jer_metx,jer_mety,met.p4().pz(),sqrt(jer_metx*jer_metx+jer_mety*jer_mety));
     
     reco::Candidate::LorentzVector jesUpP4  (jes_up_metx,jes_up_mety,met.p4().pz(),sqrt(jes_up_metx*jes_up_metx+jes_up_mety*jes_up_mety));
     reco::Candidate::LorentzVector jesDownP4(jes_down_metx,jes_down_mety,met.p4().pz(),sqrt(jes_down_metx*jes_down_metx+jes_down_mety*jes_down_mety));
     
 
  
     
     //std::cout << " met pt " << met.pt() << " met phi " << met.phi()<< " met  eta " << met.eta()<< " met e "<< met.energy() <<std::endl; 
     met.addUserFloat("pt_no_jer",met.pt());
     met.addUserFloat("phi_no_jer",met.phi());
     
     
     met.setP4(jerP4);
     if (isJESup_)  met.setP4(jesUpP4);
     if (isJESdown_)met.setP4(jesDownP4);
 
    //    std::cout<< " met "  << met.pt()<<std::endl;
    finalMETs->push_back(met);
  } 
  
  iEvent.put(finalMETs);
  
}

double SingleTopMETsProducer::resolSF(double eta, std::string syst)
{
    double fac = 0.;
    if (syst == "up")fac = 1.;
    if (syst == "down")fac = -1.;
    if (eta <= 0.5)                     return 0.079 + 0.026 * fac;
    else if ( eta > 0.5 && eta <= 1.1 ) return 0.099 + 0.028 * fac;
    else if ( eta > 1.1 && eta <= 1.7 ) return 0.121 + 0.029 * fac;
    else if ( eta > 1.7 && eta <= 2.3 ) return 0.208 + 0.046 * fac;
    else if ( eta > 2.3 && eta <= 2.8 ) return 0.254 + 0.062 * fac;         
    else if ( eta > 2.8 && eta <= 3.2 ) return 0.395 + 0.063 * fac;         
    else if ( eta > 3.2 && eta <= 5   ) return 0.056 + 0.191 * fac;         
    return 0.1;
}


SingleTopMETsProducer::~SingleTopMETsProducer(){;}
DEFINE_FWK_MODULE(SingleTopMETsProducer);
