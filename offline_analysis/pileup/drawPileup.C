//***********************************************************
//******drawing the histograms from the Hplus.C macro******
//***********************************************************
#include <TH1F>

 void drawPileup(){
   
   gROOT->ProcessLine(".L tdrstyle.C");
   //gStyle->SetOptStat("emr");
   gStyle->SetOptStat(0);
   //gStyle->SetOptLogx(1);
   gStyle->SetOptLogy(0);
   gStyle->SetOptLogz(0);
 
  //Load Files
  TFile *fWZ = new TFile("Pileup_WZ.root","READ");
  TFile *fZZ = new TFile("Pileup_ZZ.root","READ");
  TFile *fWW = new TFile("Pileup_WW.root","READ");
  TFile *fQCD = new TFile("Pileup_QCD.root","READ");
  TFile *fDY = new TFile("Pileup_DY.root","READ");
  TFile *ft = new TFile("Pileup_t.root","READ");
  TFile *ftbar = new TFile("Pileup_tbar.root","READ");
  TFile *fs = new TFile("Pileup_s.root","READ");
  TFile *fsbar = new TFile("Pileup_sbar.root","READ");
  TFile *ftW = new TFile("Pileup_tW.root","READ");
  TFile *ftWbar = new TFile("Pileup_tWbar.root","READ");
  TFile *fWJets = new TFile("Pileup_WJets.root","READ");
  TFile *fTTJets = new TFile("Pileup_TTJets.root","READ");

  TFile *fcheck = new TFile("PUweight_Bkg2.root","READ");
   TFile *fdata = new TFile("MyDataPileupHistogram.root","READ");

  //scale histograms
  double lumi_factor= 19.7*1e+15*1e-12;
  //cross section (pb)
  double xsecZZ 	= 5.196;
  double xsecWZ 	= 12.63;
  double xsecWW 	= 33.61;
  double xsecQCD 	= 134680.0;
  double xsecDY 	= 3504;
  double xsect 		= 56.4;
  double xsectbar 	= 30.7;
  double xsecs 		= 3.79;
  double xsecsbar 	= 1.76;
  double xsectW 	= 11.1;
  double xsectWbar 	= 11.1;
  double xsecWJets 	= 36257;
  double xsecTTJets 	= 252.9;
  
  const double ScaleZZ=lumi_factor*xsecZZ    / (9795752*1.001);
  const double ScaleWZ=lumi_factor*xsecWZ   / (9996215*1.001);
  const double ScaleWW=lumi_factor*xsecWW   / (7.733679*1e7*1.001);
  const double ScaleQCD=lumi_factor*xsecQCD  / (5.537337*1e7*1.001);
  const double ScaleDY=lumi_factor*xsecDY   / (2.970527*1e7*1.001);
  const double Scalet=lumi_factor*xsect     / (37557727*1.001);
  const double Scaletbar=lumi_factor*xsectbar  / (1934083*1.001);
  const double Scales=lumi_factor*xsecs     / (259748*1.001);
  const double Scalesbar=lumi_factor*xsecsbar / (139887*1.001);
  const double ScaletW=lumi_factor*xsectW   / (497270*1.001);
  const double ScaletWbar=lumi_factor*xsectWbar / (493077*1.001);
  const double ScaleWJets=lumi_factor*xsecWJets / (7.301221*1e7*1.001);
  const double ScaleTTJets=lumi_factor*xsecTTJets / (6923652);


//LOAD HISTOGRAMS
  
   TH1F *Target_WZ     = (TH1F*)fWZ->Get("pileup");
   TH1F *Target_ZZ     = (TH1F*)fZZ->Get("pileup");
   TH1F *Target_WW     = (TH1F*)fWW->Get("pileup");
   TH1F *Target_QCD    = (TH1F*)fQCD->Get("pileup");
   TH1F *Target_DY     = (TH1F*)fDY->Get("pileup");
   TH1F *Target_t      = (TH1F*)ft->Get("pileup");
   TH1F *Target_tbar   = (TH1F*)ftbar->Get("pileup");
   TH1F *Target_s      = (TH1F*)fs->Get("pileup");
   TH1F *Target_sbar   = (TH1F*)fsbar->Get("pileup");
   TH1F *Target_tW     = (TH1F*)ftW->Get("pileup");
   TH1F *Target_tWbar  = (TH1F*)ftWbar->Get("pileup");
   TH1F *Target_WJets  = (TH1F*)fWJets->Get("pileup");
   TH1F *Target_TTJets = (TH1F*)fTTJets->Get("pileup");
 
   TH1F *Target_check = (TH1F*)fcheck->Get("test");
   TH1F *Target_data = (TH1F*)fdata->Get("pileup");
 
 	Target_WW->Scale(ScaleWW);
  	Target_ZZ->Scale(ScaleZZ);
	Target_WZ->Scale(ScaleWZ);
 	Target_QCD->Scale(ScaleQCD);
 	Target_DY->Scale(ScaleDY);
 	Target_t->Scale(Scalet);
 	Target_tbar->Scale(Scaletbar);
 	Target_s->Scale(Scales);
 	Target_sbar->Scale(Scalesbar);
 	Target_tW->Scale(ScaletW);
 	Target_tWbar->Scale(ScaletWbar);
 	Target_WJets->Scale(ScaleWJets);
 	Target_TTJets->Scale(ScaleTTJets);

  Target_WZ->SetFillColor(kGray+3);  
  Target_WZ->SetLineColor(kGray+3);
  Target_WW->SetFillColor(kGray+3);
  Target_WW->SetLineColor(kGray+3);
  Target_ZZ->SetFillColor(kGray+3);
  Target_ZZ->SetLineColor(kGray+3);
  Target_QCD->SetFillColor(kBlue-7);
  Target_DY->SetFillColor(kMagenta-2);
  Target_t->SetFillColor(kGreen+1);
  Target_t->SetLineColor(kGreen+1);
  Target_tbar->SetFillColor(kGreen+1);
  Target_tbar->SetLineColor(kGreen+1);
  Target_tW->SetLineColor(kGreen+1);
  Target_tW->SetFillColor(kGreen+1);
  Target_tWbar->SetFillColor(kGreen+1);
  Target_tWbar->SetLineColor(kGreen+1);
  Target_s->SetFillColor(kGreen+1);
  Target_s->SetLineColor(kGreen+1);
  Target_sbar->SetFillColor(kGreen+1);
  Target_sbar->SetLineColor(kGreen+1);
  Target_WJets->SetFillColor(kOrange-2);
  Target_TTJets->SetFillColor(kRed-4);
 

   TLegend *leg = new TLegend(0.75,0.6,0.89,0.89);
   leg->SetBorderSize(0);
   leg->SetLineColor(0);
   leg->SetLineStyle(0);
   leg->SetLineWidth(0);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   leg->AddEntry(Target_WW,"VV","f");
   leg->AddEntry(Target_QCD,"QCD","f");
   leg->AddEntry(Target_DY,"Z+Jets","f");
   leg->AddEntry(Target_t,"Single top","f");
   leg->AddEntry(Target_WJets,"W+Jets","f");
   leg->AddEntry(Target_TTJets,"TTbar","f");
   
 //************************************************Define Stacks
 
    THStack *hs_Target;	
    hs_Target= new THStack("hs_Target","Cutflow;;#events");
//     hs_MUeta= new THStack("hs_MUeta","Muon eta");
//     hs_MUpt= new THStack("hs_MUpt",";Muon pt (GeV);");
//     hs_Jeta= new THStack("hs_Jeta",";Jet eta;");
//     hs_Jpt= new THStack("hs_Jpt",";Jet pt (GeV);");
//     hs_nJet= new THStack("hs_nJet",";Jet Multeplicity ;");
//     hs_MET= new THStack("hs_MET",";MET;");
//     hs_kinfit= new THStack("hs_kinfit",";M_{jj} (GeV);");   
    
     hs_Target->Add(Target_WZ);  
     hs_Target->Add(Target_WW);  
     hs_Target->Add(Target_ZZ);  
     hs_Target->Add(Target_QCD);  
     hs_Target->Add(Target_DY);  
     hs_Target->Add(Target_t);  
     hs_Target->Add(Target_tbar);  
     hs_Target->Add(Target_tW);  
     hs_Target->Add(Target_tWbar);  
     hs_Target->Add(Target_s);  
     hs_Target->Add(Target_sbar);  
     hs_Target->Add(Target_WJets);  
     hs_Target->Add(Target_TTJets);  
     TH1 *sum_Target = hs_Target->GetStack()->Last();
  
     Target_check->SetFillColor(kRed-4);
     Target_data->SetFillColor(kBlue-4);
     	Target_check->SetTitle("");
	Target_data ->SetTitle("");
	sum_Target  ->SetTitle("");
     	Target_check->GetXaxis()->SetTitle("pileup interactions");
	Target_data ->GetXaxis()->SetTitle("pileup interactions");
	sum_Target  ->GetXaxis()->SetTitle("pileup interactions");
        Target_data->GetXaxis()->SetLabelSize(0.05);
        Target_data->GetXaxis()->SetTitleSize(0.05);
        Target_data->SetMarkerStyle(20);
        Target_data->GetYaxis()->SetLabelSize(0.05);
        Target_check->GetXaxis()->SetLabelSize(0.05);
        Target_check->GetXaxis()->SetTitleSize(0.05);
        Target_check->SetMarkerStyle(20);
        Target_check->GetYaxis()->SetLabelSize(0.05);
	sum_Target->GetXaxis()->SetLabelSize(0.05);
	sum_Target->GetXaxis()->SetTitleSize(0.05);
	sum_Target->SetMarkerStyle(20);
	sum_Target->GetYaxis()->SetLabelSize(0.05);
  
  TCanvas *Cut = new TCanvas("MyCanvas","MyCanvas",1600,400);
  Cut->Divide(3,1);
  Cut->cd(1);
  sum_Target->Draw();
  Cut->cd(2);
  Target_data->Draw();
  Cut->cd(3);
  Target_check->Draw();
 
//    TFile *fHistos= new TFile("Pileup_Bkg.root","RECREATE");
//  sum_Target->Write();


}//end drawHplus
