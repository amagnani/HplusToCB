//***********************************************************
//******drawing the histograms from the Hplus.C macro******
//***********************************************************
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


	     
 void drawKinFit(TString TargetName, TString generator){
 
 int masses[9]={90,100,110,120,130,140,150,155,160};
   gROOT->LoadMacro("stackShapes.C");
   gROOT->LoadMacro("tdrStyle.C");
   gStyle->SetOptStat(0);

 //prendo gli istogrammi di segnale //li scalo per il 10\%
      TH1 *ch[9];
   double const signalScale=45.522 / 252.9 ;
     for (int h=0;h<9;h++){
      ch[h] = stackShapes(TargetName,generator,0,masses[h]);
      ch[h]->Scale(signalScale);
      ch[h]->SetLineWidth(3);
      ch[h]->SetLineColor(kMagenta);
      ch[h]->SetMaximum(190);
      ch[h]->SetLabelSize(0.05);
      ch[h]->GetXaxis()->SetTitleSize(0.05);
 //     ch[h]->GetYaxis()->SetTitleSize(0.);
       ch[h]->GetYaxis()->SetLabelSize(0.05);
     ch[h]->GetXaxis()->SetTitle("di-jet inv. mass (GeV)");
      //ch[h]->SetTitleSize(0.2);
      ch[h]->SetTitle(" ");
      }
      
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
  else if (generator=="amc@nlo") { TFile *fTTJets = new TFile("../output/HplusHistos_TTnlo.root","READ");}
  else if (generator=="powheg") { TFile *fTTJets = new TFile("../output/HplusHistos_TTpow.root","READ");}
 
  
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
   double xsecTTJets_up       = 268.2;
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
 

     THStack *hs_Target;      
     hs_Target= new THStack("hs_Target","");
     
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

    TLegend *leg[9];
    char string[20];
    
    for(int m=0;m<9;m++){
  //  leg[m]= new TLegend(0.12,0.6,0.4,0.89);
  //
 leg[m]= new TLegend(0.6,0.8,1.,0.9);
    leg[m]->SetBorderSize(0);
    leg[m]->SetLineColor(0);
    leg[m]->SetLineStyle(0);
    leg[m]->SetLineWidth(0);
    leg[m]->SetFillColor(0);
    leg[m]->SetFillStyle(1001);
    sprintf(string,"H+ %i GeV",masses[m]);
     leg[m]->AddEntry(ch[m],string,"l");

     }
  
  KinFit2 = new TCanvas("KinFit2","Kinematic fit 9",1200,900);
  KinFit2->Divide(3,3);
  
  KinFit2->cd(1);      
  ch[0]->Draw();
  hs_Target->Draw("same");
  ch[0]->Draw("same");
  leg[0]->Draw();

  KinFit2->cd(2);      
  ch[1]->Draw();
  hs_Target->Draw("same");
  ch[1]->Draw("same");
  leg[1]->Draw();


  KinFit2->cd(3);      
  ch[2]->Draw();
  hs_Target->Draw("same");
  ch[2]->Draw("same");
  leg[2]->Draw();
 
  KinFit2->cd(4);      
  ch[3]->Draw();
  hs_Target->Draw("same");
  ch[3]->Draw("same");
  leg[3]->Draw();
  
  KinFit2->cd(5);      
  ch[4]->Draw();
  hs_Target->Draw("same");
  ch[4]->Draw("same");
  leg[4]->Draw();
  
  KinFit2->cd(6);      
  ch[5]->Draw();
  hs_Target->Draw("same");
  ch[5]->Draw("same");
  leg[5]->Draw();
  
  KinFit2->cd(7);      
  ch[6]->Draw();
  hs_Target->Draw("same");
  ch[6]->Draw("same");
  leg[6]->Draw();
 
  KinFit2->cd(8);      
 ch[7]->Draw();
  hs_Target->Draw("same");
  ch[7]->Draw("same");
   leg[7]->Draw();

  KinFit2->cd(9);      

   ch[8]->Draw();
   hs_Target->Draw("same");
   ch[8]->Draw("same");
  leg[8]->Draw();
 
  KinFit2->SaveAs("template.png");
 


}//end drawHplus
