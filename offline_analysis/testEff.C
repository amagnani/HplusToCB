#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <TChain.h>
#include <TH1F.h>
#include <TFile.h>
#include <TROOT.h>
#include <TBranch.h>
#include <TTree.h>
void testEff(){

     double PtBins[]  = {20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 600, 800};
     double EtaBins[] = {0, 0.8, 1.6, 2.4};

	cout<<"Load Btag efficiencies"<<endl;
	char Btagstring[30];
	char outputTag[30];
	sprintf(outputTag,"TTJetsSplit");
	//TString outputTag="TTJetsSplit";
	cout<<outputTag<<endl;
	sprintf(Btagstring,"efficiency/BTagEff_%s.new.root",outputTag);
        cout<<"Btagstring "<<Btagstring<<endl;
	
	TFile *Btagin= new TFile(Btagstring,"READ");
	h2_EffMapB    = (TH2D*)Btagin->Get("Uh2_BTaggingEff_bS");
	h2_EffMapC    = (TH2D*)Btagin->Get("Uh2_BTaggingEff_cS");
	h2_EffMapUDSG = (TH2D*)Btagin->Get("Uh2_BTaggingEff_udsgS"); 
 	
// /* 	cout<<h2_EffMapB->GetName()<<endl;
// 	cout<<h2_EffMapC->GetName()<<endl;
// 	cout<<h2_EffMapUDSG->GetName()<<endl;
//  */	
	int effbinx=h2_EffMapUDSG->GetXaxis()->GetNbins(); cout<<"nbinx "<<effbinx<<endl;
	int effbiny=h2_EffMapUDSG->GetYaxis()->GetNbins(); cout<<"nbiny "<<effbiny<<endl; 
	

	cout<<"test light"<<endl;
        for(int cc=1;cc<effbinx+1;cc++){
        for(int dd=1;dd<effbiny+1;dd++){
        cout<<cc<<" "<<dd<<" "<< h2_EffMapUDSG->GetBinContent(cc,dd) << " Ptbins "<<PtBins[cc-1] << " etabins "<< EtaBins[dd-1] << "	"<<h2_EffMapUDSG->GetBinContent(
	h2_EffMapUDSG->GetXaxis()->FindBin(PtBins[cc-1]),h2_EffMapUDSG->GetYaxis()->FindBin( EtaBins[dd-1]) )  <<endl;      }}
	

}
