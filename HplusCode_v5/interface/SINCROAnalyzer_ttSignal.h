// -*- C++ -*-
//
// Package:    SINCROAnalyzer_ttSignal_ttSignal
// Class:      SINCROAnalyzer_ttSignal
// 
/**\class SINCROAnalyzer_ttSignal SINCROAnalyzer_ttSignal.cc Hplus/SINCROAnalyzer_ttSignal/src/SINCROAnalyzer_ttSignal.cc

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

class SINCROAnalyzer_ttSignal : public edm::EDAnalyzer  {
public:
  explicit SINCROAnalyzer_ttSignal(const edm::ParameterSet & params): 
  sampleFlag_(  params.getParameter<std::string>("sampleFlag") ),  
  stepFlag_(  params.getParameter<std::string>("stepFlag") ) {};
  ~SINCROAnalyzer_ttSignal();

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
  int Nstep4=0;  //pt1>55
  int Nstep4b=0; //pt2>45
  int Nstep4c=0; //pt2>35
  int Nstep5=0;  //pt2>20
  int Nstep6=0;  //1 b
  int Nstep7=0;  //2 b
  int Nstep8=0;  //3 b
  
  //GEN  
  
  Int_t run;
  Int_t luminosityBlock;
  Int_t event;
  
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

//***************************************************************end Reco, begin kinFit 
 
    std::string                  sampleFlag_;
    std::string                  stepFlag_;

  // ----------member data ---------------------------
//protected:
//    std::string                  sampleFlag_;
};
