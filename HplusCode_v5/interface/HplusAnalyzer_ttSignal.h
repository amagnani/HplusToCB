// -*- C++ -*-
//
// Package:    HplusAnalyzer_ttSignal_ttSignal
// Class:      HplusAnalyzer_ttSignal
// 
/**\class HplusAnalyzer_ttSignal HplusAnalyzer_ttSignal.cc Hplus/HplusAnalyzer_ttSignal/src/HplusAnalyzer_ttSignal.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Alice
//         Created:  Fri Jan 15 11:10:12 CEST 2016
// $Id$
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "AnalysisDataFormats/TopObjects/interface/TtSemiLeptonicEvent.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

// PU summary info
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h" 

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include <TH1F.h>
#include <TTree.h>
#include <TLorentzVector.h>
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/PatCandidates/interface/TriggerEvent.h"
#include "DataFormats/PatCandidates/interface/TriggerObject.h"
#include "DataFormats/PatCandidates/interface/TriggerPath.h"
#include "DataFormats/PatCandidates/interface/TriggerObject.h"
#include "DataFormats/PatCandidates/interface/TriggerFilter.h"
#include "DataFormats/Common/interface/RefVector.h"
#include "DataFormats/FWLite/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "DataFormats/METReco/interface/PFMETCollection.h"
#include "DataFormats/METReco/interface/PFMET.h"
#include "DataFormats/METReco/interface/PFMETFwd.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"
#include <map>
#include <string>
#include "FWCore/Utilities/interface/Exception.h"
#include "FWCore/Utilities/interface/EDMException.h" 
#include "FWCore/Utilities/interface/InputTag.h"
#include <vector>
#include "CommonTools/UtilAlgos/interface/DeltaR.h"
#include "DataFormats/RecoCandidate/interface/RecoCandidate.h"
#include "DataFormats/VertexReco/interface/Vertex.h"

#include "AnalysisDataFormats/TopObjects/interface/TtSemiLeptonicEvent.h"
#include "AnalysisDataFormats/TopObjects/interface/TtSemiLepEvtPartons.h"
#include "PhysicsTools/Utilities/interface/LumiReWeighting.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

//
// class declaration
//

class HplusAnalyzer_ttSignal : public edm::EDAnalyzer  {
public:
  explicit HplusAnalyzer_ttSignal(const edm::ParameterSet & params): 
  sampleFlag_(  params.getParameter<std::string>("sampleFlag") ),  
  stepFlag_(  params.getParameter<std::string>("stepFlag") ) {};
  ~HplusAnalyzer_ttSignal();

  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


private:
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  virtual void beginRun(edm::Run const&, edm::EventSetup const&);
  virtual void endRun(edm::Run const&, edm::EventSetup const&);
  virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
  virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
 
 
  std::map<std::string, TH1F*> Plots;
  edm::Service<TFileService> fs;
  TTree* HplusTree;
  
  //GEN  
  
  Int_t run;
  Int_t luminosityBlock;
  Int_t event;
  Int_t MCcat;
  

  Int_t GenPart_daughterQuarkBarofHplus_pdgId;
  Int_t GenPart_daughterQuarkofHplus_pdgId;
 
  float GenPart_top_pt;
  float GenPart_topBar_pt;

  float GenPart_Hplus_mass;



  float GenPart_Hmass, GenPart_Wmass, GenPart_Tmass,  GenPart_formule_Tmass, GenPart_Tbarmass;

  Int_t nSimVertex;
  double lumiWeight;
  double lumiWeight_up;
  double lumiWeight_down;
  Int_t goodEvent; // 1 if the event is muon plus jets

  std::vector<float> TopJet_pt;
  std::vector<float> TopJet_eta;
  std::vector<float> TopJet_csv;
  std::vector<float> WJet_pt;
  std::vector<float> WJet_eta;
  std::vector<float> WJet_csv;
  std::vector<float> AddJet_pt;
  std::vector<float> AddJet_eta;
  std::vector<float> AddJet_csv;
  std::vector<float> *pTopJet_pt;
  std::vector<float> *pTopJet_eta;
  std::vector<float> *pTopJet_csv;
  std::vector<float> *pWJet_pt;
  std::vector<float> *pWJet_eta;
  std::vector<float> *pWJet_csv;
  std::vector<float> *pAddJet_pt;
  std::vector<float> *pAddJet_eta;
  std::vector<float> *pAddJet_csv;




//***************************************************************end Gen Particle initialization, begin truth match 

  float MatchJet_Hmass; //invariant mass of the two jets coming from H
  float MatchJet_Tmass; //invariant mass of the genH and the matched b jet
  float MatchJet_formule_Tmass;  //invariant mass of the genH and the matched b jet (with my computations)
  Int_t MatchJet_jetflag;	//exact jet combination 1000*jetH1(c)+100*jetH2+10*jetT+1*jetTbar
  
  unsigned int MatchJet_daughterQuarkofTop_index;    
  float MatchJet_daughterQuarkofTop_pt,  MatchJet_daughterQuarkofTop_recOverGenPt, MatchJet_daughterQuarkofTop_eta, MatchJet_daughterQuarkofTop_phi;	  
  float MatchJet_daughterQuarkofTop_bDiscrCSV;

  unsigned int MatchJet_daughterQuarkofTopBar_index;	     
  float MatchJet_daughterQuarkofTopBar_pt, MatchJet_daughterQuarkofTopBar_recOverGenPt, MatchJet_daughterQuarkofTopBar_eta, MatchJet_daughterQuarkofTopBar_phi;	   
  float MatchJet_daughterQuarkofTopBar_bDiscrCSV;

  unsigned int MatchJet_daughterQuarkofHplus_index;  
  float MatchJet_daughterQuarkofHplus_pt, MatchJet_daughterQuarkofHplus_recOverGenPt, MatchJet_daughterQuarkofHplus_eta, MatchJet_daughterQuarkofHplus_phi; 	
  float MatchJet_daughterQuarkofHplus_bDiscrCSV;

  unsigned int MatchJet_daughterQuarkBarofHplus_index;       
  float MatchJet_daughterQuarkBarofHplus_pt, MatchJet_daughterQuarkBarofHplus_recOverGenPt, MatchJet_daughterQuarkBarofHplus_eta, MatchJet_daughterQuarkBarofHplus_phi;	 
  float MatchJet_daughterQuarkBarofHplus_bDiscrCSV;
 
//***************************************************************end Truth Match, begin Reco 
 
   float MUpt, MUp;
   float MUeta, MUphi, MUtheta;
   float MUpx, MUpy, MUpz;
   float MUrelIso, MUd0, MUdz, MUnormChi2;
   int   MUnOfHits, MUlayer, MUnOfPixels, MUisGlobal, MUisPF, MUstations;
   
   int   nLep;
   
   Int_t nJet;
   int nbJet;
   int nbJetloose;
   int realnJet;
   std::vector<float> Jpt, Jp;
   std::vector<float> Jeta, Jphi, Jtheta;
   std::vector<float> Jpx, Jpy, Jpz;
   std::vector<float> JbDiscr;
   std::vector<float> Jenergy;
   std::vector<float> Jcharge;
   std::vector<int>   Jflavor;
   std::vector<float> *pJpt, *pJp;
   std::vector<float> *pJeta, *pJphi, *pJtheta;
   std::vector<float> *pJpx, *pJpy, *pJpz;
   std::vector<float> *pJbDiscr;
   std::vector<float> *pJenergy;
   std::vector<float> *pJcharge;
   std::vector<int>   *pJflavor;
 
   float METpt, METpx, METpy;
   float METeta, METphi, METtheta;
   
    
   int nVertex;



//***************************************************************end Reco, begin kinFit 
   static const int MaxComb=100;
   int ncomb=0;
   
   int   KinFit_isValid;
   std::vector<float> KinFit_prob, KinFit_chi2;
   std::vector<int>   KinFit_lightP_index, KinFit_lightQ_index, KinFit_hadB_index;
   std::vector<int>   KinFit_lepB_index, KinFit_lepton_index;
   std::vector<float> KinFit_hadW_mass, KinFit_hadW_pt, KinFit_hadW_eta, KinFit_hadW_phi;
   std::vector<float> KinFit_lepW_mass, KinFit_lepW_pt, KinFit_lepW_eta, KinFit_lepW_phi;
   std::vector<float> KinFit_hadTop_mass, KinFit_hadTop_pt, KinFit_hadTop_eta, KinFit_hadTop_phi;
   std::vector<float> KinFit_lepTop_mass, KinFit_lepTop_pt, KinFit_lepTop_eta, KinFit_lepTop_phi;
 
   std::vector<float> KinFit_hadQuark_pt, KinFit_hadQuark_eta, KinFit_hadQuark_phi;
   std::vector<float> KinFit_hadQuarkBar_pt, KinFit_hadQuarkBar_eta, KinFit_hadQuarkBar_phi;
   std::vector<float> KinFit_hadQuarkBar_px, KinFit_hadQuarkBar_py, KinFit_hadQuarkBar_pz, KinFit_hadQuarkBar_energy;
   std::vector<float> KinFit_hadB_pt, KinFit_hadB_eta, KinFit_hadB_phi;
   std::vector<float> KinFit_lepB_pt, KinFit_lepB_eta, KinFit_lepB_phi;

   std::vector<float> *pKinFit_prob, *pKinFit_chi2;
   std::vector<int>   *pKinFit_lightP_index, *pKinFit_lightQ_index, *pKinFit_hadB_index;
   std::vector<int>   *pKinFit_lepB_index, *pKinFit_lepton_index;
   std::vector<float> *pKinFit_hadW_mass, *pKinFit_hadW_pt, *pKinFit_hadW_eta, *pKinFit_hadW_phi;
   std::vector<float> *pKinFit_lepW_mass, *pKinFit_lepW_pt, *pKinFit_lepW_eta, *pKinFit_lepW_phi;
   std::vector<float> *pKinFit_hadTop_mass, *pKinFit_hadTop_pt, *pKinFit_hadTop_eta, *pKinFit_hadTop_phi;
   std::vector<float> *pKinFit_lepTop_mass, *pKinFit_lepTop_pt, *pKinFit_lepTop_eta, *pKinFit_lepTop_phi;
 
   std::vector<float> *pKinFit_hadQuark_pt, *pKinFit_hadQuark_eta, *pKinFit_hadQuark_phi;
   std::vector<float> *pKinFit_hadQuarkBar_pt, *pKinFit_hadQuarkBar_eta, *pKinFit_hadQuarkBar_phi;
   std::vector<float> *pKinFit_hadQuarkBar_px, *pKinFit_hadQuarkBar_py, *pKinFit_hadQuarkBar_pz, *pKinFit_hadQuarkBar_energy;
   std::vector<float> *pKinFit_hadB_pt, *pKinFit_hadB_eta, *pKinFit_hadB_phi;
   std::vector<float> *pKinFit_lepB_pt, *pKinFit_lepB_eta, *pKinFit_lepB_phi;

//***************************************************************end Reco, begin kinFit 
 
    std::string                  sampleFlag_;
    std::string                  stepFlag_;

  // ----------member data ---------------------------
//protected:
//    std::string                  sampleFlag_;
};
