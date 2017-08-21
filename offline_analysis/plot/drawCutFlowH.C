//***********************************************************
//******drawing the histograms from the Hplus.C macro******
//***********************************************************
#include <TH1F>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

 void drawCutFlowH(){

  TString TargetName4 ="Reco_hnVertex_4_sys0";
  TString TargetName6= "Reco_hnVertex_6_sys0";
  TString TargetName8a="Reco_hnVertex_8a_sys0";
  TString TargetName8b="Reco_hnVertex_8b_sys0";
  TString TargetName9b="Reco_hnVertex_9b_sys0";
 
  vector< TString> TargetName;
  TargetName.push_back(TargetName4);
  TargetName.push_back(TargetName6);
  TargetName.push_back(TargetName8a);
  TargetName.push_back(TargetName8b);
  TargetName.push_back(TargetName9b);

  gROOT->ProcessLine(".L tdrstyle.C");
 //  gStyle->SetOptStat("emr");
   gStyle->SetOptStat(0);
  // gStyle->SetOptLogx(1);
   gStyle->SetOptLogy(1);
   gStyle->SetOptLogz(0);
 
 //Load Files
  TFile *f[9];
  f[0]=  new TFile("../output/HplusHistos_H90.root","READ");
  f[1] = new TFile("../output/HplusHistos_H100.root","READ");
  f[2] = new TFile("../output/HplusHistos_H110.root","READ");
  f[3] = new TFile("../output/HplusHistos_H120.root","READ");
  f[4] = new TFile("../output/HplusHistos_H130.root","READ");
  f[5] = new TFile("../output/HplusHistos_H140.root","READ");
  f[6] = new TFile("../output/HplusHistos_H150.root","READ");
  f[7] = new TFile("../output/HplusHistos_H155.root","READ");
  f[8] = new TFile("../output/HplusHistos_H160.root","READ");

  double lumi_factor= 19.7*1e+15*1e-12;
  //cross section (pb)
  double xsecH 	= 80.928; 

  double events[9]={
  		199777,
		199807,
		199804,
		199769,
		199761,
		199803,
		199810,
		199815,
		199806
  };
  double Scale[9]={0};
  
//LOAD HISTOGRAMS 

for(int i=0;i<9;i++){
  TH1 *topr= (TH1*)f[i]->Get( "Reco_hTopPtWeight_Start_sys0");
  cout<<topr->GetMean()<<endl;
  topreweight=topr->GetMean();
  cout<<"topreweight "<<topreweight<<endl;

  Scale[i] =lumi_factor*xsecH /  (events[i]* topreweight) ;
  
  cout<<"scale "<<i<<" "<<Scale[i]<<endl;
}


//LOAD HISTOGRAMS
  double events_H90      [5];
  double events_H100	 [5];
  double events_H110	 [5];
  double events_H120	 [5];
  double events_H130	 [5];
  double events_H140	 [5];
  double events_H150	 [5];
  double events_H155	 [5];
  double events_H160	 [5];

for(int nsel=0; nsel<5;nsel++){  
cout<<TargetName[nsel]<<endl;
 
  TH1 *histo_H90      = (TH1*)f[0]->Get(TargetName[nsel]);
  TH1 *histo_H100     = (TH1*)f[1]->Get(TargetName[nsel]);
  TH1 *histo_H110     = (TH1*)f[2]->Get(TargetName[nsel]);
  TH1 *histo_H120     = (TH1*)f[3]->Get(TargetName[nsel]);
  TH1 *histo_H130     = (TH1*)f[4]->Get(TargetName[nsel]);
  TH1 *histo_H140     = (TH1*)f[5]->Get(TargetName[nsel]);
  TH1 *histo_H150     = (TH1*)f[6]->Get(TargetName[nsel]);
  TH1 *histo_H155     = (TH1*)f[7]->Get(TargetName[nsel]);
  TH1 *histo_H160     = (TH1*)f[8]->Get(TargetName[nsel]);

  cout<<"getting integrals "<<nsel<<endl;
 
  events_H90      [nsel]=histo_H90->GetEntries();    cout<<histo_H90->GetEntries()<<" "<<histo_H90->Integral()<<endl;
  events_H100     [nsel]=histo_H100->GetEntries();   cout<<histo_H100->GetEntries()<<" "<<histo_H100->Integral()<<endl;
  events_H110     [nsel]=histo_H110->GetEntries();   cout<<histo_H110->GetEntries()<<" "<<histo_H110->Integral()<<endl;
  events_H120     [nsel]=histo_H120->GetEntries();   cout<<histo_H120->GetEntries()<<" "<<histo_H120->Integral()<<endl;
  events_H130     [nsel]=histo_H130->GetEntries();   cout<<histo_H130->GetEntries()<<" "<<histo_H130->Integral()<<endl;
  events_H140     [nsel]=histo_H140->GetEntries();   cout<<histo_H140->GetEntries()<<" "<<histo_H140->Integral()<<endl;
  events_H150     [nsel]=histo_H150->GetEntries();   cout<<histo_H150->GetEntries()<<" "<<histo_H150->Integral()<<endl;
  events_H155     [nsel]=histo_H155->GetEntries();   cout<<histo_H155->GetEntries()<<" "<<histo_H155->Integral()<<endl;
  events_H160     [nsel]=histo_H160->GetEntries();   cout<<histo_H160->GetEntries()<<" "<<histo_H160->Integral()<<endl;
}

TH1 *Target_H90= new TH1F("Target_H90"," ",5,-0.5,4.5); 
    Target_H90->GetXaxis()->SetBinLabel(1," 1 muon");
    Target_H90->GetXaxis()->SetBinLabel(2," >= 4 jets");
    Target_H90->GetXaxis()->SetBinLabel(3,"1 btag, MET > 20 GeV");
    Target_H90->GetXaxis()->SetBinLabel(4,"2 btag");
    Target_H90->GetXaxis()->SetBinLabel(5,"3 btag");  

TH1 *Target_H100=  (TH1*) Target_H90->Clone();
TH1 *Target_H110=  (TH1*) Target_H90->Clone();
TH1 *Target_H120=  (TH1*) Target_H90->Clone();
TH1 *Target_H130=  (TH1*) Target_H90->Clone();
TH1 *Target_H140=  (TH1*) Target_H90->Clone();
TH1 *Target_H150=  (TH1*) Target_H90->Clone();
TH1 *Target_H155=  (TH1*) Target_H90->Clone();
TH1 *Target_H160=  (TH1*) Target_H90->Clone();

for(int bin=0;bin<5;bin++){

   Target_H90->Fill(bin,events_H90[bin]);
   Target_H100->Fill(bin,events_H100[bin]);
   Target_H110->Fill(bin,events_H110[bin]);
   Target_H120->Fill(bin,events_H120[bin]);
   Target_H130->Fill(bin,events_H130[bin]);
   Target_H140->Fill(bin,events_H140[bin]);
   Target_H150->Fill(bin,events_H150[bin]);
   Target_H155->Fill(bin,events_H155[bin]);
   Target_H160->Fill(bin,events_H160[bin]);

}
  
  //scalo alla fine i plot di cutflow 
  
  const double ScaleH90=Scale[0];
  const double ScaleH100=Scale[1];
  const double ScaleH110=Scale[2];
  const double ScaleH120=Scale[3];
  const double ScaleH130=Scale[4];
  const double ScaleH140=Scale[5];
  const double ScaleH150=Scale[6];
  const double ScaleH155=Scale[7];
  const double ScaleH160=Scale[8];

  Target_H90->Scale(ScaleH90);
  Target_H100->Scale(ScaleH100);
  Target_H110->Scale(ScaleH110);
  Target_H120->Scale(ScaleH120);
  Target_H130->Scale(ScaleH130);
  Target_H140->Scale(ScaleH140);
  Target_H150->Scale(ScaleH150);
  Target_H155->Scale(ScaleH155);
  Target_H160->Scale(ScaleH150);

  Target_H90->SetLineColor(kBlue);
  Target_H100->SetLineColor(kBlue+1);
  Target_H110->SetLineColor(kBlue+2);
  Target_H120->SetLineColor(kBlue+3);
  Target_H130->SetLineColor(kBlue+4);
  Target_H140->SetLineColor(kMagenta+2);
  Target_H150->SetLineColor(kMagenta);
  Target_H155->SetLineColor(kMagenta-7);
  Target_H160->SetLineColor(kMagenta-9);
 
  Target_H90->SetLineWidth(4);
  Target_H100->SetLineWidth(4);
  Target_H110->SetLineWidth(4);
  Target_H120->SetLineWidth(4);
  Target_H130->SetLineWidth(4);
  Target_H140->SetLineWidth(4);
  Target_H150->SetLineWidth(4);
  Target_H155->SetLineWidth(4);
  Target_H160->SetLineWidth(4);

   TLegend *leg = new TLegend(0.75,0.6,0.89,0.89);
   leg->SetBorderSize(0);
   leg->SetLineColor(0);
   leg->SetLineStyle(0);
   leg->SetLineWidth(0);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   leg->AddEntry(Target_H90, "H+ 90 GeV","l");
   leg->AddEntry(Target_H100,"H+ 100 GeV","l");
   leg->AddEntry(Target_H110,"H+ 110 GeV","l");
   leg->AddEntry(Target_H120,"H+ 120 GeV","l");
   leg->AddEntry(Target_H130,"H+ 130 GeV","l");
   leg->AddEntry(Target_H140,"H+ 140 GeV","l");
   leg->AddEntry(Target_H150,"H+ 150 GeV","l");
   leg->AddEntry(Target_H155,"H+ 155 GeV","l");
   leg->AddEntry(Target_H160,"H+ 160 GeV","l");

 //************************************************Define Stacks
 
  TCanvas *Cut = new TCanvas("MyCanvas","MyCanvas",1000,800);
  Target_H90->GetYaxis()->SetRangeUser(1,100000000);
  Target_H90->Draw();
  Target_H100->Draw("same");
  Target_H110->Draw("same");
  Target_H120->Draw("same");
  Target_H130->Draw("same");
  Target_H140->Draw("same");
  Target_H150->Draw("same");
  Target_H155->Draw("same");
  Target_H160->Draw("same");
  leg->Draw(); 
   
   
  //spit latex Yields table
 cout<<" \\hline "<<endl;
 cout<<" &  1 muon & $\\geq$ 4 jets  &   MET$\\geq$ 20 , $\\geq$ 1 CSVM &  $\\geq$ 2 CSVM    &  $\\geq$ 3 CSVM  \\\\"<<endl;
 cout<<" \\hline "<<endl;
 cout<<" H 90 GeV  "; for(int bin=0; bin<5; bin++) cout<<" & "<<events_H90[bin]*Scale[0];
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
 cout<<" H 100 GeV  "; for(int bin=0; bin<5; bin++) cout<<" & "<<events_H100[bin]*Scale[1];
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
 cout<<" H 110 GeV  "; for(int bin=0; bin<5; bin++) cout<<" & "<<events_H110[bin]*Scale[2];
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
 cout<<" H 120 GeV  "; for(int bin=0; bin<5; bin++) cout<<" & "<<events_H120[bin]*Scale[3];
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
 cout<<" H 130 GeV  "; for(int bin=0; bin<5; bin++) cout<<" & "<<events_H130[bin]*Scale[4];
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
 cout<<" H 140 GeV  "; for(int bin=0; bin<5; bin++) cout<<" & "<<events_H140[bin]*Scale[5];
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
 cout<<" H 150 GeV  "; for(int bin=0; bin<5; bin++) cout<<" & "<<events_H150[bin]*Scale[6];
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
 cout<<" H 155 GeV  "; for(int bin=0; bin<5; bin++) cout<<" & "<<events_H155[bin]*Scale[7];
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
 cout<<" H 160 GeV  "; for(int bin=0; bin<5; bin++) cout<<" & "<<events_H160[bin]*Scale[8];
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;

 Cut->SaveAs("cutflowH.pdf") ;


}//end drawHplus
