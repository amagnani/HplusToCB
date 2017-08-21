// -*- C++ -*-
//
// Package:    HplusAnalyzer
// Class:      HplusAnalyzer
// 
/**\class HplusAnalyzer HplusAnalyzer.cc Hplus/HplusAnalyzer/src/HplusAnalyzer.cc

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
 #include "PhysicsTools/Utilities/interface/LumiReWeighting.h"
 #include "FWCore/MessageLogger/interface/MessageLogger.h"

//
// class declaration
//

class HplusAnalyzer : public edm::EDAnalyzer  {
public:
  explicit HplusAnalyzer(const edm::ParameterSet & params): 
  sampleFlag_(  params.getParameter<std::string>("sampleFlag") ),  
  stepFlag_(  params.getParameter<std::string>("stepFlag") ) {};
  ~HplusAnalyzer();

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
  
  Int_t GenPart_daughterQuarkofTop_pdgId;
  float GenPart_daughterQuarkofTop_pt, GenPart_daughterQuarkofTop_eta,GenPart_daughterQuarkofTop_phi;
  float GenPart_daughterQuarkofTop_p, GenPart_daughterQuarkofTop_px, GenPart_daughterQuarkofTop_py, GenPart_daughterQuarkofTop_pz;
  float GenPart_daughterQuarkofTop_E, GenPart_daughterQuarkofTop_mass;

  Int_t GenPart_daughterQuarkofTopBar_pdgId;
  float GenPart_daughterQuarkofTopBar_pt, GenPart_daughterQuarkofTopBar_eta,GenPart_daughterQuarkofTopBar_phi;
  float GenPart_daughterQuarkofTopBar_p, GenPart_daughterQuarkofTopBar_px, GenPart_daughterQuarkofTopBar_py, GenPart_daughterQuarkofTopBar_pz;
  float GenPart_daughterQuarkofTopBar_E, GenPart_daughterQuarkofTopBar_mass;

  Int_t GenPart_daughterQuarkBarofWMinus_pdgId;
  float GenPart_daughterQuarkBarofWMinus_pt, GenPart_daughterQuarkBarofWMinus_eta,GenPart_daughterQuarkBarofWMinus_phi;
  float GenPart_daughterQuarkBarofWMinus_p, GenPart_daughterQuarkBarofWMinus_px, GenPart_daughterQuarkBarofWMinus_py, GenPart_daughterQuarkBarofWMinus_pz;
  float GenPart_daughterQuarkBarofWMinus_E, GenPart_daughterQuarkBarofWMinus_mass;

  Int_t GenPart_daughterQuarkofWMinus_pdgId;
  float GenPart_daughterQuarkofWMinus_pt, GenPart_daughterQuarkofWMinus_eta,GenPart_daughterQuarkofWMinus_phi;
  float GenPart_daughterQuarkofWMinus_p, GenPart_daughterQuarkofWMinus_px, GenPart_daughterQuarkofWMinus_py, GenPart_daughterQuarkofWMinus_pz;
  float GenPart_daughterQuarkofWMinus_E, GenPart_daughterQuarkofWMinus_mass;

  Int_t GenPart_daughterQuarkBarofHplus_pdgId;
  float GenPart_daughterQuarkBarofHplus_pt, GenPart_daughterQuarkBarofHplus_eta,GenPart_daughterQuarkBarofHplus_phi;
  float GenPart_daughterQuarkBarofHplus_p, GenPart_daughterQuarkBarofHplus_px, GenPart_daughterQuarkBarofHplus_py, GenPart_daughterQuarkBarofHplus_pz;
  float GenPart_daughterQuarkBarofHplus_E, GenPart_daughterQuarkBarofHplus_mass;

  Int_t GenPart_daughterQuarkofHplus_pdgId;
  float GenPart_daughterQuarkofHplus_pt, GenPart_daughterQuarkofHplus_eta,GenPart_daughterQuarkofHplus_phi;
  float GenPart_daughterQuarkofHplus_p, GenPart_daughterQuarkofHplus_px, GenPart_daughterQuarkofHplus_py, GenPart_daughterQuarkofHplus_pz;
  float GenPart_daughterQuarkofHplus_E, GenPart_daughterQuarkofHplus_mass;

  Int_t GenPart_lepton_pdgId;
  float GenPart_lepton_pt, GenPart_lepton_eta,GenPart_lepton_phi;
  float GenPart_lepton_p, GenPart_lepton_px, GenPart_lepton_py, GenPart_lepton_pz;
  float GenPart_lepton_E, GenPart_lepton_mass;

  Int_t GenPart_neutrinoBar_pdgId;
  float GenPart_neutrinoBar_pt, GenPart_neutrinoBar_eta,GenPart_neutrinoBar_phi;
  float GenPart_neutrinoBar_p, GenPart_neutrinoBar_px, GenPart_neutrinoBar_py, GenPart_neutrinoBar_pz;
  float GenPart_neutrinoBar_E;

  float GenPart_top_pt, GenPart_top_eta,GenPart_top_phi;
  float GenPart_top_p, GenPart_top_px, GenPart_top_py, GenPart_top_pz;
  float GenPart_top_E, GenPart_top_mass;

  float GenPart_topBar_pt, GenPart_topBar_eta,GenPart_topBar_phi;
  float GenPart_topBar_p, GenPart_topBar_px, GenPart_topBar_py, GenPart_topBar_pz;
  float GenPart_topBar_E, GenPart_topBar_mass;

  float GenPart_WMinus_pt, GenPart_WMinus_eta,GenPart_WMinus_phi;
  float GenPart_WMinus_p, GenPart_WMinus_px, GenPart_WMinus_py, GenPart_WMinus_pz;
  float GenPart_WMinus_E, GenPart_WMinus_mass;

  float GenPart_Hplus_pt, GenPart_Hplus_eta,GenPart_Hplus_phi;
  float GenPart_Hplus_p, GenPart_Hplus_px, GenPart_Hplus_py, GenPart_Hplus_pz;
  float GenPart_Hplus_E, GenPart_Hplus_mass;


  Int_t GenPart_numberofLightQuarks;
  Int_t GenPart_numberofBQuarks;
  Int_t GenPart_numberofLeptons;
 

  float GenPart_Hmass, GenPart_Wmass, GenPart_Tmass,  GenPart_formule_Tmass, GenPart_Tbarmass;

  Int_t nSimVertex;
  double lumiWeight;
  double lumiWeight_up;
  double lumiWeight_down;
 Int_t goodEvent; // 1 if the event is muon plus jets




//***************************************************************end Gen Particle initialization, begin truth match 

  float MatchJet_Hmass; //invariant mass of the two jets coming from H
  float MatchJet_Tmass; //invariant mass of the genH and the matched b jet
  float MatchJet_formule_Tmass;  //invariant mass of the genH and the matched b jet (with my computations)
  Int_t MatchJet_jetflag;	//exact jet combination 1000*jetH1(c)+100*jetH2+10*jetT+1*jetTbar
  
  unsigned int MatchJet_daughterQuarkofTop_index;    
  float MatchJet_daughterQuarkofTop_pt,  MatchJet_daughterQuarkofTop_recOverGenPt, MatchJet_daughterQuarkofTop_eta, MatchJet_daughterQuarkofTop_phi;	  
  float MatchJet_daughterQuarkofTop_p, MatchJet_daughterQuarkofTop_px, MatchJet_daughterQuarkofTop_py, MatchJet_daughterQuarkofTop_pz;
  float MatchJet_daughterQuarkofTop_E;  
  float MatchJet_daughterQuarkofTop_deltaRj;	 //min Delta R with other jets 
  float MatchJet_daughterQuarkofTop_deltaRmu;	 //Delta R with the muon 
  float MatchJet_daughterQuarkofTop_bDiscrCSV;

  unsigned int MatchJet_daughterQuarkofTopBar_index;	     
  float MatchJet_daughterQuarkofTopBar_pt, MatchJet_daughterQuarkofTopBar_recOverGenPt, MatchJet_daughterQuarkofTopBar_eta, MatchJet_daughterQuarkofTopBar_phi;	   
  float MatchJet_daughterQuarkofTopBar_p, MatchJet_daughterQuarkofTopBar_px, MatchJet_daughterQuarkofTopBar_py, MatchJet_daughterQuarkofTopBar_pz;
  float MatchJet_daughterQuarkofTopBar_E;  
  float MatchJet_daughterQuarkofTopBar_deltaRj;     //min Delta R with other jets 
  float MatchJet_daughterQuarkofTopBar_deltaRmu;    //Delta R with the muon 
  float MatchJet_daughterQuarkofTopBar_bDiscrCSV;

  unsigned int MatchJet_daughterQuarkofHplus_index;  
  float MatchJet_daughterQuarkofHplus_pt, MatchJet_daughterQuarkofHplus_recOverGenPt, MatchJet_daughterQuarkofHplus_eta, MatchJet_daughterQuarkofHplus_phi; 	
  float MatchJet_daughterQuarkofHplus_p, MatchJet_daughterQuarkofHplus_px, MatchJet_daughterQuarkofHplus_py, MatchJet_daughterQuarkofHplus_pz;
  float MatchJet_daughterQuarkofHplus_E;  
  float MatchJet_daughterQuarkofHplus_deltaRj;     //min Delta R with other jets 
  float MatchJet_daughterQuarkofHplus_deltaRmu;    //Delta R with the muon 
  float MatchJet_daughterQuarkofHplus_bDiscrCSV;

  unsigned int MatchJet_daughterQuarkBarofHplus_index;       
  float MatchJet_daughterQuarkBarofHplus_pt, MatchJet_daughterQuarkBarofHplus_recOverGenPt, MatchJet_daughterQuarkBarofHplus_eta, MatchJet_daughterQuarkBarofHplus_phi;	 
  float MatchJet_daughterQuarkBarofHplus_p, MatchJet_daughterQuarkBarofHplus_px, MatchJet_daughterQuarkBarofHplus_py, MatchJet_daughterQuarkBarofHplus_pz;
  float MatchJet_daughterQuarkBarofHplus_E;  
  float MatchJet_daughterQuarkBarofHplus_deltaRj;     //min Delta R with other jets 
  float MatchJet_daughterQuarkBarofHplus_deltaRmu;    //Delta R with the muon 
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
   int   realnJet;
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
   Int_t KinFit_isValid;
   int ncomb=0;
   float KinFit_prob[MaxComb], KinFit_chi2[MaxComb];
   Int_t KinFit_lightP_index[MaxComb], KinFit_lightQ_index[MaxComb], KinFit_hadB_index[MaxComb];
   Int_t KinFit_lepB_index[MaxComb], KinFit_lepton_index[MaxComb];
   float KinFit_hadW_mass[MaxComb], KinFit_hadW_pt[MaxComb], KinFit_hadW_eta[MaxComb], KinFit_hadW_phi[MaxComb];
   float KinFit_hadW_px[MaxComb], KinFit_hadW_py[MaxComb], KinFit_hadW_pz[MaxComb], KinFit_hadW_energy[MaxComb];
   float KinFit_lepW_mass[MaxComb], KinFit_lepW_pt[MaxComb], KinFit_lepW_eta[MaxComb], KinFit_lepW_phi[MaxComb];
   float KinFit_lepW_px[MaxComb], KinFit_lepW_py[MaxComb], KinFit_lepW_pz[MaxComb], KinFit_lepW_energy[MaxComb];
   float KinFit_hadTop_mass[MaxComb], KinFit_hadTop_pt[MaxComb], KinFit_hadTop_eta[MaxComb], KinFit_hadTop_phi[MaxComb];
   float KinFit_hadTop_px[MaxComb], KinFit_hadTop_py[MaxComb], KinFit_hadTop_pz[MaxComb], KinFit_hadTop_energy[MaxComb];
   float KinFit_lepTop_mass[MaxComb], KinFit_lepTop_pt[MaxComb], KinFit_lepTop_eta[MaxComb], KinFit_lepTop_phi[MaxComb];
   float KinFit_lepTop_px[MaxComb], KinFit_lepTop_py[MaxComb], KinFit_lepTop_pz[MaxComb], KinFit_lepTop_energy[MaxComb];
 
   float KinFit_hadQuark_pt[MaxComb], KinFit_hadQuark_eta[MaxComb], KinFit_hadQuark_phi[MaxComb];
   float KinFit_hadQuark_px[MaxComb], KinFit_hadQuark_py[MaxComb],KinFit_hadQuark_pz[MaxComb], KinFit_hadQuark_energy[MaxComb];
   float KinFit_hadQuarkBar_pt[MaxComb], KinFit_hadQuarkBar_eta[MaxComb], KinFit_hadQuarkBar_phi[MaxComb];
   float KinFit_hadQuarkBar_px[MaxComb], KinFit_hadQuarkBar_py[MaxComb], KinFit_hadQuarkBar_pz[MaxComb], KinFit_hadQuarkBar_energy[MaxComb];
   float KinFit_hadB_pt[MaxComb], KinFit_hadB_eta[MaxComb], KinFit_hadB_phi[MaxComb];
   float KinFit_hadB_px[MaxComb], KinFit_hadB_py[MaxComb], KinFit_hadB_pz[MaxComb], KinFit_hadB_energy[MaxComb];
   float KinFit_lepB_pt[MaxComb], KinFit_lepB_eta[MaxComb], KinFit_lepB_phi[MaxComb];
   float KinFit_lepB_px[MaxComb], KinFit_lepB_py[MaxComb], KinFit_lepB_pz[MaxComb], KinFit_lepB_energy[MaxComb];

//***************************************************************end Reco, begin kinFit 
 
    std::string                  sampleFlag_;
    std::string                  stepFlag_;

  // ----------member data ---------------------------
//protected:
//    std::string                  sampleFlag_;
};
