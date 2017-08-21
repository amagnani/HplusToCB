#define BEff_cxx
#include "BEff.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <vector>
#include <iostream>

void BEff::Loop(TFile *fHistos,  char *ext, int flag, char *outputTag )
{
time_t start= time(0);
 

//Top pt scale factor
TF1 *SF = new TF1("SF","exp(0.156-0.00137*x)",5,1000);

//unweighted
     char Uname_BTaggingEff_Denom_b[30];
     char Uname_BTaggingEff_Denom_c[30];
     char Uname_BTaggingEff_Denom_udsg[30];
     char Uname_BTaggingEff_Num_b[30];
     char Uname_BTaggingEff_Num_c[30];
     char Uname_BTaggingEff_Num_udsg[30];
     char Uname_BTaggingEff_b[30];
     char Uname_BTaggingEff_c[30];
     char Uname_BTaggingEff_udsg[30];

     char name_hTopPtWeight[30];    
     char name_hTopPtWeight_up[30];    
     char name_hTopPtWeight_down[30];    
 
     sprintf(name_hTopPtWeight,      "hTopPtWeight");
     sprintf(name_hTopPtWeight_up ,  "hTopPtWeight_up"); 
     sprintf(name_hTopPtWeight_down ,"hTopPtWeight_down"); 
 
 
     hTopPtWeight= new TH1F(name_hTopPtWeight,   "TopPtweight",100,0,5);	 
     hTopPtWeight_up= new TH1F(name_hTopPtWeight_up,   "TopPtweight",100,0,5);	    
     hTopPtWeight_down= new TH1F(name_hTopPtWeight_down,   "TopPtweight",100,0,5);	      

     sprintf(Uname_BTaggingEff_Denom_b	 , "Uh2_BTaggingEff_Denom_b%s",ext);
     sprintf(Uname_BTaggingEff_Denom_c	 , "Uh2_BTaggingEff_Denom_c%s",ext);
     sprintf(Uname_BTaggingEff_Denom_udsg , "Uh2_BTaggingEff_Denom_udsg%s",ext);
     sprintf(Uname_BTaggingEff_Num_b	 , "Uh2_BTaggingEff_Num_b%s",ext);
     sprintf(Uname_BTaggingEff_Num_c	 , "Uh2_BTaggingEff_Num_c%s",ext);
     sprintf(Uname_BTaggingEff_Num_udsg	 , "Uh2_BTaggingEff_Num_udsg%s",ext);
     sprintf(Uname_BTaggingEff_b      , "Uh2_BTaggingEff_b%s",ext);
     sprintf(Uname_BTaggingEff_c      , "Uh2_BTaggingEff_c%s",ext);
     sprintf(Uname_BTaggingEff_udsg   , "Uh2_BTaggingEff_udsg%s",ext);

     double PtBins[]  = {20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 600, 800};
     double EtaBins[] = {0, 0.8, 1.6, 2.4};
					 

     Uh2_BTaggingEff_Denom_b    =    new TH2D(Uname_BTaggingEff_Denom_b, ";p_{T} [GeV];#eta",16, PtBins, 3, EtaBins);
     Uh2_BTaggingEff_Denom_c    =    new TH2D(Uname_BTaggingEff_Denom_c, ";p_{T} [GeV];#eta",16, PtBins, 3, EtaBins);
     Uh2_BTaggingEff_Denom_udsg = new TH2D(Uname_BTaggingEff_Denom_udsg, ";p_{T} [GeV];#eta",16, PtBins, 3, EtaBins);
     Uh2_BTaggingEff_Num_b     =       new TH2D(Uname_BTaggingEff_Num_b, ";p_{T} [GeV];#eta",16, PtBins, 3, EtaBins);
     Uh2_BTaggingEff_Num_c     =       new TH2D(Uname_BTaggingEff_Num_c, ";p_{T} [GeV];#eta",16, PtBins, 3, EtaBins);
     Uh2_BTaggingEff_Num_udsg  =    new TH2D(Uname_BTaggingEff_Num_udsg, ";p_{T} [GeV];#eta",16, PtBins, 3, EtaBins);
	
     hGenTopPt = new TH1F("hGenTopPt",";gen top quark p_{T} [GeV];events",80,0,400);


//   In a ROOT session, you can do:
//      Root > .L BEff.C
//      Root > BEff t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
//   for (Long64_t jentry=0; jentry<1000001;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      // if (jentry > 20) continue;
      if (jentry%100000 ==0 ) //{ cout<<"events "<<jentry<<" minutes "<<difftime(time(0),start)/60<<endl; }

// cout<< "flag"<<flag<<endl;
//     if(flag==2 || flag==3){ 

	//top pt reweighting 
	float wt, wtbar, t, t_up, t_down;
	wt=SF->Eval(GenPart_top_pt);
	wtbar=SF->Eval(GenPart_topBar_pt);
	t=sqrt(wt*wtbar);
	t_up=t*t;
	t_down=1;
  
//  cout<<"t"<<t<<endl;
//  cout<<"t_up"<<t_up<<endl;
//  cout<<"t_down"<<t_down<<endl;
 
     hTopPtWeight->Fill(t);
     hTopPtWeight_up->Fill(t_up);
     hTopPtWeight_down->Fill(t_down);
     
     hGenTopPt->Fill(GenPart_top_pt);
      
//}
// loop over jets
   for(int it = 0; it < Jpt->size() ; it++)
   {
      if( abs((*Jflavor)[it])==5 )
  
      {
	Uh2_BTaggingEff_Denom_b->Fill((*Jpt)[it], (*Jeta)[it]);
	if( (*JbDiscr)[it] >= 0.679 ) { 
					Uh2_BTaggingEff_Num_b->Fill((*Jpt)[it], (*Jeta)[it]); }
      }
      else if( abs((*Jflavor)[it])==4 )
      {
	Uh2_BTaggingEff_Denom_c->Fill((*Jpt)[it], (*Jeta)[it]);
	if( (*JbDiscr)[it] >= 0.679 ) {
					Uh2_BTaggingEff_Num_c->Fill((*Jpt)[it], (*Jeta)[it]); }
					
      }
      else
      {
	Uh2_BTaggingEff_Denom_udsg->Fill((*Jpt)[it], (*Jeta)[it]);
	if( (*JbDiscr)[it] >= 0.679 ) {
					Uh2_BTaggingEff_Num_udsg->Fill((*Jpt)[it], (*Jeta)[it]);}
        
      }
   
   
   }
    
   }

