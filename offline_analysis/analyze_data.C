#define analyze_data_cxx
#include "analyze_data.h"
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

void analyze_data::Loop(TFile *fHistos, TH2D *h2_EffMapB, TH2D * h2_EffMapC, TH2D *h2_EffMapUDSG,TH1D *SFb_errors, char *ext, int flag)
{

time_t start= time(0);
 
     char name_hBTagWeight[30];	 
     char name_hnVertex[30];	 
     char name_hnVertexNW[30]; 
     char name_hnSimVertex[30];	 
     char name_hnSimVertexNW[30]; 
     char name_hnJet[30]; 	
     char name_hJeta[30]; 	
     char name_hJpt[30]; 	
     char name_hJb[30]; 	
     char name_hMET[30]; 	
     char name_hMUeta[30]; 	
     char name_hMUpt[30]; 	
     char name_hMUrelIso[30];
    
					 
     sprintf(name_hBTagWeight 	, "Reco_hBTagWeight_%s_sys0",ext);
     sprintf(name_hnVertex 	, "Reco_hnVertex_%s_sys0",ext);
     sprintf(name_hnVertexNW 	, "Reco_hnVertexNW_%s_sys0",ext);
     sprintf(name_hnSimVertex 	, "Reco_hnSimVertex_%s_sys0",ext);
     sprintf(name_hnSimVertexNW , "Reco_hnSimVertexNW_%s_sys0",ext);
     sprintf(name_hnJet 	, "Reco_hnJet_%s_sys0",ext);	
     sprintf(name_hJeta 	, "Reco_hJeta_%s_sys0",ext);	
     sprintf(name_hJpt 		, "Reco_hJpt_%s_sys0",ext);	
     sprintf(name_hJb 		, "Reco_hJb_%s_sys0",ext);	      
     sprintf(name_hMET 		, "Reco_hMET_%s_sys0",ext);	
 
     sprintf(name_hMUeta 	, "Reco_hMUeta_%s_sys0",ext);	
     sprintf(name_hMUpt 	, "Reco_hMUpt_%s_sys0",ext);	
     sprintf(name_hMUrelIso 	, "Reco_hMUrelIso_%s_sys0",ext);


     Reco_hBTagWeight= new TH1F(name_hBTagWeight,	"Btagweight",100,0,5);  
     Reco_hnVertex= new TH1F(name_hnVertex,		"# Vertexes",70,0,70);  
     Reco_hnVertexNW= new TH1F(name_hnVertexNW,		"# Vertexes not weighted",70,0,70);  
     Reco_hnSimVertex= new TH1F(name_hnSimVertex,	"# Vertexes",70,0,70);  
     Reco_hnSimVertexNW= new TH1F(name_hnSimVertexNW,	"# Vertexes not weighted",70,0,70);  
     Reco_hnJet= new TH1F(name_hnJet,			"# jets",8,3,11);  
     Reco_hJeta= new TH1F(name_hJeta,			"jets eta",60,-3,3);  
     Reco_hJpt= new TH1F(name_hJpt,			"jets pt (Gev)",80,20,100);  
     Reco_hJb= new TH1F(name_hJb,			"jets b-Discriminator (Gev)",40,-1.5,1.5); 
     Reco_hMET= new TH1F(name_hMET,			"MET (Gev)",43,14,100); 
 
     Reco_hMUeta= new TH1F(name_hMUeta,			"muon |eta|",60,-3,3);  
     Reco_hMUpt= new TH1F(name_hMUpt,			"muon pt (Gev)",80,20,100);  
     Reco_hMUrelIso=new TH1F(name_hMUrelIso,		"Muon Relative Isolation",24,0,0.3);



//   In a ROOT session, you can do:
//      Root > .L analyze_data.C
//      Root > analyze_data t
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
       if (jentry%1000000 ==0 ){ cout<<"events "<<jentry<<" minutes "<<difftime(time(0),start)/60<<endl; }
//------------------------------------------------------------------------Computing event weight

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




	Reco_hnJet->Fill(nJet);
	if (Jpt->size()>3){
	for(int jj=0; jj<4; jj++){
	  Reco_hJeta->Fill((*Jeta)[jj]);
	  Reco_hJpt->Fill((*Jpt)[jj]);
	  Reco_hJb->Fill((*JbDiscr)[jj]);
  
	  }}
       //MET
       Reco_hMET->Fill(METpt);  
     
    Reco_hnVertex->Fill(nVertex);
    Reco_hnVertexNW->Fill(nVertex);
    //Reco_hnSimVertex->Fill(nSimVertex);
    //Reco_hnSimVertexNW->Fill(nSimVertex);
    Reco_hMUeta->Fill(MUeta);
    Reco_hMUpt->Fill(MUpt);
    Reco_hMUrelIso->Fill(MUrelIso);



   }
//Writinghistograms


   Reco_hBTagWeight->Write();
   Reco_hnVertex->Write();
   Reco_hnSimVertex->Write();
   Reco_hnSimVertexNW->Write();
   Reco_hnJet->Write();
   Reco_hJeta->Write();
   Reco_hJpt->Write();
   Reco_hJb->Write(); 
   Reco_hMET->Write();

   Reco_hMUeta->Write();
   Reco_hMUpt->Write(); 
   Reco_hMUrelIso->Write();

}
