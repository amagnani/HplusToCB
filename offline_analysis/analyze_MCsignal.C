#define analyze_MCsignal_cxx
#include "analyze_MCsignal.h"
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

void analyze_MCsignal::Loop(TFile *fHistos, TH2D *h2_EffMapB, TH2D * h2_EffMapC, TH2D *h2_EffMapUDSG, TH1F *TTmassup_weight, TH1F *TTmassdown_weight, TH1F *TTmatchup_weight , TH1F *TTmatchdown_weight,
      TH1F *TTscaleup_weight, TH1F *TTscaledown_weight, TH1D *SFb_errors, char *ext, int flag)
{
time_t start= time(0);
     char name_hTopPtWeight[30];	 

     char name_hnVertex[30];	 
     char name_hnVertexNW[30]; 
     char name_hnJet[30]; 	
     char name_hJeta[30]; 	
     char name_hJpt[30]; 	
     char name_hJb[30]; 	
     char name_hMET[30]; 	
     char name_hMUeta[30]; 	
     char name_hMUpt[30]; 	
     char name_hMUrelIso[30];
   
for(int e=0;e<15;e++){    
					 
     sprintf(name_hTopPtWeight 	, "Reco_hTopPtWeight_%s_sys%i",ext,e);
     sprintf(name_hnVertex 	, "Reco_hnVertex_%s_sys%i",ext,e);
     sprintf(name_hnVertexNW 	, "Reco_hnVertexNW_%s_sys%i",ext,e);
     sprintf(name_hnJet 	, "Reco_hnJet_%s_sys%i",ext,e);	
     sprintf(name_hJeta 	, "Reco_hJeta_%s_sys%i",ext,e);	
     sprintf(name_hJpt 		, "Reco_hJpt_%s_sys%i",ext,e);	
     sprintf(name_hJb 		, "Reco_hJb_%s_sys%i",ext,e);	      
     sprintf(name_hMET 		, "Reco_hMET_%s_sys%i",ext,e);	
 
     sprintf(name_hMUeta 	, "Reco_hMUeta_%s_sys%i",ext,e);	
     sprintf(name_hMUpt 	, "Reco_hMUpt_%s_sys%i",ext,e);	
     sprintf(name_hMUrelIso 	, "Reco_hMUrelIso_%s_sys%i",ext,e);


     hTopPtWeight[e]= new TH1F(name_hTopPtWeight,	"TopPtweight",100,0,5);  
     Reco_hnVertex[e]= new TH1F(name_hnVertex,		"# Vertexes",70,0,70);  
     Reco_hnVertexNW[e]= new TH1F(name_hnVertexNW,	"# Vertexes not weighted",70,0,70);  
     Reco_hnJet[e]= new TH1F(name_hnJet,		"# jets",8,3,11);  
     Reco_hJeta[e]= new TH1F(name_hJeta,		"jets eta",60,-3,3);  
     Reco_hJpt[e]= new TH1F(name_hJpt,			"jets pt (Gev)",80,20,100);  
     Reco_hJb[e]= new TH1F(name_hJb,			"jets b-Discriminator (Gev)",40,-1.5,1.5); 
     Reco_hMET[e]= new TH1F(name_hMET,			"MET (Gev)",43,14,100); 

     Reco_hMUeta[e]= new TH1F(name_hMUeta,		"muon |eta|",60,-3,3);  
     Reco_hMUpt[e]= new TH1F(name_hMUpt,		"muon pt (Gev)",80,20,100);  
     Reco_hMUrelIso[e]=new TH1F(name_hMUrelIso,		"Muon Relative Isolation",24,0,0.3);
}

if (flag!=1){

//Top pt scale factor
TF1 *SF = new TF1("SF","exp(0.156-0.00137*x)",5,1000);


//Btag scale factors
float ptmin[] = {20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 600};
float ptmax[] = {30, 40, 50, 60, 70, 80,100, 120, 160, 210, 260, 320, 400, 500, 600, 800};

// from https://twiki.cern.ch/twiki/pub/CMS/BtagRecommendation53XReReco/SFb-pt_WITHttbar_payload_EPS13.txt
//Tagger: CSVM within 20 < pt < 800 GeV, abs(eta) < 2.4, x = pt
 TF1 *SFb = new TF1("SFb","(0.938887+(0.00017124*x))+(-2.76366e-07*(x*x))",20,800);

//light flavor scale factors from https://twiki.cern.ch/twiki/pub/CMS/BtagRecommendation53XReReco/SFlightFuncs_EPS2013.C
TF1 *SFl_0to0p8 = new TF1("SFl_0to0p8","((1.07541+(0.00231827*x))+(-4.74249e-06*(x*x)))+(2.70862e-09*(x*(x*x)))", 20.,1000);
TF1 *SFlMin_0to0p8 = new TF1("SFlMin_0to0p8","((0.964527+(0.00149055*x))+(-2.78338e-06*(x*x)))+(1.51771e-09*(x*(x*x)))", 20.,1000);
TF1 *SFlMax_0to0p8 = new TF1("SFlMax_0to0p8","((1.18638+(0.00314148*x))+(-6.68993e-06*(x*x)))+(3.89288e-09*(x*(x*x)))", 20.,1000);

TF1 *SFl_0p8to1p6 = new TF1("SFl_0p8to1p6","((1.05613+(0.00114031*x))+(-2.56066e-06*(x*x)))+(1.67792e-09*(x*(x*x)))", 20.,1000);
TF1 *SFlMin_0p8to1p60to0p8 = new TF1("SFlMin_0p8to1p6","((0.946051+(0.000759584*x))+(-1.52491e-06*(x*x)))+(9.65822e-10*(x*(x*x)))", 20.,1000);
TF1 *SFlMax_0p8to1p60to0p8 = new TF1("SFlMax_0p8to1p6","((1.16624+(0.00151884*x))+(-3.59041e-06*(x*x)))+(2.38681e-09*(x*(x*x)))", 20.,1000);

TF1 *SFl_1p6to2p4 = new TF1("SFl_1p6to2p4","((1.05625+(0.000487231*x))+(-2.22792e-06*(x*x)))+(1.70262e-09*(x*(x*x)))", 20.,850);
TF1 *SFlMin_1p6to2p4 = new TF1("SFlMin_1p6to2p4","((0.956736+(0.000280197*x))+(-1.42739e-06*(x*x)))+(1.0085e-09*(x*(x*x)))", 20.,850);
TF1 *SFlMax_1p6to2p4 = new TF1("SFlMax_1p6to2p4","((1.15575+(0.000693344*x))+(-3.02661e-06*(x*x)))+(2.39752e-09*(x*(x*x)))", 20.,850);


     //Muon Scale factors
     float eta_bin[3]=      {	 0.9,	   1.2,     2.1 };

     float triggerSF[3]=    { 0.9837,	0.9656,  0.9962 };
     float triggerSF_err[3]={ 0.00021, 0.00066, 0.00052 };

     float idSF[3]=	    { 0.9925,	0.9928,  0.9960 };
     float idSF_err[3]=     { 0.0002,	0.0003,  0.0003 };

     float isoSF[3]=	    { 0.9959,	0.9878,  1.0027 };
     float isoSF_err[3]=    { 0.00002,  0.0003,  0.0002 };

} 


//   In a ROOT session, you can do:
//      Root > .L analyze_MCsignal.C
//      Root > analyze_MCsignal t
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

        double w, w_up, w_down,  m, m_up, m_down; float b ,b_up, b_down,b1_up, b1_down, t, t_up, t_down;
	if (flag==1) {
	   w=1;w_up=1;w_down=1;
	   m=1;m_up=1;m_down=1;
	} else{
	   w=lumiWeight; w_up=lumiWeight_up; w_down=lumiWeight_down;
	   m=1; m_up=1; m_down=1;

//secondo me questa roba è sbagliata	  	   
	   if(MUeta!=0){
	      for(int k=0; k<3;k++){
	       if(fabs(MUeta)<eta_bin[k]) { 
	          m=triggerSF[k]*idSF[k]*isoSF[k];

		  float errA= sqrt(triggerSF_err[k]*triggerSF_err[k]+(0.002*triggerSF[k])*(0.002*triggerSF[k])+(0.02*triggerSF[k])*(0.02*triggerSF[k]));
		  float errB= sqrt(idSF_err[k]*idSF_err[k]          +(0.005*idSF[k])*(0.005*idSF[k])          +(0.02*idSF[k])*(0.02*idSF[k]) );
		  float errC= sqrt(isoSF_err[k]*isoSF_err[k]        +(0.002*isoSF[k])*(0.002*isoSF[k])        +(0.02*isoSF[k])*(0.02*isoSF[k]) );
		  m_up  =(triggerSF[k]+errA)*(idSF[k]+errB)*(isoSF[k]+errC);
    		  m_down=(triggerSF[k]-errA)*(idSF[k]-errB)*(isoSF[k]-errC);

		  //cout<<m<<" m "<<m_up<<" m "<<m_down<<" m "<<endl;
		  break;
		}  
	      }
	  }    
	}
	b=1;b_up=1;b_down=1; t=1;t_up=1;t_down=1;

     //top pt reweighting 
     float wt, wtbar;
     wt=SF->Eval(GenPart_top_pt);
     wtbar=SF->Eval(GenPart_topBar_pt);
     t=sqrt(wt*wtbar);
     t_up=t*t;
     t_down=1;
     
 //    cout<<GenPart_top_pt<<" "<<wt<<" "<<GenPart_topBar_pt<<" "<<wtbar<<" "<<t<<endl;
 
     hTopPtWeight[0]->Fill(t);
     hTopPtWeight[7]->Fill(t_up);
     hTopPtWeight[8]->Fill(t_down);
      
  //monte carlo ttbar uncertainties scale factors
  
 float mass_up=1, mass_down=1, match_up=1, match_down=1, scale_up=1, scale_down=1;

 if(GenPart_top_pt<400){
  mass_up     = TTmassup_weight    ->GetBinContent(TTmassup_weight    ->GetXaxis()->FindBin(GenPart_top_pt));	
  mass_down   = TTmassdown_weight  ->GetBinContent(TTmassdown_weight  ->GetXaxis()->FindBin(GenPart_top_pt));	
  match_up    = TTmatchup_weight   ->GetBinContent(TTmatchup_weight   ->GetXaxis()->FindBin(GenPart_top_pt));	
  match_down  = TTmatchdown_weight ->GetBinContent(TTmatchdown_weight ->GetXaxis()->FindBin(GenPart_top_pt));	
  scale_up    = TTscaleup_weight   ->GetBinContent(TTscaleup_weight   ->GetXaxis()->FindBin(GenPart_top_pt));	
  scale_down  = TTscaledown_weight ->GetBinContent(TTscaledown_weight ->GetXaxis()->FindBin(GenPart_top_pt));	
 }
   //Btagging scale factors  
   if ( (flag!=1) && (isPartOf(ext,"8a") || isPartOf(ext,"8b") || isPartOf(ext,"9b"))){

    std::vector<JetInfo> myjets,myjets_up,myjets_down,myjets1_up,myjets1_down;
    //std::vector<JetInfo> untaggedjets;
     
     BTagWeight b_calculator;
     if ( isPartOf(ext,"8a"))	b_calculator = BTagWeight(1,99);
     if ( isPartOf(ext,"8b"))	b_calculator = BTagWeight(2,99);
     if ( isPartOf(ext,"9b"))	b_calculator = BTagWeight(3,99);
     
     float ScaleFactor;
     double ScaleFactor_up;
     double ScaleFactor_down;
     double ScaleFactor1_up;
     double ScaleFactor1_down;
     double ScaleFactor_unc;
 
     float tagEfficiency;
  
     double jpt;
     bool btag = false;
     bool btagNominal = false;
     bool btagUp = false;
     bool btagDown = false;
  
     int tags=0; 
 
 // loop over jets
    for(int it = 0; it < Jpt->size() ; it++)
    { 
    
    btag = (*JbDiscr)[it] > 0.679;
    //cout<<"un jet "<< (*JbDiscr)[it]<<" "<<btag << endl;
 
	if( abs((*Jflavor)[it])==5 )
    
	{
	jpt=(*Jpt)[it]);
	if (jpt>800) jpt=800;
	if (jpt<20) jpt=20;
	ScaleFactor	= SFb->Eval(jpt);
	ScaleFactor_unc = SFb_errors->GetBinContent(SFb_errors->GetXaxis()->FindBin(jpt));
	ScaleFactor_up        = ScaleFactor + ScaleFactor_unc;
	ScaleFactor_down = ScaleFactor - ScaleFactor_unc;
	ScaleFactor1_up        = ScaleFactor;
	ScaleFactor1_down  = ScaleFactor ;
	tagEfficiency = h2_EffMapB->GetBinContent( h2_EffMapB->GetXaxis()->FindBin(jpt), h2_EffMapB->GetYaxis()->FindBin(fabs((*Jeta)[it]) ));
	}
	else if( abs((*Jflavor)[it])==4 )
	{
	jpt=(*Jpt)[it]);
	if (jpt>800) jpt=800;
	if (jpt<20) jpt=20;
	ScaleFactor	= SFb->Eval(jpt);
	ScaleFactor_unc = SFb_errors->GetBinContent(SFb_errors->GetXaxis()->FindBin(jpt));
	ScaleFactor_up   = ScaleFactor + 2*ScaleFactor_unc;
	ScaleFactor_down = ScaleFactor - 2*ScaleFactor_unc;
	ScaleFactor1_up   = ScaleFactor;
	ScaleFactor1_down = ScaleFactor;
	tagEfficiency = h2_EffMapC->GetBinContent( h2_EffMapC->GetXaxis()->FindBin(jpt), h2_EffMapC->GetYaxis()->FindBin(fabs((*Jeta)[it])) );
	}
	else	//LIGHT JETS
      {
	 jpt = (*Jpt)[it]);
	 double jAbsEta = fabs((*Jeta)[it]);
	 if ( jAbsEta<1.6 && jpt>1000. ) jpt = 1000.;
	 else if ( jAbsEta>=1.6 && jpt>850. ) jpt = 850.;
	 if ( jpt<20 ) jpt = 20.;
 
       if(jAbsEta<0.8)
       {
	 ScaleFactor	  = SFl_0to0p8->Eval(jpt);
	 ScaleFactor1_up   = ScaleFactor + ( jpt>1000. ? 2. : 1. )*(SFlMax_0to0p8->Eval(jpt) - SFl_0to0p8->Eval(jpt));
	 ScaleFactor1_down = ScaleFactor + ( jpt>1000. ? 2. : 1. )*(SFlMin_0to0p8->Eval(jpt) - SFl_0to0p8->Eval(jpt));
 	 ScaleFactor_up   = ScaleFactor ;
	 ScaleFactor_down = ScaleFactor ;
      }
       else if(jAbsEta>=0.8 && jAbsEta<1.6)
       {
	 ScaleFactor	  = SFl_0p8to1p6->Eval(jpt);
	 ScaleFactor1_up   = ScaleFactor + ( jpt>1000. ? 2. : 1. )*(SFlMax_0p8to1p6->Eval(jpt) - SFl_0p8to1p6->Eval(jpt));
	 ScaleFactor1_down = ScaleFactor + ( jpt>1000. ? 2. : 1. )*(SFlMin_0p8to1p6->Eval(jpt) - SFl_0p8to1p6->Eval(jpt));
	 ScaleFactor_up   = ScaleFactor ;
	 ScaleFactor_down = ScaleFactor ;
       }
       else
       {
	 ScaleFactor	  = SFl_1p6to2p4->Eval(jpt);
	 ScaleFactor1_up   = ScaleFactor + ( jpt>850. ? 2. : 1. )*(SFlMax_1p6to2p4->Eval(jpt) - SFl_1p6to2p4->Eval(jpt));
	 ScaleFactor1_down = ScaleFactor + ( jpt>850. ? 2. : 1. )*(SFlMin_1p6to2p4->Eval(jpt) - SFl_1p6to2p4->Eval(jpt));
	 ScaleFactor_up   = ScaleFactor;
	 ScaleFactor_down = ScaleFactor;
       }
 
       tagEfficiency = h2_EffMapUDSG->GetBinContent( h2_EffMapUDSG->GetXaxis()->FindBin(jpt), h2_EffMapUDSG->GetYaxis()->FindBin(fabs((*Jeta)[it])) );
       
       }
	      
       //cout<<btag<<" "<<(*Jflavor)[it]<<" "<<jpt<<" "<<fabs((*Jeta)[it])<<" "<<tagEfficiency<<" "<<ScaleFactor<<endl;
	 
      if(btag) tags++;
       
		       //cout <<" "<<tagEfficiency <<endl;
		  JetInfo *JETINFO       = new JetInfo(tagEfficiency,ScaleFactor);
		  JetInfo *JETINFO_up    = new JetInfo(tagEfficiency,ScaleFactor_up);
		  JetInfo *JETINFO_down  = new JetInfo(tagEfficiency,ScaleFactor_down);
		  JetInfo *JETINFO1_up   = new JetInfo(tagEfficiency,ScaleFactor1_up);
		  JetInfo *JETINFO1_down = new JetInfo(tagEfficiency,ScaleFactor1_down);
		  myjets.push_back(*JETINFO); 
		  myjets_up.push_back(*JETINFO_up); 
		  myjets_down.push_back(*JETINFO_down); 
		  myjets1_up.push_back(*JETINFO1_up); 
		  myjets1_down.push_back(*JETINFO1_down); 
		       //cout<<"btag "<<btag<<"filling tag"<<taggedjets.back().eff<<" "<<taggedjets.back().sf<<endl;
	       delete JETINFO;
	       delete JETINFO1_up;
	       delete JETINFO1_down;
 	       delete JETINFO_up;
	       delete JETINFO_down;
     
    }
   //cout<<"End Loop over jets"<<endl;
 
      
      /*cout<<"DUMP JETINFO"<<tags<<endl;
      for (int kk=0; kk<taggedjets.size();kk++){
      cout<<"tagged " <<taggedjets[kk].eff<<" "<<taggedjets[kk].sf<<endl;
      }
      for (int kk=0; kk<untaggedjets.size();kk++){
      cout<<"untagged " <<untaggedjets[kk].eff<<" "<<untaggedjets[kk].sf<<endl;
      }
      */
      
      //finalmente, il peso 
      b      =b_calculator.weight(myjets,       tags);  
      b1_up  =b_calculator.weight(myjets1_up,   tags);  
      b1_down=b_calculator.weight(myjets1_down, tags);  
      b_up   =b_calculator.weight(myjets_up,    tags);  
      b_down =b_calculator.weight(myjets_down,  tags);  
      //cout<<b<<endl; 
      
      myjets.clear();
      myjets_up.clear();
      myjets_down.clear();
      myjets1_up.clear();
      myjets1_down.clear();
      tags=0;
 
 }  //fine commento tagli 
   //     double w, w_up, w_down,  m, m_up, m_down; float b ,b_up, b_down, t, t_up, t_down;
   //	w=1; w_up=1; w_down=1; m=1; m_up=1; m_down=1; b=1; b_up=1; b_down=1; t=1; t_up=1; t_down=1;

	//Set Weight
        float P[15];
	P[0]=w		*m	*b	*t;          	//central
	P[1]=w_up  	*m	*b	*t;      	//PU up
	P[2]=w_down	*m	*b	*t;     	//PU down
	P[3]=w		*m   	*b1_up	*t;     	//light b
	P[4]=w		*m	*b1_down*t;		//light b
	P[5]=w		*m	*b_up  	*t;		//btag up
	P[6]=w		*m	*b_down	*t;		//btag down
	P[7]=w		*m	*b	*t_up  ;	//top pt up
	P[8]=w		*m	*b	*t_down;	//top pt down
	P[9]=w		*m	*b	*t	*mass_up;          	//mass  up
	P[10]=w		*m	*b	*t	*mass_down;          	//mass  down
	P[11]=w		*m	*b	*t	*match_up;          	//match up
	P[12]=w		*m	*b	*t	*match_down;          	//match down
	P[13]=w		*m	*b	*t	*scale_up;          	//scale up
	P[14]=w		*m	*b	*t	*scale_down;          	//scale down

	
