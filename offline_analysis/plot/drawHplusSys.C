//***********************************************************
//******drawing the histograms from the Hplus.C macro******
//***********************************************************
#include <TH1F>
#include <iostream>
#include <string.h>
#include <vector>

/* Possible input Names
   
   cutflow
   MUeta
   MUpt
   Jeta
   Jpt
   nJet
   MET	
	
*/	     
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


 void drawHplusSys(TString TargetName, TString generator,TString title, float Range1, float Range2, int log ){
 
   cout<<TargetName<<endl;
   char G[5]="Gen";
   char Jpt[5]="hJpt";
   char Jeta[5]="hJeta";
   char nJet[5]="hnJet";
   char MUpt[5]="hMUpt";
   char MUeta[5]="hMUeta";
   char MUiso[5]="hMUrelIso";
   char MET[5]="hMET";
 
   char ext4[5]="4";
   char ext6[5]="6";
   char ext7[5]="7";
   char ext9b[5]="9b";
   char ext8[5]="8";
   char ext8b[5]="8b";
 
   char Vertex[5]="hnVertex";
   char VertexNW[5]="hnVertexNW";
   char Jeta[5]="hJeta";
   char nJet[5]="hnJet";
   char MUpt[5]="hMUpt";
   char MUeta[5]="hMUeta";
   char MUiso[5]="hMUrelIso";
   char MET[5]="hMET";
    
   gROOT->ProcessLine(".L tdrstyle.C");
   //gStyle->SetOptStat("emr");
   gStyle->SetOptStat(0);
   // gStyle->SetOptLogx(1);
   gStyle->SetOptLogy(1);
   gStyle->SetOptLogz(0);
  
 //Load Files
  TFile *fWZ = new TFile("../output_backup/HplusHistos_9b_WZ.root","READ");
  TFile *fZZ = new TFile("../output_backup/HplusHistos_9b_ZZ.root","READ");
  TFile *fWW = new TFile("../output_backup/HplusHistos_9b_WW.root","READ");
  TFile *fQCD = new TFile("../output_backup/HplusHistos_9b_QCD.root","READ");
  TFile *fDY = new TFile("../output_backup/HplusHistos_9b_DY.root","READ");
  TFile *fZbb = new TFile("../output_backup/HplusHistos_9b_Zbb.root","READ");
  TFile *ft = new TFile("../output_backup/HplusHistos_9b_t.root","READ");
  TFile *ftbar = new TFile("../output_backup/HplusHistos_9b_tbar.root","READ");
  TFile *fs = new TFile("../output_backup/HplusHistos_9b_s.root","READ");
  TFile *fsbar = new TFile("../output_backup/HplusHistos_9b_sbar.root","READ");
  TFile *ftW = new TFile("../output_backup/HplusHistos_9b_tW.root","READ");
  TFile *ftWbar = new TFile("../output_backup/HplusHistos_9b_tWbar.root","READ");
  TFile *fWJets = new TFile("../output_backup/HplusHistos_9b_WJets.root","READ");
  TFile *fWbb = new TFile("../output_backup/HplusHistos_9b_Wbb.root","READ");
  TFile *fTTZ = new TFile("../output_backup/HplusHistos_9b_TTZ.root","READ");
  TFile *fTTH = new TFile("../output_backup/HplusHistos_9b_TTH.root","READ");
  TFile *fTTW = new TFile("../output_backup/HplusHistos_9b_TTW.root","READ");
  TFile *fdata = new TFile("../output_backup/HplusHistos_data.root","READ");
  if (generator=="pythia") { TFile *fTTJets = new TFile("../output_backup/HplusHistos_TTJetsSplit.root","READ");}
  else if (generator=="amc@nlo") { TFile *fTTJets = new TFile("../output_backup/HplusHistos_TTnlo.root","READ");}
  else if (generator=="powheg") { TFile *fTTJets = new TFile("../output_backup/HplusHistos_TTpow.root","READ");}
 
  
   //scale histograms
   double lumi_factor= 19.7*1e+15*1e-12;
   //cross section (pb)
   double xsecZZ      = 5.196;
   double xsecWZ      = 12.63;
   double xsecWW      = 33.61;
   double xsecQCD     = 134680.0;
   double xsecDY      = 3504;
   double xsect       = 56.4;
   double xsectbar    = 30.7;
   double xsecs       = 3.79;
   double xsecsbar    = 1.76;
   double xsectW      = 11.1;
   double xsectWbar   = 11.1;
   double xsecWJets   = 36257;
   double xsecTTJets  = 252.9;
   double xsecWbb     = 377.4;
   double xsecZbb     = 76.75;
   double xsecTTZ     = 0.2057;
   double xsecTTH     = 0.133;
   double xsecTTW     = 0.232;
   double xsecTTJets_up  = 268.2;
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

 //tt catergories     // =0   ---> ttbb  
		      // =1   ---> ttbj
		      // =2   ---> ttcc
		      // =3   ---> ttqq
		      // =4   ---> ttother
		      
//  //get normalization factor for top reweighting procedure
// if (generator=="pythia") {  double topreweight=0.990549;}
//    else if (generator=="amc@nlo") {  double topreweight=1;}
//get normalization factor for top reweighting procedure
if (generator=="pythia") {  double topreweight=0.9993;}  //weight up 1.007 //weight down 1
if (generator=="powheg") {  double topreweight=0.9995;}  //weight up 1.007 //weight down 1
   else if (generator=="amc@nlo") {  double topreweight=1;}


 // double topreweight=1;		      
 // 
 // TH1 *weightsum   = (TH1*)fTTJets->Get("Reco_hTopPtWeight_Start_0_0");
 // TH1 *weight0     = (TH1*)fTTJets->Get("Reco_hTopPtWeight_Start_0_0");
 // TH1 *weight1     = (TH1*)fTTJets->Get("Reco_hTopPtWeight_Start_0_1");
 // TH1 *weight2     = (TH1*)fTTJets->Get("Reco_hTopPtWeight_Start_0_2");
 // TH1 *weight3     = (TH1*)fTTJets->Get("Reco_hTopPtWeight_Start_0_3");
 // TH1 *weight4     = (TH1*)fTTJets->Get("Reco_hTopPtWeight_Start_0_4");
 // 
 // weightsum->Add(weight1);
 // weightsum->Add(weight2);
 // weightsum->Add(weight3);
 // weightsum->Add(weight4);
 // 
 // topreweight=weightsum->GetMean();
 // cout<<"+++++++++topreweight "<<topreweight<<endl;		      
 // cout<<"+++++++++entries "<<weightsum->GetEntries()<<endl;
 // cout<<"+++++++++mean "<<weightsum->GetMean()<<endl;
 // 
if (generator=="pythia") {
      const double      ScaleTTJets=lumi_factor*xsecTTJets / (61762848 * topreweight) ;
      const double      ScaleTTJets_up=lumi_factor*xsecTTJets_up / (61762848 * topreweight) ; 
      const double      ScaleTTJets_down=lumi_factor*xsecTTJets_down / (61762848 * topreweight) ; 
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
   TH1 *Target_WZ     = (TH1*)fWZ->Get(TargetName+"_sys0");
   TH1 *Target_ZZ     = (TH1*)fZZ->Get(TargetName+"_sys0");
   TH1 *Target_WW     = (TH1*)fWW->Get(TargetName+"_sys0");
   TH1 *Target_QCD    = (TH1*)fQCD->Get(TargetName+"_sys0");
   TH1 *Target_DY     = (TH1*)fDY->Get(TargetName+"_sys0");
   TH1 *Target_t      = (TH1*)ft->Get(TargetName+"_sys0");
   TH1 *Target_tbar   = (TH1*)ftbar->Get(TargetName+"_sys0");
   TH1 *Target_s      = (TH1*)fs->Get(TargetName+"_sys0");
   TH1 *Target_sbar   = (TH1*)fsbar->Get(TargetName+"_sys0");
   TH1 *Target_tW     = (TH1*)ftW->Get(TargetName+"_sys0");
   TH1 *Target_tWbar  = (TH1*)ftWbar->Get(TargetName+"_sys0");
   TH1 *Target_WJets  = (TH1*)fWJets->Get(TargetName+"_sys0");
   TH1 *Target_TTJets = (TH1*)fTTJets->Get(TargetName+"_sys0");
   TH1 *Target_Wbb    = (TH1*)fWbb->Get(TargetName+"_sys0");
   TH1 *Target_Zbb    = (TH1*)fZbb->Get(TargetName+"_sys0");
   TH1 *Target_TTH    = (TH1*)fTTH->Get(TargetName+"_sys0");
   TH1 *Target_TTW    = (TH1*)fTTW->Get(TargetName+"_sys0");
   TH1 *Target_TTZ    = (TH1*)fTTZ->Get(TargetName+"_sys0");
   
    TH1 *Target_TTJets_0 = (TH1*)fTTJets->Get(TargetName+"_sys0"+"_0");
    TH1 *Target_TTJets_1 = (TH1*)fTTJets->Get(TargetName+"_sys0"+"_1");
    TH1 *Target_TTJets_2 = (TH1*)fTTJets->Get(TargetName+"_sys0"+"_2");
    TH1 *Target_TTJets_3 = (TH1*)fTTJets->Get(TargetName+"_sys0"+"_3");
    TH1 *Target_TTJets_4 = (TH1*)fTTJets->Get(TargetName+"_sys0"+"_4");
 
//    TH1 *Target_TTJets_0 = (TH1*)fTTJets->Get("Reco_hMUrelIso8b_sys0_0");
//    TH1 *Target_TTJets_1 = (TH1*)fTTJets->Get("Reco_hMUrelIso8b_sys0_1");
//    TH1 *Target_TTJets_2 = (TH1*)fTTJets->Get("Reco_hMUrelIso8b_sys0_2");
//    TH1 *Target_TTJets_3 = (TH1*)fTTJets->Get("Reco_hMUrelIso8b_sys0_3");
//    TH1 *Target_TTJets_4 = (TH1*)fTTJets->Get("Reco_hMUrelIso8b_sys0_4");
 
   TH1 *Target_data   = (TH1*)fdata->Get(TargetName+"_sys0");
 
  if (TargetName != "cutflow") { 
  

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
      Target_Wbb->Scale(ScaleWbb);
      Target_Zbb->Scale(ScaleZbb);
      Target_TTZ->Scale(ScaleTTZ);
      Target_TTH->Scale(ScaleTTH);
      Target_TTW->Scale(ScaleTTW);
      Target_TTJets_0->Scale(ScaleTTJets);
      Target_TTJets_1->Scale(ScaleTTJets);
      Target_TTJets_2->Scale(ScaleTTJets);
      Target_TTJets_3->Scale(ScaleTTJets);
      Target_TTJets_4->Scale(ScaleTTJets);
  }   
 
   Target_WZ->SetFillColor(kGray+3);  
   Target_WZ->SetLineColor(kGray+3);
   Target_WW->SetFillColor(kGray+3);
   Target_WW->SetLineColor(kGray+3);
   Target_ZZ->SetFillColor(kGray+3);
   Target_ZZ->SetLineColor(kGray+3);
   Target_QCD->SetFillColor(kBlue-7);
   Target_DY->SetFillColor(kMagenta-2);
   Target_Zbb->SetFillColor(kViolet+1);
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
   Target_Wbb->SetFillColor(kOrange+1);
   Target_TTZ->SetFillColor(kMagenta-10);
   Target_TTZ->SetLineColor(kMagenta-10);
   Target_TTH->SetLineColor(kMagenta-9);
   Target_TTH->SetFillColor(kMagenta-9);
   Target_TTW->SetFillColor(kMagenta-7);
   Target_TTW->SetLineColor(kMagenta-7);
   Target_data->SetMarkerStyle(20);
   Target_data->SetLineColor(kBlack);
   Target_TTJets_0->SetFillColor(kRed-4);
   Target_TTJets_1->SetFillColor(kCyan-10);
   Target_TTJets_2->SetFillColor(kAzure+1);
   Target_TTJets_3->SetFillColor(kAzure+2);
   Target_TTJets_4->SetFillColor(kAzure+3);
 
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
  
   TCanvas *Cut = new TCanvas("MyCanvas","MyCanvas",1000,800);
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
   gPad->SetLogy(log);
   gPad->SetLogx(0);
 
 
 //**************************************************************Axis Range settings
   if(isPartOf(TargetName,Jpt)) {cout<<"Ha funzionato"<<endl;}
   if(isPartOf(TargetName,"relIso")) sum_Target->GetXaxis()->SetRangeUser(0,0.15);   
   if(isPartOf(TargetName,"Vertex")) sum_Target->GetXaxis()->SetRangeUser(0,40);   
   gStyle->SetOptLogy(log); 
 
   sum_Target->GetYaxis()->SetLabelSize(0.05);
   sum_Target->GetYaxis()->SetRangeUser(Range1,Range2);
   sum_Target->SetTitle("");
   sum_Target->Draw();
   hs_Target->Draw("same");   
   
   Target_data->GetXaxis()->SetLabelSize(0.1);
   Target_data->SetMarkerStyle(20);
   Target_data->SetTitle("");
   Target_data->Draw("PEsame");

 //*comment here if you do not want it
   //draw systematic band
   gROOT->LoadMacro("spitSYS.C");

  TH1 * PUDown  	=spitSYS(TargetName,generator,1); 
  TH1 * PUUp		=spitSYS(TargetName,generator,2);
  TH1 * muDown  	=spitSYS(TargetName,generator,3);
  TH1 * muUp		=spitSYS(TargetName,generator,4);
  TH1 * BtagSFDown	=spitSYS(TargetName,generator,5);
  TH1 * BtagSFUp	=spitSYS(TargetName,generator,6);
  TH1 * topPtWeightDown =spitSYS(TargetName,generator,7);
  //TH1 * topPtWeightUp	=spitSYS(TargetName,generator,0,1);

 if(isPartOf(TargetName,"9b")) TH1 * jerDown	     =spitSYS(TargetName,generator,10);
 if(isPartOf(TargetName,"9b")) TH1 * jerUp	     =spitSYS(TargetName,generator,11);
 if(isPartOf(TargetName,"9b")) TH1 * jesDown	     =spitSYS(TargetName,generator,12);
 if(isPartOf(TargetName,"9b")) TH1 * jesUp	     =spitSYS(TargetName,generator,13);

 if(isPartOf(TargetName,"9b")) TH1 * scaleDown       =spitSYS(TargetName,generator,14);
 if(isPartOf(TargetName,"9b")) TH1 * scaleUp	     =spitSYS(TargetName,generator,15);
 if(isPartOf(TargetName,"9b")) TH1 * matchDown       =spitSYS(TargetName,generator,18);
 if(isPartOf(TargetName,"9b")) TH1 * matchUp	     =spitSYS(TargetName,generator,19);
 if(isPartOf(TargetName,"9b")) TH1 * massDown	     =spitSYS(TargetName,generator,16);
 if(isPartOf(TargetName,"9b")) TH1 * massUp	     =spitSYS(TargetName,generator,17);
 if(isPartOf(TargetName,"9b")) TH1 * nloDown  =spitSYS(TargetName,generator,30); //stackShapes(TargetName,generator,8,30);
 if(isPartOf(TargetName,"9b")) TH1 * powDown	     =spitSYS(TargetName,generator,31); //stackShapes(TargetName,generator,0,31);
  
  
  TH1 * lumiDown 	 =spitSYS(TargetName,generator,100); //stackShapes(TargetName,generator,8,30);
  TH1 * lumiUp    	 =spitSYS(TargetName,generator,101); //stackShapes(TargetName,generator,8,30);
  TH1 * xsecDown         =spitSYS(TargetName,generator,102); //stackShapes(TargetName,generator,0,31);
  TH1 * xsecUp           =spitSYS(TargetName,generator,103); //stackShapes(TargetName,generator,0,31);

 //Sum all the bands 
 TH1 *histo_up= (TH1*)PUUp->Clone();
 histo_up->Add(muUp);
 histo_up->Add(BtagSFUp);
 //histo_up->Add(topPtWeightUp);   //top pt one sided band
 if(isPartOf(TargetName,"9b")) histo_up->Add(jerUp);
 if(isPartOf(TargetName,"9b")) histo_up->Add(jesUp);
 if(isPartOf(TargetName,"9b")) histo_up->Add(scaleUp);
 if(isPartOf(TargetName,"9b")) histo_up->Add(matchUp);
 if(isPartOf(TargetName,"9b")) histo_up->Add(massUp);
 histo_up->Add(lumiUp);
 histo_up->Add(xsecUp);
 
 TH1 *histo_down= (TH1*)PUDown->Clone();
 histo_down->Add(muDown);
 histo_down->Add(BtagSFDown);
 histo_down->Add(topPtWeightDown);
 if(isPartOf(TargetName,"9b")) histo_down->Add(jerDown);
 if(isPartOf(TargetName,"9b")) histo_down->Add(jesDown);
 if(isPartOf(TargetName,"9b")) histo_down->Add(scaleDown);
 if(isPartOf(TargetName,"9b")) histo_down->Add(matchDown);
 if(isPartOf(TargetName,"9b")) histo_down->Add(massDown);
 if(isPartOf(TargetName,"9b")) histo_down->Add(nloDown);
 if(isPartOf(TargetName,"9b")) histo_down->Add(powDown);
 histo_down->Add(lumiDown);
 histo_down->Add(xsecDown);
 
 //int 200=sum_Target->GetN200X();
  // static const int 200=200;
 ///+++++fine disegna band  
 cout<<sum_Target->GetNbinsX()<<endl;
   double x[200];
   double y[200];
   double x[200];
   double errxp[200];
   double errxm[200];
   double erryp[200];
   double errym[200];
  cout<<"ci sono"<<endl;
   for(int bb=0;bb<sum_Target->GetNbinsX();bb++){
 
 
   //dalla Stack Monte carlo
   x[bb]=sum_Target->GetBinCenter(bb+1);
   errxp[bb]=(sum_Target->GetBinWidth(bb+1))/2;
   errxm[bb]=errxp[bb];
   y[bb]=sum_Target->GetBinContent(bb+1);
 
  //dal file per la sistematica
   erryp[bb]=sqrt(histo_up->GetBinContent(bb+1));
   errym[bb]=sqrt(histo_down->GetBinContent(bb+1));
 
 
 //   cout<<"histoup "<<histo_up->GetBinContent(bb+1)<<" "<< erryp[bb]<<endl;
 //   cout<<"histodown "<<histo_down->GetBinContent(bb+1)<<" "<< errym[bb]<<endl;
 //   cout<<"200 "<<x[bb]<<" "<<errxp[bb]<<" "<<errxm[bb]<<" "<<y[bb]<<" "<<erryp[bb]<<" "<<errym[bb]<<endl;
 
  }
   for(int bb=0;bb<sum_Target->GetNbinsX();bb++){
    cout<<"error "<<Target_data->GetBinContent(bb+1)<<" "<< Target_data->GetBinError(bb+1)<<endl;
 }
   int bins=sum_Target->GetNbinsX();
   Band = new TGraphAsymmErrors(bins,x,y,errxm,errxp,errym,erryp);
   Band->SetFillStyle(3001); 
   Band->SetFillColor(kGray+3); 
   Band->Draw("p2same"); 
 
   TH1 *stack_up=(TH1*)sum_Target->Clone();
   TH1 *stack_down=(TH1*)sum_Target->Clone();
   for(int bb=0;bb<sum_Target->GetNbinsX();bb++){
   stack_up->SetBinContent(bb+1,sum_Target->GetBinContent(bb+1)+erryp[bb]);
   stack_down->SetBinContent(bb+1,sum_Target->GetBinContent(bb+1)-errym[bb]);
 }
// ///+++++fine disegna band  
   leg->Draw();
   leg2->Draw();
   Cut->cd(2);
   TH1F * Discrepancy=CustomSubtractHisto("", sum_Target, Target_data);
      Discrepancy->SetStats(0);
      Discrepancy->SetLineColor(1);
      //Discrepancy->SetLineStyle(2);
      Discrepancy->GetXaxis()->SetTickLength(0.1);
      Discrepancy->GetXaxis()->SetLabelSize(0.1);
      Discrepancy->SetMarkerStyle(20);
	gPad->SetLogy(0);
	gPad->SetLogx(0);
        gPad->SetTicks();
      Discrepancy->GetYaxis()->SetRangeUser(0.2, 1.7);
      if(isPartOf(TargetName,"relIso"))       Discrepancy->GetXaxis()->SetRangeUser(0, 0.15);
      if(isPartOf(TargetName,"Vertex"))       Discrepancy->GetXaxis()->SetRangeUser(0, 40);
      Discrepancy->GetYaxis()->SetNdivisions(505);
      Discrepancy->GetXaxis()->SetLabelSize(0.15);
      Discrepancy->GetYaxis()->SetLabelSize(0.15);
      Discrepancy->GetYaxis()->SetTitle(" Data/Bkg");
      Discrepancy->GetXaxis()->SetTitle(title);
      Discrepancy->GetYaxis()->SetTitleSize(0.15);
      Discrepancy->GetYaxis()->SetTitleOffset(0.3);
      Discrepancy->GetXaxis()->SetTitleOffset(1.2);
      Discrepancy->GetXaxis()->SetTitleSize(0.15);

     
      Discrepancy->Draw("EP");
 //band  
   TH1F * Discrepancy_up=CustomSubtractHisto("", sum_Target,stack_up );
   TH1F * Discrepancy_down=CustomSubtractHisto("", sum_Target,stack_down );

  double dy[200];
  for(int d=0;d<200;d++){ dy[d]=1;}
  double derryp[200];
  double derrym[200];
   
   for(int bb=0;bb<sum_Target->GetNbinsX();bb++){
 
  //dal file per la sistematica
   derryp[bb]=Discrepancy_up->GetBinContent(bb+1) -1 ;
   derrym[bb]=1- Discrepancy_down->GetBinContent(bb+1);
 
 } 
   Discrepancy_Band = new TGraphAsymmErrors(bins,x,dy,errxm,errxp,derrym,derryp);
   Discrepancy_Band->SetFillStyle(3001); 
   Discrepancy_Band->SetFillColor(kGray+3); 
   Discrepancy_Band->Draw("p2"); 


double la=0;
double lb=0;
la=sum_Target->GetBinLowEdge(1);
lb=sum_Target->GetBinLowEdge(sum_Target->GetNbinsX() );
        TLine *l1 = new TLine(la, 1, lb,  1);
   if(isPartOf(TargetName,"relIso")) { TLine *l1 = new TLine(0, 1, 0.15,  1);} 
   if(isPartOf(TargetName,"Vertex")) { TLine *l1 = new TLine(0, 1, 40,  1);} 
   if(isPartOf(TargetName,"nJet")) { TLine *l1 = new TLine(3, 1, 11,  1);} 
   else{ TLine *l1 = new TLine(la, 1, lb,  1);}
    TLine *l1 = new TLine(0, 1, 40,  1);
        l1->SetLineColor(kRed);
	l1->SetLineWidth(2);
        l1->Draw("");
        Discrepancy->Draw("same"); 
        //l1->Draw("");
	Cut->cd(0);
	b->SetGridy();
	b->Draw();
 
 
  //*************************************************other  
   float MC=sum_Target->Integral();
   float DATA=Target_data->Integral();
   float ttbb=Target_TTJets_0->Integral();
   float ttbj=Target_TTJets_1->Integral();
   float ttcc=Target_TTJets_2->Integral();
   float ttjj=Target_TTJets_3->Integral();
   float ttother=Target_TTJets_4->Integral();
   float tt=ttbb+ttbj+ttcc+ttjj+ttother;
   
   cout<<" Tot MC" <<MC<<" Data "<<DATA<<endl;
   cout<<" ttbb" <<ttbb<<" perc "<<ttbb/MC<<endl;
   cout<<" ttbj" <<ttbj<<" perc "<<ttbj/MC<<endl;
   cout<<" ttcc" <<ttcc<<" perc "<<ttcc/MC<<endl;
   cout<<" ttjj" <<ttjj<<" perc "<<ttjj/MC<<endl;
   cout<<" ttother" <<ttother<<" perc "<<ttother/MC<<endl;
 
    cout<<" Tot tt" <<tt<<" Data "<<DATA<<endl;
   cout<<" ttbb" <<ttbb<<" perc "<<ttbb/tt<<endl;
   cout<<" ttbj" <<ttbj<<" perc "<<ttbj/tt<<endl;
   cout<<" ttcc" <<ttcc<<" perc "<<ttcc/tt<<endl;
   cout<<" ttjj" <<ttjj<<" perc "<<ttjj/tt<<endl;
   cout<<" ttother" <<ttother<<" perc "<<ttother/tt<<endl;

  Cut->SaveAs("MyCanvas.png") ;
//gApplication->Terminate(); 

}//end drawHplus


