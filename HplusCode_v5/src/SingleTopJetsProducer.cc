/*
 *\Author: A. Orso M. Iorio 
 *
 *
 *\version  $Id: SingleTopJetsProducer.cc,v 1.5.12.3.4.2 2013/06/21 20:40:25 oiorio Exp $ 
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

#include "PhysicsTools/HplusCode_v5/interface/SingleTopJetsProducer.h"

#include <vector>
#include <memory>

#include "DataFormats/Math/interface/LorentzVector.h"
#include "FWCore/ParameterSet/interface/FileInPath.h"
#include "JetMETCorrections/Objects/interface/JetCorrector.h"

//using namespace pat;


SingleTopJetsProducer::SingleTopJetsProducer(const edm::ParameterSet& iConfig) 
{
  src_                 = iConfig.getParameter<edm::InputTag>	 ( "src" );
  isData_              = iConfig.getUntrackedParameter< bool >	 ( "isData" ,false);
  isJERup_             = iConfig.getUntrackedParameter< bool >   ( "isJERup" ,false);
  isJERdown_           = iConfig.getUntrackedParameter< bool > ( "isJERdown" ,false);
  isJESup_             = iConfig.getUntrackedParameter< bool >   ( "isJESup" ,false);
  isJESdown_           = iConfig.getUntrackedParameter< bool > ( "isJESdown" ,false);
  
  JESUncertaintiesPath_ = iConfig.getParameter< edm::FileInPath >("JESUncertaintiesPath");
  cut_ = iConfig.getParameter< std::string >("cut"); 
  
  removeOverlap_ = iConfig.getUntrackedParameter< bool >("removeOverlap",true); 
  muonsSrc_ = iConfig.getParameter<edm::InputTag>("muonsSrc");

  produces<std::vector<pat::Jet> >();
  jecUnc  = new JetCorrectionUncertainty(*(new JetCorrectorParameters(JESUncertaintiesPath_.fullPath().data(), "Total")));

}

void SingleTopJetsProducer::produce(edm::Event & iEvent, const edm::EventSetup & iEventSetup){
  
  //  for(std::vector<edm::InputTag>::const_iterator it=names.begin();it != names.end;++it){}

  iEvent.getByLabel(src_,jets);     //selected pat jets
  iEvent.getByLabel(src_,vjets);    //selected pat jets

  std::auto_ptr< std::vector< pat::Jet > > initialJets(new std::vector< pat::Jet >(*jets));
  std::auto_ptr< std::vector< pat::Jet > > finalJets(new std::vector< pat::Jet >);

   if(removeOverlap_)iEvent.getByLabel(muonsSrc_,muons);
 
   
   for(size_t i = 0; i < jets->size(); ++i){
      //    pat::Jet & jet = (*initialJets)[i];
      pat::Jet & jet = (*initialJets)[i];
    
//        std::cout<<"overlap "<<removeOverlap_<<std::endl;
// 	bool isOverlapped = false;
// 	if(removeOverlap_){
//        for(size_t e = 0; e < muons->size(); ++e){
//       if(deltaR(jets->at(i),muons->at(e))<0.5) {
// 	isOverlapped = true;
// 	break;
//       }
//        }
// 	}
	
//       std::cout<<"isOverlapped "<<isOverlapped<<std::endl;
//	if( isOverlapped)continue;
	
    
	double ptCorr = jet.pt(); 
	double genpt = -1; 
	if(jet.genJet()!=0) genpt = jet.genJet()->pt();
	
	double resolScale	= resolSF(fabs(jet.eta()),"");
	if (isJERup_)	resolScale = resolSF(fabs(jet.eta()),"up");
	if (isJERdown_) resolScale = resolSF(fabs(jet.eta()),"down");
	double smear = std::max((double)(0.0), (double)(ptCorr + (ptCorr - genpt) * resolScale) / ptCorr);
	//std::cout << "test smear * ptCorr " << smear*ptCorr << " v2 "<< std::max(0.0,genpt+(1+resolScale)*(ptCorr-genpt))<< " difference " << smear*ptCorr-std::max(0.0,genpt+(1+resolScale)*(ptCorr-genpt)) << std::endl;
	
       if(jet.genJet()==0) {
       smear = 1;
       }
       
       //std::cout<<i<<" th jet initial pt "<<ptCorr<<" genpt " <<genpt <<" eta "<< jet.eta() <<" resolScale "<<resolScale<<" smear "<< smear<<std::endl;
       
       jet.addUserFloat("jer_smear",smear);
       if(isData_) smear=1;
       
       jet.addUserFloat("pt_no_jer", (jet.p4()).pt());
       jet.addUserFloat("eta_no_jer",(jet.p4()).eta());
       jet.addUserFloat("phi_no_jer",(jet.p4()).phi());
       jet.addUserFloat("e_no_jer",  (jet.p4()).e());
       
      
       jet.setP4(jet.p4()*smear);
   //	std::cout << "pt " << jet.pt() << " eta "<< jet.eta() << std::endl;
      
      Selector cut(cut_);
      if(!cut(jet))continue; 
   
       jecUnc->setJetEta(jet.eta());
       jecUnc->setJetPt(jet.pt());
       double JetCorrection = jecUnc->getUncertainty(true);
    
       if(isData_) JetCorrection=0;
       jet.addUserFloat("JESUncertaintyTotalShift",JetCorrection);
       
       if(isJESup_)   jet.setP4(jet.p4()*(1+JetCorrection));
       if(isJESdown_) jet.setP4(jet.p4()*(1-JetCorrection));
       
       finalJets->push_back(jet);
   } 
  
  iEvent.put(finalJets);

}

double SingleTopJetsProducer::resolSF(double eta, std::string syst)
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


SingleTopJetsProducer::~SingleTopJetsProducer(){;}
DEFINE_FWK_MODULE(SingleTopJetsProducer);
