//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Jun 11 20:21:28 2016 by ROOT version 5.32/00
// from TTree HplusGenPartTree/HplusGenPartTree
// found on file: /lustre/cms/store/user/amagnani/DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball/crab_DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_HplusToCBar_Step5Jun8/160610_210913/0000/analyzePatTopSelection_103.root
//////////////////////////////////////////////////////////

#ifndef pippo9_h
#define pippo9_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class pippo9 {
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

   pippo9(TTree *tree=0);
   virtual ~pippo9();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef pippo9_cxx
pippo9::pippo9(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/lustre/cms/store/user/amagnani/DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball/crab_DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_HplusToCBar_Step5Jun8/160610_210913/0000/analyzePatTopSelection_103.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/lustre/cms/store/user/amagnani/DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball/crab_DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_HplusToCBar_Step5Jun8/160610_210913/0000/analyzePatTopSelection_103.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/lustre/cms/store/user/amagnani/DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball/crab_DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_HplusToCBar_Step5Jun8/160610_210913/0000/analyzePatTopSelection_103.root:/analyzeStep9b");
      dir->GetObject("HplusGenPartTree",tree);

   }
   Init(tree);
}

pippo9::~pippo9()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t pippo9::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t pippo9::LoadTree(Long64_t entry)
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

void pippo9::Init(TTree *tree)
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

Bool_t pippo9::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void pippo9::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t pippo9::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef pippo9_cxx
