//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Feb  2 19:44:14 2016 by ROOT version 5.32/00
// from TTree HplusGenPartTree/HplusGenPartTree
// found on file: analyzePatTopSelection.ttbar.root
//////////////////////////////////////////////////////////

#ifndef analyze_ttsplit_kinfit_h
#define analyze_ttsplit_kinfit_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class analyze_ttsplit_kinfit {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           run;
   Int_t           luminosityBlock;
   Int_t           event;
   Double_t        lumiWeight;
   Double_t        lumiWeight_up;
   Double_t        lumiWeight_down;
   UInt_t          MCcat;
   Int_t           GenPart_daughterQuarkBarofHplus_pdgId;
   Int_t           GenPart_daughterQuarkofHplus_pdgId;
   Float_t         GenPart_top_pt;
   Float_t         GenPart_topBar_pt;
   Float_t         GenPart_Hplus_mass;
   Float_t         GenPart_Hmass;
   Float_t         GenPart_Wmass;
   Float_t         GenPart_Tmass;
   Float_t         GenPart_formule_Tmass;
   Float_t         GenPart_Tbarmass;
   vector<float>   *TopJet_pt;
   vector<float>   *TopJet_eta;
   vector<float>   *TopJet_csv;
   vector<float>   *WJet_pt;
   vector<float>   *WJet_eta;
   vector<float>   *WJet_csv;
   vector<float>   *AddJet_pt;
   vector<float>   *AddJet_eta;
   vector<float>   *AddJet_csv;
   Float_t         MatchJet_Hmass;
   Float_t         MatchJet_Tmass;
   Float_t         MatchJet_formule_Tmass;
   Int_t           MatchJet_jetflag;
   Int_t           MatchJet_daughterQuarkofTop_index;
   Float_t         MatchJet_daughterQuarkofTop_pt;
   Float_t         MatchJet_daughterQuarkofTop_recOverGenPt;
   Float_t         MatchJet_daughterQuarkofTop_eta;
   Float_t         MatchJet_daughterQuarkofTop_phi;
   Float_t         MatchJet_daughterQuarkofTop_bDiscrCSV;
   Int_t           MatchJet_daughterQuarkofTopBar_index;
   Float_t         MatchJet_daughterQuarkofTopBar_pt;
   Float_t         MatchJet_daughterQuarkofTopBar_recOverGenPt;
   Float_t         MatchJet_daughterQuarkofTopBar_eta;
   Float_t         MatchJet_daughterQuarkofTopBar_phi;
   Float_t         MatchJet_daughterQuarkofTopBar_bDiscrCSV;
   Int_t           MatchJet_daughterQuarkofHplus_index;
   Float_t         MatchJet_daughterQuarkofHplus_pt;
   Float_t         MatchJet_daughterQuarkofHplus_recOverGenPt;
   Float_t         MatchJet_daughterQuarkofHplus_eta;
   Float_t         MatchJet_daughterQuarkofHplus_phi;
   Float_t         MatchJet_daughterQuarkofHplus_bDiscrCSV;
   Int_t           MatchJet_daughterQuarkBarofHplus_index;
   Float_t         MatchJet_daughterQuarkBarofHplus_pt;
   Float_t         MatchJet_daughterQuarkBarofHplus_recOverGenPt;
   Float_t         MatchJet_daughterQuarkBarofHplus_eta;
   Float_t         MatchJet_daughterQuarkBarofHplus_phi;
   Float_t         MatchJet_daughterQuarkBarofHplus_bDiscrCSV;
   Float_t         MUpt;
   Float_t         MUeta;
   Float_t         MUphi;
   Float_t         MUtheta;
   Float_t         MUp;
   Float_t         MUpx;
   Float_t         MUpy;
   Float_t         MUpz;
   Float_t         MUrelIso;
   Float_t         MUd0;
   Float_t         MUdz;
   Float_t         MUnormChi2;
   Int_t           MUnOfHits;
   Int_t           MUlayer;
   Int_t           MUnOfPixels;
   Int_t           MUisGlobal;
   Int_t           MUisPF;
   Int_t           MUstations;
   Int_t           nLep;
   Int_t           nJet;
   Int_t           nbJet;
   Int_t           nbJetloose;
   vector<float>   *Jpt;
   vector<float>   *Jeta;
   vector<float>   *Jphi;
   vector<float>   *Jtheta;
   vector<float>   *Jp;
   vector<float>   *Jpx;
   vector<float>   *Jpy;
   vector<float>   *Jpz;
   vector<float>   *JbDiscr;
   vector<float>   *Jenergy;
   vector<float>   *Jcharge;
   vector<int>     *Jflavor;
   Float_t         METpt;
   Float_t         METpx;
   Float_t         METpy;
   Float_t         METeta;
   Float_t         METphi;
   Float_t         METtheta;
   Int_t           nVertex;
   Int_t           KinFit_isValid;
   Int_t           ncomb;
   vector<float>   *KinFit_prob;
   vector<float>   *KinFit_chi2;
   vector<int>     *KinFit_lightP_index;
   vector<int>     *KinFit_lightQ_index;
   vector<int>     *KinFit_hadB_index;
   vector<int>     *KinFit_lepB_index;
   vector<int>     *KinFit_lepton_index;
   vector<float>   *KinFit_hadW_mass;
   vector<float>   *KinFit_hadW_pt;
   vector<float>   *KinFit_hadW_eta;
   vector<float>   *KinFit_hadW_phi;
   vector<float>   *KinFit_lepW_mass;
   vector<float>   *KinFit_lepW_pt;
   vector<float>   *KinFit_lepW_eta;
   vector<float>   *KinFit_lepW_phi;
   vector<float>   *KinFit_hadTop_mass;
   vector<float>   *KinFit_hadTop_pt;
   vector<float>   *KinFit_hadTop_eta;
   vector<float>   *KinFit_hadTop_phi;
   vector<float>   *KinFit_lepTop_mass;
   vector<float>   *KinFit_lepTop_pt;
   vector<float>   *KinFit_lepTop_eta;
   vector<float>   *KinFit_lepTop_phi;
   vector<float>   *KinFit_hadQuark_pt;
   vector<float>   *KinFit_hadQuark_eta;
   vector<float>   *KinFit_hadQuark_phi;
   vector<float>   *KinFit_hadQuarkBar_pt;
   vector<float>   *KinFit_hadQuarkBar_eta;
   vector<float>   *KinFit_hadQuarkBar_phi;
   vector<float>   *KinFit_hadB_pt;
   vector<float>   *KinFit_hadB_eta;
   vector<float>   *KinFit_hadB_phi;
   vector<float>   *KinFit_lepB_pt;
   vector<float>   *KinFit_lepB_eta;
   vector<float>   *KinFit_lepB_phi;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_luminosityBlock;   //!
   TBranch        *b_event;   //!
   TBranch        *b_lumiWeight;   //!
   TBranch        *b_lumiWeight_up;   //!
   TBranch        *b_lumiWeight_down;   //!
   TBranch        *b_MCcat;   //!
   TBranch        *b_GenPart_daughterQuarkBarofHplus_pdgId;   //!
   TBranch        *b_GenPart_daughterQuarkofHplus_pdgId;   //!
   TBranch        *b_GenPart_top_pt;   //!
   TBranch        *b_GenPart_topBar_pt;   //!
   TBranch        *b_GenPart_Hplus_mass;   //!
   TBranch        *b_GenPart_Hmass;   //!
   TBranch        *b_GenPart_Wmass;   //!
   TBranch        *b_GenPart_Tmass;   //!
   TBranch        *b_GenPart_formule_Tmass;   //!
   TBranch        *b_GenPart_Tbarmass;   //!
   TBranch        *b_TopJet_pt;   //!
   TBranch        *b_TopJet_eta;   //!
   TBranch        *b_TopJet_csv;   //!
   TBranch        *b_WJet_pt;   //!
   TBranch        *b_WJet_eta;   //!
   TBranch        *b_WJet_csv;   //!
   TBranch        *b_AddJet_pt;   //!
   TBranch        *b_AddJet_eta;   //!
   TBranch        *b_AddJet_csv;   //!
   TBranch        *b_MatchJet_Hmass;   //!
   TBranch        *b_MatchJet_Tmass;   //!
   TBranch        *b_MatchJet_formule_Tmass;   //!
   TBranch        *b_MatchJet_jetflag;   //!
   TBranch        *b_MatchJet_daughterQuarkofTop_index;   //!
   TBranch        *b_MatchJet_daughterQuarkofTop_pt;   //!
   TBranch        *b_MatchJet_daughterQuarkofTop_recOverGenPt;   //!
   TBranch        *b_MatchJet_daughterQuarkofTop_eta;   //!
   TBranch        *b_MatchJet_daughterQuarkofTop_phi;   //!
   TBranch        *b_MatchJet_daughterQuarkofTop_dbDiscrCSV;   //!
   TBranch        *b_MatchJet_daughterQuarkofTopBar_index;   //!
   TBranch        *b_MatchJet_daughterQuarkofTopBar_pt;   //!
   TBranch        *b_MatchJet_daughterQuarkofTopBar_recOverGenPt;   //!
   TBranch        *b_MatchJet_daughterQuarkofTopBar_eta;   //!
   TBranch        *b_MatchJet_daughterQuarkofTopBar_phi;   //!
   TBranch        *b_MatchJet_daughterQuarkofTopBar_dbDiscrCSV;   //!
   TBranch        *b_MatchJet_daughterQuarkofHplus_index;   //!
   TBranch        *b_MatchJet_daughterQuarkofHplus_pt;   //!
   TBranch        *b_MatchJet_daughterQuarkofHplus_recOverGenPt;   //!
   TBranch        *b_MatchJet_daughterQuarkofHplus_eta;   //!
   TBranch        *b_MatchJet_daughterQuarkofHplus_phi;   //!
   TBranch        *b_MatchJet_daughterQuarkofHplus_dbDiscrCSV;   //!
   TBranch        *b_MatchJet_daughterQuarkBarofHplus_index;   //!
   TBranch        *b_MatchJet_daughterQuarkBarofHplus_pt;   //!
   TBranch        *b_MatchJet_daughterQuarkBarofHplus_recOverGenPt;   //!
   TBranch        *b_MatchJet_daughterQuarkBarofHplus_eta;   //!
   TBranch        *b_MatchJet_daughterQuarkBarofHplus_phi;   //!
   TBranch        *b_MatchJet_daughterQuarkBarofHplus_dbDiscrCSV;   //!
   TBranch        *b_MUpt;   //!
   TBranch        *b_MUeta;   //!
   TBranch        *b_MUphi;   //!
   TBranch        *b_MUtheta;   //!
   TBranch        *b_MUp;   //!
   TBranch        *b_MUpx;   //!
   TBranch        *b_MUpy;   //!
   TBranch        *b_MUpz;   //!
   TBranch        *b_MUrelIso;   //!
   TBranch        *b_MUd0;   //!
   TBranch        *b_MUdz;   //!
   TBranch        *b_MUnormChi2;   //!
   TBranch        *b_MUnOfHits;   //!
   TBranch        *b_MUlayer;   //!
   TBranch        *b_MUnOfPixels;   //!
   TBranch        *b_MUisGlobal;   //!
   TBranch        *b_MUisPF;   //!
   TBranch        *b_MUstations;   //!
   TBranch        *b_nLep;   //!
   TBranch        *b_nJet;   //!
   TBranch        *b_nbJet;   //!
   TBranch        *b_nbJetloose;   //!
   TBranch        *b_Jpt;   //!
   TBranch        *b_Jeta;   //!
   TBranch        *b_Jphi;   //!
   TBranch        *b_Jtheta;   //!
   TBranch        *b_Jp;   //!
   TBranch        *b_Jpx;   //!
   TBranch        *b_Jpy;   //!
   TBranch        *b_Jpz;   //!
   TBranch        *b_JbDiscr;   //!
   TBranch        *b_Jenergy;   //!
   TBranch        *b_Jcharge;   //!
   TBranch        *b_Jflavor;   //!
   TBranch        *b_METpt;   //!
   TBranch        *b_METpx;   //!
   TBranch        *b_METpy;   //!
   TBranch        *b_METeta;   //!
   TBranch        *b_METphi;   //!
   TBranch        *b_METtheta;   //!
   TBranch        *b_nVertex;   //!
   TBranch        *b_KinFit_isValid;   //!
   TBranch        *b_ncomb;   //!
   TBranch        *b_KinFit_prob;   //!
   TBranch        *b_KinFit_chi2;   //!
   TBranch        *b_KinFit_lightP_index;   //!
   TBranch        *b_KinFit_lightQ_index;   //!
   TBranch        *b_KinFit_hadB_index;   //!
   TBranch        *b_KinFit_lepB_index;   //!
   TBranch        *b_KinFit_lepton_index;   //!
   TBranch        *b_KinFit_hadW_mass;   //!
   TBranch        *b_KinFit_hadW_pt;   //!
   TBranch        *b_KinFit_hadW_eta;   //!
   TBranch        *b_KinFit_hadW_phi;   //!
   TBranch        *b_KinFit_lepW_mass;   //!
   TBranch        *b_KinFit_lepW_pt;   //!
   TBranch        *b_KinFit_lepW_eta;   //!
   TBranch        *b_KinFit_lepW_phi;   //!
   TBranch        *b_KinFit_hadTop_mass;   //!
   TBranch        *b_KinFit_hadTop_pt;   //!
   TBranch        *b_KinFit_hadTop_eta;   //!
   TBranch        *b_KinFit_hadTop_phi;   //!
   TBranch        *b_KinFit_lepTop_mass;   //!
   TBranch        *b_KinFit_lepTop_pt;   //!
   TBranch        *b_KinFit_lepTop_eta;   //!
   TBranch        *b_KinFit_lepTop_phi;   //!
   TBranch        *b_KinFit_hadQuark_pt;   //!
   TBranch        *b_KinFit_hadQuark_eta;   //!
   TBranch        *b_KinFit_hadQuark_phi;   //!
   TBranch        *b_KinFit_hadQuarkBar_pt;   //!
   TBranch        *b_KinFit_hadQuarkBar_eta;   //!
   TBranch        *b_KinFit_hadQuarkBar_phi;   //!
   TBranch        *b_KinFit_hadB_pt;   //!
   TBranch        *b_KinFit_hadB_eta;   //!
   TBranch        *b_KinFit_hadB_phi;   //!
   TBranch        *b_KinFit_lepB_pt;   //!
   TBranch        *b_KinFit_lepB_eta;   //!
   TBranch        *b_KinFit_lepB_phi;   //!

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_luminosityBlock;   //!
   TBranch        *b_event;   //!
   TBranch        *b_lumiWeight;   //!
   TBranch        *b_lumiWeight_up;   //!
   TBranch        *b_lumiWeight_down;   //!
   TBranch        *b_MCcat;   //!
   TBranch        *b_GenPart_daughterQuarkBarofHplus_pdgId;   //!
   TBranch        *b_GenPart_daughterQuarkofHplus_pdgId;   //!
   TBranch        *b_GenPart_top_pt;   //!
   TBranch        *b_GenPart_topBar_pt;   //!
   TBranch        *b_GenPart_Hplus_mass;   //!
   TBranch        *b_GenPart_Hmass;   //!
   TBranch        *b_GenPart_Wmass;   //!
   TBranch        *b_GenPart_Tmass;   //!
   TBranch        *b_GenPart_formule_Tmass;   //!
   TBranch        *b_GenPart_Tbarmass;   //!
   TBranch        *b_TopJet_pt;   //!
   TBranch        *b_TopJet_eta;   //!
   TBranch        *b_TopJet_csv;   //!
   TBranch        *b_WJet_pt;   //!
   TBranch        *b_WJet_eta;   //!
   TBranch        *b_WJet_csv;   //!
   TBranch        *b_AddJet_pt;   //!
   TBranch        *b_AddJet_eta;   //!
   TBranch        *b_AddJet_csv;   //!
   TBranch        *b_MatchJet_Hmass;   //!
   TBranch        *b_MatchJet_Tmass;   //!
   TBranch        *b_MatchJet_formule_Tmass;   //!
   TBranch        *b_MatchJet_jetflag;   //!
   TBranch        *b_MatchJet_daughterQuarkofTop_index;   //!
   TBranch        *b_MatchJet_daughterQuarkofTop_pt;   //!
   TBranch        *b_MatchJet_daughterQuarkofTop_recOverGenPt;   //!
   TBranch        *b_MatchJet_daughterQuarkofTop_eta;   //!
   TBranch        *b_MatchJet_daughterQuarkofTop_phi;   //!
   TBranch        *b_MatchJet_daughterQuarkofTop_dbDiscrCSV;   //!
   TBranch        *b_MatchJet_daughterQuarkofTopBar_index;   //!
   TBranch        *b_MatchJet_daughterQuarkofTopBar_pt;   //!
   TBranch        *b_MatchJet_daughterQuarkofTopBar_recOverGenPt;   //!
   TBranch        *b_MatchJet_daughterQuarkofTopBar_eta;   //!
   TBranch        *b_MatchJet_daughterQuarkofTopBar_phi;   //!
   TBranch        *b_MatchJet_daughterQuarkofTopBar_dbDiscrCSV;   //!
   TBranch        *b_MatchJet_daughterQuarkofHplus_index;   //!
   TBranch        *b_MatchJet_daughterQuarkofHplus_pt;   //!
   TBranch        *b_MatchJet_daughterQuarkofHplus_recOverGenPt;   //!
   TBranch        *b_MatchJet_daughterQuarkofHplus_eta;   //!
   TBranch        *b_MatchJet_daughterQuarkofHplus_phi;   //!
   TBranch        *b_MatchJet_daughterQuarkofHplus_dbDiscrCSV;   //!
   TBranch        *b_MatchJet_daughterQuarkBarofHplus_index;   //!
   TBranch        *b_MatchJet_daughterQuarkBarofHplus_pt;   //!
   TBranch        *b_MatchJet_daughterQuarkBarofHplus_recOverGenPt;   //!
   TBranch        *b_MatchJet_daughterQuarkBarofHplus_eta;   //!
   TBranch        *b_MatchJet_daughterQuarkBarofHplus_phi;   //!
   TBranch        *b_MatchJet_daughterQuarkBarofHplus_dbDiscrCSV;   //!
   TBranch        *b_MUpt;   //!
   TBranch        *b_MUeta;   //!
   TBranch        *b_MUphi;   //!
   TBranch        *b_MUtheta;   //!
   TBranch        *b_MUp;   //!
   TBranch        *b_MUpx;   //!
   TBranch        *b_MUpy;   //!
   TBranch        *b_MUpz;   //!
   TBranch        *b_MUrelIso;   //!
   TBranch        *b_MUd0;   //!
   TBranch        *b_MUdz;   //!
   TBranch        *b_MUnormChi2;   //!
   TBranch        *b_MUnOfHits;   //!
   TBranch        *b_MUlayer;   //!
   TBranch        *b_MUnOfPixels;   //!
   TBranch        *b_MUisGlobal;   //!
   TBranch        *b_MUisPF;   //!
   TBranch        *b_MUstations;   //!
   TBranch        *b_nLep;   //!
   TBranch        *b_nJet;   //!
   TBranch        *b_nbJet;   //!
   TBranch        *b_nbJetloose;   //!
   TBranch        *b_Jpt;   //!
   TBranch        *b_Jeta;   //!
   TBranch        *b_Jphi;   //!
   TBranch        *b_Jtheta;   //!
   TBranch        *b_Jp;   //!
   TBranch        *b_Jpx;   //!
   TBranch        *b_Jpy;   //!
   TBranch        *b_Jpz;   //!
   TBranch        *b_JbDiscr;   //!
   TBranch        *b_Jenergy;   //!
   TBranch        *b_Jcharge;   //!
   TBranch        *b_Jflavor;   //!
   TBranch        *b_METpt;   //!
   TBranch        *b_METpx;   //!
   TBranch        *b_METpy;   //!
   TBranch        *b_METeta;   //!
   TBranch        *b_METphi;   //!
   TBranch        *b_METtheta;   //!
   TBranch        *b_nVertex;   //!
   TBranch        *b_KinFit_isValid;   //!
   TBranch        *b_ncomb;   //!
   TBranch        *b_KinFit_prob;   //!
   TBranch        *b_KinFit_chi2;   //!
   TBranch        *b_KinFit_lightP_index;   //!
   TBranch        *b_KinFit_lightQ_index;   //!
   TBranch        *b_KinFit_hadB_index;   //!
   TBranch        *b_KinFit_lepB_index;   //!
   TBranch        *b_KinFit_lepton_index;   //!
   TBranch        *b_KinFit_hadW_mass;   //!
   TBranch        *b_KinFit_hadW_pt;   //!
   TBranch        *b_KinFit_hadW_eta;   //!
   TBranch        *b_KinFit_hadW_phi;   //!
   TBranch        *b_KinFit_lepW_mass;   //!
   TBranch        *b_KinFit_lepW_pt;   //!
   TBranch        *b_KinFit_lepW_eta;   //!
   TBranch        *b_KinFit_lepW_phi;   //!
   TBranch        *b_KinFit_hadTop_mass;   //!
   TBranch        *b_KinFit_hadTop_pt;   //!
   TBranch        *b_KinFit_hadTop_eta;   //!
   TBranch        *b_KinFit_hadTop_phi;   //!
   TBranch        *b_KinFit_lepTop_mass;   //!
   TBranch        *b_KinFit_lepTop_pt;   //!
   TBranch        *b_KinFit_lepTop_eta;   //!
   TBranch        *b_KinFit_lepTop_phi;   //!
   TBranch        *b_KinFit_hadQuark_pt;   //!
   TBranch        *b_KinFit_hadQuark_eta;   //!
   TBranch        *b_KinFit_hadQuark_phi;   //!
   TBranch        *b_KinFit_hadQuarkBar_pt;   //!
   TBranch        *b_KinFit_hadQuarkBar_eta;   //!
   TBranch        *b_KinFit_hadQuarkBar_phi;   //!
   TBranch        *b_KinFit_hadB_pt;   //!
   TBranch        *b_KinFit_hadB_eta;   //!
   TBranch        *b_KinFit_hadB_phi;   //!
   TBranch        *b_KinFit_lepB_pt;   //!
   TBranch        *b_KinFit_lepB_eta;   //!
   TBranch        *b_KinFit_lepB_phi;   //!

   //HISTOGRAMS
   TH1F		*hTopPtWeight[9][5];
   TH1F		*Gen_hTopDecay[9][5];
   TH1F		*Gen_hTbarmass;
   TH1F		*Gen_hTmass;
   TH1F		*Gen_hWmass;
   TH1F		*Gen_hHmass;
   TH1F		*Gen_hnSimVertexNW;
   TH1F		*Gen_hnSimVertex;
   TH1F 	*MatchJet_hHmass;
   TH1F		*MatchJet_hTmass;
   TH1F		*MatchJet_hptRatio1;
   TH1F		*MatchJet_hptRatio2;
   TH1F		*MatchJet_hptRatio3;
   TH1F		*MatchJet_hptRatio4;

   TH1F 	*MatchJet_deltaPhiLight;
   TH1F 	*MatchJet_deltaPhiB1;
   TH1F 	*MatchJet_deltaPhiB2;

   TH1F 	*MatchJet_deltaEtaLight;
   TH1F 	*MatchJet_deltaEtaB1;
   TH1F 	*MatchJet_deltaEtaB2;
   
   TH1F 	*MatchJet_deltaRLight;
   TH1F 	*MatchJet_deltaRB1;
   TH1F 	*MatchJet_deltaRB2;
   
   TH1F *MatchJet_hdaughterQuarkofTop_index;
   TH1F *MatchJet_hdaughterQuarkofTop_pt; 
   TH1F *MatchJet_hdaughterQuarkofTop_eta;
   TH1F *MatchJet_hdaughterQuarkofTop_phi;
   TH1F *MatchJet_hdaughterQuarkofTop_bDiscrCSV;

   TH1F *MatchJet_hdaughterQuarkofTopBar_index;
   TH1F *MatchJet_hdaughterQuarkofTopBar_pt;
   TH1F *MatchJet_hdaughterQuarkofTopBar_eta;
   TH1F *MatchJet_hdaughterQuarkofTopBar_phi;
   TH1F *MatchJet_hdaughterQuarkofTopBar_bDiscrCSV;  
 
   TH1F *MatchJet_hdaughterQuarkofHplus_index;
   TH1F *MatchJet_hdaughterQuarkofHplus_pt;
   TH1F *MatchJet_hdaughterQuarkofHplus_eta;
   TH1F *MatchJet_hdaughterQuarkofHplus_phi;
   TH1F *MatchJet_hdaughterQuarkofHplus_bDiscrCSV; 

   TH1F *MatchJet_hdaughterQuarkBarofHplus_index;
   TH1F *MatchJet_hdaughterQuarkBarofHplus_pt;
   TH1F *MatchJet_hdaughterQuarkBarofHplus_eta;
   TH1F *MatchJet_hdaughterQuarkBarofHplus_phi;
   TH1F *MatchJet_hdaughterQuarkBarofHplus_bDiscrCSV; 

  TH1F *Reco_hBTagWeight[9][5];
  TH1F *Reco_hnVertexNW[9][5];
  TH1F *Reco_hnVertex[9][5];
  TH1F *Reco_hnSimVertexNW[9][5];
  TH1F *Reco_hnSimVertex[9][5];
  TH1F *Reco_hMUeta[9][5];
  TH1F *Reco_hMUpt[9][5];
  TH1F *Reco_hMUrelIso[9][5];
  
  TH1F *Reco_hnJet[9][5];
  TH1F *Reco_hJeta[9][5];
  TH1F *Reco_hJpt[9][5];
  TH1F *Reco_hJb[9][5];
  TH1F *Reco_hMET[9][5];

  TH1F *KinFit_hprob_v1[9][5];
  TH1F *KinFit_hprob2_v1[9][5];
  TH1F *KinFit_hprob3_v1[9][5];
  TH1F *KinFit_hchi2_v1[9][5];
  TH1F *KinFit_hHmass_v1[9][5]; 
  TH1F *KinFit_hlepWmass_v1[9][5]; 
  TH1F *KinFit_hhadTopmass_v1[9][5];
  TH1F *KinFit_hlepTopmass_v1[9][5];

  TH1F *KinFit_hprob_v2[9][5];
  TH1F *KinFit_hprob2_v2[9][5];
  TH1F *KinFit_hprob3_v2[9][5];
  TH1F *KinFit_hchi2_v2[9][5];
  TH1F *KinFit_hHmass_v2[9][5]; 
  TH1F *KinFit_hlepWmass_v2[9][5]; 
  TH1F *KinFit_hhadTopmass_v2[9][5];
  TH1F *KinFit_hlepTopmass_v2[9][5];

  TH1F *KinFit_hprob_v3[9][5];
  TH1F *KinFit_hprob2_v3[9][5];
  TH1F *KinFit_hprob3_v3[9][5];
  TH1F *KinFit_hchi2_v3[9][5];
  TH1F *KinFit_hHmass_v3[9][5]; 
  TH1F *KinFit_hlepWmass_v3[9][5]; 
  TH1F *KinFit_hhadTopmass_v3[9][5];
  TH1F *KinFit_hlepTopmass_v3[9][5];

  TH1F *KinFit_hprob_v4[9][5];
  TH1F *KinFit_hprob2_v4[9][5];
  TH1F *KinFit_hprob3_v4[9][5];
  TH1F *KinFit_hchi2_v4[9][5];
  TH1F *KinFit_hHmass_v4[9][5]; 
  TH1F *KinFit_hlepWmass_v4[9][5]; 
  TH1F *KinFit_hhadTopmass_v4[9][5];
  TH1F *KinFit_hlepTopmass_v4[9][5];

  TH1F *KinFit_hprob_v5[9][5];
  TH1F *KinFit_hprob2_v5[9][5];
  TH1F *KinFit_hprob3_v5[9][5];
  TH1F *KinFit_hchi2_v5[9][5];
  TH1F *KinFit_hHmass_v5[9][5]; 
  TH1F *KinFit_hlepWmass_v5[9][5]; 
  TH1F *KinFit_hhadTopmass_v5[9][5];
  TH1F *KinFit_hlepTopmass_v5[9][5];

  TH1F *KinFit_hnVertex[9][5];  //stesse indentiche distribuzioni di prima, ma solo per eventi che sopravvivono al fit cinematico
  TH1F *KinFit_hMUeta[9][5];
  TH1F *KinFit_hMUpt[9][5];
  TH1F *KinFit_hnJet[9][5];
  TH1F *KinFit_hJeta[9][5];
  TH1F *KinFit_hJpt[9][5];  
  TH1F *KinFit_hMET[9][5];
  //control plots per versione del fit suggerita da marcello
  TH1F *KinFit_hnVertex_v4[9][5];  //stesse indentiche distribuzioni di prima, ma solo per eventi che sopravvivono al fit cinematico
  TH1F *KinFit_hMUeta_v4[9][5];
  TH1F *KinFit_hMUpt_v4[9][5];
  TH1F *KinFit_hnJet_v4[9][5];
  TH1F *KinFit_hJeta_v4[9][5];
  TH1F *KinFit_hJpt_v4[9][5];  
  TH1F *KinFit_hMET_v4[9][5];
  
  //control plots per versione del fit suggerita da marcello
  TH1F *KinFit_hnVertex_v5[9][5];  //stesse indentiche distribuzioni di prima, ma solo per eventi che sopravvivono al fit cinematico
  TH1F *KinFit_hMUeta_v5[9][5];
  TH1F *KinFit_hMUpt_v5[9][5];
  TH1F *KinFit_hnJet_v5[9][5];
  TH1F *KinFit_hJeta_v5[9][5];
  TH1F *KinFit_hJpt_v5[9][5];  
  TH1F *KinFit_hMET_v5[9][5];


   analyze_ttsplit_kinfit(TTree *tree=0);
   virtual ~analyze_ttsplit_kinfit();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(TFile *fHistos,  TH2D *h2_EffMapB, TH2D * h2_EffMapC, TH2D *h2_EffMapUDSG,TH1D *SFb_errors, char *ext, int flag);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef analyze_ttsplit_kinfit_cxx