//---------------------------------------------------------------end event weight 
//---------------------------------------------------------------top pt weight to be added !!


for(int g=0;g<15;g++){

	Reco_hnJet[g]->Fill(nJet,P[g]);
	if (Jpt->size()>3){
	for(int jj=0; jj<4; jj++){
	  Reco_hJeta[g]->Fill((*Jeta)[jj],P[g]);
	  Reco_hJpt[g]->Fill((*Jpt)[jj],P[g]);
	  Reco_hJb[g]->Fill((*JbDiscr)[jj],P[g]);
  
	  }}
       //MET
       Reco_hMET[g]->Fill(METpt,P[g]);  
     
    Reco_hnVertex[g]->Fill(nVertex,P[g]);
    Reco_hnVertexNW[g]->Fill(nVertex);
    Reco_hMUeta[g]->Fill(MUeta,P[g]);
    Reco_hMUpt[g]->Fill(MUpt,P[g]);
    Reco_hMUrelIso[g]->Fill(MUrelIso,P[g]);
}
}


//Writinghistograms

for(int e=0;e<15;e++){

   hTopPtWeight[e]->Write();
   Reco_hnVertex[e]->Write();
   Reco_hnJet[e]->Write();
   Reco_hJeta[e]->Write();
   Reco_hJpt[e]->Write();
   Reco_hJb[e]->Write(); 
   Reco_hMET[e]->Write();

   Reco_hMUeta[e]->Write();
   Reco_hMUpt[e]->Write(); 
   Reco_hMUrelIso[e]->Write();
}
 
}
