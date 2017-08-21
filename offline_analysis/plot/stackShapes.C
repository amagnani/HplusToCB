//***********************************************************
//******drawing the histograms from the Hplus.C macro******
//***********************************************************
#include <TH1F>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

TH1 *  stackShapes(TString TargetName, TString generator, int SYSnumber, int STACKnumber){

int masses[9]={90,100,110,120,130,140,150,155,160};
 
 cout<<"SYSnumber "<< SYSnumber<<" STACKnumber "<<STACKnumber<<endl;

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
  double xsecPseudo 	= 252.9; 

 
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

  const double conversion= 61661666 ;	//f
  const double jerup     = 26261867	;//f
  const double jerdown   = 61661666 ;	//f
  const double jesup     = 55109953;	//f
  const double jesdown   = 27200639 ;	//f


  const double massup   = 24356695 ;	//f
  const double massdown = 23619355 ;	//f
  const double scaleup  =  41842754;	//f
  const double scaledown=  38710166;	//f


 
  //sistemare qui aggiungendo peso per PU reweight ( ed il numero di eventi del TTbar Bonus) 0.9905= peso medio per il top pt reweight allo step Start
  //const double ScaleTTJets_up=lumi_factor*xsecTTJets_up / (62056531 * 0.9905) ; 
  //const double ScaleTTJets_down=lumi_factor*xsecTTJets_down / (62056531 * 0.9905) ; 

//tt catergories  	// =0   ---> ttbb  
	      		// =1   ---> ttbj
	      		// =2   ---> ttcc
	      		// =3   ---> ttqq
	      		// =4   ---> ttother
			
//get normalization factor for top reweighting procedure
double topreweight=1;

  if (generator=="pythia") {
  	double topreweight=0.9993;	
	if (SYSnumber==7) topreweight=0.9905491; 
	if (SYSnumber==8) topreweight=1;   //questa cosa secondo me è da sistemare
  }
  if (generator=="amc@nlo") double topreweight=1;	
cout<<"ATTENZIONE topptweight fissato a mano, valido per pythia"<<endl;		

if (generator=="pythia") {
  const double ScaleTTJets   = lumi_factor*xsecTTJets /     (62131965 * topreweight) ;
  const double Scalematchup  = lumi_factor*xsecTTJets /     ( 37083003* topreweight);	//f
  const double Scalematchdown= lumi_factor*xsecTTJets /     ( 20437520* topreweight);	//f
}
else if (generator=="amc@nlo"){
      const double 	ScaleTTJets=lumi_factor*xsecTTJets / (32811330 * topreweight) ;  
}
else if (generator=="powheg") {
      const double 	ScaleTTJets=lumi_factor*xsecTTJets / (21578775 * topreweight) ; 
}

  const double Scalenlo  = lumi_factor*xsecTTJets /  32811330;	//f  
  const double Scalepow  = lumi_factor*xsecTTJets /  (21578775 * 0.9995 );	//f  

 TString SYSext="_sys";
 SYSext+=SYSnumber;


  //Load Files
 
 if(STACKnumber==2 || STACKnumber==20  || STACKnumber==21 || STACKnumber==22  || STACKnumber==23){
 
 cout<<" background"<< TargetName+SYSext<< endl;
 if(STACKnumber==2){
  TFile *fWZ  = new TFile("../output_backup/HplusHistos_9b_WZ.root","READ");
  TFile *fZZ  = new TFile("../output_backup/HplusHistos_9b_ZZ.root","READ");
  TFile *fWW  = new TFile("../output_backup/HplusHistos_9b_WW.root","READ");
  TFile *fQCD = new TFile("../output_backup/HplusHistos_9b_QCD.root","READ");
  TFile *fDY  = new TFile("../output_backup/HplusHistos_9b_DY.root","READ");
  TFile *fZbb = new TFile("../output_backup/HplusHistos_9b_Zbb.root","READ");
  TFile *ft   = new TFile("../output_backup/HplusHistos_9b_t.root","READ");
  TFile *ftbar= new TFile("../output_backup/HplusHistos_9b_tbar.root","READ");
  TFile *fs   = new TFile("../output_backup/HplusHistos_9b_s.root","READ");
  TFile *fsbar= new TFile("../output_backup/HplusHistos_9b_sbar.root","READ");
  TFile *ftW  = new TFile("../output_backup/HplusHistos_9b_tW.root","READ");
  TFile *ftWbar= new TFile("../output_backup/HplusHistos_9b_tWbar.root","READ");
  TFile *fWJets= new TFile("../output_backup/HplusHistos_9b_WJets.root","READ");
  TFile *fWbb = new TFile("../output_backup/HplusHistos_9b_Wbb.root","READ");
  TFile *fTTZ = new TFile("../output_backup/HplusHistos_9b_TTZ.root","READ");
  TFile *fTTH = new TFile("../output_backup/HplusHistos_9b_TTH.root","READ");
  TFile *fTTW = new TFile("../output_backup/HplusHistos_9b_TTW.root","READ");
  }
 if(STACKnumber==20){
  TFile *fWZ  = new TFile("../../v30JERdown/output/HplusHistos_9b_WZ.root","READ");
  TFile *fZZ  = new TFile("../../v30JERdown/output/HplusHistos_9b_ZZ.root","READ");
  TFile *fWW  = new TFile("../../v30JERdown/output/HplusHistos_9b_WW.root","READ");
  TFile *fQCD = new TFile("../../v30JERdown/output/HplusHistos_9b_QCD.root","READ");
  TFile *fDY  = new TFile("../../v30JERdown/output/HplusHistos_9b_DY.root","READ");
  TFile *fZbb = new TFile("../../v30JERdown/output/HplusHistos_9b_Zbb.root","READ");
  TFile *ft   = new TFile("../../v30JERdown/output/HplusHistos_9b_t.root","READ");
  TFile *ftbar= new TFile("../../v30JERdown/output/HplusHistos_9b_tbar.root","READ");
  TFile *fs   = new TFile("../../v30JERdown/output/HplusHistos_9b_s.root","READ");
  TFile *fsbar= new TFile("../../v30JERdown/output/HplusHistos_9b_sbar.root","READ");
  TFile *ftW  = new TFile("../../v30JERdown/output/HplusHistos_9b_tW.root","READ");
  TFile *ftWbar= new TFile("../../v30JERdown/output/HplusHistos_9b_tWbar.root","READ");
  TFile *fWJets= new TFile("../../v30JERdown/output/HplusHistos_9b_WJets.root","READ");
  TFile *fWbb = new TFile("../../v30JERdown/output/HplusHistos_9b_Wbb.root","READ");
  TFile *fTTZ = new TFile("../../v30JERdown/output/HplusHistos_9b_TTZ.root","READ");
  TFile *fTTH = new TFile("../../v30JERdown/output/HplusHistos_9b_TTH.root","READ");
  TFile *fTTW = new TFile("../../v30JERdown/output/HplusHistos_9b_TTW.root","READ");
  }
 if(STACKnumber==21){
  TFile *fWZ  = new TFile("../../v30JERup/output/HplusHistos_9b_WZ.root","READ");
  TFile *fZZ  = new TFile("../../v30JERup/output/HplusHistos_9b_ZZ.root","READ");
  TFile *fWW  = new TFile("../../v30JERup/output/HplusHistos_9b_WW.root","READ");
  TFile *fQCD = new TFile("../../v30JERup/output/HplusHistos_9b_QCD.root","READ");
  TFile *fDY  = new TFile("../../v30JERup/output/HplusHistos_9b_DY.root","READ");
  TFile *fZbb = new TFile("../../v30JERup/output/HplusHistos_9b_Zbb.root","READ");
  TFile *ft   = new TFile("../../v30JERup/output/HplusHistos_9b_t.root","READ");
  TFile *ftbar= new TFile("../../v30JERup/output/HplusHistos_9b_tbar.root","READ");
  TFile *fs   = new TFile("../../v30JERup/output/HplusHistos_9b_s.root","READ");
  TFile *fsbar= new TFile("../../v30JERup/output/HplusHistos_9b_sbar.root","READ");
  TFile *ftW  = new TFile("../../v30JERup/output/HplusHistos_9b_tW.root","READ");
  TFile *ftWbar= new TFile("../../v30JERup/output/HplusHistos_9b_tWbar.root","READ");
  TFile *fWJets= new TFile("../../v30JERup/output/HplusHistos_9b_WJets.root","READ");
  TFile *fWbb = new TFile("../../v30JERup/output/HplusHistos_9b_Wbb.root","READ");
  TFile *fTTZ = new TFile("../../v30JERup/output/HplusHistos_9b_TTZ.root","READ");
  TFile *fTTH = new TFile("../../v30JERup/output/HplusHistos_9b_TTH.root","READ");
  TFile *fTTW = new TFile("../../v30JERup/output/HplusHistos_9b_TTW.root","READ");
  }
 if(STACKnumber==22){
  TFile *fWZ  = new TFile("../../v30JESdown/output/HplusHistos_9b_WZ.root","READ");
  TFile *fZZ  = new TFile("../../v30JESdown/output/HplusHistos_9b_ZZ.root","READ");
  TFile *fWW  = new TFile("../../v30JESdown/output/HplusHistos_9b_WW.root","READ");
  TFile *fQCD = new TFile("../../v30JESdown/output/HplusHistos_9b_QCD.root","READ");
  TFile *fDY  = new TFile("../../v30JESdown/output/HplusHistos_9b_DY.root","READ");
  TFile *fZbb = new TFile("../../v30JESdown/output/HplusHistos_9b_Zbb.root","READ");
  TFile *ft   = new TFile("../../v30JESdown/output/HplusHistos_9b_t.root","READ");
  TFile *ftbar= new TFile("../../v30JESdown/output/HplusHistos_9b_tbar.root","READ");
  TFile *fs   = new TFile("../../v30JESdown/output/HplusHistos_9b_s.root","READ");
  TFile *fsbar= new TFile("../../v30JESdown/output/HplusHistos_9b_sbar.root","READ");
  TFile *ftW  = new TFile("../../v30JESdown/output/HplusHistos_9b_tW.root","READ");
  TFile *ftWbar= new TFile("../../v30JESdown/output/HplusHistos_9b_tWbar.root","READ");
  TFile *fWJets= new TFile("../../v30JESdown/output/HplusHistos_9b_WJets.root","READ");
  TFile *fWbb = new TFile("../../v30JESdown/output/HplusHistos_9b_Wbb.root","READ");
  TFile *fTTZ = new TFile("../../v30JESdown/output/HplusHistos_9b_TTZ.root","READ");
  TFile *fTTH = new TFile("../../v30JESdown/output/HplusHistos_9b_TTH.root","READ");
  TFile *fTTW = new TFile("../../v30JESdown/output/HplusHistos_9b_TTW.root","READ");
  }
 if(STACKnumber==23){
  TFile *fWZ  = new TFile("../../v30JESup/output/HplusHistos_9b_WZ.root","READ");
  TFile *fZZ  = new TFile("../../v30JESup/output/HplusHistos_9b_ZZ.root","READ");
  TFile *fWW  = new TFile("../../v30JESup/output/HplusHistos_9b_WW.root","READ");
  TFile *fQCD = new TFile("../../v30JESup/output/HplusHistos_9b_QCD.root","READ");
  TFile *fDY  = new TFile("../../v30JESup/output/HplusHistos_9b_DY.root","READ");
  TFile *fZbb = new TFile("../../v30JESup/output/HplusHistos_9b_Zbb.root","READ");
  TFile *ft   = new TFile("../../v30JESup/output/HplusHistos_9b_t.root","READ");
  TFile *ftbar= new TFile("../../v30JESup/output/HplusHistos_9b_tbar.root","READ");
  TFile *fs   = new TFile("../../v30JESup/output/HplusHistos_9b_s.root","READ");
  TFile *fsbar= new TFile("../../v30JESup/output/HplusHistos_9b_sbar.root","READ");
  TFile *ftW  = new TFile("../../v30JESup/output/HplusHistos_9b_tW.root","READ");
  TFile *ftWbar= new TFile("../../v30JESup/output/HplusHistos_9b_tWbar.root","READ");
  TFile *fWJets= new TFile("../../v30JESup/output/HplusHistos_9b_WJets.root","READ");
  TFile *fWbb = new TFile("../../v30JESup/output/HplusHistos_9b_Wbb.root","READ");
  TFile *fTTZ = new TFile("../../v30JESup/output/HplusHistos_9b_TTZ.root","READ");
  TFile *fTTH = new TFile("../../v30JESup/output/HplusHistos_9b_TTH.root","READ");
  TFile *fTTW = new TFile("../../v30JESup/output/HplusHistos_9b_TTW.root","READ");
  }
  
  TH1 *Target_WZ   = (TH1*)fWZ->Get(TargetName+SYSext);
  TH1 *Target_ZZ   = (TH1*)fZZ->Get(TargetName+SYSext);
  TH1 *Target_WW   = (TH1*)fWW->Get(TargetName+SYSext);
  TH1 *Target_QCD  = (TH1*)fQCD->Get(TargetName+SYSext);
  TH1 *Target_DY   = (TH1*)fDY->Get(TargetName+SYSext);
  TH1 *Target_t	   = (TH1*)ft->Get(TargetName+SYSext);
  TH1 *Target_tbar = (TH1*)ftbar->Get(TargetName+SYSext);
  TH1 *Target_s	   = (TH1*)fs->Get(TargetName+SYSext);
  TH1 *Target_sbar = (TH1*)fsbar->Get(TargetName+SYSext);
  TH1 *Target_tW   = (TH1*)ftW->Get(TargetName+SYSext);
  TH1 *Target_tWbar= (TH1*)ftWbar->Get(TargetName+SYSext);
  TH1 *Target_WJets= (TH1*)fWJets->Get(TargetName+SYSext);
  TH1 *Target_Wbb  = (TH1*)fWbb->Get(TargetName+SYSext);
  TH1 *Target_Zbb  = (TH1*)fZbb->Get(TargetName+SYSext);
  TH1 *Target_TTH  = (TH1*)fTTH->Get(TargetName+SYSext);
  TH1 *Target_TTZ  = (TH1*)fTTZ->Get(TargetName+SYSext);
  TH1 *Target_TTW  = (TH1*)fTTW->Get(TargetName+SYSext);
  
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
  Target_Wbb->Scale(ScaleWbb);
  Target_Zbb->Scale(ScaleZbb);
  Target_TTZ->Scale(ScaleTTZ);
  Target_TTH->Scale(ScaleTTH);
  Target_TTW->Scale(ScaleTTW);
  
    THStack *Bkg;	
    Bkg= new THStack("Bkg","");
    
    Bkg->Add(Target_WZ);  
    Bkg->Add(Target_WW);  
    Bkg->Add(Target_ZZ);  
    Bkg->Add(Target_QCD);  
    Bkg->Add(Target_DY);  
    Bkg->Add(Target_Zbb);  
    Bkg->Add(Target_TTW);  
    Bkg->Add(Target_TTH);  
    Bkg->Add(Target_TTZ);  
    Bkg->Add(Target_WJets);  
    Bkg->Add(Target_Wbb);  
    Bkg->Add(Target_t);  
    Bkg->Add(Target_tbar);  
    Bkg->Add(Target_tW);  
    Bkg->Add(Target_tWbar);  
    Bkg->Add(Target_s);  
    Bkg->Add(Target_sbar);  
    
    TH1 *resultTarget = Bkg->GetStack()->Last(); 
    
    
     }

 else if(STACKnumber==1 || (STACKnumber>9 && STACKnumber<20) || (STACKnumber>29 && STACKnumber<40) ){
 cout<<" top"<<endl;
 
 
  if (generator=="pythia") { 
  
  if (STACKnumber==1)  TFile *fTTJets = new TFile("../output_backup/HplusHistos_TTJetsSplit.root","READ");
  if (STACKnumber==10) TFile *fTTJets = new TFile("../../v30JERdown/output/HplusHistos_TTJetsSplit.root","READ");
  if (STACKnumber==11) TFile *fTTJets = new TFile("../../v30JERup/output/HplusHistos_TTJetsSplit.root","READ");
  if (STACKnumber==12) TFile *fTTJets = new TFile("../../v30JESdown/output/HplusHistos_TTJetsSplit.root","READ");
  if (STACKnumber==13) TFile *fTTJets = new TFile("../../v30JESdown/output/HplusHistos_TTJetsSplit.root","READ");
  if (STACKnumber==14) TFile *fTTJets = new TFile("../output_backup/HplusHistos_TTscaledown.root","READ");
  if (STACKnumber==15) TFile *fTTJets = new TFile("../output_backup/HplusHistos_TTscaleup.root","READ");
  if (STACKnumber==16) TFile *fTTJets = new TFile("../output_backup/HplusHistos_TTmassdown.root","READ");
  if (STACKnumber==17) TFile *fTTJets = new TFile("../output_backup/HplusHistos_TTmassup.root","READ");
  if (STACKnumber==18) TFile *fTTJets = new TFile("../output_backup/HplusHistos_TTmatchdown.root","READ");
  if (STACKnumber==19) TFile *fTTJets = new TFile("../output_backup/HplusHistos_TTmatchup.root","READ");
  if (STACKnumber==30) TFile *fTTJets = new TFile("../output_backup/HplusHistos_TTnlo.root","READ");
  if (STACKnumber==31) TFile *fTTJets = new TFile("../output_backup/HplusHistos_TTpow.root","READ");
  
  }
  else if (generator=="amc@nlo") { TFile *fTTJets = new TFile("../output_backup/HplusHistos_TTnlo.root","READ");}
  else if (generator=="powheg") { TFile *fTTJets = new TFile("../output_backup/HplusHistos_ptw_TTpow.root","READ");}

  TH1 *Target_TTJets_0 = (TH1*)fTTJets->Get(TargetName+SYSext+"_0");
  TH1 *Target_TTJets_1 = (TH1*)fTTJets->Get(TargetName+SYSext+"_1");
  TH1 *Target_TTJets_2 = (TH1*)fTTJets->Get(TargetName+SYSext+"_2");
  TH1 *Target_TTJets_3 = (TH1*)fTTJets->Get(TargetName+SYSext+"_3");
  TH1 *Target_TTJets_4 = (TH1*)fTTJets->Get(TargetName+SYSext+"_4");
  
   if (STACKnumber==1) {
  Target_TTJets_0->Scale(ScaleTTJets);
  Target_TTJets_1->Scale(ScaleTTJets);
  Target_TTJets_2->Scale(ScaleTTJets);
  Target_TTJets_3->Scale(ScaleTTJets);
  Target_TTJets_4->Scale(ScaleTTJets);
   }
  if (STACKnumber==10){
    const double JERUP = ScaleTTJets*conversion/jerdown;
  Target_TTJets_0->Scale(JERUP);
  Target_TTJets_1->Scale(JERUP);
  Target_TTJets_2->Scale(JERUP);
  Target_TTJets_3->Scale(JERUP);
  Target_TTJets_4->Scale(JERUP);
  }
  if (STACKnumber==11){
    const double JERDOWN = ScaleTTJets*conversion/jerup;
  Target_TTJets_0->Scale(JERDOWN);
  Target_TTJets_1->Scale(JERDOWN);
  Target_TTJets_2->Scale(JERDOWN);
  Target_TTJets_3->Scale(JERDOWN);
  Target_TTJets_4->Scale(JERDOWN);
  }
  if (STACKnumber==12){
   const double JESUP = ScaleTTJets*conversion/jesdown;
  Target_TTJets_0->Scale(JESUP);
  Target_TTJets_1->Scale(JESUP);
  Target_TTJets_2->Scale(JESUP);
  Target_TTJets_3->Scale(JESUP);
  Target_TTJets_4->Scale(JESUP);
  }
  if (STACKnumber==13){
    const double JESDOWN = ScaleTTJets*conversion/jerup;
  Target_TTJets_0->Scale(JESDOWN);
  Target_TTJets_1->Scale(JESDOWN);
  Target_TTJets_2->Scale(JESDOWN);
  Target_TTJets_3->Scale(JESDOWN);
  Target_TTJets_4->Scale(JESDOWN);  
  }
  if (STACKnumber==15){
    const double SCALEUP = ScaleTTJets*conversion/scaleup;
  Target_TTJets_0->Scale(SCALEUP);
  Target_TTJets_1->Scale(SCALEUP);
  Target_TTJets_2->Scale(SCALEUP);
  Target_TTJets_3->Scale(SCALEUP);
  Target_TTJets_4->Scale(SCALEUP);
  }
  if (STACKnumber==14){
    const double SCALEDOWN = ScaleTTJets*conversion/scaledown;
  Target_TTJets_0->Scale(SCALEDOWN);
  Target_TTJets_1->Scale(SCALEDOWN);
  Target_TTJets_2->Scale(SCALEDOWN);
  Target_TTJets_3->Scale(SCALEDOWN);
  Target_TTJets_4->Scale(SCALEDOWN);
  }
  if (STACKnumber==17){
   const double MASSUP = ScaleTTJets*conversion/massup;
  Target_TTJets_0->Scale(MASSUP);
  Target_TTJets_1->Scale(MASSUP);
  Target_TTJets_2->Scale(MASSUP);
  Target_TTJets_3->Scale(MASSUP);
  Target_TTJets_4->Scale(MASSUP);
  }
  if (STACKnumber==16){
    const double MASSDOWN = ScaleTTJets*conversion/massdown;
  Target_TTJets_0->Scale(MASSDOWN);
  Target_TTJets_1->Scale(MASSDOWN);
  Target_TTJets_2->Scale(MASSDOWN);
  Target_TTJets_3->Scale(MASSDOWN);
  Target_TTJets_4->Scale(MASSDOWN);  
  }
  if (STACKnumber==19){
  Target_TTJets_0->Scale(Scalematchup);
  Target_TTJets_1->Scale(Scalematchup);
  Target_TTJets_2->Scale(Scalematchup);
  Target_TTJets_3->Scale(Scalematchup);
  Target_TTJets_4->Scale(Scalematchup);
  }
  if (STACKnumber==18){
  Target_TTJets_0->Scale(Scalematchdown);
  Target_TTJets_1->Scale(Scalematchdown);
  Target_TTJets_2->Scale(Scalematchdown);
  Target_TTJets_3->Scale(Scalematchdown);
  Target_TTJets_4->Scale(Scalematchdown);  
  }
  if (STACKnumber==30){
  Target_TTJets_0->Scale(Scalenlo);
  Target_TTJets_1->Scale(Scalenlo);
  Target_TTJets_2->Scale(Scalenlo);
  Target_TTJets_3->Scale(Scalenlo);
  Target_TTJets_4->Scale(Scalenlo);  
  }
  if (STACKnumber==31){
  Target_TTJets_0->Scale(Scalepow);
  Target_TTJets_1->Scale(Scalepow);
  Target_TTJets_2->Scale(Scalepow);
  Target_TTJets_3->Scale(Scalepow);
  Target_TTJets_4->Scale(Scalepow);  
  }
  
   
    THStack *Top;	
    Top= new THStack("Top","");


    Top->Add(Target_TTJets_0);  
    Top->Add(Target_TTJets_1);  
    Top->Add(Target_TTJets_2);  
    Top->Add(Target_TTJets_3);  
    Top->Add(Target_TTJets_4);  
   
    TH1 *resultTarget = Top->GetStack()->Last();


}

else { 
  
  
  double topreweight=1;


   
 
  if(STACKnumber==90)	{ TFile *fPseudoData= new TFile("../output_backup/HplusHistos_H90.root","READ"); cout<<STACKnumber<<endl;}
  if(STACKnumber==100)	{ TFile *fPseudoData = new TFile("../output_backup/HplusHistos_H100.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==110)	{ TFile *fPseudoData = new TFile("../output_backup/HplusHistos_H110.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==120)	{ TFile *fPseudoData = new TFile("../output_backup/HplusHistos_H120.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==130)	{ TFile *fPseudoData = new TFile("../output_backup/HplusHistos_H130.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==140)	{ TFile *fPseudoData = new TFile("../output_backup/HplusHistos_H140.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==150)	{ TFile *fPseudoData = new TFile("../output_backup/HplusHistos_H150.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==155)	{ TFile *fPseudoData = new TFile("../output_backup/HplusHistos_H155.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==160)	{ TFile *fPseudoData = new TFile("../output_backup/HplusHistos_H160.root","READ");cout<<STACKnumber<<endl;}

  if(STACKnumber==1090)	       { STACKnumber=90; TFile *fPseudoData = new TFile("../../v30JERdown/output/HplusHistos_H90.root","READ"); cout<<STACKnumber<<endl;}
  if(STACKnumber==1100)        { STACKnumber=100;  TFile *fPseudoData = new TFile("../../v30JERdown/output/HplusHistos_H100.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==1110)        { STACKnumber=110;  TFile *fPseudoData = new TFile("../../v30JERdown/output/HplusHistos_H110.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==1120)        { STACKnumber=120;  TFile *fPseudoData = new TFile("../../v30JERdown/output/HplusHistos_H120.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==1130)        { STACKnumber=130;  TFile *fPseudoData = new TFile("../../v30JERdown/output/HplusHistos_H130.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==1140)        { STACKnumber=140;  TFile *fPseudoData = new TFile("../../v30JERdown/output/HplusHistos_H140.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==1150)        { STACKnumber=150;  TFile *fPseudoData = new TFile("../../v30JERdown/output/HplusHistos_H150.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==1155)        { STACKnumber=155;  TFile *fPseudoData = new TFile("../../v30JERdown/output/HplusHistos_H155.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==1160)        { STACKnumber=160;  TFile *fPseudoData = new TFile("../../v30JERdown/output/HplusHistos_H160.root","READ");cout<<STACKnumber<<endl;}

  if(STACKnumber==2090)	       { STACKnumber=90; TFile *fPseudoData = new TFile("../../v30JERup/output/HplusHistos_H90.root","READ"); cout<<STACKnumber<<endl;}
  if(STACKnumber==2100)        { STACKnumber=100;TFile *fPseudoData = new TFile("../../v30JERup/output/HplusHistos_H100.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==2110)        { STACKnumber=110;TFile *fPseudoData = new TFile("../../v30JERup/output/HplusHistos_H110.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==2120)        { STACKnumber=120;TFile *fPseudoData = new TFile("../../v30JERup/output/HplusHistos_H120.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==2130)        { STACKnumber=130;TFile *fPseudoData = new TFile("../../v30JERup/output/HplusHistos_H130.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==2140)        { STACKnumber=140;TFile *fPseudoData = new TFile("../../v30JERup/output/HplusHistos_H140.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==2150)        { STACKnumber=150;TFile *fPseudoData = new TFile("../../v30JERup/output/HplusHistos_H150.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==2155)        { STACKnumber=155;TFile *fPseudoData = new TFile("../../v30JERup/output/HplusHistos_H155.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==2160)        { STACKnumber=160;TFile *fPseudoData = new TFile("../../v30JERup/output/HplusHistos_H160.root","READ");cout<<STACKnumber<<endl;}

  if(STACKnumber==3090)	       { STACKnumber=90; TFile *fPseudoData = new TFile("../../v30JESdown/output/HplusHistos_H90.root","READ"); cout<<STACKnumber<<endl;}
  if(STACKnumber==3100)        { STACKnumber=100;TFile *fPseudoData = new TFile("../../v30JESdown/output/HplusHistos_H100.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==3110)        { STACKnumber=110;TFile *fPseudoData = new TFile("../../v30JESdown/output/HplusHistos_H110.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==3120)        { STACKnumber=120;TFile *fPseudoData = new TFile("../../v30JESdown/output/HplusHistos_H120.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==3130)        { STACKnumber=130;TFile *fPseudoData = new TFile("../../v30JESdown/output/HplusHistos_H130.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==3140)        { STACKnumber=140;TFile *fPseudoData = new TFile("../../v30JESdown/output/HplusHistos_H140.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==3150)        { STACKnumber=150;TFile *fPseudoData = new TFile("../../v30JESdown/output/HplusHistos_H150.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==3155)        { STACKnumber=155;TFile *fPseudoData = new TFile("../../v30JESdown/output/HplusHistos_H155.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==3160)        { STACKnumber=160;TFile *fPseudoData = new TFile("../../v30JESdown/output/HplusHistos_H160.root","READ");cout<<STACKnumber<<endl;}

  if(STACKnumber==4090)	       { STACKnumber=90; TFile *fPseudoData = new TFile("../../v30JESup/output/HplusHistos_H90.root","READ"); cout<<STACKnumber<<endl;}
  if(STACKnumber==4100)        { STACKnumber=100;TFile *fPseudoData = new TFile("../../v30JESup/output/HplusHistos_H100.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==4110)        { STACKnumber=110;TFile *fPseudoData = new TFile("../../v30JESup/output/HplusHistos_H110.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==4120)        { STACKnumber=120;TFile *fPseudoData = new TFile("../../v30JESup/output/HplusHistos_H120.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==4130)        { STACKnumber=130;TFile *fPseudoData = new TFile("../../v30JESup/output/HplusHistos_H130.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==4140)        { STACKnumber=140;TFile *fPseudoData = new TFile("../../v30JESup/output/HplusHistos_H140.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==4150)        { STACKnumber=150;TFile *fPseudoData = new TFile("../../v30JESup/output/HplusHistos_H150.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==4155)        { STACKnumber=155;TFile *fPseudoData = new TFile("../../v30JESup/output/HplusHistos_H155.root","READ");cout<<STACKnumber<<endl;}
  if(STACKnumber==4160)        { STACKnumber=160;TFile *fPseudoData = new TFile("../../v30JESup/output/HplusHistos_H160.root","READ");cout<<STACKnumber<<endl;}
   
  Target_PseudoData  = (TH1*)fPseudoData->Get( TargetName+SYSext );
  TH1 *topr= (TH1*)fPseudoData->Get( "Reco_hTopPtWeight_Start_sys0");
  cout<<topr->GetMean()<<endl;
  if (SYSnumber!=7 && SYSnumber !=8) {
  topreweight=topr->GetMean();
  } else {
  topreweight=1;
  }
  const double ScalePseudo_90 =lumi_factor*xsecPseudo/(199777* topreweight) ;
  const double ScalePseudo_100=lumi_factor*xsecPseudo/(199807* topreweight) ;
  const double ScalePseudo_110=lumi_factor*xsecPseudo/(199804* topreweight) ;
  const double ScalePseudo_120=lumi_factor*xsecPseudo/(199769* topreweight) ;
  const double ScalePseudo_130=lumi_factor*xsecPseudo/(199761* topreweight) ;
  const double ScalePseudo_140=lumi_factor*xsecPseudo/(199803* topreweight) ;
  const double ScalePseudo_150=lumi_factor*xsecPseudo/(199810* topreweight) ;
  const double ScalePseudo_155=lumi_factor*xsecPseudo/(199815* topreweight) ;
  const double ScalePseudo_160=lumi_factor*xsecPseudo/(199806* topreweight) ;

if (STACKnumber==90)    {  Target_PseudoData->Scale(ScalePseudo_90);}
if (STACKnumber==100)	{  Target_PseudoData->Scale(ScalePseudo_100);}
if (STACKnumber==110)	{  Target_PseudoData->Scale(ScalePseudo_110);}
if (STACKnumber==120)	{  Target_PseudoData->Scale(ScalePseudo_120);}
if (STACKnumber==130)	{  Target_PseudoData->Scale(ScalePseudo_130);}
if (STACKnumber==140)	{  Target_PseudoData->Scale(ScalePseudo_140);}
if (STACKnumber==150)	{  Target_PseudoData->Scale(ScalePseudo_150);}
if (STACKnumber==155)	{  Target_PseudoData->Scale(ScalePseudo_155);}
if (STACKnumber==160)	{  Target_PseudoData->Scale(ScalePseudo_160);}

      for (int h=0;h<9;h++){
    if(STACKnumber==masses[h]){ //background
    TH1 *resultTarget = Target_PseudoData; break;}
    }
    else {cout<<"BREAK!!!!!!!!!!!!!!!!"<<endl;}


}

 return resultTarget;


}//end drawHplus


