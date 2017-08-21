#include <TH1F.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <fstream>
#include <vector>

TH1F *tt_weight; TH1F *test;

void ttWeight(){
  
    
     //Getting tt mass up gen top pt distribution------------------------------------------------------ 
     Char_t Filename0[100];     Char_t Filename1[100];     Char_t Filename2[100]; 
     Char_t Filename3[100];     Char_t Filename4[100];     Char_t Filename5[100];

     sprintf(Filename0,"../v30/efficiency/BTagEff2_TTmassup.root");
     sprintf(Filename1,"../v30/efficiency/BTagEff2_TTmassdown.root");
     sprintf(Filename2,"../v30/efficiency/BTagEff2_TTmatchup.root");
     sprintf(Filename3,"../v30/efficiency/BTagEff2_TTmatchdown.root");
     sprintf(Filename4,"../v30/efficiency/BTagEff2_TTscaleup.root");
     sprintf(Filename5,"../v30/efficiency/BTagEff2_TTscaledown.root");

     TFile *f0 = new TFile(Filename0);
     TFile *f1 = new TFile(Filename1);
     TFile *f2 = new TFile(Filename2);
     TFile *f3 = new TFile(Filename3);
     TFile *f4 = new TFile(Filename4);
     TFile *f5 = new TFile(Filename5);
  
     TH1F *h0  = (TH1F*)f0->Get("hGenTopPt");
     TH1F *h1  = (TH1F*)f1->Get("hGenTopPt");
     TH1F *h2  = (TH1F*)f2->Get("hGenTopPt");
     TH1F *h3  = (TH1F*)f3->Get("hGenTopPt");
     TH1F *h4  = (TH1F*)f4->Get("hGenTopPt");
     TH1F *h5  = (TH1F*)f5->Get("hGenTopPt");
  
     h0  ->SetName("h0");
     h1  ->SetName("h1");
     h2  ->SetName("h2");
     h3  ->SetName("h3");
     h4  ->SetName("h4");
     h5  ->SetName("h5");

     TH1F *TTmassup_weight    = (TH1F*)h0->Clone();
     TH1F *TTmassdown_weight  = (TH1F*)h1->Clone();
     TH1F *TTmatchup_weight   = (TH1F*)h2->Clone();
     TH1F *TTmatchdown_weight = (TH1F*)h3->Clone();
     TH1F *TTscaleup_weight   = (TH1F*)h4->Clone();
     TH1F *TTscaledown_weight = (TH1F*)h5->Clone();

     TTmassup_weight    ->SetName("TTmassup_weight");
     TTmassdown_weight  ->SetName("TTmassdown_weight");
     TTmatchup_weight   ->SetName("TTmatchup_weight ");  
     TTmatchdown_weight ->SetName("TTmatchdown_weight"); 
     TTscaleup_weight   ->SetName("TTscaleup_weight ");  
     TTscaledown_weight ->SetName("TTscaledown_weight");  

	//Getting MC Nvertex distribution--------------------------------------------------------- 
	Char_t Filename[100];
  	sprintf(Filename,"../v30/efficiency/BTagEff2_TTJetsSplit.root");
 	TFile *f   = new TFile(Filename);
	TH1F *h  = (TH1F*)f->Get("hGenTopPt");
	h ->SetName("h"); 
	TH1F *TTmass_nominal  = (TH1F*)h->Clone();
 	TTmass_nominal  ->SetName("TTmass_nominal");
       
	//Initializing output file----------------------------------------------------------------
	Char_t filename[100];
	sprintf(filename,"signalSys.root");
	TFile *fHistos;
	fHistos = new TFile(filename,"RECREATE"); //______________________________________________
        
	const double nevent0= h0->Integral();
	const double nevent1= h1->Integral();
	const double nevent2= h2->Integral();
	const double nevent3= h3->Integral();
	const double nevent4= h4->Integral();
	const double nevent5= h5->Integral();
	const double neventBkg= TTmass_nominal->Integral();

        TTmassup_weight   ->Scale(1/nevent0);
        TTmassdown_weight ->Scale(1/nevent1);
        TTmatchup_weight  ->Scale(1/nevent2);
        TTmatchdown_weight->Scale(1/nevent3);
        TTscaleup_weight  ->Scale(1/nevent4);
        TTscaledown_weight->Scale(1/nevent5);
        TTmass_nominal    ->Scale(1/neventBkg);
	
        TTmassup_weight->Divide(&(*TTmass_nominal));
        TTmassdown_weight ->Divide(&(*TTmass_nominal));
        TTmatchup_weight   ->Divide(&(*TTmass_nominal));     
        TTmatchdown_weight->Divide(&(*TTmass_nominal));
        TTscaleup_weight  ->Divide(&(*TTmass_nominal));
        TTscaledown_weight->Divide(&(*TTmass_nominal));
 
  	TTmassup_weight		->Write();
        TTmassdown_weight 	->Write();
        TTmatchup_weight 	->Write(); 
        TTmatchdown_weight	->Write();
        TTscaleup_weight  	->Write();
        TTscaledown_weight	->Write();
	
	
	//TEST 
	TH1F *test  =(TH1F*)TTmassup_weight->Clone();
	TH1F *test_nominal  =(TH1F*)h->Clone();
	test_nominal->SetName("test_nominal");
	test->SetName("test");
	test_nominal->Multiply(&(*test));
	test_nominal->Write();
	h0->Write();
	h->Write();

	//______________________________________________
        fHistos->Close();
        
      ofstream PUout;
      char PUstring[20];
      sprintf(PUstring,"tt.txt");
      PUout.open(PUstring);
      float *PUbin = TTmassup_weight->GetArray();
      float *h0A = h0->GetArray();
      float *h1A = h1->GetArray();
	for(int b=0;b<80;b++){
 PUout<<h0A[b]<<" "<<h1A[b] <<" "<<PUbin[b]<<endl;
  cout<<h0A[b]<<" "<<h1A[b] <<" "<<PUbin[b]<<endl;
	 }

gApplication->Terminate();
}
