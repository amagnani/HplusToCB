//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Feb  2 19:42:42 2016 by ROOT version 5.32/00
// from TTree HplusGenPartTree/HplusGenPartTree
// found on file: analyzePatTopSelection.data.root
//////////////////////////////////////////////////////////

#ifndef analyze_data_h
#define analyze_data_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class analyze_data {
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

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_luminosityBlock;   //!
   TBranch        *b_event;   //!
   TBranch        *b_lumiWeight;   //!
   TBranch        *b_lumiWeight_up;   //!
   TBranch        *b_lumiWeight_down;   //!
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
 
   //HISTOGRAMS

  TH1F *Reco_hBTagWeight;
  TH1F *Reco_hnVertexNW;
  TH1F *Reco_hnVertex;
  TH1F *Reco_hnSimVertexNW;
  TH1F *Reco_hnSimVertex;
  TH1F *Reco_hMUeta;
  TH1F *Reco_hMUpt;
  TH1F *Reco_hMUrelIso;
  
  TH1F *Reco_hnJet;
  TH1F *Reco_hJeta;
  TH1F *Reco_hJpt;
  TH1F *Reco_hJb;
  TH1F *Reco_hMET;


   analyze_data(TTree *tree=0);
   virtual ~analyze_data();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(TFile *fHistos,  TH2D *h2_EffMapB, TH2D * h2_EffMapC, TH2D *h2_EffMapUDSG,TH1D *SFb_errors, char *ext, int flag);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef analyze_data_cxx
analyze_data::analyze_data(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("analyzePatTopSelection.data.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("analyzePatTopSelection.data.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("analyzePatTopSelection.data.root:/analyzeStep9");
      dir->GetObject("HplusGenPartTree",tree);

   }
   Init(tree);
}

analyze_data::~analyze_data()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t analyze_data::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t analyze_data::LoadTree(Long64_t entry)
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

void analyze_data::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).


   // Set object pointer
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
   Notify();
}

Bool_t analyze_data::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void analyze_data::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t analyze_data::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef analyze_data_cxx
