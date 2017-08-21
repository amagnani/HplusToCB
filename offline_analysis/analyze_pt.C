#define analyze_pt_cxx
#include "analyze_pt.h"
#include <TH2.h>
#include <TH1F.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include "JetInfo.h"
#include "BTagWeight.h"
#include <vector>
#include <list>
using namespace std;

bool isPartOf(char* w1, char* w2)
{
    int i=0;
    int j=0;

    for(i;i < strlen(w1); i++)
    {
        if(w1[i] == w2[j])
        {
            j++;
        }
    }

    if(strlen(w2) == j)
        return true;
    else
        return false;
}

void analyze_pt::Loop(TFile *fHistos, TH2D *h2_EffMapB, TH2D * h2_EffMapC, TH2D *h2_EffMapUDSG,TH1D *SFb_errors, char *ext, int flag)
{
time_t start= time(0);
     char name_topb[30];	 
     char name_antitopb[30];	 
     char name_b[30];	     
     char name_c[30];	     
					 
     sprintf(name_topb 	, "topb");
     sprintf(name_antitopb, "antitopb");
     sprintf(name_b  , "b");
     sprintf(name_c  , "c"); 

 
     topb= new TH1F(name_topb,			"jet pt (Gev)",80,20,100);  
     antitopb= new TH1F(name_antitopb,			"jet pt (Gev)",80,20,100);  
     b= new TH1F(name_b,			"jet pt (Gev)",80,20,100);  
     c= new TH1F(name_c,			"jet pt (Gev)",80,20,100);  




//   In a ROOT session, you can do:
//      Root > .L analyze_pt.C
//      Root > analyze_pt t
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
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
       if (jentry % 1000000 ==0 ){ cout<<"events "<<jentry<<" minutes "<<difftime(time(0),start)/60<<endl; }
       
//------------------------------------------------------------------------Computing event weight


  // MCcat;   // =1   ---> ttbb  
	      // =2   ---> ttbj
	      // =3   ---> ttcc
	      // =4   ---> ttqq
	      // =5   ---> ttother


int region;   //region =1   ---> REGIONE A : MET<20, Iso<0.12  
	      //region =2   ---> REGIONE B : MET<20, Iso>0.12
	      //region =3   ---> REGIONE C : MET>20, Iso>0.12 non isolated, regione da cui estrarre la shape per la QCD
	      //region =4   ---> REGIONE D : MET>20, Iso<0.12 ISOLATED

int usualSel; //intero che mi dice se devo riempire o no gli istogrammi secondo le selezioni senza stima QCD data driven

if ( ext=="Start") {usualSel =1;}
else {
  if ( METpt <=20 &&  MUrelIso <0.12 ) {region = 1;
  				       if ( ext=="4" || ext=="6" )  { usualSel= 1;}
  				       			       else { usualSel= 0;}
 				       }

  if ( METpt <=20 &&  MUrelIso >=0.12 ) {region = 2;
  				       if ( ext=="4" || ext=="6" )  { usualSel= 0;}
  				       			       else { usualSel= 0;}
 				       }
  if ( METpt >20 &&  MUrelIso >=0.12 ) {region = 3;
  				       if ( ext=="4" || ext=="6" )  { usualSel= 0;}
  				       			       else { usualSel= 0;}
 				       }
  if ( METpt >20 &&  MUrelIso <0.12 ) {region = 4;
  				       if ( ext=="4" || ext=="6" )  { usualSel= 1;}
  				       			       else { usualSel= 1;}
 				       }
}
if (!usualSel) continue;

 

	topb->		Fill(MatchJet_daughterQuarkofTop_pt);
	antitopb->	Fill(MatchJet_daughterQuarkofTopBar_pt);
	b->		Fill(MatchJet_daughterQuarkBarofHplus_pt);
	c->		Fill(MatchJet_daughterQuarkofHplus_pt);
}


//Writinghistograms

	topb->	Write();
	antitopb->	Write();
	b->	Write();	
	c->	Write();	
  
}
