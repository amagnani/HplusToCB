//***********************************************************
//******drawing the histograms from the Hplus.C macro******
//***********************************************************
#include <TH1F>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

 void drawCutFlowSys(TString generator){

  TString TargetName4 ="Reco_hnVertex_4_sys0";
  TString TargetName6 ="Reco_hnVertex_6_sys0";
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
   //gStyle->SetOptLogx(1);
   gStyle->SetOptLogy(1);
   gStyle->SetOptLogz(0);
 
 //Load Files
  TFile *fWZ = new TFile("../output/HplusHistos_9b_WZ.root","READ");
  TFile *fZZ = new TFile("../output/HplusHistos_9b_ZZ.root","READ");
  TFile *fWW = new TFile("../output/HplusHistos_9b_WW.root","READ");
  TFile *fQCD = new TFile("../output/HplusHistos_9b_QCD.root","READ");
  TFile *fDY = new TFile("../output/HplusHistos_9b_DY.root","READ");
  TFile *fZbb = new TFile("../output/HplusHistos_9b_Zbb.root","READ");
  TFile *ft = new TFile("../output/HplusHistos_9b_t.root","READ");
  TFile *ftbar = new TFile("../output/HplusHistos_9b_tbar.root","READ");
  TFile *fs = new TFile("../output/HplusHistos_9b_s.root","READ");
  TFile *fsbar = new TFile("../output/HplusHistos_9b_sbar.root","READ");
  TFile *ftW = new TFile("../output/HplusHistos_9b_tW.root","READ");
  TFile *ftWbar = new TFile("../output/HplusHistos_9b_tWbar.root","READ");
  TFile *fWJets = new TFile("../output/HplusHistos_9b_WJets.root","READ");
  TFile *fWbb = new TFile("../output/HplusHistos_9b_Wbb.root","READ");
  TFile *fTTZ = new TFile("../output/HplusHistos_9b_TTZ.root","READ");
  TFile *fTTH = new TFile("../output/HplusHistos_9b_TTH.root","READ");
  TFile *fTTW = new TFile("../output/HplusHistos_9b_TTW.root","READ");
  TFile *fdata = new TFile("../output/HplusHistos_data.root","READ");
  if (generator=="pythia") { TFile *fTTJets = new TFile("../output/HplusHistos_TTJetsSplit.root","READ");}
  else if (generator=="amc@nlo") { TFile *fTTJets = new TFile("../output/TTnlo.root","READ");}
  else if (generator=="powheg") { TFile *fTTJets = new TFile("../output/TTpow.root","READ");}
 
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
  double xsecWbb 	= 377.4;
  double xsecZbb 	= 76.75;
  double xsecTTZ 	= 0.2057;
  double xsecTTH 	= 0.133;
  double xsecTTW 	= 0.232;

  double xsecTTJets_up 	= 268.2;
  double xsecTTJets_down= 236.6;
 
  const double ScaleZZ=lumi_factor*xsecZZ         / 9799908  ;//f
  const double ScaleWZ=lumi_factor*xsecWZ         / 9907189  ;//f
  const double ScaleWW=lumi_factor*xsecWW         / 10000431 ;//f
  const double ScaleQCD=lumi_factor*xsecQCD       / 57789606 ;//f       
  const double ScaleDY=lumi_factor*xsecDY         / 29632361 ;//f
  const double Scalet=lumi_factor*xsect           / 3579368  ;//f
  const double Scaletbar=lumi_factor*xsectbar     / 1935072  ;//f
  const double Scales=lumi_factor*xsecs           / 259961   ;//f
  const double Scalesbar=lumi_factor*xsecsbar     / 139974   ;//f
  const double ScaletW=lumi_factor*xsectW   	  / 484222   ;//f
  const double ScaletWbar=lumi_factor*xsectWbar	  / 493460   ;//f
  const double ScaleWJets=lumi_factor*xsecWJets	  / (57684680+18344535) ;//f
  const double ScaleTTZ=lumi_factor*xsecTTZ	  / 210160   ;//f
  const double ScaleTTH=lumi_factor*xsecTTH	  / 995697   ;//f
  const double ScaleTTW=lumi_factor*xsecTTW	  / 196046   ;//f
  const double ScaleWbb=lumi_factor*xsecWbb	  / 20598354 ;//f
  const double ScaleZbb=lumi_factor*xsecZbb       / 14109084 ;//f

  //scaledown 38776813 scaleup 41908271
  //sistemare qui aggiungendo peso per PU reweight ( ed il numero di eventi del TTbar Bonus) 0.9905= peso medio per il top pt reweight allo step Start
  //const double ScaleTTJets_up=lumi_factor*xsecTTJets_up / (62056531 * 0.9905) ; 
  //const double ScaleTTJets_down=lumi_factor*xsecTTJets_down / (62056531 * 0.9905) ; 

//tt catergories  	// =0   ---> ttbb  
	      		// =1   ---> ttbj
	      		// =2   ---> ttcc
	      		// =3   ---> ttqq
	      		// =4   ---> ttother
			
//get normalization factor for top reweighting procedure
if (generator=="pythia") {  double topreweight=0.9993;}  //weight up 1.007 //weight down 1
//if (generator=="pythia") {  double topreweight=0.9905;}  //weight up 1.007 //weight down 1
if (generator=="powheg") {  double topreweight=0.9995;}  //weight up 1.007 //weight down 1
   else if (generator=="amc@nlo") {  double topreweight=1;}


if (generator=="pythia") {
      const double      ScaleTTJets=lumi_factor*xsecTTJets / (62131965 * topreweight) ;
      const double      ScaleTTJets_up=lumi_factor*xsecTTJets_up / (62131965* topreweight) ; 
      const double      ScaleTTJets_down=lumi_factor*xsecTTJets_down / (62131965 * topreweight) ; 
}
else if (generator=="amc@nlo"){
      const double 	ScaleTTJets=lumi_factor*xsecTTJets / (32811330 * topreweight) ; 
      const double      ScaleTTJets_up=lumi_factor*xsecTTJets_up / (32811330 * topreweight) ; 
      const double      ScaleTTJets_down=lumi_factor*xsecTTJets_down / (32811330 * topreweight) ; 
}
else if (generator=="powheg") {
      const double 	ScaleTTJets=lumi_factor*xsecTTJets / (21578775 * topreweight) ; 
      const double      ScaleTTJets_up=lumi_factor*xsecTTJets_up / (21578775 * topreweight) ; 
      const double      ScaleTTJets_down=lumi_factor*xsecTTJets_down / (21578775 * topreweight) ; 
}




//LOAD HISTOGRAMS
  double events_WZ     [5];
  double events_ZZ     [5];
  double events_WW     [5];
  double events_QCD    [5];
  double events_DY     [5];
  double events_t      [5];
  double events_tbar   [5];
  double events_s      [5];
  double events_sbar   [5];
  double events_tW     [5];
  double events_tWbar  [5];
  double events_WJets  [5];
  double events_Wbb    [5];
  double events_Zbb    [5];
  double events_TTZ    [5];
  double events_TTH    [5];
  double events_TTW    [5];
  double events_data   [5];
  double events_TTJets_0[5];
  double events_TTJets_1[5];
  double events_TTJets_2[5];
  double events_TTJets_3[5];
  double events_TTJets_4[5];
  
for(int nsel=0; nsel<5;nsel++){  
cout<<TargetName[nsel]<<endl;
  TH1 *histo_WZ     = (TH1*)fWZ->Get(TargetName[nsel]);
  TH1 *histo_ZZ     = (TH1*)fZZ->Get(TargetName[nsel]);
  TH1 *histo_WW     = (TH1*)fWW->Get(TargetName[nsel]);
  TH1 *histo_QCD    = (TH1*)fQCD->Get(TargetName[nsel]);
  TH1 *histo_DY     = (TH1*)fDY->Get(TargetName[nsel]);
  TH1 *histo_t      = (TH1*)ft->Get(TargetName[nsel]);
  TH1 *histo_tbar   = (TH1*)ftbar->Get(TargetName[nsel]);
  TH1 *histo_s      = (TH1*)fs->Get(TargetName[nsel]);
  TH1 *histo_sbar   = (TH1*)fsbar->Get(TargetName[nsel]);
  TH1 *histo_tW     = (TH1*)ftW->Get(TargetName[nsel]);
  TH1 *histo_tWbar  = (TH1*)ftWbar->Get(TargetName[nsel]);
  TH1 *histo_WJets  = (TH1*)fWJets->Get(TargetName[nsel]);
  TH1 *histo_Wbb    = (TH1*)fWbb->Get(TargetName[nsel]);
  TH1 *histo_Zbb    = (TH1*)fZbb->Get(TargetName[nsel]);
  TH1 *histo_TTH    = (TH1*)fTTH->Get(TargetName[nsel]);
  TH1 *histo_TTZ    = (TH1*)fTTZ->Get(TargetName[nsel]);
  TH1 *histo_TTW    = (TH1*)fTTW->Get(TargetName[nsel]);
  TH1 *histo_data   = (TH1*)fdata->Get(TargetName[nsel]);

  TH1 *histo_TTJets_0 = (TH1*)fTTJets->Get(TargetName[nsel]+"_0");
  TH1 *histo_TTJets_1 = (TH1*)fTTJets->Get(TargetName[nsel]+"_1");
  TH1 *histo_TTJets_2 = (TH1*)fTTJets->Get(TargetName[nsel]+"_2");
  TH1 *histo_TTJets_3 = (TH1*)fTTJets->Get(TargetName[nsel]+"_3");
  TH1 *histo_TTJets_4 = (TH1*)fTTJets->Get(TargetName[nsel]+"_4");

  cout<<"getting integrals "<<nsel<<endl;
  events_WZ     [nsel]=histo_WZ->Integral();   cout<<"events_WZ "<<events_WZ<<endl;
  events_ZZ     [nsel]=histo_ZZ->Integral();    cout<<"events_ZZ "<<events_WZ<<endl;
  events_WW     [nsel]=histo_WW->Integral();    cout<<"events_WW "<<events_WZ<<endl;
  events_QCD    [nsel]=histo_QCD->Integral();   cout<<"events_QCD "<<events_QCD<<endl;
  events_DY     [nsel]=histo_DY->Integral();    cout<<"events_DY "<<events_DY<<endl;
  events_t      [nsel]=histo_t->Integral();  
  events_tbar   [nsel]=histo_tbar->Integral(); 
  events_s      [nsel]=histo_s->Integral();    
  events_sbar   [nsel]=histo_sbar->Integral(); 
  events_tW     [nsel]=histo_tW->Integral();   
  events_tWbar  [nsel]=histo_tWbar->Integral();
  events_WJets  [nsel]=histo_WJets->Integral();
  events_Wbb    [nsel]=histo_Wbb->Integral();  
  events_Zbb    [nsel]=histo_Zbb->Integral();  
  events_TTZ    [nsel]=histo_TTZ->Integral();  
  events_TTH    [nsel]=histo_TTH->Integral();  
  events_TTW    [nsel]=histo_TTW->Integral();  
  events_data   [nsel]=histo_data->Integral(); 

  events_TTJets_0[nsel]=histo_TTJets_0->Integral(); cout<<"events_TTJets_0 "<<events_TTJets_0[nsel]<<endl;
  events_TTJets_1[nsel]=histo_TTJets_1->Integral();
  events_TTJets_2[nsel]=histo_TTJets_2->Integral();
  events_TTJets_3[nsel]=histo_TTJets_3->Integral();
  events_TTJets_4[nsel]=histo_TTJets_4->Integral();
} 


TH1 *Target_WZ= new TH1F("Target_WZ"," ",5,-0.5,4.5); 
    Target_WZ->GetXaxis()->SetBinLabel(1," 1 muon");
    Target_WZ->GetXaxis()->SetBinLabel(2," >= 4 jets");  
    Target_WZ->GetXaxis()->SetBinLabel(3,"1 btag");
    Target_WZ->GetXaxis()->SetBinLabel(4,"2 btag");
    Target_WZ->GetXaxis()->SetBinLabel(5,"3 btag");  

  TH1 *Target_ZZ     = (TH1*) Target_WZ->Clone();
  TH1 *Target_WW     = (TH1*) Target_WZ->Clone();
  TH1 *Target_QCD    = (TH1*) Target_WZ->Clone();
  TH1 *Target_DY     = (TH1*) Target_WZ->Clone();
  TH1 *Target_t      = (TH1*) Target_WZ->Clone();
  TH1 *Target_tbar   = (TH1*) Target_WZ->Clone();
  TH1 *Target_s      = (TH1*) Target_WZ->Clone();
  TH1 *Target_sbar   = (TH1*) Target_WZ->Clone();
  TH1 *Target_tW     = (TH1*) Target_WZ->Clone();
  TH1 *Target_tWbar  = (TH1*) Target_WZ->Clone();
  TH1 *Target_WJets  = (TH1*) Target_WZ->Clone();
  TH1 *Target_TTJets = (TH1*) Target_WZ->Clone();
  TH1 *Target_Wbb    = (TH1*) Target_WZ->Clone();
  TH1 *Target_Zbb    = (TH1*) Target_WZ->Clone();
  TH1 *Target_TTZ    = (TH1*) Target_WZ->Clone();
  TH1 *Target_TTH    = (TH1*) Target_WZ->Clone();
  TH1 *Target_TTW    = (TH1*) Target_WZ->Clone();
  TH1 *Target_data   = (TH1*) Target_WZ->Clone();

  TH1 *Target_TTJets_0 = (TH1*) Target_WZ->Clone();
  TH1 *Target_TTJets_1 = (TH1*) Target_WZ->Clone();
  TH1 *Target_TTJets_2 = (TH1*) Target_WZ->Clone();
  TH1 *Target_TTJets_3 = (TH1*) Target_WZ->Clone();
  TH1 *Target_TTJets_4 = (TH1*) Target_WZ->Clone();

for(int bin=0;bin<5;bin++){

   Target_WZ->Fill(bin,events_WZ[bin]);
   Target_ZZ->Fill(bin,events_ZZ[bin]);
   Target_WW->Fill(bin,events_WW[bin]);
   Target_QCD->Fill(bin,events_QCD[bin]);
   Target_DY->Fill(bin,events_DY[bin]);
   Target_t->Fill(bin,events_t[bin]);
   Target_tbar->Fill(bin,events_tbar[bin]);
   Target_s->Fill(bin,events_s[bin]);
   Target_sbar->Fill(bin,events_sbar[bin]);
   Target_tW->Fill(bin,events_tW[bin]);
   Target_tWbar->Fill(bin,events_tWbar[bin]);
   Target_WJets->Fill(bin,events_WJets[bin]);
   Target_Wbb->Fill(bin,events_Wbb[bin]);
   Target_Zbb->Fill(bin,events_Zbb[bin]);
   Target_TTZ->Fill(bin,events_TTZ[bin]);
   Target_TTH->Fill(bin,events_TTH[bin]);
   Target_TTW->Fill(bin,events_TTW[bin]);
   Target_data->Fill(bin,events_data[bin] ); 

   Target_TTJets_0->Fill(bin,events_TTJets_0[bin]);
   Target_TTJets_1->Fill(bin,events_TTJets_1[bin]);
   Target_TTJets_2->Fill(bin,events_TTJets_2[bin]);
   Target_TTJets_3->Fill(bin,events_TTJets_3[bin]);
   Target_TTJets_4->Fill(bin,events_TTJets_4[bin]);
    }


//scalo alla fine i plot di cutflow 
  Target_WW->Scale(ScaleWW);
  Target_ZZ->Scale(ScaleZZ);
  Target_WZ->Scale(ScaleWZ);
  Target_QCD->Scale(ScaleQCD);
  Target_DY->Scale(ScaleDY);
  Target_Zbb->Scale(ScaleZbb);
  Target_Wbb->Scale(ScaleWbb);
  Target_t->Scale(Scalet);
  Target_tbar->Scale(Scaletbar);
  Target_s->Scale(Scales);
  Target_sbar->Scale(Scalesbar);
  Target_tW->Scale(ScaletW);
  Target_tWbar->Scale(ScaletWbar);
  Target_WJets->Scale(ScaleWJets);
  Target_TTJets->Scale(ScaleTTJets);
  Target_TTZ->Scale(ScaleTTZ);
  Target_TTH->Scale(ScaleTTH);
  Target_TTW->Scale(ScaleTTW);
  Target_TTJets_0->Scale(ScaleTTJets);
  Target_TTJets_1->Scale(ScaleTTJets);
  Target_TTJets_2->Scale(ScaleTTJets);
  Target_TTJets_3->Scale(ScaleTTJets);
  Target_TTJets_4->Scale(ScaleTTJets);

  Target_WZ->SetFillColor(kGray+3);  
  Target_WZ->SetLineColor(kGray+3);
  Target_WW->SetFillColor(kGray+3);
  Target_WW->SetLineColor(kGray+3);
  Target_ZZ->SetFillColor(kGray+3);
  Target_ZZ->SetLineColor(kGray+3);
  Target_QCD->SetFillColor(kBlue-7);
  Target_QCD->SetLineColor(kBlue-7);
  Target_DY->SetFillColor(kMagenta-2);
  Target_DY->SetLineColor(kMagenta-2);
  Target_Zbb->SetFillColor(kViolet+1);
  Target_Zbb->SetLineColor(kViolet+1);
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
  Target_WJets->SetLineColor(kOrange-2);
  Target_Wbb->SetFillColor(kOrange+1);
  Target_Wbb->SetLineColor(kOrange+1);
   Target_TTZ->SetFillColor(kMagenta-10);
  Target_TTZ->SetLineColor(kMagenta-10);
  Target_TTH->SetLineColor(kMagenta-9);
  Target_TTH->SetFillColor(kMagenta-9);
  Target_TTW->SetFillColor(kMagenta-7);
  Target_TTW->SetLineColor(kMagenta-7);
  Target_data->SetMarkerStyle(20);
  Target_data->SetLineColor(kBlack);

  Target_TTJets_0->SetFillColor(kRed-4);
  Target_TTJets_0->SetLineColor(kRed-4);
  Target_TTJets_1->SetFillColor(kCyan-10);
  Target_TTJets_1->SetLineColor(kCyan-10);
  Target_TTJets_2->SetFillColor(kAzure+1);
  Target_TTJets_2->SetLineColor(kAzure+1);
  Target_TTJets_3->SetFillColor(kAzure+2);
  Target_TTJets_3->SetLineColor(kAzure+2);
  Target_TTJets_4->SetFillColor(kAzure+3);
  Target_TTJets_4->SetLineColor(kAzure+3);

//******************************************************************************DATA

   TLegend *leg = new TLegend(0.6,0.6,0.75,0.89);
   leg->SetBorderSize(0);
   leg->SetLineColor(0);
   leg->SetLineStyle(0);
   leg->SetLineWidth(0);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   leg->AddEntry(Target_data,"data","p");
   leg->AddEntry(Target_WW,"VV","f");
   leg->AddEntry(Target_QCD,"QCD","f");
   leg->AddEntry(Target_DY, "Z+Jets","f");
   leg->AddEntry(Target_Zbb,"Z+bb","f");
   leg->AddEntry(Target_TTZ,"ttZ","f");
   leg->AddEntry(Target_TTJets_0,"ttbb","f");
   leg->AddEntry(Target_TTJets_1,"ttbj","f");
   
   
   
   TLegend *leg2 = new TLegend(0.75,0.6,0.89,0.89);
   leg2->SetBorderSize(0);
   leg2->SetLineColor(0);
   leg2->SetLineStyle(0);
   leg2->SetLineWidth(0);
   leg2->SetFillColor(0);
   leg2->SetFillStyle(1001);
   leg2->AddEntry(Target_TTH,"ttH","f");
   leg2->AddEntry(Target_TTW,"ttW","f");
   leg2->AddEntry(Target_WJets,"W+Jets","f");
   leg2->AddEntry(Target_Wbb,"W+bb","f");
   leg2->AddEntry(Target_t,"Single top","f");
   leg2->AddEntry(Target_TTJets_2,"ttcc","f");
   leg2->AddEntry(Target_TTJets_3,"ttjj","f");
   leg2->AddEntry(Target_TTJets_4,"tt other","f");
    
 //************************************************Define Stacks
  

    THStack *hs_Target;	
    hs_Target= new THStack("hs_Target","Cutflow;;#events");
    
     hs_Target->Add(Target_WZ);  
     hs_Target->Add(Target_WW);  
     hs_Target->Add(Target_ZZ);  
     hs_Target->Add(Target_QCD);  
     hs_Target->Add(Target_DY);  
     hs_Target->Add(Target_Zbb);  
     hs_Target->Add(Target_TTW);  
     hs_Target->Add(Target_TTH);  
     hs_Target->Add(Target_TTZ);  
     hs_Target->Add(Target_WJets);  
     hs_Target->Add(Target_Wbb);  
     hs_Target->Add(Target_t);  
     hs_Target->Add(Target_tbar);  
     hs_Target->Add(Target_tW);  
     hs_Target->Add(Target_tWbar);  
     hs_Target->Add(Target_s);  
     hs_Target->Add(Target_sbar);  
     hs_Target->Add(Target_TTJets_0);  
     hs_Target->Add(Target_TTJets_1);  
     hs_Target->Add(Target_TTJets_2);  
     hs_Target->Add(Target_TTJets_3);  
     hs_Target->Add(Target_TTJets_4);  
     
     TH1 *sum_Target = hs_Target->GetStack()->Last();


     gROOT->LoadMacro("CustomSubtractHisto.cc");
 
  TCanvas *Cut = new TCanvas("MyCanvas","MyCanvas",800,800);
  Target_WZ->Draw();
//  Cut = new TCanvas("Cut","CutFlow",1000,600);
  TPad * b = new TPad("b", "b",0.05, 0.25, 0.096, 0.35);
  b->SetBorderMode(0);
 
  Cut->Divide(1,2);
  Cut->GetPad(1)->SetPad(0, 0.3, 1, 1);
  Cut->GetPad(1)->SetBottomMargin(0);
  Cut->GetPad(2)->SetPad(0, 0, 1, 0.3);
  Cut->GetPad(2)->SetTopMargin(0);
  Cut->GetPad(2)->SetBottomMargin(0.4);
  Cut->cd(1);
  gPad->SetLogx(0);


  sum_Target->GetYaxis()->SetLabelSize(0.05);
  sum_Target->GetYaxis()->SetRangeUser(1,100000000);
  sum_Target->Draw();
  hs_Target->Draw("same");	
  
  Target_data->GetXaxis()->SetLabelSize(0.1);
  Target_data->SetMarkerStyle(20);
  Target_data->Draw("PEsame");

  // 
//    //draw systematic band
//   gROOT->LoadMacro("spitCutFlowSYS.C");
//   TH1 * wUP   =spitCutFlowSYS(generator,1);
//   TH1 * wDOWN =spitCutFlowSYS(generator,2);
//   TH1 * mUP   =spitCutFlowSYS(generator,3);
//   TH1 * mDOWN =spitCutFlowSYS(generator,4);
//   TH1 * bUP   =spitCutFlowSYS(generator,5);
//   TH1 * bDOWN =spitCutFlowSYS(generator,6);
//   TH1 * tUP   =spitCutFlowSYS(generator,8);
//   TH1 * tDOWN =spitCutFlowSYS(generator,7);
//   
//  
//   wUP	->Add(sum_Target,-1);
//   wDOWN ->Add(sum_Target,-1);
//   mUP	->Add(sum_Target,-1);
//   mDOWN ->Add(sum_Target,-1);
//   bUP	->Add(sum_Target,-1);
//   bDOWN ->Add(sum_Target,-1);
//   tUP	->Add(sum_Target,-1);
//   tDOWN ->Add(sum_Target,-1);
//   wUP	->Multiply(wUP);
//   wDOWN ->Multiply(wDOWN);
//   mUP	->Multiply(mUP);
//   mDOWN ->Multiply(mDOWN);
//   bUP	->Multiply(bUP);
//   bDOWN ->Multiply(bDOWN);
//   tUP	->Multiply(tUP);
//   tDOWN ->Multiply(tDOWN);
//  
// //per il momento b, w e t
// TH1 *histo_up= (TH1*)wUP->Clone();
// histo_up->Add(bUP);
// histo_up->Add(tUP);
// 
// TH1 *histo_down= (TH1*)wDOWN->Clone();
// histo_down->Add(bDOWN);
// histo_down->Add(tDOWN);
//   double x[200];
//   double y[200];
//   double x[200];
//   double errxp[200];
//   double errxm[200];
//   double erryp[200];
//   double errym[200];
//   for(int bb=0;bb<sum_Target->GetNbinsX();bb++){
// 
// 
//   //dalla Stack Monte carlo
//   x[bb]=sum_Target->GetBinCenter(bb+1);
//   errxp[bb]=(sum_Target->GetBinWidth(bb+1))/2;
//   errxm[bb]=errxp[bb];
//   y[bb]=sum_Target->GetBinContent(bb+1);
// 
//  //dal file per la sistematica
//   erryp[bb]=sqrt(histo_up->GetBinContent(bb+1));
//   errym[bb]=sqrt(histo_down->GetBinContent(bb+1));
// 
// 
//    cout<<"histoup "<<histo_up->GetBinContent(bb+1)<<" "<< erryp[bb]<<endl;
//    cout<<"histodown "<<histo_down->GetBinContent(bb+1)<<" "<< errym[bb]<<endl;
//    cout<<"200 "<<x[bb]<<" "<<errxp[bb]<<" "<<errxm[bb]<<" "<<y[bb]<<" "<<erryp[bb]<<" "<<errym[bb]<<endl;
// 
//  }
//   for(int bb=0;bb<sum_Target->GetNbinsX();bb++){
//    cout<<"error "<<Target_data->GetBinContent(bb+1)<<" "<< Target_data->GetBinError(bb+1)<<endl;
// }
//   int bins=sum_Target->GetNbinsX();
//   Band = new TGraphAsymmErrors(bins,x,y,errxm,errxp,errym,erryp);
//   Band->SetFillStyle(3001); 
//   Band->SetFillColor(kBlack); 
//   Band->Draw("p2same"); 
// 
//   TH1 *stack_up=(TH1*)sum_Target->Clone();
//   TH1 *stack_down=(TH1*)sum_Target->Clone();
//   for(int bb=0;bb<sum_Target->GetNbinsX();bb++){
//   stack_up->SetBinContent(bb+1,sum_Target->GetBinContent(bb+1)+erryp[bb]);
//   stack_down->SetBinContent(bb+1,sum_Target->GetBinContent(bb+1)-errym[bb]);
// }

  leg->Draw();
  leg2->Draw();
   Cut->cd(2);
  
    TH1F * Discrepancy=CustomSubtractHisto("", sum_Target, Target_data);
    Discrepancy->GetXaxis()->SetBinLabel(1," 1 muon");
    Discrepancy->GetXaxis()->SetBinLabel(2," >= 4 jets");  
    Discrepancy->GetXaxis()->SetBinLabel(3,"1 btag, MET>20 ");
    Discrepancy->GetXaxis()->SetBinLabel(4,"2 btag ");
    Discrepancy->GetXaxis()->SetBinLabel(5,"3 btag ");  
       Discrepancy->SetStats(0);
       Discrepancy->SetLineColor(1);
       //Discrepancy->SetLineWidth(4);
       //Discrepancy->SetBinContent(0,1);
       Discrepancy->GetXaxis()->SetTickLength(0.1);
       Discrepancy->SetMarkerStyle(20);
       Discrepancy->GetXaxis()->SetLabelSize(0.1);
       //Discrepancy->GetXaxis()->SetTitle(hTitle);
  //   Discrepancy->GetXaxis()->SetRangeUser(0, 25);
       gPad->SetLogy(0);
       gPad->SetLogx(0);
       gPad->SetTicks();
       Discrepancy->GetYaxis()->SetRangeUser(0.2, 1.7);
       Discrepancy->GetYaxis()->SetNdivisions(505);
       Discrepancy->GetXaxis()->SetLabelSize(0.15);
       Discrepancy->GetYaxis()->SetLabelSize(0.15);
       Discrepancy->GetYaxis()->SetTitle(" Data/Bkg");
       Discrepancy->GetYaxis()->SetTitleSize(0.15);
       Discrepancy->GetYaxis()->SetTitleOffset(0.3);
       Discrepancy->GetXaxis()->SetTitleOffset(1.2);
       Discrepancy->GetXaxis()->SetTitleSize(0.15);
       Discrepancy->GetXaxis()->SetTitle("");
       Discrepancy->Draw("EP");
   // TH1F * Discrepancy_up=CustomSubtractHisto("", sum_Target,stack_up );
    //TH1F * Discrepancy_down=CustomSubtractHisto("", sum_Target,stack_down );
 
   double dy[200];
   for(int d=0;d<200;d++){ dy[d]=1;}
   double derryp[200];
   double derrym[200];
    
//   for(int bb=0;bb<sum_Target->GetNbinsX();bb++){
// 
//  //dal file per la sistematica
//   derryp[bb]=Discrepancy_up->GetBinContent(bb+1) -1 ;
//   derrym[bb]=1- Discrepancy_down->GetBinContent(bb+1);
// 
// } 
//   Discrepancy_Band = new TGraphAsymmErrors(bins,x,dy,errxm,errxp,derrym,derryp);
//   Discrepancy_Band->SetFillStyle(3001); 
//   //Discrepancy_Band->SetFillColor(kGray); 
//   Discrepancy_Band->Draw("p2"); 
// 
// 
 double la=0;
 double lb=0;
 la=sum_Target->GetBinLowEdge(1);
 lb=1+sum_Target->GetBinLowEdge(sum_Target->GetNbinsX() );
         TLine *l1 = new TLine(la, 1, lb,  1);
         l1->SetLineColor(kRed);
 	l1->SetLineWidth(2);
         l1->Draw("");
         Discrepancy->Draw("same"); 
 	Cut->cd(0);
 	//b->SetGridy();
 	b->Draw();
//   



 //spit latex Yields table
 cout<<" \\hline "<<endl;
 cout<<" &  1 muon & $\\geq$ 4 jets  &   MET$\\geq$20 , $\\geq$ 1 CSVM &  $\\geq$ 2 CSVM     & $\\geq$ 3 CSVM  \\\\"<<endl;
 cout<<" \\hline "<<endl;
  cout<<" tt bb  "; for(int bin=0; bin<5; bin++) cout<<" & "<<Target_TTJets_0->GetBinContent(bin+1);
  cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
  cout<<" tt bj  "; for(int bin=0; bin<5; bin++) cout<<" & "<<Target_TTJets_1->GetBinContent(bin+1);
  cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
  cout<<" tt cc  "; for(int bin=0; bin<5; bin++) cout<<" & "<<Target_TTJets_2->GetBinContent(bin+1);
  cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
  cout<<" tt jj  "; for(int bin=0; bin<5; bin++) cout<<" & "<<Target_TTJets_3->GetBinContent(bin+1);
  cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
  cout<<" tt other  "; for(int bin=0; bin<5; bin++) cout<<" & "<<Target_TTJets_4->GetBinContent(bin+1);
  cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
  cout<<" tt   "; for(int bin=0; bin<5; bin++) cout<<" & "<<Target_TTJets_0->GetBinContent(bin+1)+Target_TTJets_1->GetBinContent(bin+1)+Target_TTJets_2->GetBinContent(bin+1)+Target_TTJets_3->GetBinContent(bin+1)+Target_TTJets_4->GetBinContent(bin+1);
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
 cout<<" diboson  "; for(int bin=0; bin<5; bin++) cout<<" & "<<events_ZZ[bin]*ScaleZZ+ events_WZ[bin]*ScaleWZ + events_WW[bin]*ScaleWW ;
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
 cout<<" single top  "; for(int bin=0; bin<5; bin++) cout<<" & "<<events_t[bin]*Scalet+ events_tbar[bin]*Scaletbar + events_s[bin]*Scales  + events_sbar[bin]*Scalesbar
 + events_tW[bin]*ScaletW + events_tWbar[bin]*ScaletWbar;
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
 cout<<" W+jets  "; for(int bin=0; bin<5; bin++) cout<<" & "<<events_WJets[bin]*ScaleWJets;
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
 cout<<" W+bb  "; for(int bin=0; bin<5; bin++) cout<<" & "<<events_Wbb[bin]*ScaleWbb;
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
 cout<<" Z+jets  "; for(int bin=0; bin<5; bin++) cout<<" & "<<events_DY[bin]*ScaleDY;
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
 cout<<" Z+bb "; for(int bin=0; bin<5; bin++) cout<<" & "<<events_Zbb[bin]*ScaleZbb;
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
 cout<<" QCD  "; for(int bin=0; bin<5; bin++) cout<<" & "<<events_QCD[bin]*ScaleQCD;
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
 cout<<" ttZ  "; for(int bin=0; bin<5; bin++) cout<<" & "<<events_TTZ[bin]*ScaleTTZ;
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
 cout<<" ttH  "; for(int bin=0; bin<5; bin++) cout<<" & "<<events_TTH[bin]*ScaleTTH;
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
 cout<<" ttW  "; for(int bin=0; bin<5; bin++) cout<<" & "<<events_TTW[bin]*ScaleTTW;
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
 cout<<" total bkg  "; for(int bin=0; bin<5; bin++) cout<<" & "<<sum_Target->GetBinContent(bin+1);
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;
 cout<<" data "; for(int bin=0; bin<5; bin++) cout<<" & "<<events_data[bin];
 cout<<" \\\\ "<<endl; cout<<" \\hline "<<endl;



 //   cout<<" ttbar up  "; for(int bin=0; bin<5; bin++) cout<<"  "<<events_TTJets[bin]*ScaleTTJets_up;
//    cout<<" ttbar down  "; for(int bin=0; bin<5; bin++) cout<<"  "<<events_TTJets[bin]*ScaleTTJets_down;

 //const char figure[30],
 //sprintf(figure,"%s.png",TargetName);
 Cut->SaveAs("cutflow.pdf") ;



}//end drawHplus


