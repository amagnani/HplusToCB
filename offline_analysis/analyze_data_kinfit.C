#define analyze_data_kinfit_cxx
#include "analyze_data_kinfit.h"
#include <TH2.h>
#include <TH1F.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <math.h>
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

void analyze_data_kinfit::Loop(TFile *fHistos, TH2D *h2_EffMapB, TH2D * h2_EffMapC, TH2D *h2_EffMapUDSG,TH1D *SFb_errors, char *ext, int flag)
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


     Reco_hBTagWeight= new TH1F(name_hBTagWeight,		"Btagweight",100,0,5);  
     Reco_hnVertex= new TH1F(name_hnVertex,		"# Vertexes",70,0,70);  
     Reco_hnVertexNW= new TH1F(name_hnVertexNW,		"# Vertexes not weighted",70,0,70);  
     Reco_hnSimVertex= new TH1F(name_hnSimVertex,		"# Vertexes",70,0,70);  
     Reco_hnSimVertexNW= new TH1F(name_hnSimVertexNW,	"# Vertexes not weighted",70,0,70);  
     Reco_hnJet= new TH1F(name_hnJet,			"# jets",8,3,11);  
     Reco_hJeta= new TH1F(name_hJeta,			"jets eta",60,-3,3);  
     Reco_hJpt= new TH1F(name_hJpt,			"jets pt (Gev)",80,20,100);  
     Reco_hJb= new TH1F(name_hJb,				"jets b-Discriminator (Gev)",40,-1.5,1.5); 
     Reco_hMET= new TH1F(name_hMET,			"MET (Gev)",43,14,100); 
 
     Reco_hMUeta= new TH1F(name_hMUeta,			"muon |eta|",60,-3,3);  
     Reco_hMUpt= new TH1F(name_hMUpt,			"muon pt (Gev)",80,20,100);  
     Reco_hMUrelIso=new TH1F(name_hMUrelIso,		"Muon Relative Isolation",24,0,0.3);

     char name_hprob_v1[50];
     char name_hprob2_v1[50];
     char name_hprob3_v1[50];
     char name_hchi2_v1[50];
     char name_hHmass_v1[50];
     char name_hlepWmass_v1[50];
     char name_hhadTopmass_v1[50];
     char name_hlepTopmass_v1[50];

     char name_hprob_v2[50];
     char name_hprob2_v2[50];
     char name_hprob3_v2[50];
     char name_hchi2_v2[50];
     char name_hHmass_v2[50];
     char name_hlepWmass_v2[50];
     char name_hhadTopmass_v2[50];
     char name_hlepTopmass_v2[50];

     char name_hprob_v3[50];
     char name_hprob2_v3[50];
     char name_hprob3_v3[50];
     char name_hchi2_v3[50];
     char name_hHmass_v3[50];
     char name_hlepWmass_v3[50];
     char name_hhadTopmass_v3[50];
     char name_hlepTopmass_v3[50];

     char name_hprob_v4[50];
     char name_hprob2_v4[50];
     char name_hprob3_v4[50];
     char name_hchi2_v4[50];
     char name_hHmass_v4[50];
     char name_hlepWmass_v4[50];
     char name_hhadTopmass_v4[50];
     char name_hlepTopmass_v4[50];

     char name_hprob_v5[50];
     char name_hprob2_v5[50];
     char name_hprob3_v5[50];
     char name_hchi2_v5[50];
     char name_hHmass_v5[50];
     char name_hlepWmass_v5[50];
     char name_hhadTopmass_v5[50];
     char name_hlepTopmass_v5[50];


     sprintf(name_hprob_v1,"KinFit_hprob_v1_%s_sys0",ext);
     sprintf(name_hprob2_v1,"KinFit_hprob2_v1_%s_sys0",ext);
     sprintf(name_hprob3_v1,"KinFit_hprob3_v1_%s_sys0",ext);
     sprintf(name_hchi2_v1,"KinFit_hchi2_v1_%s_sys0",ext);
     sprintf(name_hHmass_v1,"KinFit_hHmass_v1_%s_sys0",ext);
     sprintf(name_hlepWmass_v1,"KinFit_hlepWmass_v1_%s_sys0",ext);
     sprintf(name_hhadTopmass_v1,"KinFit_hhadTopmass_v1_%s_sys0",ext);
     sprintf(name_hlepTopmass_v1,"KinFit_hlepTopmass_v1_%s_sys0",ext);

     KinFit_hprob_v1= new TH1F(name_hprob_v1,"KinFit Probability",40,0,1);
     KinFit_hprob2_v1= new TH1F(name_hprob2_v1,"KinFit Probability",40,0,1);
     KinFit_hprob3_v1= new TH1F(name_hprob3_v1,"KinFit Probability",40,0,1);
     KinFit_hchi2_v1= new TH1F(name_hchi2_v1,"KinFit Chi Squared",100,0,100);
     KinFit_hHmass_v1= new TH1F(name_hHmass_v1,"H invariant mass (Gev)",40,0,200);
     KinFit_hlepWmass_v1= new TH1F(name_hlepWmass_v1,"W invariant mass (Gev)",40,0,200);
     KinFit_hhadTopmass_v1= new TH1F(name_hhadTopmass_v1,"hadronic top invariant mass (Gev)",70,50,400);
     KinFit_hlepTopmass_v1= new TH1F(name_hlepTopmass_v1,"leptonic top invariant mass (Gev)",70,50,400);

     sprintf(name_hprob_v2,"KinFit_hprob_v2_%s_sys0",ext);
     sprintf(name_hprob2_v2,"KinFit_hprob2_v2_%s_sys0",ext);
     sprintf(name_hprob3_v2,"KinFit_hprob3_v2_%s_sys0",ext);
     sprintf(name_hchi2_v2,"KinFit_hchi2_v2_%s_sys0",ext);
     sprintf(name_hHmass_v2,"KinFit_hHmass_v2_%s_sys0",ext);
     sprintf(name_hlepWmass_v2,"KinFit_hlepWmass_v2_%s_sys0",ext);
     sprintf(name_hhadTopmass_v2,"KinFit_hhadTopmass_v2_%s_sys0",ext);
     sprintf(name_hlepTopmass_v2,"KinFit_hlepTopmass_v2_%s_sys0",ext);

     KinFit_hprob_v2= new TH1F(name_hprob_v2,"KinFit Probability",40,0,1);
     KinFit_hprob2_v2= new TH1F(name_hprob2_v2,"KinFit Probability",40,0,1);
     KinFit_hprob3_v2= new TH1F(name_hprob3_v2,"KinFit Probability",40,0,1);
     KinFit_hchi2_v2= new TH1F(name_hchi2_v2,"KinFit Chi Squared",100,0,100);
     KinFit_hHmass_v2= new TH1F(name_hHmass_v2,"H invariant mass (Gev)",40,0,200);
     KinFit_hlepWmass_v2= new TH1F(name_hlepWmass_v2,"W invariant mass (Gev)",40,0,200);
     KinFit_hhadTopmass_v2= new TH1F(name_hhadTopmass_v2,"hadronic top invariant mass (Gev)",70,50,400);
     KinFit_hlepTopmass_v2= new TH1F(name_hlepTopmass_v2,"leptonic top invariant mass (Gev)",70,50,400);

     sprintf(name_hprob_v3,"KinFit_hprob_v3_%s_sys0",ext);
     sprintf(name_hprob2_v3,"KinFit_hprob2_v3_%s_sys0",ext);
     sprintf(name_hprob3_v3,"KinFit_hprob3_v3_%s_sys0",ext);
     sprintf(name_hchi2_v3,"KinFit_hchi2_v3_%s_sys0",ext);
     sprintf(name_hHmass_v3,"KinFit_hHmass_v3_%s_sys0",ext);
     sprintf(name_hlepWmass_v3,"KinFit_hlepWmass_v3_%s_sys0",ext);
     sprintf(name_hhadTopmass_v3,"KinFit_hhadTopmass_v3_%s_sys0",ext);
     sprintf(name_hlepTopmass_v3,"KinFit_hlepTopmass_v3_%s_sys0",ext);

     KinFit_hprob_v3= new TH1F(name_hprob_v3,"KinFit Probability",40,0,1);
     KinFit_hprob2_v3= new TH1F(name_hprob2_v3,"KinFit Probability",40,0,1);
     KinFit_hprob3_v3= new TH1F(name_hprob3_v3,"KinFit Probability",40,0,1);
     KinFit_hchi2_v3= new TH1F(name_hchi2_v3,"KinFit Chi Squared",100,0,100);
     KinFit_hHmass_v3= new TH1F(name_hHmass_v3,"H invariant mass (Gev)",40,0,200);
     KinFit_hlepWmass_v3= new TH1F(name_hlepWmass_v3,"W invariant mass (Gev)",40,0,200);
     KinFit_hhadTopmass_v3= new TH1F(name_hhadTopmass_v3,"hadronic top invariant mass (Gev)",70,50,400);
     KinFit_hlepTopmass_v3= new TH1F(name_hlepTopmass_v3,"leptonic top invariant mass (Gev)",70,50,400);

     sprintf(name_hprob_v4,"KinFit_hprob_v4_%s_sys0",ext);
     sprintf(name_hprob2_v4,"KinFit_hprob2_v4_%s_sys0",ext);
     sprintf(name_hprob3_v4,"KinFit_hprob3_v4_%s_sys0",ext);
     sprintf(name_hchi2_v4,"KinFit_hchi2_v4_%s_sys0",ext);
     sprintf(name_hHmass_v4,"KinFit_hHmass_v4_%s_sys0",ext);
     sprintf(name_hlepWmass_v4,"KinFit_hlepWmass_v4_%s_sys0",ext);
     sprintf(name_hhadTopmass_v4,"KinFit_hhadTopmass_v4_%s_sys0",ext);
     sprintf(name_hlepTopmass_v4,"KinFit_hlepTopmass_v4_%s_sys0",ext);

     KinFit_hprob_v4= new TH1F(name_hprob_v4,"KinFit Probability",40,0,1);
     KinFit_hprob2_v4= new TH1F(name_hprob2_v4,"KinFit Probability",40,0,1);
     KinFit_hprob3_v4= new TH1F(name_hprob3_v4,"KinFit Probability",40,0,1);
     KinFit_hchi2_v4= new TH1F(name_hchi2_v4,"KinFit Chi Squared",100,0,100);
     KinFit_hHmass_v4= new TH1F(name_hHmass_v4,"H invariant mass (Gev)",40,0,200);
     KinFit_hlepWmass_v4= new TH1F(name_hlepWmass_v4,"W invariant mass (Gev)",40,0,200);
     KinFit_hhadTopmass_v4= new TH1F(name_hhadTopmass_v4,"hadronic top invariant mass (Gev)",70,50,400);
     KinFit_hlepTopmass_v4= new TH1F(name_hlepTopmass_v4,"leptonic top invariant mass (Gev)",70,50,400);

     sprintf(name_hprob_v5,"KinFit_hprob_v5_%s_sys0",ext);
     sprintf(name_hprob2_v5,"KinFit_hprob2_v5_%s_sys0",ext);
     sprintf(name_hprob3_v5,"KinFit_hprob3_v5_%s_sys0",ext);
     sprintf(name_hchi2_v5,"KinFit_hchi2_v5_%s_sys0",ext);
     sprintf(name_hHmass_v5,"KinFit_hHmass_v5_%s_sys0",ext);
     sprintf(name_hlepWmass_v5,"KinFit_hlepWmass_v5_%s_sys0",ext);
     sprintf(name_hhadTopmass_v5,"KinFit_hhadTopmass_v5_%s_sys0",ext);
     sprintf(name_hlepTopmass_v5,"KinFit_hlepTopmass_v5_%s_sys0",ext);

     KinFit_hprob_v5= new TH1F(name_hprob_v5,"KinFit Probability",40,0,1);
     KinFit_hprob2_v5= new TH1F(name_hprob2_v5,"KinFit Probability",40,0,1);
     KinFit_hprob3_v5= new TH1F(name_hprob3_v5,"KinFit Probability",40,0,1);
     KinFit_hchi2_v5= new TH1F(name_hchi2_v5,"KinFit Chi Squared",100,0,100);
     KinFit_hHmass_v5= new TH1F(name_hHmass_v5,"H invariant mass (Gev)",40,0,200);
     KinFit_hlepWmass_v5= new TH1F(name_hlepWmass_v5,"W invariant mass (Gev)",40,0,200);
     KinFit_hhadTopmass_v5= new TH1F(name_hhadTopmass_v5,"hadronic top invariant mass (Gev)",70,50,400);
     KinFit_hlepTopmass_v5= new TH1F(name_hlepTopmass_v5,"leptonic top invariant mass (Gev)",70,50,400);


	  char name_KinFit_hnVertex[30];  
	  char name_KinFit_hMUeta[30];
	  char name_KinFit_hMUpt[30];
	  char name_KinFit_hnJet[30];
	  char name_KinFit_hJeta[30];
	  char name_KinFit_hJpt[30];  
	  char name_KinFit_hMET[30];

	  char name_KinFit_hnVertex_v4[30];  
	  char name_KinFit_hMUeta_v4[30];
	  char name_KinFit_hMUpt_v4[30];
	  char name_KinFit_hnJet_v4[30];
	  char name_KinFit_hJeta_v4[30];
	  char name_KinFit_hJpt_v4[30];  
	  char name_KinFit_hMET_v4[30];

	  char name_KinFit_hnVertex_v5[30];  
	  char name_KinFit_hMUeta_v5[30];
	  char name_KinFit_hMUpt_v5[30];
	  char name_KinFit_hnJet_v5[30];
	  char name_KinFit_hJeta_v5[30];
	  char name_KinFit_hJpt_v5[30];  
	  char name_KinFit_hMET_v5[30];


     sprintf(	name_KinFit_hnVertex            ,"KinFit_hnVertex_%s_sys0",ext);
     sprintf(	name_KinFit_hMUeta              ,"KinFit_hMUeta_%s_sys0",ext);
     sprintf(	name_KinFit_hMUpt	        ,"KinFit_hMUpt_%s_sys0",ext);
     sprintf(   name_KinFit_hnJet	        ,"KinFit_hnJet_%s_sys0",ext);
     sprintf(	name_KinFit_hJeta	        ,"KinFit_hJeta_%s_sys0",ext);
     sprintf(	name_KinFit_hJpt                ,"KinFit_hJpt_%s_sys0",ext);
     sprintf(	name_KinFit_hMET	        ,"KinFit_hMET_%s_sys0",ext);
 
     sprintf(	name_KinFit_hnVertex_v4         ,"KinFit_hnVertex_v4_%s_sys0",ext);
     sprintf(	name_KinFit_hMUeta_v4           ,"KinFit_hMUeta_v4_%s_sys0",ext);
     sprintf(	name_KinFit_hMUpt_v4	        ,"KinFit_hMUpt_v4_%s_sys0",ext);
     sprintf(   name_KinFit_hnJet_v4	        ,"KinFit_hnJet_v4_%s_sys0",ext);
     sprintf(	name_KinFit_hJeta_v4	        ,"KinFit_hJeta_v4_%s_sys0",ext);
     sprintf(	name_KinFit_hJpt_v4             ,"KinFit_hJpt_v4_%s_sys0",ext);
     sprintf(	name_KinFit_hMET_v4	        ,"KinFit_hMET_v4_%s_sys0",ext);
 
 
     sprintf(	name_KinFit_hnVertex_v5         ,"KinFit_hnVertex_v5_%s_sys0",ext);
     sprintf(	name_KinFit_hMUeta_v5           ,"KinFit_hMUeta_v5_%s_sys0",ext);
     sprintf(	name_KinFit_hMUpt_v5	        ,"KinFit_hMUpt_v5_%s_sys0",ext);
     sprintf(   name_KinFit_hnJet_v5	        ,"KinFit_hnJet_v5_%s_sys0",ext);
     sprintf(	name_KinFit_hJeta_v5	        ,"KinFit_hJeta_v5_%s_sys0",ext);
     sprintf(	name_KinFit_hJpt_v5             ,"KinFit_hJpt_v5_%s_sys0",ext);
     sprintf(	name_KinFit_hMET_v5	        ,"KinFit_hMET_v5_%s_sys0",ext);
 

     KinFit_hnVertex= new TH1F(name_KinFit_hnVertex,  	     "# Vertexes",70,0,70);  
     KinFit_hJeta= new TH1F(name_KinFit_hJeta,		     "jets eta",60,-3,3);  
     KinFit_hnJet= new TH1F(name_KinFit_hnJet,		     "# jets",8,3,11);  
     KinFit_hJpt= new TH1F(name_KinFit_hJpt,  		     "jets pt (Gev)",80,20,100);  
     KinFit_hMET= new TH1F(name_KinFit_hMET,  		     "MET (Gev)",43,14,100); 
     KinFit_hMUeta= new TH1F(name_KinFit_hMUeta,		     "muon |eta|",60,-3,3);  
     KinFit_hMUpt= new TH1F(name_KinFit_hMUpt,		     "muon pt (Gev)",80,20,100);  

     KinFit_hnVertex_v4= new TH1F(name_KinFit_hnVertex_v4,  	     "# Vertexes",70,0,70);  
     KinFit_hJeta_v4= new TH1F(name_KinFit_hJeta_v4,		     "jets eta",60,-3,3);  
     KinFit_hnJet_v4= new TH1F(name_KinFit_hnJet_v4,		     "# jets",8,3,11);  
     KinFit_hJpt_v4= new TH1F(name_KinFit_hJpt_v4,  		     "jets pt (Gev)",80,20,100);  
     KinFit_hMET_v4= new TH1F(name_KinFit_hMET_v4,  		     "MET (Gev)",43,14,100); 
     KinFit_hMUeta_v4= new TH1F(name_KinFit_hMUeta_v4,		     "muon |eta|",60,-3,3);  
     KinFit_hMUpt_v4= new TH1F(name_KinFit_hMUpt_v4,		     "muon pt (Gev)",80,20,100); 
      
     KinFit_hnVertex_v5= new TH1F(name_KinFit_hnVertex_v5,  	     "# Vertexes",70,0,70);  
     KinFit_hJeta_v5= new TH1F(name_KinFit_hJeta_v5,		     "jets eta",60,-3,3);  
     KinFit_hnJet_v5= new TH1F(name_KinFit_hnJet_v5,		     "# jets",8,3,11);  
     KinFit_hJpt_v5= new TH1F(name_KinFit_hJpt_v5,  		     "jets pt (Gev)",80,20,100);  
     KinFit_hMET_v5= new TH1F(name_KinFit_hMET_v5,  		     "MET (Gev)",43,14,100); 
     KinFit_hMUeta_v5= new TH1F(name_KinFit_hMUeta_v5,		     "muon |eta|",60,-3,3);  
     KinFit_hMUpt_v5= new TH1F(name_KinFit_hMUpt_v5,		     "muon pt (Gev)",80,20,100);  


