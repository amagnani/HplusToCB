// -*- C++ -*-
//
// Package:    HplusAnalyzer
// Class:      HplusAnalyzer
// 
/**\class HplusAnalyzer HplusAnalyzer.cc HplusAnalysis/HplusAnalyzer/src/HplusAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Alice Magnani,,,
//         Created:  Fri Jan 15 10:59:18 CET 2016
// $Id$
//
//


#include "../interface/HplusAnalyzer.h"

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
// HplusAnalyzer::HplusAnalyzer(const edm::ParameterSet& params)
// 
// {
//    //now do what ever initialization is needed
// 
// }


HplusAnalyzer::~HplusAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
HplusAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  using namespace std;
  using namespace reco;
 //______________________________________________________________________________________

  float Tnpv = -1;
  int BX;
  lumiWeight=1;

  //HANDLES
  Handle< vector<pat::Jet> > handleJet_; 
  iEvent.getByLabel("goodJets", handleJet_);
  Handle< vector<pat::Muon> > handleMuon_;
  iEvent.getByLabel("tightMuons", handleMuon_);
  Handle< vector<reco::GenParticle> > handleGenPart_;
  iEvent.getByLabel("prunedGenParticles", handleGenPart_);
  Handle< vector<pat::Jet> > handlebJet_; 
  iEvent.getByLabel("bJets", handlebJet_);
  Handle< vector<pat::Jet> > handleloosebJet_; 
  iEvent.getByLabel("loosebJets", handleloosebJet_);
  Handle< vector<pat::Muon> > handleVetoMuon_;
  iEvent.getByLabel("vetoMuons", handleVetoMuon_);
  Handle< vector<pat::Electron> > handleEle_;
  iEvent.getByLabel("vetoElecs", handleEle_);
  Handle< vector<pat::MET> > handleMET_;
  iEvent.getByLabel("goodMETs", handleMET_);
  Handle< vector<reco::Vertex> > handleVertex_;
  iEvent.getByLabel("goodOfflinePrimaryVertices", handleVertex_);
  
  
 //Gen Particles initialization
  run=0; luminosityBlock=0; event=0; 
  GenPart_daughterQuarkofTop_pdgId=0;
  GenPart_daughterQuarkofTop_pt=0; GenPart_daughterQuarkofTop_eta=0;GenPart_daughterQuarkofTop_phi=0;
  GenPart_daughterQuarkofTop_p=0; GenPart_daughterQuarkofTop_px=0; GenPart_daughterQuarkofTop_py=0;
  GenPart_daughterQuarkofTop_pz=0;
  GenPart_daughterQuarkofTop_E=0; GenPart_daughterQuarkofTop_mass=0;

  GenPart_daughterQuarkofTopBar_pdgId=0;
  GenPart_daughterQuarkofTopBar_pt=0; GenPart_daughterQuarkofTopBar_eta=0; GenPart_daughterQuarkofTopBar_phi=0;
  GenPart_daughterQuarkofTopBar_p=0; GenPart_daughterQuarkofTopBar_px=0; GenPart_daughterQuarkofTopBar_py=0; GenPart_daughterQuarkofTopBar_pz=0;
  GenPart_daughterQuarkofTopBar_E=0; GenPart_daughterQuarkofTopBar_mass=0;
  GenPart_daughterQuarkBarofWMinus_pdgId=0;
  GenPart_daughterQuarkBarofWMinus_pt=0; GenPart_daughterQuarkBarofWMinus_eta=0;GenPart_daughterQuarkBarofWMinus_phi=0;
  GenPart_daughterQuarkBarofWMinus_p=0; GenPart_daughterQuarkBarofWMinus_px=0; GenPart_daughterQuarkBarofWMinus_py=0; GenPart_daughterQuarkBarofWMinus_pz=0;
  GenPart_daughterQuarkBarofWMinus_E=0; GenPart_daughterQuarkBarofWMinus_mass=0;

  GenPart_daughterQuarkofWMinus_pdgId=0;
  GenPart_daughterQuarkofWMinus_pt=0; GenPart_daughterQuarkofWMinus_eta=0; GenPart_daughterQuarkofWMinus_phi=0;
  GenPart_daughterQuarkofWMinus_p=0; GenPart_daughterQuarkofWMinus_px=0; GenPart_daughterQuarkofWMinus_py=0; GenPart_daughterQuarkofWMinus_pz=0;
  GenPart_daughterQuarkofWMinus_E=0; GenPart_daughterQuarkofWMinus_mass=0;

  GenPart_daughterQuarkBarofHplus_pdgId=0;
  GenPart_daughterQuarkBarofHplus_pt=0; GenPart_daughterQuarkBarofHplus_eta=0; GenPart_daughterQuarkBarofHplus_phi=0;
  GenPart_daughterQuarkBarofHplus_p=0; GenPart_daughterQuarkBarofHplus_px=0; GenPart_daughterQuarkBarofHplus_py=0; GenPart_daughterQuarkBarofHplus_pz=0;
  GenPart_daughterQuarkBarofHplus_E=0; GenPart_daughterQuarkBarofHplus_mass=0;

  GenPart_daughterQuarkofHplus_pdgId=0;
  GenPart_daughterQuarkofHplus_pt=0; GenPart_daughterQuarkofHplus_eta=0; GenPart_daughterQuarkofHplus_phi=0;
  GenPart_daughterQuarkofHplus_p=0; GenPart_daughterQuarkofHplus_px=0; GenPart_daughterQuarkofHplus_py=0; GenPart_daughterQuarkofHplus_pz=0;
  GenPart_daughterQuarkofHplus_E=0; GenPart_daughterQuarkofHplus_mass=0;

  GenPart_lepton_pdgId=0;
  GenPart_lepton_pt=0; GenPart_lepton_eta=0; GenPart_lepton_phi=0;
  GenPart_lepton_p=0; GenPart_lepton_px=0; GenPart_lepton_py=0; GenPart_lepton_pz=0;
  GenPart_lepton_E=0; GenPart_lepton_mass=0;

  GenPart_neutrinoBar_pdgId=0;
  GenPart_neutrinoBar_pt=0; GenPart_neutrinoBar_eta=0; GenPart_neutrinoBar_phi=0;
  GenPart_neutrinoBar_p=0; GenPart_neutrinoBar_px=0; GenPart_neutrinoBar_py=0; GenPart_neutrinoBar_pz=0;
  GenPart_neutrinoBar_E=0;

  GenPart_top_pt=0; GenPart_top_eta=0; GenPart_top_phi=0;
  GenPart_top_p=0; GenPart_top_px=0; GenPart_top_py=0; GenPart_top_pz=0;
  GenPart_top_E=0; GenPart_top_mass=0;

  GenPart_topBar_pt=0; GenPart_topBar_eta=0; GenPart_topBar_phi=0;
  GenPart_topBar_p=0; GenPart_topBar_px=0; GenPart_topBar_py=0; GenPart_topBar_pz=0;
  GenPart_topBar_E=0; GenPart_topBar_mass=0;

  GenPart_WMinus_pt=0; GenPart_WMinus_eta=0; GenPart_WMinus_phi=0;
  GenPart_WMinus_p=0; GenPart_WMinus_px=0; GenPart_WMinus_py=0; GenPart_WMinus_pz=0;
  GenPart_WMinus_E=0; GenPart_WMinus_mass=0;

  GenPart_Hplus_pt=0; GenPart_Hplus_eta=0; GenPart_Hplus_phi=0;
  GenPart_Hplus_p=0; GenPart_Hplus_px=0; GenPart_Hplus_py=0; GenPart_Hplus_pz=0;
  GenPart_Hplus_E=0; GenPart_Hplus_mass=0;

  
  GenPart_numberofLightQuarks=0;
  GenPart_numberofBQuarks=0;
  GenPart_numberofLeptons=0;

   
  GenPart_Hmass=0;
  GenPart_Wmass=0;
  GenPart_Tmass=0;
  GenPart_formule_Tmass=0;
  GenPart_Tbarmass=0;
  

  vector<reco::GenParticle> Hdecay;
  vector<reco::GenParticle> Wdecay;
  vector<reco::GenParticle> Tdecay;
  vector<reco::GenParticle> Tbardecay;
  reco::GenParticle Hh; //generated Higgs
  reco::GenParticle gpart;
 
//--------------------------------------------------------------------------------------------------------------

  MatchJet_Hmass=0;
  MatchJet_Tmass=0;
  MatchJet_formule_Tmass=0;
  MatchJet_jetflag=0;
  float drj=99999;

  MatchJet_daughterQuarkofTop_index=99999;
  MatchJet_daughterQuarkofTop_pt=99999; MatchJet_daughterQuarkofTop_recOverGenPt=99999; MatchJet_daughterQuarkofTop_eta=99999; MatchJet_daughterQuarkofTop_phi=99999;
  MatchJet_daughterQuarkofTop_p=99999; MatchJet_daughterQuarkofTop_px=99999;
  MatchJet_daughterQuarkofTop_py=99999; MatchJet_daughterQuarkofTop_pz=99999;
  MatchJet_daughterQuarkofTop_E=99999;
  MatchJet_daughterQuarkofTop_deltaRj=99999; 
  MatchJet_daughterQuarkofTop_deltaRmu=99999; 
  MatchJet_daughterQuarkofTop_bDiscrCSV=99999; 
 
  MatchJet_daughterQuarkofTopBar_index=99999;
  MatchJet_daughterQuarkofTopBar_pt=99999; MatchJet_daughterQuarkofTopBar_recOverGenPt=99999; MatchJet_daughterQuarkofTopBar_eta=99999; MatchJet_daughterQuarkofTopBar_phi=99999;
  MatchJet_daughterQuarkofTopBar_p=99999; MatchJet_daughterQuarkofTopBar_px=99999;
  MatchJet_daughterQuarkofTopBar_py=99999; MatchJet_daughterQuarkofTopBar_pz=99999;
  MatchJet_daughterQuarkofTopBar_E=99999;
  MatchJet_daughterQuarkofTopBar_deltaRj=99999; 
  MatchJet_daughterQuarkofTopBar_deltaRmu=99999; 
  MatchJet_daughterQuarkofTopBar_bDiscrCSV=99999; 

  MatchJet_daughterQuarkofHplus_index=99999;
  MatchJet_daughterQuarkofHplus_pt=99999; MatchJet_daughterQuarkofHplus_recOverGenPt=99999; MatchJet_daughterQuarkofHplus_eta=99999; MatchJet_daughterQuarkofHplus_phi=99999;
  MatchJet_daughterQuarkofHplus_p=99999; MatchJet_daughterQuarkofHplus_px=99999;
  MatchJet_daughterQuarkofHplus_py=99999; MatchJet_daughterQuarkofHplus_pz=99999;
  MatchJet_daughterQuarkofHplus_E=99999;
  MatchJet_daughterQuarkofHplus_deltaRj=99999; 
  MatchJet_daughterQuarkofHplus_deltaRmu=99999; 
  MatchJet_daughterQuarkofHplus_bDiscrCSV=99999; 

  MatchJet_daughterQuarkBarofHplus_index=99999;
  MatchJet_daughterQuarkBarofHplus_pt=99999; MatchJet_daughterQuarkBarofHplus_recOverGenPt=99999; MatchJet_daughterQuarkBarofHplus_eta=99999; MatchJet_daughterQuarkBarofHplus_phi=99999;
  MatchJet_daughterQuarkBarofHplus_p=99999; MatchJet_daughterQuarkBarofHplus_px=99999;
  MatchJet_daughterQuarkBarofHplus_py=99999; MatchJet_daughterQuarkBarofHplus_pz=99999;
  MatchJet_daughterQuarkBarofHplus_E=99999;
  MatchJet_daughterQuarkBarofHplus_deltaRj=99999; 
  MatchJet_daughterQuarkBarofHplus_deltaRmu=99999; 
  MatchJet_daughterQuarkBarofHplus_bDiscrCSV=99999; 


 
  DeltaR<pat::Jet, pat::Jet> deltaRjj;
 
  pat::Jet jet;  
  vector<pat::Jet> Hjets;  
  pat::Jet Tbjet; //b jet coming from the top
  pat::Jet iijet;
  vector<int> jetpdg;
  vector<unsigned int> jetorder;
  float dr;
  int tbarjetf=0; int tjetf=0; 
  

  unsigned int nMuon= handleMuon_->size();
 

//___________________________________________________________________________________________________________


  nLep=0;
  
  nJet=4;  //used for dimension of vectors
  realnJet=0;
  Jpt.clear(); Jp.clear(); Jeta.clear(); Jphi.clear(); Jtheta.clear();
  Jpx.clear(); Jpy.clear(); Jpz.clear();
  JbDiscr.clear(); Jenergy.clear(); Jcharge.clear(); Jflavor.clear();
  
  METpt=0; METpx=0; METpy=0; METeta=0, METphi=0, METtheta=0;
  
  nVertex=0;
  nSimVertex=0;

  
  
  
  pat::Muon mu;  
  pat::Muon firstMuon; 
  pat::Jet mj;
  Int_t muflag=0;
  float chargedIso;
  float neutralIso;
  float photonIso; 
  
  pat::Electron ele;
  
  reco::Vertex vertex;
  
 
  pat::MET met;  

  vector<float> METpz;

   
  nLep=handleVetoMuon_->size()+handleEle_->size();
 
//___________________________________________________________________________________________________________
 
  KinFit_isValid=0;
 
  for(unsigned int i = 0;i<4;i++){
  KinFit_prob[i]=0; KinFit_chi2[i]=0;
  KinFit_lightP_index[i]=0; KinFit_lightQ_index[i]=0; KinFit_hadB_index[i]=0;
  KinFit_lepB_index[i]=0; KinFit_lepton_index[i]=0;
  KinFit_hadW_mass[i]=0; KinFit_hadW_pt[i]=0; KinFit_hadW_eta[i]=0;KinFit_hadW_phi[i]=0;
  KinFit_hadW_px[i]=0; KinFit_hadW_py[i]=0; KinFit_hadW_pz[i]=0; KinFit_hadW_energy[i]=0;
  KinFit_lepW_mass[i]=0; KinFit_lepW_pt[i]=0; KinFit_lepW_eta[i]=0; KinFit_lepW_phi[i]=0;
  KinFit_lepW_px[i]=0; KinFit_lepW_py[i]=0; KinFit_lepW_pz[i]=0; KinFit_lepW_energy[i]=0;
  KinFit_hadTop_mass[i]=0; KinFit_hadTop_pt[i]=0; KinFit_hadTop_eta[i]=0; KinFit_hadTop_phi[i]=0;
  KinFit_hadTop_px[i]=0; KinFit_hadTop_py[i]=0; KinFit_hadTop_pz[i]=0; KinFit_hadTop_energy[i]=0;
  KinFit_lepTop_mass[i]=0; KinFit_lepTop_pt[i]=0; KinFit_lepTop_eta[i]=0; KinFit_lepTop_phi[i]=0;
  KinFit_lepTop_px[i]=0; KinFit_lepTop_py[i]=0; KinFit_lepTop_pz[i]=0; KinFit_lepTop_energy[i]=0;
 
  KinFit_hadQuark_pt[i]=0; KinFit_hadQuark_eta[i]=0; KinFit_hadQuark_phi[i]=0;
  KinFit_hadQuark_px[i]=0; KinFit_hadQuark_py[i]=0;KinFit_hadQuark_pz[i]=0; KinFit_hadQuark_energy[i]=0;
  KinFit_hadQuarkBar_pt[i]=0; KinFit_hadQuarkBar_eta[i]=0; KinFit_hadQuarkBar_phi[i]=0;
  KinFit_hadQuarkBar_px[i]=0; KinFit_hadQuarkBar_py[i]=0; KinFit_hadQuarkBar_pz[i]=0; KinFit_hadQuarkBar_energy[i]=0;
  KinFit_hadB_pt[i]=0; KinFit_hadB_eta[i]=0; KinFit_hadB_phi[i]=0;
  KinFit_hadB_px[i]=0; KinFit_hadB_py[i]=0; KinFit_hadB_pz[i]=0; KinFit_hadB_energy[i]=0;
  KinFit_lepB_pt[i]=0; KinFit_lepB_eta[i]=0; KinFit_lepB_phi[i]=0;
  KinFit_lepB_px[i]=0; KinFit_lepB_py[i]=0; KinFit_lepB_pz[i]=0; KinFit_lepB_energy[i]=0;
  KinFit_prob[i]=0;
  KinFit_chi2[i]=0;
}
  

  
 const reco::Candidate* KinFit_lepTop;  
 const reco::Candidate* KinFit_lepW; 
 const reco::Candidate* KinFit_hadTop;  
 const reco::Candidate* KinFit_hadW; 
 const reco::Candidate* KinFit_hadQuark;
 const reco::Candidate* KinFit_hadQuarkBar;
 const reco::Candidate* KinFit_hadB;
 const reco::Candidate* KinFit_lepB;
 

//___________________________________________________________________________________________________________
  
  //Filling GenPart variables
  
  
  //REMOVE GEN Wbb and Zbb events from WJets and ZJets samples
  if  (sampleFlag_=="WZJets" ) { 
    int bnumber=0;
    for(unsigned int igen = 0; igen < handleGenPart_->size(); igen++) {
      gpart = handleGenPart_->at(igen);
      if (gpart.status()==3 && abs(gpart.pdgId())==5) bnumber ++;
    } 

    if(bnumber==2 || (bnumber>2)){
      //cout<<"strange bnumber "<<bnumber<<endl;
      return;
     }
   
 
 if(bnumber==2) cout<<"Evento Wbb o Zbb, non dovrebbe essere qui"<<endl;
}
  //end REMOVE GEN Wbb and Zbb events from WJets and ZJets samples

 
   //STUDY Wbb Zbbb Backgound (temporary)
// 
//   if  (sampleFlag_=="Bkg" ) { 
//   cout<<"init event"<<endl;
//     for(unsigned int igen = 0; igen < handleGenPart_->size(); igen++) {
//       gpart = handleGenPart_->at(igen);
//      const Candidate* mot = gpart.mother();
//       if ((gpart.status()==3) && (abs(gpart.pdgId())==5 ) && (mot!=0) && ((*mot).pdgId()!=21)) cout<<" voglio andare a vivere in campagna "<<(*mot).pdgId()<<endl;
//       if ((gpart.status()==3) && (abs(gpart.pdgId())!=5)&& (mot!=0) &&((*mot).pdgId()==21 )) cout<<" chi sei "<<gpart.pdgId()<<endl;
//     } 
//  
// }
 
 
    //end STUDY Wbb Zbbb Backgound (temporary)

 
 if  (sampleFlag_=="MCsignal" || sampleFlag_=="MCttbar" ) { 

 //set particle in hadronic branch
 int hadID=0;
 if(sampleFlag_=="MCsignal" ) {hadID=37;}
 else {hadID=24;}
  
  
   for(unsigned int igen = 0; igen < handleGenPart_->size(); igen++) {
    
     gpart = handleGenPart_->at(igen);
     //get the particle's mother
     const Candidate* mot = gpart.mother();
     
     
      //count number of different particles
      if (gpart.status()==3 && fabs(gpart.pdgId())<5) GenPart_numberofLightQuarks++;
      //devo togliere da qui i genitori del top
      if (gpart.status()==3 && fabs(gpart.pdgId())==5) GenPart_numberofBQuarks++;
      if (gpart.status()==3 && (fabs(gpart.pdgId())==11 ||fabs(gpart.pdgId())==13 || fabs(gpart.pdgId())==15 ) ) GenPart_numberofLeptons++;
      
    
      //if mother exsists
      if(mot!=0){ 
	     
	 // get the top quark
	if(gpart.pdgId()==6 && gpart.status()==3){
	  GenPart_top_pt=gpart.pt(); GenPart_top_eta=gpart.eta(); GenPart_top_phi=gpart.phi();
	  GenPart_top_px=gpart.px(); GenPart_top_py=gpart.py(); GenPart_top_pz=gpart.pz();
	  GenPart_top_p=sqrt(gpart.px()*gpart.px()+gpart.py()*gpart.py()+gpart.pz()*gpart.pz());
	  GenPart_top_E=gpart.energy(); GenPart_top_mass=gpart.mass();
	}
    
       // get the topbar quark
       if(gpart.pdgId()==-6 && gpart.status()==3){
	 GenPart_topBar_pt=gpart.pt(); GenPart_topBar_eta=gpart.eta(); GenPart_topBar_phi=gpart.phi();
	 GenPart_topBar_px=gpart.px(); GenPart_topBar_py=gpart.py(); GenPart_topBar_pz=gpart.pz();
	 GenPart_topBar_p=sqrt(gpart.px()*gpart.px()+gpart.py()*gpart.py()+gpart.pz()*gpart.pz());
	 GenPart_topBar_E=gpart.energy(); GenPart_topBar_mass=gpart.mass();
	 
	 
      }
 
       // get the W-
       if(gpart.pdgId()==-24 && gpart.status()==3){
	 GenPart_WMinus_pt=gpart.pt(); GenPart_WMinus_eta=gpart.eta(); GenPart_WMinus_phi=gpart.phi();
	 GenPart_WMinus_px=gpart.px(); GenPart_WMinus_py=gpart.py(); GenPart_WMinus_pz=gpart.pz();
	 GenPart_WMinus_p=sqrt(gpart.px()*gpart.px()+gpart.py()*gpart.py()+gpart.pz()*gpart.pz());
	 GenPart_WMinus_E=gpart.energy(); GenPart_WMinus_mass=gpart.mass();
      Tbardecay.push_back(gpart);
       }
 
	// get the H+
       if(gpart.pdgId()==hadID && gpart.status()==3){
	 GenPart_Hplus_pt=gpart.pt(); GenPart_Hplus_eta=gpart.eta(); GenPart_Hplus_phi=gpart.phi();
	 GenPart_Hplus_px=gpart.px(); GenPart_Hplus_py=gpart.py(); GenPart_Hplus_pz=gpart.pz();
	 GenPart_Hplus_p=sqrt(gpart.px()*gpart.px()+gpart.py()*gpart.py()+gpart.pz()*gpart.pz());
	 GenPart_Hplus_E=gpart.energy(); GenPart_Hplus_mass=gpart.mass();
      Hh=gpart;
      Tdecay.push_back(gpart);
       }
    
	// get the  daughter quark of top
	if((*mot).pdgId()==6 && fabs(gpart.pdgId())<6 && gpart.status()==3){
	  GenPart_daughterQuarkofTop_pdgId=gpart.pdgId();
	  GenPart_daughterQuarkofTop_pt=gpart.pt(); GenPart_daughterQuarkofTop_eta=gpart.eta(); GenPart_daughterQuarkofTop_phi=gpart.phi();
	  GenPart_daughterQuarkofTop_px=gpart.px(); GenPart_daughterQuarkofTop_py=gpart.py(); GenPart_daughterQuarkofTop_pz=gpart.pz();
	  GenPart_daughterQuarkofTop_p=sqrt(gpart.px()*gpart.px()+gpart.py()*gpart.py()+gpart.pz()*gpart.pz());
	  GenPart_daughterQuarkofTop_E=gpart.energy(); GenPart_daughterQuarkofTop_mass=gpart.mass();
       Tdecay.push_back(gpart);
	}
 
	// get the  daughter quark of topbar
	if((*mot).pdgId()==-6 && fabs(gpart.pdgId())<6 && gpart.status()==3){
	  GenPart_daughterQuarkofTopBar_pdgId=gpart.pdgId();
	  GenPart_daughterQuarkofTopBar_pt=gpart.pt(); GenPart_daughterQuarkofTopBar_eta=gpart.eta(); GenPart_daughterQuarkofTopBar_phi=gpart.phi();
	  GenPart_daughterQuarkofTopBar_px=gpart.px(); GenPart_daughterQuarkofTopBar_py=gpart.py(); GenPart_daughterQuarkofTopBar_pz=gpart.pz();
	  GenPart_daughterQuarkofTopBar_p=sqrt(gpart.px()*gpart.px()+gpart.py()*gpart.py()+gpart.pz()*gpart.pz());
	  GenPart_daughterQuarkofTopBar_E=gpart.energy(); GenPart_daughterQuarkofTopBar_mass=gpart.mass();
       Tbardecay.push_back(gpart);
	}
	
	// get the  daughter quark of WMinus
	if((*mot).pdgId()==-24 && gpart.pdgId()>0 && gpart.pdgId()<6 && gpart.status()==3){
	  GenPart_daughterQuarkofWMinus_pdgId=gpart.pdgId();
	  GenPart_daughterQuarkofWMinus_pt=gpart.pt(); GenPart_daughterQuarkofWMinus_eta=gpart.eta(); GenPart_daughterQuarkofWMinus_phi=gpart.phi();
	  GenPart_daughterQuarkofWMinus_px=gpart.px(); GenPart_daughterQuarkofWMinus_py=gpart.py(); GenPart_daughterQuarkofWMinus_pz=gpart.pz();
	  GenPart_daughterQuarkofWMinus_p=sqrt(gpart.px()*gpart.px()+gpart.py()*gpart.py()+gpart.pz()*gpart.pz());
	  GenPart_daughterQuarkofWMinus_E=gpart.energy(); GenPart_daughterQuarkofWMinus_mass=gpart.mass();
       Wdecay.push_back(gpart);
	}
	
	// get the  daughter quarkbar of WMinus
	if((*mot).pdgId()==-24 && gpart.pdgId()<0 && gpart.pdgId()>-6 && gpart.status()==3){
	  GenPart_daughterQuarkBarofWMinus_pdgId=gpart.pdgId();
	  GenPart_daughterQuarkBarofWMinus_pt=gpart.pt(); GenPart_daughterQuarkBarofWMinus_eta=gpart.eta(); GenPart_daughterQuarkBarofWMinus_phi=gpart.phi();
	  GenPart_daughterQuarkBarofWMinus_px=gpart.px(); GenPart_daughterQuarkBarofWMinus_py=gpart.py(); GenPart_daughterQuarkBarofWMinus_pz=gpart.pz();
	  GenPart_daughterQuarkBarofWMinus_p=sqrt(gpart.px()*gpart.px()+gpart.py()*gpart.py()+gpart.pz()*gpart.pz());
	  GenPart_daughterQuarkBarofWMinus_E=gpart.energy(); GenPart_daughterQuarkBarofWMinus_mass=gpart.mass();
       Wdecay.push_back(gpart);
	}
   
	// get the  daughter quark of Hplus
	if((*mot).pdgId()==hadID && gpart.pdgId()>0 && gpart.status()==3){
	  GenPart_daughterQuarkofHplus_pdgId=gpart.pdgId(); 
	  GenPart_daughterQuarkofHplus_pt=gpart.pt(); GenPart_daughterQuarkofHplus_eta=gpart.eta(); GenPart_daughterQuarkofHplus_phi=gpart.phi();
	  GenPart_daughterQuarkofHplus_px=gpart.px(); GenPart_daughterQuarkofHplus_py=gpart.py(); GenPart_daughterQuarkofHplus_pz=gpart.pz();
	  GenPart_daughterQuarkofHplus_p=sqrt(gpart.px()*gpart.px()+gpart.py()*gpart.py()+gpart.pz()*gpart.pz());
	  GenPart_daughterQuarkofHplus_E=gpart.energy(); GenPart_daughterQuarkofHplus_mass=gpart.mass();
       Hdecay.push_back(gpart);
       }
	
	// get the  daughter quarkbar of Hplus
	if((*mot).pdgId()==hadID && gpart.pdgId()<0 && gpart.status()==3){
	  GenPart_daughterQuarkBarofHplus_pdgId=gpart.pdgId(); 
	  GenPart_daughterQuarkBarofHplus_pt=gpart.pt(); GenPart_daughterQuarkBarofHplus_eta=gpart.eta(); GenPart_daughterQuarkBarofHplus_phi=gpart.phi();
	  GenPart_daughterQuarkBarofHplus_px=gpart.px(); GenPart_daughterQuarkBarofHplus_py=gpart.py(); GenPart_daughterQuarkBarofHplus_pz=gpart.pz();
	  GenPart_daughterQuarkBarofHplus_p=sqrt(gpart.px()*gpart.px()+gpart.py()*gpart.py()+gpart.pz()*gpart.pz());
	  GenPart_daughterQuarkBarofHplus_E=gpart.energy(); GenPart_daughterQuarkBarofHplus_mass=gpart.mass();
       Hdecay.push_back(gpart);
	}
    
	// get the lepton from W
	if((*mot).pdgId()==-24 && (gpart.pdgId()==11 || gpart.pdgId()==13 || gpart.pdgId()==15) && gpart.status()==3){
	  GenPart_lepton_pdgId=gpart.pdgId();
	  GenPart_lepton_pt=gpart.pt(); GenPart_lepton_eta=gpart.eta(); GenPart_lepton_phi=gpart.phi();
	  GenPart_lepton_px=gpart.px(); GenPart_lepton_py=gpart.py(); GenPart_lepton_pz=gpart.pz();
	  GenPart_lepton_p=sqrt(gpart.px()*gpart.px()+gpart.py()*gpart.py()+gpart.pz()*gpart.pz());
	  GenPart_lepton_E=gpart.energy(); GenPart_lepton_mass=gpart.mass();
       Wdecay.push_back(gpart);
      }
    
	 // get the neutrino from W
	if((*mot).pdgId()==-24 && (gpart.pdgId()==-12 || gpart.pdgId()==-14 || gpart.pdgId()==-16) && gpart.status()==3){
	  GenPart_neutrinoBar_pdgId=gpart.pdgId();
	  GenPart_neutrinoBar_pt=gpart.pt(); GenPart_neutrinoBar_eta=gpart.eta(); GenPart_neutrinoBar_phi=gpart.phi();
	  GenPart_neutrinoBar_px=gpart.px(); GenPart_neutrinoBar_py=gpart.py(); GenPart_neutrinoBar_pz=gpart.pz();
	  GenPart_neutrinoBar_p=sqrt(gpart.px()*gpart.px()+gpart.py()*gpart.py()+gpart.pz()*gpart.pz());
	  GenPart_neutrinoBar_E=gpart.energy(); 
       Wdecay.push_back(gpart);
	}     
      
   
    }//end if mother exists 
   
   }//end loop on genparticles
 
   GenPart_Hmass=(Hdecay[0].p4()+Hdecay[1].p4()).M();
   GenPart_Wmass=(Wdecay[0].p4()+Wdecay[1].p4()).M();
   GenPart_Tmass=(Tdecay[0].p4()+Tdecay[1].p4()).M();
   
   GenPart_formule_Tmass=sqrt((Tdecay[0].energy()+Tdecay[1].energy())*(Tdecay[0].energy()+Tdecay[1].energy())
			 -(Tdecay[0].px()+Tdecay[1].px())*(Tdecay[0].px()+Tdecay[1].px())
			 -(Tdecay[0].py()+Tdecay[1].py())*(Tdecay[0].py()+Tdecay[1].py())
			 -(Tdecay[0].pz()+Tdecay[1].pz())*(Tdecay[0].pz()+Tdecay[1].pz())
			 );
		       
   
   GenPart_Tbarmass=(Tbardecay[0].p4()+Tbardecay[1].p4()).M();
 

//___________________________________________________________________________________________
 
  for(unsigned int igen = 0; igen < handleGenPart_->size(); igen++) {
	gpart = handleGenPart_->at(igen);
	// get the H+
       if(gpart.pdgId()==hadID && gpart.status()==3){
      Hh=gpart;
       }
     }
 
   //T Invariant mass using gen H+ and the pat jet matched with with the gen jet coming from t
   
     for(unsigned int ijet=0; ijet<handleJet_->size(); ijet++){
      
       jet = handleJet_->at(ijet); 
       
       
       //get matched parton
       const reco::GenParticle *parton=jet.genParton();
       
       if(parton!=0) {  	 
       //get the mother of the matched parton
       const reco::Candidate *jmot=(*parton).mother();
       
       if(jmot!=0) {
       
	 
      //get the c-jet
      if((*jmot).pdgId()==hadID && (*parton).pdgId()>0){
	  
	Hjets.push_back(jet); 
	//jetpdg.push_back((*parton).pdgId());
	//jetorder.push_back(ijet); 
	MatchJet_jetflag=MatchJet_jetflag+1000*ijet;
	MatchJet_daughterQuarkofHplus_index=ijet;
	MatchJet_daughterQuarkofHplus_pt=jet.pt();
	MatchJet_daughterQuarkofHplus_recOverGenPt=jet.pt()/(*parton).pt();
	MatchJet_daughterQuarkofHplus_eta=jet.eta();
	MatchJet_daughterQuarkofHplus_phi=jet.phi();
	MatchJet_daughterQuarkofHplus_px=jet.px(); MatchJet_daughterQuarkofHplus_py=jet.py(); MatchJet_daughterQuarkofHplus_pz=jet.pz();
	MatchJet_daughterQuarkofHplus_p=sqrt(jet.px()*jet.px()+jet.py()*jet.py()+jet.pz()*jet.pz());
	MatchJet_daughterQuarkofHplus_E=jet.energy();
	MatchJet_daughterQuarkofHplus_bDiscrCSV=jet.bDiscriminator("combinedSecondaryVertexBJetTags");
       
	// isolation wrt other jets
	dr=99999;
	for(unsigned int ii=0; ii<handleJet_->size(); ii++){
		 iijet=handleJet_->at(ii);
	 if(ii!=ijet){
		   dr=deltaRjj(jet,iijet);
		   if(dr<MatchJet_daughterQuarkofHplus_deltaRj) MatchJet_daughterQuarkofHplus_deltaRj=dr;
	 }
	}
	
      }
 
	  if((*jmot).pdgId()==hadID && (*parton).pdgId()<0){
	  
	Hjets.push_back(jet); 
	//jetpdg.push_back((*parton).pdgId());
	//jetorder.push_back(ijet); 
	MatchJet_jetflag=MatchJet_jetflag+100*ijet;
	MatchJet_daughterQuarkBarofHplus_index=ijet;
	MatchJet_daughterQuarkBarofHplus_pt=jet.pt();
	MatchJet_daughterQuarkBarofHplus_recOverGenPt=jet.pt()/(*parton).pt();
	MatchJet_daughterQuarkBarofHplus_eta=jet.eta();
	MatchJet_daughterQuarkBarofHplus_phi=jet.phi();
	MatchJet_daughterQuarkBarofHplus_px=jet.px(); MatchJet_daughterQuarkBarofHplus_py=jet.py(); MatchJet_daughterQuarkBarofHplus_pz=jet.pz();
	MatchJet_daughterQuarkBarofHplus_p=sqrt(jet.px()*jet.px()+jet.py()*jet.py()+jet.pz()*jet.pz());
	MatchJet_daughterQuarkBarofHplus_E=jet.energy();
	MatchJet_daughterQuarkBarofHplus_bDiscrCSV=jet.bDiscriminator("combinedSecondaryVertexBJetTags");
       
	// isolation wrt other jets
	dr=99999;
	for(unsigned int ii=0; ii<handleJet_->size(); ii++){
		 iijet=handleJet_->at(ii);
	 if(ii!=ijet){
		   dr=deltaRjj(jet,iijet);
		   if(dr<MatchJet_daughterQuarkBarofHplus_deltaRj) MatchJet_daughterQuarkBarofHplus_deltaRj=dr;
	 }
	}
      
      }
	
	  if((*jmot).pdgId()==6){
	 tjetf=1;
	 Tbjet=jet;
	 
	//jetpdg.push_back((*parton).pdgId());
	//jetorder.push_back(ijet); 
	MatchJet_jetflag=MatchJet_jetflag+10*ijet;
	MatchJet_daughterQuarkofTop_index=ijet;
	MatchJet_daughterQuarkofTop_pt=jet.pt();
	MatchJet_daughterQuarkofTop_recOverGenPt=jet.pt()/(*parton).pt();
	MatchJet_daughterQuarkofTop_eta=jet.eta();
	MatchJet_daughterQuarkofTop_phi=jet.phi();
	MatchJet_daughterQuarkofTop_px=jet.px(); MatchJet_daughterQuarkofTop_py=jet.py(); MatchJet_daughterQuarkofTop_pz=jet.pz();
	MatchJet_daughterQuarkofTop_p=sqrt(jet.px()*jet.px()+jet.py()*jet.py()+jet.pz()*jet.pz());
	MatchJet_daughterQuarkofTop_E=jet.energy();
	MatchJet_daughterQuarkofTop_bDiscrCSV=jet.bDiscriminator("combinedSecondaryVertexBJetTags");
       
	// isolation wrt other jets
	dr=99999;
	for(unsigned int ii=0; ii<handleJet_->size(); ii++){
		 iijet=handleJet_->at(ii);
	 if(ii!=ijet){
		   dr=deltaRjj(jet,iijet);
		   if(dr<MatchJet_daughterQuarkofTop_deltaRj) MatchJet_daughterQuarkofTop_deltaRj=dr;
	 }
	}
       
       //Massa invariante tra gen H+ e jet proveniente da t 
		float jetTmass=(Tbjet.p4()+Hh.p4()).M();
	   MatchJet_Tmass=jetTmass; 
	float jet_formuleTmass=sqrt((Tbjet.energy()+Hh.energy())*(Tbjet.energy()+Hh.energy())
					    -(Tbjet.px()+Hh.px())*(Tbjet.px()+Hh.px())
					    -(Tbjet.py()+Hh.py())*(Tbjet.py()+Hh.py())
					    -(Tbjet.pz()+Hh.pz())*(Tbjet.pz()+Hh.pz())
				     );
				     
	   MatchJet_formule_Tmass=jet_formuleTmass; 
      
      }
       
	  if((*jmot).pdgId()==-6){
	  
	tbarjetf=1;
	MatchJet_jetflag=MatchJet_jetflag+ijet;
	MatchJet_daughterQuarkofTopBar_index=ijet;
	MatchJet_daughterQuarkofTopBar_pt=jet.pt();
	MatchJet_daughterQuarkofTopBar_recOverGenPt=jet.pt()/(*parton).pt();
	MatchJet_daughterQuarkofTopBar_eta=jet.eta();
	MatchJet_daughterQuarkofTopBar_phi=jet.phi();
	MatchJet_daughterQuarkofTopBar_px=jet.px(); MatchJet_daughterQuarkofTopBar_py=jet.py(); MatchJet_daughterQuarkofTopBar_pz=jet.pz();
	MatchJet_daughterQuarkofTopBar_p=sqrt(jet.px()*jet.px()+jet.py()*jet.py()+jet.pz()*jet.pz());
	MatchJet_daughterQuarkofTopBar_E=jet.energy();
	MatchJet_daughterQuarkofTopBar_bDiscrCSV=jet.bDiscriminator("combinedSecondaryVertexBJetTags");
       
	// isolation wrt other jets
	dr=99999;
	for(unsigned int ii=0; ii<handleJet_->size(); ii++){
		 iijet=handleJet_->at(ii);
	 if(ii!=ijet){
		   dr=deltaRjj(jet,iijet);
		   if(dr<MatchJet_daughterQuarkofTopBar_deltaRj) MatchJet_daughterQuarkofTopBar_deltaRj=dr;
	 }
	}
      
      }
  
       }//end if mot  
	}//end if parton
  
     } //end loop on jets
    
     //fill invariant masses
     if(Hjets.size()==2){
	float jetHmass=(Hjets[0].p4()+Hjets[1].p4()).M();
	MatchJet_Hmass=jetHmass; 
      }
      
     if(Hjets.size()+tbarjetf+tjetf!=4) MatchJet_jetflag=99999;
    
    //********************************************************************************isolamento dal muone  
     if(nMuon>0){
	mu = handleMuon_->at(0);
	firstMuon=mu;
    
     
      for(unsigned int mm=0; mm<handleJet_->size(); mm++){
	mj=handleJet_->at(mm);
	dr=deltaR(firstMuon,mj);
	//isolation of the four matched jets
      
	if(mm==MatchJet_daughterQuarkofHplus_index){
       drj=deltaR(firstMuon,mj);
       if(drj<MatchJet_daughterQuarkofHplus_deltaRmu) MatchJet_daughterQuarkofHplus_deltaRmu=drj;
	  drj=9999;
	}
      
	if(mm==MatchJet_daughterQuarkBarofHplus_index){
       drj=deltaR(firstMuon,mj);
       if(drj<MatchJet_daughterQuarkBarofHplus_deltaRmu) MatchJet_daughterQuarkBarofHplus_deltaRmu=drj;
	  drj=9999;
	}
      if(mm==MatchJet_daughterQuarkofTop_index){
       drj=deltaR(firstMuon,mj);
       if(drj<MatchJet_daughterQuarkofTop_deltaRmu) MatchJet_daughterQuarkofTop_deltaRmu=drj;
	  drj=9999;
	}
      if(mm==MatchJet_daughterQuarkofTopBar_index){
       drj=deltaR(firstMuon,mj);
       if(drj<MatchJet_daughterQuarkofTopBar_deltaRmu) MatchJet_daughterQuarkofTopBar_deltaRmu=drj;
	  drj=9999;
	}
  }
  } //end c'è almeno un muone  

} //end if MCsignal or MCttbar

//___________________________________________________________________________________________

 if(nMuon>0){
      mu = handleMuon_->at(0);
        firstMuon=mu;
	muflag=1;
  }
  else goto fill;
  
  vertex = handleVertex_->at(0);
  nVertex= handleVertex_->size();
  
   //se non ci sono muoni si passa al prossimo evento
     if(muflag==0){
      goodEvent=0;
      goto fill;
    }
     
   //parametri 
   MUpt = firstMuon.pt(); MUeta = firstMuon.eta(); MUphi = firstMuon.phi();
   MUtheta = firstMuon.theta(); 
   MUpx = firstMuon.px(); MUpy  = firstMuon.py();  MUpz  = firstMuon.pz(); 
   MUp = sqrt(MUpx*MUpx+MUpy*MUpy+MUpz*MUpz);

   //parameter for isolation cuts
   chargedIso = firstMuon.pfIsolationR04().sumChargedHadronPt;
   neutralIso = firstMuon.pfIsolationR04().sumNeutralHadronEt;
   photonIso = firstMuon.pfIsolationR04().sumPhotonEt;
   MUrelIso = (chargedIso + max(0., neutralIso + photonIso - 0.5 * firstMuon.pfIsolationR04().sumPUPt) ) /  MUpt; 

//INNER TRACK
  if(!firstMuon.innerTrack().isNull()){ 
   MUlayer = firstMuon.innerTrack()->hitPattern().trackerLayersWithMeasurement();
    MUnOfPixels= firstMuon.innerTrack()->hitPattern().numberOfValidPixelHits();
 } 
 else {
    MUlayer = -1;
    MUnOfPixels= -1;
 }
 //GLOBAL TRACK
  if(!firstMuon.globalTrack().isNull()){ 
      MUnormChi2=firstMuon.globalTrack()->normalizedChi2();
      MUnOfHits=firstMuon.globalTrack()->hitPattern().numberOfValidMuonHits();
  }
  else {
     MUnormChi2=-1;
     MUnOfHits=-1;
  }
    MUd0=fabs(firstMuon.dB());
//BEST TRACK
  if(!firstMuon.muonBestTrack().isNull()){ 
//    MUd0=fabs(firstMuon.muonBestTrack()->dxy(vertex.position()));
    MUdz=fabs(firstMuon.muonBestTrack()->dz(vertex.position()));
  } 
  else {
    cout<<"NO BEST TRACK"<<endl;
    MUd0=-1;
    MUdz=-1;
  }
  
     MUisGlobal=  firstMuon.isGlobalMuon();
     MUisPF=  firstMuon.isPFMuon();
     MUstations=  firstMuon.numberOfMatchedStations();
 
 //--------------------------------------------------------------------------jets

  
 //   if(handleJet_->size()<4) {
 //     goodEvent=0;
  //    goto fill;
  //  }
 
 realnJet= handleJet_->size();
 nbJet= handlebJet_->size();
 nbJetloose= handleloosebJet_->size();
  
 for(unsigned int l = 0; l< handleJet_->size(); l++){ 
   jet=handleJet_->at(l);
   Jpt.push_back(jet.pt()); Jeta.push_back(jet.eta()); Jphi.push_back(jet.phi());
   Jtheta.push_back(jet.theta());
   Jpx.push_back(jet.px()); Jpy.push_back(jet.py()); Jpz.push_back(jet.pz());
   Jp.push_back( sqrt(jet.px()*jet.px()+jet.py()*jet.py()+jet.pz()*jet.pz()));
   JbDiscr.push_back(jet.bDiscriminator("combinedSecondaryVertexBJetTags")); 
   Jcharge.push_back(jet.jetCharge());
   Jenergy.push_back(jet.energy());
   Jflavor.push_back(jet.partonFlavour());
 } 
  
 //--------------------------------------------------------------------------MET
   if(handleMET_->size()>0){
     met = handleMET_->at(0);
     METpt = met.pt(); METpx = met.px(); METpy = met.py();
     METeta = met.eta(); METphi = met.phi();
     METtheta = met.theta(); 
   }
   else goto fill;

fill:
//___________________________________________________________________________________________

 //cout<<"stepFlag_"<<stepFlag_<<" sampleFlag_"<<sampleFlag_<<endl;
  if  (stepFlag_=="8b" || stepFlag_=="9"|| stepFlag_=="9b" ) { 
  
 // cout<<"kinfit"<<endl;
  
  edm::Handle<TtSemiLeptonicEvent> semiLepEvt;
  iEvent.getByLabel("ttSemiLepEvent", semiLepEvt);

  ncomb= semiLepEvt->numberOfAvailableHypos("kKinFit");
  
  //cout<<"ncomb"<<ncomb<<endl;
  
  unsigned int limit= (unsigned int) MaxComb; 
  if (ncomb < MaxComb) limit= (unsigned int) ncomb; 
   
  // cout<<"ncomb"<<ncomb<<"limit"<< limit <<endl;
  
   for (unsigned int h = 0; h < limit; ++h) {
    if (!semiLepEvt->isHypoValid("kKinFit", h)) break;
   
  
    {
   
   KinFit_isValid=1;

   KinFit_chi2[h]=semiLepEvt->fitChi2(h);
   KinFit_prob[h]=semiLepEvt->fitProb(h);
  
   KinFit_lightP_index[h]=semiLepEvt->jetLeptonCombination("kKinFit",h)[0];
   KinFit_lightQ_index[h]=semiLepEvt->jetLeptonCombination("kKinFit",h)[1];
   KinFit_hadB_index[h]=semiLepEvt->jetLeptonCombination("kKinFit",h)[2];
   KinFit_lepB_index[h]=semiLepEvt->jetLeptonCombination("kKinFit",h)[3];
   KinFit_lepton_index[h]=semiLepEvt->jetLeptonCombination("kKinFit",h)[4];
   
   KinFit_lepTop=semiLepEvt->leptonicDecayTop("kKinFit",h);
   KinFit_lepW=semiLepEvt->leptonicDecayW("kKinFit",h);
   KinFit_hadTop=semiLepEvt->hadronicDecayTop("kKinFit",h);
   KinFit_hadW=semiLepEvt->hadronicDecayW("kKinFit",h);
   KinFit_hadQuark=semiLepEvt->hadronicDecayQuark("kKinFit",h);
   KinFit_hadQuarkBar=semiLepEvt->hadronicDecayQuarkBar("kKinFit",h);
   KinFit_hadB=semiLepEvt->hadronicDecayB("kKinFit",h);
   KinFit_lepB=semiLepEvt->leptonicDecayB("kKinFit",h);
  
   KinFit_hadW_mass[h]=KinFit_hadW->mass(); KinFit_hadW_pt[h]=KinFit_hadW->pt(); KinFit_hadW_eta[h]=KinFit_hadW->eta();
   KinFit_hadW_phi[h]=KinFit_hadW->phi();
   KinFit_hadW_px[h]=KinFit_hadW->px(); KinFit_hadW_py[h]=KinFit_hadW->py();
   KinFit_hadW_pz[h]=KinFit_hadW->pz();KinFit_hadW_energy[h]=KinFit_hadW->energy();
  
   KinFit_lepW_mass[h]=KinFit_lepW->mass(); KinFit_lepW_pt[h]=KinFit_lepW->pt(); KinFit_lepW_eta[h]=KinFit_lepW->eta();
   KinFit_lepW_phi[h]=KinFit_lepW->phi();
   KinFit_lepW_px[h]=KinFit_lepW->px(); KinFit_lepW_py[h]=KinFit_lepW->py();
   KinFit_lepW_energy[h]=KinFit_lepW->energy();KinFit_lepW_pz[h]=KinFit_lepW->pz();
   
   KinFit_hadTop_mass[h]=KinFit_hadTop->mass(); KinFit_hadTop_pt[h]=KinFit_hadTop->pt(); KinFit_hadTop_eta[h]=KinFit_hadTop->eta();
   KinFit_hadTop_phi[h]=KinFit_hadTop->phi();
   KinFit_hadTop_px[h]=KinFit_hadTop->px(); KinFit_hadTop_py[h]=KinFit_hadTop->py();
   KinFit_hadTop_energy[h]=KinFit_hadTop->energy();KinFit_hadTop_pz[h]=KinFit_hadTop->pz();

   KinFit_lepTop_mass[h]=KinFit_lepTop->mass(); KinFit_lepTop_pt[h]=KinFit_lepTop->pt(); KinFit_lepTop_eta[h]=KinFit_lepTop->eta();
   KinFit_lepTop_phi[h]=KinFit_lepTop->phi();
   KinFit_lepTop_px[h]=KinFit_lepTop->px(); KinFit_lepTop_py[h]=KinFit_lepTop->py();
   KinFit_lepTop_pz[h]=KinFit_lepTop->pz();KinFit_lepTop_energy[h]=KinFit_lepTop->energy();

   KinFit_hadQuark_pt[h]=KinFit_hadQuark->pt();KinFit_hadQuark_eta[h]=KinFit_hadQuark->eta(); KinFit_hadQuark_phi[h]=KinFit_hadQuark->phi();
   KinFit_hadQuark_px[h]=KinFit_hadQuark->px();KinFit_hadQuark_py[h]=KinFit_hadQuark->py();KinFit_hadQuark_pz[h]=KinFit_hadQuark->pz();
   KinFit_hadQuark_energy[h]=KinFit_hadQuark->energy();
  
  
KinFit_hadQuarkBar_pt[h]=KinFit_hadQuarkBar->pt(); KinFit_hadQuarkBar_eta[h]=KinFit_hadQuarkBar->eta(); KinFit_hadQuarkBar_phi[h]=KinFit_hadQuarkBar->phi();
   KinFit_hadQuarkBar_px[h]=KinFit_hadQuarkBar->px();KinFit_hadQuarkBar_py[h]=KinFit_hadQuarkBar->py();
   KinFit_hadQuarkBar_pz[h]=KinFit_hadQuarkBar->pz();KinFit_hadQuarkBar_energy[h]=KinFit_hadQuarkBar->energy();
  
   KinFit_hadB_pt[h]=KinFit_hadB->pt(); KinFit_hadB_eta[h]=KinFit_hadB->eta(); KinFit_hadB_phi[h]=KinFit_hadB->phi();
   KinFit_hadB_px[h]=KinFit_hadB->px(); KinFit_hadB_py[h]=KinFit_hadB->py();
   KinFit_hadB_pz[h]=KinFit_hadB->pz(); KinFit_hadB_energy[h]=KinFit_hadB->energy();
  
   KinFit_lepB_pt[h]=KinFit_lepB->pt(); KinFit_lepB_eta[h]=KinFit_lepB->eta(); KinFit_lepB_phi[h]=KinFit_lepB->phi();
   KinFit_lepB_px[h]=KinFit_lepB->px(); KinFit_lepB_py[h]=KinFit_lepB->py();
   KinFit_lepB_pz[h]=KinFit_lepB->pz(); KinFit_lepB_energy[h]=KinFit_lepB->energy();

   //cout<<"massa Higgs "<< KinFit_hadW_mass[h]<<" "<<KinFit_prob[h]<<" "<<KinFit_chi2[h]<<endl;
} 
 } 
  }
 

//___________________________________________________________________________________________

//PU REWEIGHTING

if ( sampleFlag_!="Data"){

 edm::LumiReWeighting LumiWeights_;
 edm::LumiReWeighting LumiWeights_up_;
 edm::LumiReWeighting LumiWeights_down_;
 std::vector< float > Summer2012 ;




 Double_t Summer2012_S10[60] = {
                         2.560E-06,
                         5.239E-06,
                         1.420E-05,
                         5.005E-05,
                         1.001E-04,
                         2.705E-04,
                         1.999E-03,
                         6.097E-03,
                         1.046E-02,
                         1.383E-02,
                         1.685E-02,
                         2.055E-02,
                         2.572E-02,
                         3.262E-02,
                         4.121E-02,
                         4.977E-02,
                         5.539E-02,
                         5.725E-02,
                         5.607E-02,
                         5.312E-02,
                         5.008E-02,
                         4.763E-02,
                         4.558E-02,
                         4.363E-02,
                         4.159E-02,
                         3.933E-02,
                         3.681E-02,
                         3.406E-02,
                         3.116E-02,
                         2.818E-02,
                         2.519E-02,
                         2.226E-02,
                         1.946E-02,
                         1.682E-02,
                         1.437E-02,
                         1.215E-02,
                         1.016E-02,
                         8.400E-03,
                         6.873E-03,
                         5.564E-03,
                         4.457E-03,
                         3.533E-03,
                         2.772E-03,
                         2.154E-03,
                         1.656E-03,
                         1.261E-03,
                         9.513E-04,
                         7.107E-04,
                         5.259E-04,
                         3.856E-04,
                         2.801E-04,
                         2.017E-04,
                         1.439E-04,
                         1.017E-04,
                         7.126E-05,
                         4.948E-05,
                         3.405E-05,
                         2.322E-05,
                         1.570E-05,
                         5.005E-06};

			 
std::vector< float > TrueDist2011;
std::vector< float > TrueDist2011_up;
std::vector< float > TrueDist2011_down;

    double TrueDist2011_f[60] = {
13531.5    ,
21824.9    ,
41057.6    ,
249375     ,
556933     ,
3.64488e+06,
2.02449e+07,
6.09322e+07,
1.43044e+08,
2.7625e+08 ,
4.71757e+08,
7.05494e+08,
8.86931e+08,
9.95894e+08,
1.06996e+09,
1.12383e+09,
1.15144e+09,
1.15618e+09,
1.15047e+09,
1.13586e+09,
1.11175e+09,
1.08239e+09,
1.05025e+09,
1.00951e+09,
9.5004e+08 ,
8.65895e+08,
7.60206e+08,
6.42339e+08,
5.22345e+08,
4.08583e+08,
3.07365e+08,
2.2243e+08 ,
1.54751e+08,
1.03333e+08,
6.61609e+07,
4.07415e+07,
2.43881e+07,
1.45026e+07,
8.86007e+06,
5.77937e+06,
4.13131e+06,
3.2326e+06 ,
2.70553e+06,
2.35647e+06,
2.09245e+06,
1.87106e+06,
1.67367e+06,
1.49242e+06,
1.32409e+06,
1.16753e+06,
1.02242e+06,
888685	   ,
766329	   ,
655326	   ,
555551	   ,
466746	   ,
388511	   ,
320315	   ,
261513	   ,
211371};

   double TrueDist2011_f_up[60] = {
12736	    ,
19974.4     ,
34759.7     ,
168674	    ,
485192	    ,
1.85955e+06 ,
1.23813e+07 ,
4.04781e+07 ,
9.876e+07   ,
1.99124e+08 ,
3.47748e+08 ,
5.50648e+08 ,
7.51601e+08 ,
8.88181e+08 ,
9.72565e+08 ,
1.03453e+09 ,
1.07834e+09 ,
1.0986e+09  ,
1.10089e+09 ,
1.09504e+09 ,
1.08136e+09 ,
1.05945e+09 ,
1.03293e+09 ,
1.00416e+09 ,
9.6895e+08  ,
9.18937e+08 ,
8.47995e+08 ,
7.56927e+08 ,
6.52564e+08 ,
5.43409e+08 ,
4.36934e+08 ,
3.39091e+08 ,
2.54039e+08 ,
1.83728e+08 ,
1.28143e+08 ,
8.60594e+07 ,
5.565e+07   ,
3.47935e+07 ,
2.12705e+07 ,
1.29822e+07 ,
8.15438e+06 ,
5.4492e+06  ,
3.95905e+06 ,
3.12366e+06 ,
2.62441e+06 ,
2.2921e+06  ,
2.04219e+06 ,
1.8344e+06  ,
1.65022e+06 ,
1.48144e+06 ,
1.3245e+06  ,
1.17798e+06 ,
1.04144e+06 ,
914731	    ,
797852	    ,
690802	    ,
593533	    ,
505909	    ,
427683	    ,
358500
};

    double TrueDist2011_f_down[60] = {
14431.4      ,
24008.9      ,
50968.8      ,
348054	     ,
756612	     ,
7.02321e+06  ,
3.24722e+07  ,
9.23709e+07  ,
2.06558e+08  ,
3.85003e+08  ,
6.33725e+08  ,
8.6826e+08   ,
1.01498e+09  ,
1.10577e+09  ,
1.17167e+09  ,
1.20875e+09  ,
1.21716e+09  ,
1.21175e+09  ,
1.19614e+09  ,
1.16947e+09  ,
1.13681e+09  ,
1.10058e+09  ,
1.05278e+09  ,
9.81329e+08  ,
8.81134e+08  ,
7.58614e+08  ,
6.26029e+08  ,
4.95049e+08  ,
3.74918e+08  ,
2.71971e+08  ,
1.88961e+08  ,
1.25551e+08  ,
7.96347e+07  ,
4.83004e+07  ,
2.82864e+07  ,
1.63559e+07  ,
9.69034e+06  ,
6.15218e+06  ,
4.3194e+06   ,
3.34989e+06  ,
2.79249e+06  ,
2.42473e+06  ,
2.1445e+06   ,
1.90739e+06  ,
1.69488e+06  ,
1.49956e+06  ,
1.31861e+06  ,
1.15116e+06  ,
997009	     ,
856125	     ,
728504	     ,
614043	     ,
512478	     ,
423365	     ,
346083	     ,
279862	     ,
223812	     ,
176962	     ,
138301	     ,
106809};
   
    
    
    
    for( int i=0; i<60; ++i) {
      TrueDist2011.push_back(TrueDist2011_f[i]);
      TrueDist2011_up.push_back(TrueDist2011_f_up[i]);
      TrueDist2011_down.push_back(TrueDist2011_f_down[i]);
      Summer2012.push_back(Summer2012_S10[i]);
    }

    LumiWeights_ = edm::LumiReWeighting(Summer2012, TrueDist2011); 
    LumiWeights_up_ = edm::LumiReWeighting(Summer2012, TrueDist2011_up); 
    LumiWeights_down_ = edm::LumiReWeighting(Summer2012, TrueDist2011_down); 
    
 
    
    Handle<std::vector< PileupSummaryInfo > >  PupInfo;
 iEvent.getByLabel(edm::InputTag("addPileupInfo"), PupInfo);

 std::vector<PileupSummaryInfo>::const_iterator PVI;

 for(PVI = PupInfo->begin(); PVI != PupInfo->end(); ++PVI) {

   BX = PVI->getBunchCrossing();

   if(BX == 0) { 
     Tnpv = PVI->getTrueNumInteractions();
     continue;
   }

} 

 lumiWeight = LumiWeights_.weight( Tnpv );
 lumiWeight_up = LumiWeights_up_.weight( Tnpv );
 lumiWeight_down = LumiWeights_down_.weight( Tnpv );
 nSimVertex = Tnpv;
 


} 



//___________________________________________________________________________________________


  HplusTree->Fill();
//  HplusGenPartTree->Print();
 
 


#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void 
HplusAnalyzer::beginJob()
{
      //external functions:
      std::vector<float> nuPz(float, float, float, float, float, float);
      edm::Service<TFileService> fs;
      
      HplusTree = fs->make<TTree>("HplusGenPartTree","HplusGenPartTree");
 
      HplusTree->Branch("run",&run,"run/I");
      HplusTree->Branch("luminosityBlock",&luminosityBlock,"luminosityBlock/I");
      HplusTree->Branch("event",&event,"event/I");

      HplusTree->Branch("lumiWeight",&lumiWeight,"lumiWeight/D");
      HplusTree->Branch("lumiWeight_up",&lumiWeight_up,"lumiWeight_up/D");
      HplusTree->Branch("lumiWeight_down",&lumiWeight_down,"lumiWeight_down/D");
     
      HplusTree->Branch("GenPart_daughterQuarkofTop_pdgId",&GenPart_daughterQuarkofTop_pdgId, "GenPart_daughterQuarkofTop_pdgId/I");
      HplusTree->Branch("GenPart_daughterQuarkofTop_pt",&GenPart_daughterQuarkofTop_pt, "GenPart_daughterQuarkofTop_pt/F");
      HplusTree->Branch("GenPart_daughterQuarkofTop_eta",&GenPart_daughterQuarkofTop_eta, "GenPart_daughterQuarkofTop_eta/F");
      HplusTree->Branch("GenPart_daughterQuarkofTop_phi",&GenPart_daughterQuarkofTop_phi, "GenPart_daughterQuarkofTop_phi/F");
      HplusTree->Branch("GenPart_daughterQuarkofTop_p",&GenPart_daughterQuarkofTop_p, "GenPart_daughterQuarkofTop_p/F");
      HplusTree->Branch("GenPart_daughterQuarkofTop_px",&GenPart_daughterQuarkofTop_px, "GenPart_daughterQuarkofTop_px/F");
      HplusTree->Branch("GenPart_daughterQuarkofTop_py",&GenPart_daughterQuarkofTop_py, "GenPart_daughterQuarkofTop_py/F");
      HplusTree->Branch("GenPart_daughterQuarkofTop_pz",&GenPart_daughterQuarkofTop_pz, "GenPart_daughterQuarkofTop_pz/F");
      HplusTree->Branch("GenPart_daughterQuarkofTop_E",&GenPart_daughterQuarkofTop_E, "GenPart_daughterQuarkofTop_E/F");
      HplusTree->Branch("GenPart_daughterQuarkofTop_mass",&GenPart_daughterQuarkofTop_mass, "GenPart_daughterQuarkofTop_mass/F");
   
      HplusTree->Branch("GenPart_daughterQuarkofTopBar_pdgId",&GenPart_daughterQuarkofTopBar_pdgId, "GenPart_daughterQuarkofTopBar_pdgId/I");
      HplusTree->Branch("GenPart_daughterQuarkofTopBar_pt",&GenPart_daughterQuarkofTopBar_pt, "GenPart_daughterQuarkofTopBar_pt/F");
      HplusTree->Branch("GenPart_daughterQuarkofTopBar_eta",&GenPart_daughterQuarkofTopBar_eta, "GenPart_daughterQuarkofTopBar_eta/F");
      HplusTree->Branch("GenPart_daughterQuarkofTopBar_phi",&GenPart_daughterQuarkofTopBar_phi, "GenPart_daughterQuarkofTopBar_phi/F");
      HplusTree->Branch("GenPart_daughterQuarkofTopBar_p",&GenPart_daughterQuarkofTopBar_p, "GenPart_daughterQuarkofTopBar_p/F");
      HplusTree->Branch("GenPart_daughterQuarkofTopBar_px",&GenPart_daughterQuarkofTopBar_px, "GenPart_daughterQuarkofTopBar_px/F");
      HplusTree->Branch("GenPart_daughterQuarkofTopBar_py",&GenPart_daughterQuarkofTopBar_py, "GenPart_daughterQuarkofTopBar_py/F");
      HplusTree->Branch("GenPart_daughterQuarkofTopBar_pz",&GenPart_daughterQuarkofTopBar_pz, "GenPart_daughterQuarkofTopBar_pz/F");
      HplusTree->Branch("GenPart_daughterQuarkofTopBar_E",&GenPart_daughterQuarkofTopBar_E, "GenPart_daughterQuarkofTopBar_E/F");
      HplusTree->Branch("GenPart_daughterQuarkofTopBar_mass",&GenPart_daughterQuarkofTopBar_mass, "GenPart_daughterQuarkofTopBar_mass/F");
     
      HplusTree->Branch("GenPart_daughterQuarkBarofWMinus_pdgId",&GenPart_daughterQuarkBarofWMinus_pdgId, "GenPart_daughterQuarkBarofWMinus_pdgId/I");
      HplusTree->Branch("GenPart_daughterQuarkBarofWMinus_pt",&GenPart_daughterQuarkBarofWMinus_pt, "GenPart_daughterQuarkBarofWMinus_pt/F");
      HplusTree->Branch("GenPart_daughterQuarkBarofWMinus_eta",&GenPart_daughterQuarkBarofWMinus_eta, "GenPart_daughterQuarkBarofWMinus_eta/F");
      HplusTree->Branch("GenPart_daughterQuarkBarofWMinus_phi",&GenPart_daughterQuarkBarofWMinus_phi, "GenPart_daughterQuarkBarofWMinus_phi/F");
      HplusTree->Branch("GenPart_daughterQuarkBarofWMinus_p",&GenPart_daughterQuarkBarofWMinus_p, "GenPart_daughterQuarkBarofWMinus_p/F");
      HplusTree->Branch("GenPart_daughterQuarkBarofWMinus_px",&GenPart_daughterQuarkBarofWMinus_px, "GenPart_daughterQuarkBarofWMinus_px/F");
      HplusTree->Branch("GenPart_daughterQuarkBarofWMinus_py",&GenPart_daughterQuarkBarofWMinus_py, "GenPart_daughterQuarkBarofWMinus_py/F");
      HplusTree->Branch("GenPart_daughterQuarkBarofWMinus_pz",&GenPart_daughterQuarkBarofWMinus_pz, "GenPart_daughterQuarkBarofWMinus_pz/F");
      HplusTree->Branch("GenPart_daughterQuarkBarofWMinus_E",&GenPart_daughterQuarkBarofWMinus_E, "GenPart_daughterQuarkBarofWMinus_E/F");
      HplusTree->Branch("GenPart_daughterQuarkBarofWMinus_mass",&GenPart_daughterQuarkBarofWMinus_mass, "GenPart_daughterQuarkBarofWMinus_mass/F");
    
      HplusTree->Branch("GenPart_daughterQuarkofWMinus_pdgId",&GenPart_daughterQuarkofWMinus_pdgId, "GenPart_daughterQuarkofWMinus_pdgId/I");
      HplusTree->Branch("GenPart_daughterQuarkofWMinus_pt",&GenPart_daughterQuarkofWMinus_pt, "GenPart_daughterQuarkofWMinus_pt/F");
      HplusTree->Branch("GenPart_daughterQuarkofWMinus_eta",&GenPart_daughterQuarkofWMinus_eta, "GenPart_daughterQuarkofWMinus_eta/F");
      HplusTree->Branch("GenPart_daughterQuarkofWMinus_phi",&GenPart_daughterQuarkofWMinus_phi, "GenPart_daughterQuarkofWMinus_phi/F");
      HplusTree->Branch("GenPart_daughterQuarkofWMinus_p",&GenPart_daughterQuarkofWMinus_p, "GenPart_daughterQuarkofWMinus_p/F");
      HplusTree->Branch("GenPart_daughterQuarkofWMinus_px",&GenPart_daughterQuarkofWMinus_px, "GenPart_daughterQuarkofWMinus_px/F");
      HplusTree->Branch("GenPart_daughterQuarkofWMinus_py",&GenPart_daughterQuarkofWMinus_py, "GenPart_daughterQuarkofWMinus_py/F");
      HplusTree->Branch("GenPart_daughterQuarkofWMinus_pz",&GenPart_daughterQuarkofWMinus_pz, "GenPart_daughterQuarkofWMinus_pz/F");
      HplusTree->Branch("GenPart_daughterQuarkofWMinus_E",&GenPart_daughterQuarkofWMinus_E, "GenPart_daughterQuarkofWMinus_E/F");
      HplusTree->Branch("GenPart_daughterQuarkofWMinus_mass",&GenPart_daughterQuarkofWMinus_mass, "GenPart_daughterQuarkofWMinus_mass/F");
    
      HplusTree->Branch("GenPart_daughterQuarkBarofHplus_pdgId",&GenPart_daughterQuarkBarofHplus_pdgId, "GenPart_daughterQuarkBarofHplus_pdgId/I");
      HplusTree->Branch("GenPart_daughterQuarkBarofHplus_pt",&GenPart_daughterQuarkBarofHplus_pt, "GenPart_daughterQuarkBarofHplus_pt/F");
      HplusTree->Branch("GenPart_daughterQuarkBarofHplus_eta",&GenPart_daughterQuarkBarofHplus_eta, "GenPart_daughterQuarkBarofHplus_eta/F");
      HplusTree->Branch("GenPart_daughterQuarkBarofHplus_phi",&GenPart_daughterQuarkBarofHplus_phi, "GenPart_daughterQuarkBarofHplus_phi/F");
      HplusTree->Branch("GenPart_daughterQuarkBarofHplus_p",&GenPart_daughterQuarkBarofHplus_p, "GenPart_daughterQuarkBarofHplus_p/F");
      HplusTree->Branch("GenPart_daughterQuarkBarofHplus_px",&GenPart_daughterQuarkBarofHplus_px, "GenPart_daughterQuarkBarofHplus_px/F");
      HplusTree->Branch("GenPart_daughterQuarkBarofHplus_py",&GenPart_daughterQuarkBarofHplus_py, "GenPart_daughterQuarkBarofHplus_py/F");
      HplusTree->Branch("GenPart_daughterQuarkBarofHplus_pz",&GenPart_daughterQuarkBarofHplus_pz, "GenPart_daughterQuarkBarofHplus_pz/F");
      HplusTree->Branch("GenPart_daughterQuarkBarofHplus_E",&GenPart_daughterQuarkBarofHplus_E, "GenPart_daughterQuarkBarofHplus_E/F");
      HplusTree->Branch("GenPart_daughterQuarkBarofHplus_mass",&GenPart_daughterQuarkBarofHplus_mass, "GenPart_daughterQuarkBarofHplus_mass/F");
    
      HplusTree->Branch("GenPart_daughterQuarkofHplus_pdgId",&GenPart_daughterQuarkofHplus_pdgId, "GenPart_daughterQuarkofHplus_pdgId/I");
      HplusTree->Branch("GenPart_daughterQuarkofHplus_pt",&GenPart_daughterQuarkofHplus_pt, "GenPart_daughterQuarkofHplus_pt/F");
      HplusTree->Branch("GenPart_daughterQuarkofHplus_eta",&GenPart_daughterQuarkofHplus_eta, "GenPart_daughterQuarkofHplus_eta/F");
      HplusTree->Branch("GenPart_daughterQuarkofHplus_phi",&GenPart_daughterQuarkofHplus_phi, "GenPart_daughterQuarkofHplus_phi/F");
      HplusTree->Branch("GenPart_daughterQuarkofHplus_p",&GenPart_daughterQuarkofHplus_p, "GenPart_daughterQuarkofHplus_p/F");
      HplusTree->Branch("GenPart_daughterQuarkofHplus_px",&GenPart_daughterQuarkofHplus_px, "GenPart_daughterQuarkofHplus_px/F");
      HplusTree->Branch("GenPart_daughterQuarkofHplus_py",&GenPart_daughterQuarkofHplus_py, "GenPart_daughterQuarkofHplus_py/F");
      HplusTree->Branch("GenPart_daughterQuarkofHplus_pz",&GenPart_daughterQuarkofHplus_pz, "GenPart_daughterQuarkofHplus_pz/F");
      HplusTree->Branch("GenPart_daughterQuarkofHplus_E",&GenPart_daughterQuarkofHplus_E, "GenPart_daughterQuarkofHplus_E/F");
      HplusTree->Branch("GenPart_daughterQuarkofHplus_mass",&GenPart_daughterQuarkofHplus_mass, "GenPart_daughterQuarkofHplus_mass/F");
    
      HplusTree->Branch("GenPart_lepton_pdgId",&GenPart_lepton_pdgId, "GenPart_lepton_pdgId/I");
      HplusTree->Branch("GenPart_lepton_pt",&GenPart_lepton_pt, "GenPart_lepton_pt/F");
      HplusTree->Branch("GenPart_lepton_eta",&GenPart_lepton_eta, "GenPart_lepton_eta/F");
      HplusTree->Branch("GenPart_lepton_phi",&GenPart_lepton_phi, "GenPart_lepton_phi/F");
      HplusTree->Branch("GenPart_lepton_p",&GenPart_lepton_p, "GenPart_lepton_p/F");
      HplusTree->Branch("GenPart_lepton_px",&GenPart_lepton_px, "GenPart_lepton_px/F");
      HplusTree->Branch("GenPart_lepton_py",&GenPart_lepton_py, "GenPart_lepton_py/F");
      HplusTree->Branch("GenPart_lepton_pz",&GenPart_lepton_pz, "GenPart_lepton_pz/F");
      HplusTree->Branch("GenPart_lepton_E",&GenPart_lepton_E, "GenPart_lepton_E/F");
      HplusTree->Branch("GenPart_lepton_mass",&GenPart_lepton_mass, "GenPart_lepton_mass/F");
  
      HplusTree->Branch("GenPart_neutrinoBar_pdgId",&GenPart_neutrinoBar_pdgId, "GenPart_neutrinoBar_pdgId/I");
      HplusTree->Branch("GenPart_neutrinoBar_pt",&GenPart_neutrinoBar_pt, "GenPart_neutrinoBar_pt/F");
      HplusTree->Branch("GenPart_neutrinoBar_eta",&GenPart_neutrinoBar_eta, "GenPart_neutrinoBar_eta/F");
      HplusTree->Branch("GenPart_neutrinoBar_phi",&GenPart_neutrinoBar_phi, "GenPart_neutrinoBar_phi/F");
      HplusTree->Branch("GenPart_neutrinoBar_p",&GenPart_neutrinoBar_p, "GenPart_neutrinoBar_p/F");
      HplusTree->Branch("GenPart_neutrinoBar_px",&GenPart_neutrinoBar_px, "GenPart_neutrinoBar_px/F");
      HplusTree->Branch("GenPart_neutrinoBar_py",&GenPart_neutrinoBar_py, "GenPart_neutrinoBar_py/F");
      HplusTree->Branch("GenPart_neutrinoBar_pz",&GenPart_neutrinoBar_pz, "GenPart_neutrinoBar_pz/F");
      HplusTree->Branch("GenPart_neutrinoBar_E",&GenPart_neutrinoBar_E, "GenPart_neutrinoBar_E/F");
  
      HplusTree->Branch("GenPart_top_pt",&GenPart_top_pt, "GenPart_top_pt/F");
      HplusTree->Branch("GenPart_top_eta",&GenPart_top_eta, "GenPart_top_eta/F");
      HplusTree->Branch("GenPart_top_phi",&GenPart_top_phi, "GenPart_top_phi/F");
      HplusTree->Branch("GenPart_top_p",&GenPart_top_p, "GenPart_top_p/F");
      HplusTree->Branch("GenPart_top_px",&GenPart_top_px, "GenPart_top_px/F");
      HplusTree->Branch("GenPart_top_py",&GenPart_top_py, "GenPart_top_py/F");
      HplusTree->Branch("GenPart_top_pz",&GenPart_top_pz, "GenPart_top_pz/F");
      HplusTree->Branch("GenPart_top_E",&GenPart_top_E, "GenPart_top_E/F");
      HplusTree->Branch("GenPart_top_mass",&GenPart_top_mass, "GenPart_top_mass/F");
    
      HplusTree->Branch("GenPart_topBar_pt",&GenPart_topBar_pt, "GenPart_topBar_pt/F");
      HplusTree->Branch("GenPart_topBar_eta",&GenPart_topBar_eta, "GenPart_topBar_eta/F");
      HplusTree->Branch("GenPart_topBar_phi",&GenPart_topBar_phi, "GenPart_topBar_phi/F");
      HplusTree->Branch("GenPart_topBar_p",&GenPart_topBar_p, "GenPart_topBar_p/F");
      HplusTree->Branch("GenPart_topBar_px",&GenPart_topBar_px, "GenPart_topBar_px/F");
      HplusTree->Branch("GenPart_topBar_py",&GenPart_topBar_py, "GenPart_topBar_py/F");
      HplusTree->Branch("GenPart_topBar_pz",&GenPart_topBar_pz, "GenPart_topBar_pz/F");
      HplusTree->Branch("GenPart_topBar_E",&GenPart_topBar_E, "GenPart_topBar_E/F");
      HplusTree->Branch("GenPart_topBar_mass",&GenPart_topBar_mass, "GenPart_topBar_mass/F");
   
      HplusTree->Branch("GenPart_WMinus_pt",&GenPart_WMinus_pt, "GenPart_WMinus_pt/F");
      HplusTree->Branch("GenPart_WMinus_eta",&GenPart_WMinus_eta, "GenPart_WMinus_eta/F");
      HplusTree->Branch("GenPart_WMinus_phi",&GenPart_WMinus_phi, "GenPart_WMinus_phi/F");
      HplusTree->Branch("GenPart_WMinus_p",&GenPart_WMinus_p, "GenPart_WMinus_p/F");
      HplusTree->Branch("GenPart_WMinus_px",&GenPart_WMinus_px, "GenPart_WMinus_px/F");
      HplusTree->Branch("GenPart_WMinus_py",&GenPart_WMinus_py, "GenPart_WMinus_py/F");
      HplusTree->Branch("GenPart_WMinus_pz",&GenPart_WMinus_pz, "GenPart_WMinus_pz/F");
      HplusTree->Branch("GenPart_WMinus_E",&GenPart_WMinus_E, "GenPart_WMinus_E/F");
      HplusTree->Branch("GenPart_WMinus_mass",&GenPart_WMinus_mass, "GenPart_WMinus_mass/F");
   
      HplusTree->Branch("GenPart_Hplus_pt",&GenPart_Hplus_pt, "GenPart_Hplus_pt/F");
      HplusTree->Branch("GenPart_Hplus_eta",&GenPart_Hplus_eta, "GenPart_Hplus_eta/F");
      HplusTree->Branch("GenPart_Hplus_phi",&GenPart_Hplus_phi, "GenPart_Hplus_phi/F");
      HplusTree->Branch("GenPart_Hplus_p",&GenPart_Hplus_p, "GenPart_Hplus_p/F");
      HplusTree->Branch("GenPart_Hplus_px",&GenPart_Hplus_px, "GenPart_Hplus_px/F");
      HplusTree->Branch("GenPart_Hplus_py",&GenPart_Hplus_py, "GenPart_Hplus_py/F");
      HplusTree->Branch("GenPart_Hplus_pz",&GenPart_Hplus_pz, "GenPart_Hplus_pz/F");
      HplusTree->Branch("GenPart_Hplus_E",&GenPart_Hplus_E, "GenPart_Hplus_E/F");
      HplusTree->Branch("GenPart_Hplus_mass",&GenPart_Hplus_mass, "GenPart_Hplus_mass/F");
    
     
      HplusTree->Branch("GenPart_numberofLightQuarks",&GenPart_numberofLightQuarks, "GenPart_numberofLightQuarks/I");
      HplusTree->Branch("GenPart_numberofBQuarks",&GenPart_numberofBQuarks, "GenPart_numberofBQuarks/I");
      HplusTree->Branch("GenPart_numberofLeptons",&GenPart_numberofLeptons, "GenPart_numberofLeptons/I");


      HplusTree->Branch("GenPart_Hmass",&GenPart_Hmass, "GenPart_Hmass/F");
      HplusTree->Branch("GenPart_Wmass",&GenPart_Wmass, "GenPart_Wmass/F");
      HplusTree->Branch("GenPart_Tmass",&GenPart_Tmass, "GenPart_Tmass/F");
      HplusTree->Branch("GenPart_formule_Tmass",&GenPart_formule_Tmass, "GenPart_formule_Tmass/F");
      HplusTree->Branch("GenPart_Tbarmass",&GenPart_Tbarmass, "GenPart_Tbarmass/F");

      HplusTree->Branch("nSimVertex",&nSimVertex, "nSimVertex/I");
  //----------------------------------------------------------------------------------------------------------------- 
         
      HplusTree->Branch("MatchJet_Hmass",&MatchJet_Hmass, "MatchJet_Hmass/F");
      HplusTree->Branch("MatchJet_Tmass",&MatchJet_Tmass, "MatchJet_Tmass/F");
      HplusTree->Branch("MatchJet_formule_Tmass",&MatchJet_formule_Tmass, "MatchJet_formule_Tmass/F");
      HplusTree->Branch("MatchJet_jetflag",&MatchJet_jetflag, "MatchJet_jetflag/I");
 
      
      HplusTree->Branch("MatchJet_daughterQuarkofTop_index",&MatchJet_daughterQuarkofTop_index,"MatchJet_daughterQuarkofTop_index/I");
      HplusTree->Branch("MatchJet_daughterQuarkofTop_pt",&MatchJet_daughterQuarkofTop_pt, "MatchJet_daughterQuarkofTop_pt/F");
      HplusTree->Branch("MatchJet_daughterQuarkofTop_recOverGenPt",&MatchJet_daughterQuarkofTop_recOverGenPt, "MatchJet_daughterQuarkofTop_recOverGenPt/F");
      HplusTree->Branch("MatchJet_daughterQuarkofTop_eta",&MatchJet_daughterQuarkofTop_eta, "MatchJet_daughterQuarkofTop_eta/F");
      HplusTree->Branch("MatchJet_daughterQuarkofTop_phi",&MatchJet_daughterQuarkofTop_phi, "MatchJet_daughterQuarkofTop_phi/F");
      HplusTree->Branch("MatchJet_daughterQuarkofTop_p",&MatchJet_daughterQuarkofTop_p, "MatchJet_daughterQuarkofTop_p/F");
      HplusTree->Branch("MatchJet_daughterQuarkofTop_px",&MatchJet_daughterQuarkofTop_px, "MatchJet_daughterQuarkofTop_px/F");
      HplusTree->Branch("MatchJet_daughterQuarkofTop_py",&MatchJet_daughterQuarkofTop_py, "MatchJet_daughterQuarkofTop_py/F");
      HplusTree->Branch("MatchJet_daughterQuarkofTop_pz",&MatchJet_daughterQuarkofTop_pz, "MatchJet_daughterQuarkofTop_pz/F");
      HplusTree->Branch("MatchJet_daughterQuarkofTop_E",&MatchJet_daughterQuarkofTop_E, "MatchJet_daughterQuarkofTop_E/F");
      HplusTree->Branch("MatchJet_daughterQuarkofTop_deltaRj",&MatchJet_daughterQuarkofTop_deltaRj,"MatchJet_daughterQuarkofTop_deltaRj/F");
      HplusTree->Branch("MatchJet_daughterQuarkofTop_deltaRmu",&MatchJet_daughterQuarkofTop_deltaRmu, "MatchJet_daughterQuarkofTop_deltaRmu/F");
      HplusTree->Branch("MatchJet_daughterQuarkofTop_bDiscrCSV",&MatchJet_daughterQuarkofTop_bDiscrCSV, "MatchJet_daughterQuarkofTop_dbDiscrCSV/F");
 
       HplusTree->Branch("MatchJet_daughterQuarkofTopBar_index",&MatchJet_daughterQuarkofTopBar_index,"MatchJet_daughterQuarkofTopBar_index/I");
       HplusTree->Branch("MatchJet_daughterQuarkofTopBar_pt",&MatchJet_daughterQuarkofTopBar_pt, "MatchJet_daughterQuarkofTopBar_pt/F");
       HplusTree->Branch("MatchJet_daughterQuarkofTopBar_recOverGenPt",&MatchJet_daughterQuarkofTopBar_recOverGenPt, "MatchJet_daughterQuarkofTopBar_recOverGenPt/F");
       HplusTree->Branch("MatchJet_daughterQuarkofTopBar_eta",&MatchJet_daughterQuarkofTopBar_eta, "MatchJet_daughterQuarkofTopBar_eta/F");
       HplusTree->Branch("MatchJet_daughterQuarkofTopBar_phi",&MatchJet_daughterQuarkofTopBar_phi, "MatchJet_daughterQuarkofTopBar_phi/F");
       HplusTree->Branch("MatchJet_daughterQuarkofTopBar_p",&MatchJet_daughterQuarkofTopBar_p, "MatchJet_daughterQuarkofTopBar_p/F");
       HplusTree->Branch("MatchJet_daughterQuarkofTopBar_px",&MatchJet_daughterQuarkofTopBar_px, "MatchJet_daughterQuarkofTopBar_px/F");
       HplusTree->Branch("MatchJet_daughterQuarkofTopBar_py",&MatchJet_daughterQuarkofTopBar_py, "MatchJet_daughterQuarkofTopBar_py/F");
       HplusTree->Branch("MatchJet_daughterQuarkofTopBar_pz",&MatchJet_daughterQuarkofTopBar_pz, "MatchJet_daughterQuarkofTopBar_pz/F");
       HplusTree->Branch("MatchJet_daughterQuarkofTopBar_E",&MatchJet_daughterQuarkofTopBar_E, "MatchJet_daughterQuarkofTopBar_E/F");
       HplusTree->Branch("MatchJet_daughterQuarkofTopBar_deltaRj",&MatchJet_daughterQuarkofTopBar_deltaRj,"MatchJet_daughterQuarkofTopBar_deltaRj/F");
       HplusTree->Branch("MatchJet_daughterQuarkofTopBar_deltaRmu",&MatchJet_daughterQuarkofTopBar_deltaRmu, "MatchJet_daughterQuarkofTopBar_deltaRmu/F");
       HplusTree->Branch("MatchJet_daughterQuarkofTopBar_bDiscrCSV",&MatchJet_daughterQuarkofTopBar_bDiscrCSV, "MatchJet_daughterQuarkofTopBar_dbDiscrCSV/F");
       
       HplusTree->Branch("MatchJet_daughterQuarkofHplus_index",&MatchJet_daughterQuarkofHplus_index,"MatchJet_daughterQuarkofHplus_index/I");
       HplusTree->Branch("MatchJet_daughterQuarkofHplus_pt",&MatchJet_daughterQuarkofHplus_pt, "MatchJet_daughterQuarkofHplus_pt/F");
       HplusTree->Branch("MatchJet_daughterQuarkofHplus_recOverGenPt",&MatchJet_daughterQuarkofHplus_recOverGenPt, "MatchJet_daughterQuarkofHplus_recOverGenPt/F");
       HplusTree->Branch("MatchJet_daughterQuarkofHplus_eta",&MatchJet_daughterQuarkofHplus_eta, "MatchJet_daughterQuarkofHplus_eta/F");
       HplusTree->Branch("MatchJet_daughterQuarkofHplus_phi",&MatchJet_daughterQuarkofHplus_phi, "MatchJet_daughterQuarkofHplus_phi/F");
       HplusTree->Branch("MatchJet_daughterQuarkofHplus_p",&MatchJet_daughterQuarkofHplus_p, "MatchJet_daughterQuarkofHplus_p/F");
       HplusTree->Branch("MatchJet_daughterQuarkofHplus_px",&MatchJet_daughterQuarkofHplus_px, "MatchJet_daughterQuarkofHplus_px/F");
       HplusTree->Branch("MatchJet_daughterQuarkofHplus_py",&MatchJet_daughterQuarkofHplus_py, "MatchJet_daughterQuarkofHplus_py/F");
       HplusTree->Branch("MatchJet_daughterQuarkofHplus_pz",&MatchJet_daughterQuarkofHplus_pz, "MatchJet_daughterQuarkofHplus_pz/F");
       HplusTree->Branch("MatchJet_daughterQuarkofHplus_E",&MatchJet_daughterQuarkofHplus_E, "MatchJet_daughterQuarkofHplus_E/F");
       HplusTree->Branch("MatchJet_daughterQuarkofHplus_deltaRj",&MatchJet_daughterQuarkofHplus_deltaRj,"MatchJet_daughterQuarkofHplus_deltaRj/F");
       HplusTree->Branch("MatchJet_daughterQuarkofHplus_deltaRmu",&MatchJet_daughterQuarkofHplus_deltaRmu, "MatchJet_daughterQuarkofHplus_deltaRmu/F");
       HplusTree->Branch("MatchJet_daughterQuarkofHplus_bDiscrCSV",&MatchJet_daughterQuarkofHplus_bDiscrCSV, "MatchJet_daughterQuarkofHplus_dbDiscrCSV/F");
       
       HplusTree->Branch("MatchJet_daughterQuarkBarofHplus_index",&MatchJet_daughterQuarkBarofHplus_index,"MatchJet_daughterQuarkBarofHplus_index/I");
       HplusTree->Branch("MatchJet_daughterQuarkBarofHplus_pt",&MatchJet_daughterQuarkBarofHplus_pt, "MatchJet_daughterQuarkBarofHplus_pt/F");
       HplusTree->Branch("MatchJet_daughterQuarkBarofHplus_recOverGenPt",&MatchJet_daughterQuarkBarofHplus_recOverGenPt, "MatchJet_daughterQuarkBarofHplus_recOverGenPt/F");
       HplusTree->Branch("MatchJet_daughterQuarkBarofHplus_eta",&MatchJet_daughterQuarkBarofHplus_eta, "MatchJet_daughterQuarkBarofHplus_eta/F");
       HplusTree->Branch("MatchJet_daughterQuarkBarofHplus_phi",&MatchJet_daughterQuarkBarofHplus_phi, "MatchJet_daughterQuarkBarofHplus_phi/F");
       HplusTree->Branch("MatchJet_daughterQuarkBarofHplus_p",&MatchJet_daughterQuarkBarofHplus_p, "MatchJet_daughterQuarkBarofHplus_p/F");
       HplusTree->Branch("MatchJet_daughterQuarkBarofHplus_px",&MatchJet_daughterQuarkBarofHplus_px, "MatchJet_daughterQuarkBarofHplus_px/F");
       HplusTree->Branch("MatchJet_daughterQuarkBarofHplus_py",&MatchJet_daughterQuarkBarofHplus_py, "MatchJet_daughterQuarkBarofHplus_py/F");
       HplusTree->Branch("MatchJet_daughterQuarkBarofHplus_pz",&MatchJet_daughterQuarkBarofHplus_pz, "MatchJet_daughterQuarkBarofHplus_pz/F");
       HplusTree->Branch("MatchJet_daughterQuarkBarofHplus_E",&MatchJet_daughterQuarkBarofHplus_E, "MatchJet_daughterQuarkBarofHplus_E/F");
       HplusTree->Branch("MatchJet_daughterQuarkBarofHplus_deltaRj",&MatchJet_daughterQuarkBarofHplus_deltaRj,"MatchJet_daughterQuarkBarofHplus_deltaRj/F");
       HplusTree->Branch("MatchJet_daughterQuarkBarofHplus_deltaRmu",&MatchJet_daughterQuarkBarofHplus_deltaRmu, "MatchJet_daughterQuarkBarofHplus_deltaRmu/F");
       HplusTree->Branch("MatchJet_daughterQuarkBarofHplus_bDiscrCSV",&MatchJet_daughterQuarkBarofHplus_bDiscrCSV, "MatchJet_daughterQuarkBarofHplus_dbDiscrCSV/F");
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

       HplusTree->Branch("MUpt",&MUpt, "MUpt/F");
       HplusTree->Branch("MUeta",&MUeta, "MUeta/F");
       HplusTree->Branch("MUphi",&MUphi, "MUphi/F");
       HplusTree->Branch("MUtheta",&MUtheta, "MUtheta/F");
       HplusTree->Branch("MUp",&MUp, "MUp/F");
       HplusTree->Branch("MUpx",&MUpx, "MUpx/F");
       HplusTree->Branch("MUpy",&MUpy, "MUpy/F");
       HplusTree->Branch("MUpz",&MUpz, "MUpz/F");
       HplusTree->Branch("MUrelIso",&MUrelIso, "MUrelIso/F");
       HplusTree->Branch("MUd0",&MUd0, "MUd0/F");
       HplusTree->Branch("MUdz",&MUdz, "MUdz/F");
       HplusTree->Branch("MUnormChi2",&MUnormChi2, "MUnormChi2/F");
       HplusTree->Branch("MUnOfHits",&MUnOfHits, "MUnOfHits/I"); //number of valid hits
       HplusTree->Branch("MUlayer",&MUlayer, "MUlayer/I");  //number of tracker layer with measurement
       HplusTree->Branch("MUnOfPixels",&MUnOfPixels, "MUnOfPixels/I"); //number of pixels with valid hits
       HplusTree->Branch("MUisGlobal",&MUisGlobal, "MUisGlobal/I");
       HplusTree->Branch("MUisPF",&MUisPF, "MUisPF/I");
       HplusTree->Branch("MUstations",&MUstations, "MUstations/I"); 
  
       HplusTree->Branch("nLep",&nLep, "nLep/I"); // number of leptons (VetoMuons + VetoElecs)
       
       
pJpt=&Jpt;
pJeta=&Jeta;
pJphi=&Jphi;
pJtheta=&Jtheta;
pJp=&Jp;
pJpx=&Jpx;
pJpy=&Jpy;
pJpz=&Jpz;
pJbDiscr=&JbDiscr;
pJenergy=&Jenergy;
pJcharge=&Jcharge;
pJflavor=&Jflavor;
     
       //JETS
       HplusTree->Branch("nJet",&realnJet, "nJet/I");
       HplusTree->Branch("nbJet",&nbJet, "nbJet/I");
       HplusTree->Branch("nbJetloose",&nbJetloose, "nbJetloose/I");
       HplusTree->Branch("Jpt",&pJpt);
       HplusTree->Branch("Jeta",&pJeta);
       HplusTree->Branch("Jphi",&pJphi);
       HplusTree->Branch("Jtheta",&pJtheta);
       HplusTree->Branch("Jp",&pJp);
       HplusTree->Branch("Jpx",&pJpx);
       HplusTree->Branch("Jpy",&pJpy);
       HplusTree->Branch("Jpz",&pJpz);
       HplusTree->Branch("JbDiscr",&pJbDiscr);
       HplusTree->Branch("Jenergy",&pJenergy);
       HplusTree->Branch("Jcharge",&pJcharge);
       HplusTree->Branch("Jflavor",&pJflavor);
 
       //MET
       HplusTree->Branch("METpt",&METpt, "METpt/F");
       HplusTree->Branch("METpx",&METpx, "METpx/F");
       HplusTree->Branch("METpy",&METpy, "METpy/F");
       HplusTree->Branch("METeta",&METeta, "METeta/F");
       HplusTree->Branch("METphi",&METphi, "METphi/F");
       HplusTree->Branch("METtheta",&METtheta, "METtheta/F");

       //VERTEX MULTIPLICITY
       HplusTree->Branch("nVertex",&nVertex, "nVertex/I"); 

//---------------------------------------------------------------------------------------------------------

      HplusTree->Branch("KinFit_isValid",&KinFit_isValid, "KinFit_isValid/I");
      HplusTree->Branch("ncomb",&ncomb, "ncomb/I");
      HplusTree->Branch("KinFit_prob",KinFit_prob, "KinFit_prob[ncomb]/F");
      HplusTree->Branch("KinFit_chi2",KinFit_chi2, "KinFit_chi2[ncomb]/F");
      HplusTree->Branch("KinFit_lightP_index",KinFit_lightP_index,"KinFit_lightP_index[ncomb]/I");
      HplusTree->Branch("KinFit_lightQ_index",KinFit_lightQ_index,"KinFit_lightQ_index[ncomb]/I");
      HplusTree->Branch("KinFit_hadB_index",KinFit_hadB_index,"KinFit_hadB_index[ncomb]/I");
      HplusTree->Branch("KinFit_lepB_index",KinFit_lepB_index,"KinFit_lepB_index[ncomb]/I");
      HplusTree->Branch("KinFit_lepton_index",KinFit_lepton_index,"KinFit_lepton_index[ncomb]/I");
  
      HplusTree->Branch("KinFit_hadW_mass",KinFit_hadW_mass,"KinFit_hadW_mass[ncomb]/F");
      HplusTree->Branch("KinFit_hadW_pt",KinFit_hadW_pt,"KinFit_hadW_pt[ncomb]/F");
      HplusTree->Branch("KinFit_hadW_eta",KinFit_hadW_eta,"KinFit_hadW_eta[ncomb]/F");
      HplusTree->Branch("KinFit_hadW_phi",KinFit_hadW_phi,"KinFit_hadW_phi[ncomb]/F");
      HplusTree->Branch("KinFit_hadW_px",KinFit_hadW_px,"KinFit_hadW_px[ncomb]/F");
      HplusTree->Branch("KinFit_hadW_py",KinFit_hadW_py,"KinFit_hadW_py[ncomb]/F");
      HplusTree->Branch("KinFit_hadW_pz",KinFit_hadW_pz,"KinFit_hadW_pz[ncomb]/F");
      HplusTree->Branch("KinFit_hadW_energy",KinFit_hadW_energy,"KinFit_hadW_energy[ncomb]/F");
 
      HplusTree->Branch("KinFit_lepW_mass",KinFit_lepW_mass,"KinFit_lepW_mass[ncomb]/F");
      HplusTree->Branch("KinFit_lepW_pt",KinFit_lepW_pt,"KinFit_lepW_pt[ncomb]/F");
      HplusTree->Branch("KinFit_lepW_eta",KinFit_lepW_eta,"KinFit_lepW_eta[ncomb]/F");
      HplusTree->Branch("KinFit_lepW_phi",KinFit_lepW_phi,"KinFit_lepW_phi[ncomb]/F");
      HplusTree->Branch("KinFit_lepW_px",KinFit_lepW_px,"KinFit_lepW_px[ncomb]/F");
      HplusTree->Branch("KinFit_lepW_py",KinFit_lepW_py,"KinFit_lepW_py[ncomb]/F");
      HplusTree->Branch("KinFit_lepW_pz",KinFit_lepW_pz,"KinFit_lepW_pz[ncomb]/F");
      HplusTree->Branch("KinFit_lepW_energy",KinFit_lepW_energy,"KinFit_lepW_energy[ncomb]/F");
      
      HplusTree->Branch("KinFit_hadTop_mass",KinFit_hadTop_mass,"KinFit_hadTop_mass[ncomb]/F");
      HplusTree->Branch("KinFit_hadTop_pt",KinFit_hadTop_pt,"KinFit_hadTop_pt[ncomb]/F");
      HplusTree->Branch("KinFit_hadTop_eta",KinFit_hadTop_eta,"KinFit_hadTop_eta[ncomb]/F");
      HplusTree->Branch("KinFit_hadTop_phi",KinFit_hadTop_phi,"KinFit_hadTop_phi[ncomb]/F");
      HplusTree->Branch("KinFit_hadTop_px",KinFit_hadTop_px,"KinFit_hadTop_px[ncomb]/F");
      HplusTree->Branch("KinFit_hadTop_py",KinFit_hadTop_py,"KinFit_hadTop_py[ncomb]/F");
      HplusTree->Branch("KinFit_hadTop_pz",KinFit_hadTop_pz,"KinFit_hadTop_pz[ncomb]/F");
      HplusTree->Branch("KinFit_hadTop_energy",KinFit_hadTop_energy,"KinFit_hadTop_energy[ncomb]/F");
      
      HplusTree->Branch("KinFit_lepTop_mass",KinFit_lepTop_mass,"KinFit_lepTop_mass[ncomb]/F");
      HplusTree->Branch("KinFit_lepTop_pt",KinFit_lepTop_pt,"KinFit_lepTop_pt[ncomb]/F");
      HplusTree->Branch("KinFit_lepTop_eta",KinFit_lepTop_eta,"KinFit_lepTop_eta[ncomb]/F");
      HplusTree->Branch("KinFit_lepTop_phi",KinFit_lepTop_phi,"KinFit_lepTop_phi[ncomb]/F");
      HplusTree->Branch("KinFit_lepTop_px",KinFit_lepTop_px,"KinFit_lepTop_px[ncomb]/F");
      HplusTree->Branch("KinFit_lepTop_py",KinFit_lepTop_py,"KinFit_lepTop_py[ncomb]/F");
      HplusTree->Branch("KinFit_lepTop_pz",KinFit_lepTop_pz,"KinFit_lepTop_pz[ncomb]/F");
      HplusTree->Branch("KinFit_lepTop_energy",KinFit_lepTop_energy,"KinFit_lepTop_energy[ncomb]/F");
     
      HplusTree->Branch("KinFit_hadQuark_pt",KinFit_hadQuark_pt,"KinFit_hadQuark_pt[ncomb]/F");
      HplusTree->Branch("KinFit_hadQuark_eta",KinFit_hadQuark_eta,"KinFit_hadQuark_eta[ncomb]/F");
      HplusTree->Branch("KinFit_hadQuark_phi",KinFit_hadQuark_phi,"KinFit_hadQuark_phi[ncomb]/F");
      HplusTree->Branch("KinFit_hadQuark_px",KinFit_hadQuark_px,"KinFit_hadQuark_px[ncomb]/F");
      HplusTree->Branch("KinFit_hadQuark_py",KinFit_hadQuark_py,"KinFit_hadQuark_py[ncomb]/F");
      HplusTree->Branch("KinFit_hadQuark_pz",KinFit_hadQuark_pz,"KinFit_hadQuark_pz[ncomb]/F");
      HplusTree->Branch("KinFit_hadQuark_energy",KinFit_hadQuark_energy,"KinFit_hadQuark_energy[ncomb]/F");
 
      HplusTree->Branch("KinFit_hadQuarkBar_pt",KinFit_hadQuarkBar_pt,"KinFit_hadQuarkBar_pt[ncomb]/F");
      HplusTree->Branch("KinFit_hadQuarkBar_eta",KinFit_hadQuarkBar_eta,"KinFit_hadQuarkBar_eta[ncomb]/F");
      HplusTree->Branch("KinFit_hadQuarkBar_phi",KinFit_hadQuarkBar_phi,"KinFit_hadQuarkBar_phi[ncomb]/F");
      HplusTree->Branch("KinFit_hadQuarkBar_px",KinFit_hadQuarkBar_px,"KinFit_hadQuarkBar_px[ncomb]/F");
      HplusTree->Branch("KinFit_hadQuarkBar_py",KinFit_hadQuarkBar_py,"KinFit_hadQuarkBar_py[ncomb]/F");
      HplusTree->Branch("KinFit_hadQuarkBar_pz",KinFit_hadQuarkBar_pz,"KinFit_hadQuarkBar_pz[ncomb]/F");
      HplusTree->Branch("KinFit_hadQuarkBar_energy",KinFit_hadQuarkBar_energy,"KinFit_hadQuarkBar_energy[ncomb]/F");

      HplusTree->Branch("KinFit_hadB_pt",KinFit_hadB_pt,"KinFit_hadB_pt[ncomb]/F");
      HplusTree->Branch("KinFit_hadB_eta",KinFit_hadB_eta,"KinFit_hadB_eta[ncomb]/F");
      HplusTree->Branch("KinFit_hadB_phi",KinFit_hadB_phi,"KinFit_hadB_phi[ncomb]/F");
      HplusTree->Branch("KinFit_hadB_px",KinFit_hadB_px,"KinFit_hadB_px[ncomb]/F");
      HplusTree->Branch("KinFit_hadB_py",KinFit_hadB_py,"KinFit_hadB_py[ncomb]/F");
      HplusTree->Branch("KinFit_hadB_pz",KinFit_hadB_pz,"KinFit_hadB_pz[ncomb]/F");
      HplusTree->Branch("KinFit_hadB_energy",KinFit_hadB_energy,"KinFit_hadB_energy[ncomb]/F");
   
      HplusTree->Branch("KinFit_lepB_pt",KinFit_lepB_pt,"KinFit_lepB_pt[ncomb]/F");
      HplusTree->Branch("KinFit_lepB_eta",KinFit_lepB_eta,"KinFit_lepB_eta[ncomb]/F");
      HplusTree->Branch("KinFit_lepB_px",KinFit_lepB_px,"KinFit_lepB_px[ncomb]/F");
      HplusTree->Branch("KinFit_lepB_py",KinFit_lepB_py,"KinFit_lepB_py[ncomb]/F");
      HplusTree->Branch("KinFit_lepB_pz",KinFit_lepB_pz,"KinFit_lepB_pz[ncomb]/F");
      HplusTree->Branch("KinFit_lepB_energy",KinFit_lepB_energy,"KinFit_lepB_energy[ncomb]/F");


}

// ------------ method called once each job just after ending the event loop  ------------
void 
HplusAnalyzer::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
void 
HplusAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void 
HplusAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
HplusAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
HplusAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
HplusAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(HplusAnalyzer);