analyze_ttsplit_kinfit::analyze_ttsplit_kinfit(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("analyzePatTopSelection.ttbar.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("analyzePatTopSelection.ttbar.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("analyzePatTopSelection.ttbar.root:/analyzeStep9");
      dir->GetObject("HplusGenPartTree",tree);

   }
   Init(tree);
}

analyze_ttsplit_kinfit::~analyze_ttsplit_kinfit()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t analyze_ttsplit_kinfit::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t analyze_ttsplit_kinfit::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void analyze_ttsplit_kinfit::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

  // Set object pointer
   TopJet_pt = 0;
   TopJet_eta = 0;
   TopJet_csv = 0;
   WJet_pt = 0;
   WJet_eta = 0;
   WJet_csv = 0;
   AddJet_pt = 0;
   AddJet_eta = 0;
   AddJet_csv = 0;
   Jpt = 0;
   Jeta = 0;
   Jphi = 0;
   Jtheta = 0;
   Jp = 0;
   Jpx = 0;
   Jpy = 0;
   Jpz = 0;
   JbDiscr = 0;
   Jenergy = 0;
   Jcharge = 0;
   Jflavor = 0;
   KinFit_prob = 0;
   KinFit_chi2 = 0;
   KinFit_lightP_index = 0;
   KinFit_lightQ_index = 0;
   KinFit_hadB_index = 0;
   KinFit_lepB_index = 0;
   KinFit_lepton_index = 0;
   KinFit_hadW_mass = 0;
   KinFit_hadW_pt = 0;
   KinFit_hadW_eta = 0;
   KinFit_hadW_phi = 0;
   KinFit_lepW_mass = 0;
   KinFit_lepW_pt = 0;
   KinFit_lepW_eta = 0;
   KinFit_lepW_phi = 0;
   KinFit_hadTop_mass = 0;
   KinFit_hadTop_pt = 0;
   KinFit_hadTop_eta = 0;
   KinFit_hadTop_phi = 0;
   KinFit_lepTop_mass = 0;
   KinFit_lepTop_pt = 0;
   KinFit_lepTop_eta = 0;
   KinFit_lepTop_phi = 0;
   KinFit_hadQuark_pt = 0;
   KinFit_hadQuark_eta = 0;
   KinFit_hadQuark_phi = 0;
   KinFit_hadQuarkBar_pt = 0;
   KinFit_hadQuarkBar_eta = 0;
   KinFit_hadQuarkBar_phi = 0;
   KinFit_hadB_pt = 0;
   KinFit_hadB_eta = 0;
   KinFit_hadB_phi = 0;
   KinFit_lepB_pt = 0;
   KinFit_lepB_eta = 0;
   KinFit_lepB_phi = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("luminosityBlock", &luminosityBlock, &b_luminosityBlock);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("lumiWeight", &lumiWeight, &b_lumiWeight);
   fChain->SetBranchAddress("lumiWeight_up", &lumiWeight_up, &b_lumiWeight_up);
   fChain->SetBranchAddress("lumiWeight_down", &lumiWeight_down, &b_lumiWeight_down);
   fChain->SetBranchAddress("MCcat", &MCcat, &b_MCcat);
   fChain->SetBranchAddress("GenPart_daughterQuarkBarofHplus_pdgId", &GenPart_daughterQuarkBarofHplus_pdgId, &b_GenPart_daughterQuarkBarofHplus_pdgId);
   fChain->SetBranchAddress("GenPart_daughterQuarkofHplus_pdgId", &GenPart_daughterQuarkofHplus_pdgId, &b_GenPart_daughterQuarkofHplus_pdgId);
   fChain->SetBranchAddress("GenPart_top_pt", &GenPart_top_pt, &b_GenPart_top_pt);
   fChain->SetBranchAddress("GenPart_topBar_pt", &GenPart_topBar_pt, &b_GenPart_topBar_pt);
   fChain->SetBranchAddress("GenPart_Hplus_mass", &GenPart_Hplus_mass, &b_GenPart_Hplus_mass);
   fChain->SetBranchAddress("GenPart_Hmass", &GenPart_Hmass, &b_GenPart_Hmass);
   fChain->SetBranchAddress("GenPart_Wmass", &GenPart_Wmass, &b_GenPart_Wmass);
   fChain->SetBranchAddress("GenPart_Tmass", &GenPart_Tmass, &b_GenPart_Tmass);
   fChain->SetBranchAddress("GenPart_formule_Tmass", &GenPart_formule_Tmass, &b_GenPart_formule_Tmass);
   fChain->SetBranchAddress("GenPart_Tbarmass", &GenPart_Tbarmass, &b_GenPart_Tbarmass);
   fChain->SetBranchAddress("TopJet_pt", &TopJet_pt, &b_TopJet_pt);
   fChain->SetBranchAddress("TopJet_eta", &TopJet_eta, &b_TopJet_eta);
   fChain->SetBranchAddress("TopJet_csv", &TopJet_csv, &b_TopJet_csv);
   fChain->SetBranchAddress("WJet_pt", &WJet_pt, &b_WJet_pt);
   fChain->SetBranchAddress("WJet_eta", &WJet_eta, &b_WJet_eta);
   fChain->SetBranchAddress("WJet_csv", &WJet_csv, &b_WJet_csv);
   fChain->SetBranchAddress("AddJet_pt", &AddJet_pt, &b_AddJet_pt);
   fChain->SetBranchAddress("AddJet_eta", &AddJet_eta, &b_AddJet_eta);
   fChain->SetBranchAddress("AddJet_csv", &AddJet_csv, &b_AddJet_csv);
   fChain->SetBranchAddress("MatchJet_Hmass", &MatchJet_Hmass, &b_MatchJet_Hmass);
   fChain->SetBranchAddress("MatchJet_Tmass", &MatchJet_Tmass, &b_MatchJet_Tmass);
   fChain->SetBranchAddress("MatchJet_formule_Tmass", &MatchJet_formule_Tmass, &b_MatchJet_formule_Tmass);
   fChain->SetBranchAddress("MatchJet_jetflag", &MatchJet_jetflag, &b_MatchJet_jetflag);
   fChain->SetBranchAddress("MatchJet_daughterQuarkofTop_index", &MatchJet_daughterQuarkofTop_index, &b_MatchJet_daughterQuarkofTop_index);
   fChain->SetBranchAddress("MatchJet_daughterQuarkofTop_pt", &MatchJet_daughterQuarkofTop_pt, &b_MatchJet_daughterQuarkofTop_pt);
   fChain->SetBranchAddress("MatchJet_daughterQuarkofTop_recOverGenPt", &MatchJet_daughterQuarkofTop_recOverGenPt, &b_MatchJet_daughterQuarkofTop_recOverGenPt);
   fChain->SetBranchAddress("MatchJet_daughterQuarkofTop_eta", &MatchJet_daughterQuarkofTop_eta, &b_MatchJet_daughterQuarkofTop_eta);
   fChain->SetBranchAddress("MatchJet_daughterQuarkofTop_phi", &MatchJet_daughterQuarkofTop_phi, &b_MatchJet_daughterQuarkofTop_phi);
   fChain->SetBranchAddress("MatchJet_daughterQuarkofTop_bDiscrCSV", &MatchJet_daughterQuarkofTop_bDiscrCSV, &b_MatchJet_daughterQuarkofTop_dbDiscrCSV);
   fChain->SetBranchAddress("MatchJet_daughterQuarkofTopBar_index", &MatchJet_daughterQuarkofTopBar_index, &b_MatchJet_daughterQuarkofTopBar_index);
   fChain->SetBranchAddress("MatchJet_daughterQuarkofTopBar_pt", &MatchJet_daughterQuarkofTopBar_pt, &b_MatchJet_daughterQuarkofTopBar_pt);
   fChain->SetBranchAddress("MatchJet_daughterQuarkofTopBar_recOverGenPt", &MatchJet_daughterQuarkofTopBar_recOverGenPt, &b_MatchJet_daughterQuarkofTopBar_recOverGenPt);
   fChain->SetBranchAddress("MatchJet_daughterQuarkofTopBar_eta", &MatchJet_daughterQuarkofTopBar_eta, &b_MatchJet_daughterQuarkofTopBar_eta);
   fChain->SetBranchAddress("MatchJet_daughterQuarkofTopBar_phi", &MatchJet_daughterQuarkofTopBar_phi, &b_MatchJet_daughterQuarkofTopBar_phi);
   fChain->SetBranchAddress("MatchJet_daughterQuarkofTopBar_bDiscrCSV", &MatchJet_daughterQuarkofTopBar_bDiscrCSV, &b_MatchJet_daughterQuarkofTopBar_dbDiscrCSV);
   fChain->SetBranchAddress("MatchJet_daughterQuarkofHplus_index", &MatchJet_daughterQuarkofHplus_index, &b_MatchJet_daughterQuarkofHplus_index);
   fChain->SetBranchAddress("MatchJet_daughterQuarkofHplus_pt", &MatchJet_daughterQuarkofHplus_pt, &b_MatchJet_daughterQuarkofHplus_pt);
   fChain->SetBranchAddress("MatchJet_daughterQuarkofHplus_recOverGenPt", &MatchJet_daughterQuarkofHplus_recOverGenPt, &b_MatchJet_daughterQuarkofHplus_recOverGenPt);
   fChain->SetBranchAddress("MatchJet_daughterQuarkofHplus_eta", &MatchJet_daughterQuarkofHplus_eta, &b_MatchJet_daughterQuarkofHplus_eta);
   fChain->SetBranchAddress("MatchJet_daughterQuarkofHplus_phi", &MatchJet_daughterQuarkofHplus_phi, &b_MatchJet_daughterQuarkofHplus_phi);
   fChain->SetBranchAddress("MatchJet_daughterQuarkofHplus_bDiscrCSV", &MatchJet_daughterQuarkofHplus_bDiscrCSV, &b_MatchJet_daughterQuarkofHplus_dbDiscrCSV);
   fChain->SetBranchAddress("MatchJet_daughterQuarkBarofHplus_index", &MatchJet_daughterQuarkBarofHplus_index, &b_MatchJet_daughterQuarkBarofHplus_index);
   fChain->SetBranchAddress("MatchJet_daughterQuarkBarofHplus_pt", &MatchJet_daughterQuarkBarofHplus_pt, &b_MatchJet_daughterQuarkBarofHplus_pt);
   fChain->SetBranchAddress("MatchJet_daughterQuarkBarofHplus_recOverGenPt", &MatchJet_daughterQuarkBarofHplus_recOverGenPt, &b_MatchJet_daughterQuarkBarofHplus_recOverGenPt);
   fChain->SetBranchAddress("MatchJet_daughterQuarkBarofHplus_eta", &MatchJet_daughterQuarkBarofHplus_eta, &b_MatchJet_daughterQuarkBarofHplus_eta);
   fChain->SetBranchAddress("MatchJet_daughterQuarkBarofHplus_phi", &MatchJet_daughterQuarkBarofHplus_phi, &b_MatchJet_daughterQuarkBarofHplus_phi);
   fChain->SetBranchAddress("MatchJet_daughterQuarkBarofHplus_bDiscrCSV", &MatchJet_daughterQuarkBarofHplus_bDiscrCSV, &b_MatchJet_daughterQuarkBarofHplus_dbDiscrCSV);
   fChain->SetBranchAddress("MUpt", &MUpt, &b_MUpt);
   fChain->SetBranchAddress("MUeta", &MUeta, &b_MUeta);
   fChain->SetBranchAddress("MUphi", &MUphi, &b_MUphi);
   fChain->SetBranchAddress("MUtheta", &MUtheta, &b_MUtheta);
   fChain->SetBranchAddress("MUp", &MUp, &b_MUp);
   fChain->SetBranchAddress("MUpx", &MUpx, &b_MUpx);
   fChain->SetBranchAddress("MUpy", &MUpy, &b_MUpy);
   fChain->SetBranchAddress("MUpz", &MUpz, &b_MUpz);
   fChain->SetBranchAddress("MUrelIso", &MUrelIso, &b_MUrelIso);
   fChain->SetBranchAddress("MUd0", &MUd0, &b_MUd0);
   fChain->SetBranchAddress("MUdz", &MUdz, &b_MUdz);
   fChain->SetBranchAddress("MUnormChi2", &MUnormChi2, &b_MUnormChi2);
   fChain->SetBranchAddress("MUnOfHits", &MUnOfHits, &b_MUnOfHits);
   fChain->SetBranchAddress("MUlayer", &MUlayer, &b_MUlayer);
   fChain->SetBranchAddress("MUnOfPixels", &MUnOfPixels, &b_MUnOfPixels);
   fChain->SetBranchAddress("MUisGlobal", &MUisGlobal, &b_MUisGlobal);
   fChain->SetBranchAddress("MUisPF", &MUisPF, &b_MUisPF);
   fChain->SetBranchAddress("MUstations", &MUstations, &b_MUstations);
   fChain->SetBranchAddress("nLep", &nLep, &b_nLep);
   fChain->SetBranchAddress("nJet", &nJet, &b_nJet);
   fChain->SetBranchAddress("nbJet", &nbJet, &b_nbJet);
   fChain->SetBranchAddress("nbJetloose", &nbJetloose, &b_nbJetloose);
   fChain->SetBranchAddress("Jpt", &Jpt, &b_Jpt);
   fChain->SetBranchAddress("Jeta", &Jeta, &b_Jeta);
   fChain->SetBranchAddress("Jphi", &Jphi, &b_Jphi);
   fChain->SetBranchAddress("Jtheta", &Jtheta, &b_Jtheta);
   fChain->SetBranchAddress("Jp", &Jp, &b_Jp);
   fChain->SetBranchAddress("Jpx", &Jpx, &b_Jpx);
   fChain->SetBranchAddress("Jpy", &Jpy, &b_Jpy);
   fChain->SetBranchAddress("Jpz", &Jpz, &b_Jpz);
   fChain->SetBranchAddress("JbDiscr", &JbDiscr, &b_JbDiscr);
   fChain->SetBranchAddress("Jenergy", &Jenergy, &b_Jenergy);
   fChain->SetBranchAddress("Jcharge", &Jcharge, &b_Jcharge);
   fChain->SetBranchAddress("Jflavor", &Jflavor, &b_Jflavor);
   fChain->SetBranchAddress("METpt", &METpt, &b_METpt);
   fChain->SetBranchAddress("METpx", &METpx, &b_METpx);
   fChain->SetBranchAddress("METpy", &METpy, &b_METpy);
   fChain->SetBranchAddress("METeta", &METeta, &b_METeta);
   fChain->SetBranchAddress("METphi", &METphi, &b_METphi);
   fChain->SetBranchAddress("METtheta", &METtheta, &b_METtheta);
   fChain->SetBranchAddress("nVertex", &nVertex, &b_nVertex);
   fChain->SetBranchAddress("KinFit_isValid", &KinFit_isValid, &b_KinFit_isValid);
   fChain->SetBranchAddress("ncomb", &ncomb, &b_ncomb);
   fChain->SetBranchAddress("KinFit_prob", &KinFit_prob, &b_KinFit_prob);
   fChain->SetBranchAddress("KinFit_chi2", &KinFit_chi2, &b_KinFit_chi2);
   fChain->SetBranchAddress("KinFit_lightP_index", &KinFit_lightP_index, &b_KinFit_lightP_index);
   fChain->SetBranchAddress("KinFit_lightQ_index", &KinFit_lightQ_index, &b_KinFit_lightQ_index);
   fChain->SetBranchAddress("KinFit_hadB_index", &KinFit_hadB_index, &b_KinFit_hadB_index);
   fChain->SetBranchAddress("KinFit_lepB_index", &KinFit_lepB_index, &b_KinFit_lepB_index);
   fChain->SetBranchAddress("KinFit_lepton_index", &KinFit_lepton_index, &b_KinFit_lepton_index);
   fChain->SetBranchAddress("KinFit_hadW_mass", &KinFit_hadW_mass, &b_KinFit_hadW_mass);
   fChain->SetBranchAddress("KinFit_hadW_pt", &KinFit_hadW_pt, &b_KinFit_hadW_pt);
   fChain->SetBranchAddress("KinFit_hadW_eta", &KinFit_hadW_eta, &b_KinFit_hadW_eta);
   fChain->SetBranchAddress("KinFit_hadW_phi", &KinFit_hadW_phi, &b_KinFit_hadW_phi);
   fChain->SetBranchAddress("KinFit_lepW_mass", &KinFit_lepW_mass, &b_KinFit_lepW_mass);
   fChain->SetBranchAddress("KinFit_lepW_pt", &KinFit_lepW_pt, &b_KinFit_lepW_pt);
   fChain->SetBranchAddress("KinFit_lepW_eta", &KinFit_lepW_eta, &b_KinFit_lepW_eta);
   fChain->SetBranchAddress("KinFit_lepW_phi", &KinFit_lepW_phi, &b_KinFit_lepW_phi);
   fChain->SetBranchAddress("KinFit_hadTop_mass", &KinFit_hadTop_mass, &b_KinFit_hadTop_mass);
   fChain->SetBranchAddress("KinFit_hadTop_pt", &KinFit_hadTop_pt, &b_KinFit_hadTop_pt);
   fChain->SetBranchAddress("KinFit_hadTop_eta", &KinFit_hadTop_eta, &b_KinFit_hadTop_eta);
   fChain->SetBranchAddress("KinFit_hadTop_phi", &KinFit_hadTop_phi, &b_KinFit_hadTop_phi);
   fChain->SetBranchAddress("KinFit_lepTop_mass", &KinFit_lepTop_mass, &b_KinFit_lepTop_mass);
   fChain->SetBranchAddress("KinFit_lepTop_pt", &KinFit_lepTop_pt, &b_KinFit_lepTop_pt);
   fChain->SetBranchAddress("KinFit_lepTop_eta", &KinFit_lepTop_eta, &b_KinFit_lepTop_eta);
   fChain->SetBranchAddress("KinFit_lepTop_phi", &KinFit_lepTop_phi, &b_KinFit_lepTop_phi);
   fChain->SetBranchAddress("KinFit_hadQuark_pt", &KinFit_hadQuark_pt, &b_KinFit_hadQuark_pt);
   fChain->SetBranchAddress("KinFit_hadQuark_eta", &KinFit_hadQuark_eta, &b_KinFit_hadQuark_eta);
   fChain->SetBranchAddress("KinFit_hadQuark_phi", &KinFit_hadQuark_phi, &b_KinFit_hadQuark_phi);
   fChain->SetBranchAddress("KinFit_hadQuarkBar_pt", &KinFit_hadQuarkBar_pt, &b_KinFit_hadQuarkBar_pt);
   fChain->SetBranchAddress("KinFit_hadQuarkBar_eta", &KinFit_hadQuarkBar_eta, &b_KinFit_hadQuarkBar_eta);
   fChain->SetBranchAddress("KinFit_hadQuarkBar_phi", &KinFit_hadQuarkBar_phi, &b_KinFit_hadQuarkBar_phi);
   fChain->SetBranchAddress("KinFit_hadB_pt", &KinFit_hadB_pt, &b_KinFit_hadB_pt);
   fChain->SetBranchAddress("KinFit_hadB_eta", &KinFit_hadB_eta, &b_KinFit_hadB_eta);
   fChain->SetBranchAddress("KinFit_hadB_phi", &KinFit_hadB_phi, &b_KinFit_hadB_phi);
   fChain->SetBranchAddress("KinFit_lepB_pt", &KinFit_lepB_pt, &b_KinFit_lepB_pt);
   fChain->SetBranchAddress("KinFit_lepB_eta", &KinFit_lepB_eta, &b_KinFit_lepB_eta);
   fChain->SetBranchAddress("KinFit_lepB_phi", &KinFit_lepB_phi, &b_KinFit_lepB_phi);
   Notify();
}

Bool_t analyze_ttsplit_kinfit::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void analyze_ttsplit_kinfit::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t analyze_ttsplit_kinfit::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef analyze_ttsplit_kinfit_cxx