//   In a ROOT session, you can do:
//      Root > .L analyze_data_kinfit.C
//      Root > analyze_data_kinfit t
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
 
 //******************************************************************kinematic fit
 
       int NDF=1;
 
 vector<int> goodCombs; 	  //list of combinations with b jets in the right places, fit prob >0.2 and pt jets greater than 25 GeV
 vector<int> goodCombs4leading;   //list of combinations with b jets in the right places, considering only the 4 leading jets, fit prob >0.2 and pt jets greater than 25 GeV
 
 for(int cc=0; cc<ncomb; cc++){
 
 int gc=0;   //pt cut
 int gh=0;  //4 leading jets
 int v5=0;  //riempio la version v5?
 
 int Pindx = (*KinFit_lightP_index)[cc];
 int Qindx = (*KinFit_lightQ_index)[cc];
 int hBindx= (*KinFit_hadB_index)[cc];
 int lBindx= (*KinFit_lepB_index)[cc];
 
 double lightPb = (*JbDiscr)[Pindx];
 double lightQb = (*JbDiscr)[Qindx];
 double hadBb	= (*JbDiscr)[hBindx];
 double lepBb	= (*JbDiscr)[lBindx];
 
 double lightPpt = (*Jpt)[Pindx];
 double lightQpt = (*Jpt)[Qindx];
 double hadBpt   = (*Jpt)[hBindx];
 double lepBpt   = (*Jpt)[lBindx];
 
 
 if((*KinFit_hadQuark_pt)[cc]>25 && (*KinFit_hadQuarkBar_pt)[cc]>25 && (*KinFit_lepB_pt)[cc]>25 && (*KinFit_hadB_pt)[cc]>25) gc=1;
 if(Pindx<4 && Qindx<4 && hBindx<4 && lBindx<4 ) gh=1;
 float myprob=TMath::Prob((*KinFit_chi2)[cc],NDF);
 float myprob3=TMath::Exp(-1/double(NDF)*(*KinFit_chi2)[cc]);
 
 //cout<<lightPb<<" "<<lightQb<<" "<<hadBb<<" "<<lepBb<<endl;
 if (isPartOf(ext,"9b")){
 if ( (hadBb>0.679) && (lepBb>0.679) && ( (lightPb>0.679) ^ (lightQb>0.679) ) && gc && myprob3 >0.2 )	    goodCombs.push_back(cc);
 if ( (hadBb>0.679) && (lepBb>0.679) && ( (lightPb>0.679) ^ (lightQb>0.679) ) && gc && myprob3 >0.2 && cc==0 ) v5=1;	   
 if ( (hadBb>0.679) && (lepBb>0.679) && ( (lightPb>0.679) ^ (lightQb>0.679) ) && gc && gh && myprob3 >0.2 ) goodCombs4leading.push_back(cc);
 }
 else {
 if ( (hadBb>0.244) && (lepBb>0.679) && ( (lightPb>0.679) ^ (lightQb>0.679) ) && gc && myprob3 >0.2   )       goodCombs.push_back(cc);
 if ( (hadBb>0.244) && (lepBb>0.679) && ( (lightPb>0.679) ^ (lightQb>0.679) ) && gc && myprob3 >0.2  && cc==0  ) v5=1;
 if ( (hadBb>0.244) && (lepBb>0.679) && ( (lightPb>0.679) ^ (lightQb>0.679) ) && gc && gh && myprob3 >0.2   ) goodCombs4leading.push_back(cc);
 }
 
 
 //considero solo la prima combinazione, e controllo che abbia i b tags nei posto giusti (versione5)
 if( v5==1) {
 
      //Fill simple control plots after the kinfit*************************************
 
 
	      KinFit_hnJet_v5->Fill(nJet);
	      if (Jpt->size()>3){
		      for(int jj=0; jj<4; jj++){
				      KinFit_hJeta_v5->Fill((*Jeta)[jj]);
				      KinFit_hJpt_v5->Fill((*Jpt)[jj]);
			      }}
	      KinFit_hMET_v5->Fill(METpt);  
	      KinFit_hnVertex_v5->Fill(nVertex);
	      KinFit_hMUeta_v5->Fill(MUeta);
	      KinFit_hMUpt_v5->Fill(MUpt);
 
 //Fill simple control plots after the kinfit*************************************
	float myprob=TMath::Prob((*KinFit_chi2)[cc],NDF);
	float myprob3=TMath::Exp(-1/double(NDF)*(*KinFit_chi2)[cc]);
 
       
	KinFit_hprob_v5->Fill((*KinFit_prob)[cc]);
	KinFit_hprob2_v5->Fill(myprob[cc]);
	KinFit_hprob3_v5->Fill(myprob3[cc]);
	KinFit_hchi2_v5->Fill((*KinFit_chi2)[cc]);
	KinFit_hHmass_v5->Fill((*KinFit_hadW_mass)[cc]);
	KinFit_hlepWmass_v5->Fill((*KinFit_lepW_mass)[cc]);
	KinFit_hhadTopmass_v5->Fill((*KinFit_hadTop_mass)[cc]);
	KinFit_hlepTopmass_v5->Fill((*KinFit_lepTop_mass)[cc]);
 
 }
 v5=0;
 
 }
 
 //cout<<goodCombs.size()<<endl;
 
 
 if(goodCombs.size()>1){
 
 
 //Fill simple control plots after the kinfit*************************************
 
 
     KinFit_hnJet->Fill(nJet);
     if (Jpt->size()>3){
     for(int jj=0; jj<4; jj++){
       KinFit_hJeta->Fill((*Jeta)[jj]);
       KinFit_hJpt->Fill((*Jpt)[jj]);
       }}
     KinFit_hMET->Fill(METpt);  
     KinFit_hnVertex->Fill(nVertex);
     KinFit_hMUeta->Fill(MUeta);
     KinFit_hMUpt->Fill(MUpt);
 
 //Fill simple control plots after the kinfit*************************************
 
 
 int bestcomb=-1; 
 int s1=goodCombs[0];
 int s2=goodCombs[1];
 int hadb1=(*KinFit_hadB_index)[s1];
 int hadb2=(*KinFit_hadB_index)[s2];
 
 //for(int c=0; c<goodCombs.size(); c++){
  for(int c=0; c<2; c++){
  
  int myc=goodCombs[c];
  
  int Pindx = (*KinFit_lightP_index)[myc];
  int Qindx = (*KinFit_lightQ_index)[myc];
  int hBindx= (*KinFit_hadB_index)[myc];
  int lBindx= (*KinFit_lepB_index)[myc];
  
  
 
  //cout<<KinFit_prob[myc]<<" "<<KinFit_hadW_mass[myc]<<" "<<deltaR[myc]<< " " <<deltaRinit[myc]<<endl;
  
      float myprob1=TMath::Prob((*KinFit_chi2)[myc],NDF);
      float myprob31=TMath::Exp(-1/double(NDF)*(*KinFit_chi2)[myc]);
  
	
      KinFit_hprob_v1->Fill((*KinFit_prob)[myc],myprob31);
      KinFit_hprob2_v1->Fill(myprob[myc],myprob31);
      KinFit_hprob3_v1->Fill(myprob3[myc],myprob31);
      KinFit_hchi2_v1->Fill((*KinFit_chi2)[myc],myprob31);
      KinFit_hHmass_v1->Fill((*KinFit_hadW_mass)[myc],myprob31);
      KinFit_hlepWmass_v1->Fill((*KinFit_lepW_mass)[myc],myprob31);
      KinFit_hhadTopmass_v1->Fill((*KinFit_hadTop_mass)[myc],myprob31);
      KinFit_hlepTopmass_v1->Fill((*KinFit_lepTop_mass)[myc],myprob31);
  
  
  if(c==0){   
      KinFit_hprob_v2->Fill((*KinFit_prob)[myc]);
      KinFit_hprob2_v2->Fill(myprob[myc]);
      KinFit_hprob3_v2->Fill(myprob3[myc]);
      KinFit_hchi2_v2->Fill((*KinFit_chi2)[myc]);
      KinFit_hHmass_v2->Fill((*KinFit_hadW_mass)[myc]);
      KinFit_hlepWmass_v2->Fill((*KinFit_lepW_mass)[myc]);
      KinFit_hhadTopmass_v2->Fill((*KinFit_hadTop_mass)[myc]);
      KinFit_hlepTopmass_v2->Fill((*KinFit_lepTop_mass)[myc]);
  
  }
  
  
     }
 
 // fit by mass
  if ( hadb1>hadb2 ) {bestcomb=goodCombs[0];}
   else { bestcomb=goodCombs[1];}  
 
      float myprob=TMath::Prob((*KinFit_chi2)[bestcomb],NDF);
      float myprob3=TMath::Exp(-1/double(NDF)*(*KinFit_chi2)[bestcomb]);
      KinFit_hprob_v3->Fill((*KinFit_prob)[bestcomb]);
      KinFit_hprob2_v3->Fill(myprob[bestcomb]);
      KinFit_hprob3_v3->Fill(myprob3[bestcomb]);
      KinFit_hchi2_v3->Fill((*KinFit_chi2)[bestcomb]);
      KinFit_hHmass_v3->Fill((*KinFit_hadW_mass)[bestcomb]);
      KinFit_hlepWmass_v3->Fill((*KinFit_lepW_mass)[bestcomb]);
      KinFit_hhadTopmass_v3->Fill((*KinFit_hadTop_mass)[bestcomb]);
      KinFit_hlepTopmass_v3->Fill((*KinFit_lepTop_mass)[bestcomb]);
   
 
 }// if at least one good comb
 goodCombs.clear();
 
 
 //rifaccio considerando solo i primi 4 jet
 if(goodCombs4leading.size()>1){
 
 
      //Fill simple control plots after the kinfit*************************************
 
 
	      KinFit_hnJet_v4->Fill(nJet);
	      if (Jpt->size()>3){
		      for(int jj=0; jj<4; jj++){
				      KinFit_hJeta_v4->Fill((*Jeta)[jj]);
				      KinFit_hJpt_v4->Fill((*Jpt)[jj]);
		      }}
	      KinFit_hMET_v4->Fill(METpt);  
	      KinFit_hnVertex_v4->Fill(nVertex);
	       KinFit_hMUeta_v4->Fill(MUeta);
	      KinFit_hMUpt_v4->Fill(MUpt);
 
       //Fill simple control plots after the kinfit*************************************
  
       for(int c=0; c<2; c++){
  
	    int myc=goodCombs4leading[c];
  
	    float myprob4=TMath::Prob((*KinFit_chi2)[myc],NDF);
		    float myprob34=TMath::Exp(-1/double(NDF)*(*KinFit_chi2)[myc]);
  
	
			    KinFit_hprob_v4->Fill((*KinFit_prob)[myc],myprob34);
			    KinFit_hprob2_v4->Fill(myprob[myc],myprob34);
			    KinFit_hprob3_v4->Fill(myprob3[myc],myprob34);
			    KinFit_hchi2_v4->Fill((*KinFit_chi2)[myc],myprob34);
			    KinFit_hHmass_v4->Fill((*KinFit_hadW_mass)[myc],myprob34);
			    KinFit_hlepWmass_v4->Fill((*KinFit_lepW_mass)[myc],myprob34);
			    KinFit_hhadTopmass_v4->Fill((*KinFit_hadTop_mass)[myc],myprob34);
			    KinFit_hlepTopmass_v4->Fill((*KinFit_lepTop_mass)[myc],myprob34);
  
       }
 }// if at least one good comb 4 leading
 goodCombs4leading.clear();

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

  KinFit_hprob_v1->Write();
   KinFit_hprob2_v1->Write();
   KinFit_hprob3_v1->Write();
   KinFit_hchi2_v1->Write();
   KinFit_hHmass_v1->Write();
   KinFit_hlepWmass_v1->Write(); 
   KinFit_hhadTopmass_v1->Write();
   KinFit_hlepTopmass_v1->Write();

   KinFit_hprob_v2->Write();
   KinFit_hprob2_v2->Write();
   KinFit_hprob3_v2->Write();
   KinFit_hchi2_v2->Write();
   KinFit_hHmass_v2->Write();
   KinFit_hlepWmass_v2->Write(); 
   KinFit_hhadTopmass_v2->Write();
   KinFit_hlepTopmass_v2->Write();

   KinFit_hprob_v3->Write();
   KinFit_hprob2_v3->Write();
   KinFit_hprob3_v3->Write();
   KinFit_hchi2_v3->Write();
   KinFit_hHmass_v3->Write();
   KinFit_hlepWmass_v3->Write(); 
   KinFit_hhadTopmass_v3->Write();
   KinFit_hlepTopmass_v3->Write();

   KinFit_hprob_v4->Write();
   KinFit_hprob2_v4->Write();
   KinFit_hprob3_v4->Write();
   KinFit_hchi2_v4->Write();
   KinFit_hHmass_v4->Write();
   KinFit_hlepWmass_v4->Write(); 
   KinFit_hhadTopmass_v4->Write();
   KinFit_hlepTopmass_v4->Write();

   KinFit_hprob_v5->Write();
   KinFit_hprob2_v5->Write();
   KinFit_hprob3_v5->Write();
   KinFit_hchi2_v5->Write();
   KinFit_hHmass_v5->Write();
   KinFit_hlepWmass_v5->Write(); 
   KinFit_hhadTopmass_v5->Write();
   KinFit_hlepTopmass_v5->Write();

   KinFit_hnVertex->Write();
   KinFit_hJeta->Write();
   KinFit_hnJet->Write();
   KinFit_hJpt->Write();
   KinFit_hMET->Write();
   KinFit_hMUeta->Write();
   KinFit_hMUpt->Write();

   KinFit_hnVertex_v4->Write();
   KinFit_hJeta_v4->Write();
   KinFit_hnJet_v4->Write();
   KinFit_hJpt_v4->Write();
   KinFit_hMET_v4->Write();
   KinFit_hMUeta_v4->Write();
   KinFit_hMUpt_v4->Write();

   KinFit_hnVertex_v5->Write();
   KinFit_hJeta_v5->Write();
   KinFit_hnJet_v5->Write();
   KinFit_hJpt_v5->Write();
   KinFit_hMET_v5->Write();
   KinFit_hMUeta_v5->Write();
   KinFit_hMUpt_v5->Write();

   
}
