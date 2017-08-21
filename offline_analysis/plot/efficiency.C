//***********************************************************
//******drawing the histograms from the Hplus.C macro******
//***********************************************************
#include <TH1F>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

 void efficiency(TString sample){

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

   

 //Load Files
  TString title="../output/HplusHistos_"+sample+".root";
  cout<<title<<endl;
  TFile *f = new TFile(title,"READ");

  //scale histograms
  double lumi_factor= 19.7*1e+15*1e-12;
  //cross section (pb)
 //  double xsecZZ 	= 5.196;
//   double xsecWZ 	= 12.63;
//   double xsecWW 	= 33.61;
//   double xsecQCD 	= 134680.0;
   double xsecDY 	= 3504;
//   double xsect 		= 56.4;
//   double xsectbar 	= 30.7;
//   double xsecs 		= 3.79;
//   double xsecsbar 	= 1.76;
//   double xsectW 	= 11.1;
//   double xsectWbar 	= 11.1;
//   double xsecWJets 	= 36257;
  double xsecTTJets 	= 252.9;
//   double xsecWbb 	= 377.4;
//   double xsecZbb 	= 76.75;
//   double xsecTTZ 	= 0.2057;
//   double xsecTTH 	= 0.133;
//   double xsecTTW 	= 0.232;

//   double xsecTTJets_up 	= 268.2;
//   double xsecTTJets_down= 236.6;
 // 
//   const double ScaleZZ=lumi_factor*xsecZZ         / 9799908  ;//f
//   const double ScaleWZ=lumi_factor*xsecWZ         / 9907189  ;//f
//   const double ScaleWW=lumi_factor*xsecWW         / 10000431 ;//f
//   const double ScaleQCD=lumi_factor*xsecQCD       / 57789606 ;//f       
//   const double ScaleDY=lumi_factor*xsecDY         / 29632361 ;//f
//   const double Scalet=lumi_factor*xsect           / 3579368  ;//f
//   const double Scaletbar=lumi_factor*xsectbar     / 1935072  ;//f
//   const double Scales=lumi_factor*xsecs           / 259961   ;//f
//   const double Scalesbar=lumi_factor*xsecsbar     / 139974   ;//f
//   const double ScaletW=lumi_factor*xsectW   	  / 484222   ;//f
//   const double ScaletWbar=lumi_factor*xsectWbar	  / 493460   ;//f
//   const double ScaleWJets=lumi_factor*xsecWJets	  / (57684680+18344535) ;//f
//   const double ScaleTTZ=lumi_factor*xsecTTZ	  / 210160   ;//f
//   const double ScaleTTH=lumi_factor*xsecTTH	  / 995697   ;//f
//   const double ScaleTTW=lumi_factor*xsecTTW	  / 196046   ;//f
//   const double ScaleWbb=lumi_factor*xsecWbb	  / 20598354 ;//f
//   const double ScaleZbb=lumi_factor*xsecZbb       / 14109084 ;//f
// 
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

      //const double 	ScaleTTJets=lumi_factor*xsecTTJets / (21578775) ; 
      const double 	ScaleTTJets=lumi_factor*xsecTTJets / 62131965;  //reprocess, full stat
      //const double 	ScaleTTJets=lumi_factor*xsecTTJets / 61762848;   //vecchio


//LOAD HISTOGRAMS
  double events_TTJets_0[5];
  double events_TTJets_1[5];
  double events_TTJets_2[5];
  double events_TTJets_3[5];
  double events_TTJets_4[5];
  
for(int nsel=4; nsel<5;nsel++){  
cout<<TargetName[nsel]<<endl;

  TH1 *histo_TTJets_0 = (TH1*)f->Get(TargetName[nsel]+"_0");
  TH1 *histo_TTJets_1 = (TH1*)f->Get(TargetName[nsel]+"_1");
  TH1 *histo_TTJets_2 = (TH1*)f->Get(TargetName[nsel]+"_2");
  TH1 *histo_TTJets_3 = (TH1*)f->Get(TargetName[nsel]+"_3");
  TH1 *histo_TTJets_4 = (TH1*)f->Get(TargetName[nsel]+"_4");

  cout<<"getting integrals "<<nsel<<endl;

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


  TH1 *Target_TTJets_0 = (TH1*) Target_WZ->Clone();
  TH1 *Target_TTJets_1 = (TH1*) Target_WZ->Clone();
  TH1 *Target_TTJets_2 = (TH1*) Target_WZ->Clone();
  TH1 *Target_TTJets_3 = (TH1*) Target_WZ->Clone();
  TH1 *Target_TTJets_4 = (TH1*) Target_WZ->Clone();

for(int bin=0;bin<5;bin++){

  
   Target_TTJets_0->Fill(bin,events_TTJets_0[bin]);
   Target_TTJets_1->Fill(bin,events_TTJets_1[bin]);
   Target_TTJets_2->Fill(bin,events_TTJets_2[bin]);
   Target_TTJets_3->Fill(bin,events_TTJets_3[bin]);
   Target_TTJets_4->Fill(bin,events_TTJets_4[bin]);
    }


//scalo alla fine i plot di cutflow 
  Target_TTJets_0->Scale(ScaleTTJets);
  Target_TTJets_1->Scale(ScaleTTJets);
  Target_TTJets_2->Scale(ScaleTTJets);
  Target_TTJets_3->Scale(ScaleTTJets);
  Target_TTJets_4->Scale(ScaleTTJets);


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



 //   cout<<" ttbar up  "; for(int bin=0; bin<5; bin++) cout<<"  "<<events_TTJets[bin]*ScaleTTJets_up;
//    cout<<" ttbar down  "; for(int bin=0; bin<5; bin++) cout<<"  "<<events_TTJets[bin]*ScaleTTJets_down;

 


}//end drawHplus