//Save Histograms

Uh2_BTaggingEff_Denom_b->Write();
Uh2_BTaggingEff_Denom_c->Write();
Uh2_BTaggingEff_Denom_udsg->Write();
Uh2_BTaggingEff_Num_b->Write();
Uh2_BTaggingEff_Num_c->Write();
Uh2_BTaggingEff_Num_udsg->Write();


TH2D *Uh2_BTaggingEff_b    =(TH2D*) Uh2_BTaggingEff_Num_b->Clone();
TH2D *Uh2_BTaggingEff_c    =(TH2D*) Uh2_BTaggingEff_Num_c->Clone();
TH2D *Uh2_BTaggingEff_udsg =(TH2D*) Uh2_BTaggingEff_Num_udsg->Clone();

Uh2_BTaggingEff_b->SetName(Uname_BTaggingEff_b);
Uh2_BTaggingEff_c->SetName(Uname_BTaggingEff_c);
Uh2_BTaggingEff_udsg->SetName(Uname_BTaggingEff_udsg);


Uh2_BTaggingEff_b->Divide(&(*Uh2_BTaggingEff_Denom_b));
Uh2_BTaggingEff_c->Divide(&(*Uh2_BTaggingEff_Denom_c));
Uh2_BTaggingEff_udsg->Divide(&(*Uh2_BTaggingEff_Denom_udsg));

Uh2_BTaggingEff_b->Write();
Uh2_BTaggingEff_c->Write();
Uh2_BTaggingEff_udsg->Write();
 
 hTopPtWeight->Write();
 hTopPtWeight_up->Write();
 hTopPtWeight_down->Write();
 hGenTopPt->Write();

}
