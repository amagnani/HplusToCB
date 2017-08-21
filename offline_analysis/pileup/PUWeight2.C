#include <TH1F.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <fstream>
#include <vector>

TH1F *pileup_weight; TH1F *test;

void PUWeight2(){
  
    
     //Getting data Nvertex distribution------------------------------------------------------ 
     Char_t Filename0[100];
     sprintf(Filename0,"MyDataPileupHistogram.root");
     TFile *f0 = new TFile(Filename0);
     TH1 *pileup_weight_init  = (TH1*)f0->Get("pileup");
      
     pileup_weight= new TH1F("pileup_weight","Nvertex",70,0,70);     
     double f=0;
     for(int b=1;b<71;b++){
       f=pileup_weight_init->GetBinContent(b);
       pileup_weight->Fill(b-1,f);
     }
	
	//Getting MC Nvertex distribution--------------------------------------------------------- 
	Char_t Filename[100];
  	sprintf(Filename,"Pileup_Bkg.root");
 	TFile *f1   = new TFile(Filename);
	TH1 *pileup_MC  = (TH1*)f1->Get("pileup");
        
	//Initializing output file----------------------------------------------------------------
	Char_t filename[100];
	sprintf(filename,"PUweight_Bkg2.root");
	TFile *fHistos;
	fHistos = new TFile(filename,"RECREATE"); //______________________________________________
        
	const double nevent= pileup_weight->Integral();
	const double neventBkg= pileup_MC->Integral();
        pileup_weight->Scale(1/nevent);
        pileup_MC->Scale(1/neventBkg);
	
        pileup_weight->Divide(&(*pileup_MC));
  	pileup_weight->Write();
	
	
	//TEST
	test  =new TH1F("test","Nvertex",70,0,70);
        for(int b=1;b<71;b++){
	f=pileup_weight->GetBinContent(b);
	test->Fill(b-1,f);
         }
	test->Multiply(&(*pileup_MC));
	test->Write();
	//______________________________________________
        fHistos->Close();
        
	//Print Histogram
	float *PUbin = pileup_weight->GetArray();
        for(int b=0;b<70;b++){
	cout<<b<<" "<<PUbin[b]<<endl;
         }

}
