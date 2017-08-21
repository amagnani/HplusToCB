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
#include "BTagWeight.h"
#include "JetInfo.h"


TH2D *h2_EffMapB;   
TH2D *h2_EffMapC;   
TH2D *h2_EffMapUDSG;   
TH1D *SFb_errors;

using namespace std;


void runHplus_data()
{
double PtBins[] = {20, 30, 40, 50, 60, 70, 80, 100, 120, 160, 210, 260, 320, 400, 500, 600, 800};

 SFb_errors= new TH1D("SFb_errors","SFb_errors",16,PtBins); 
 SFb_errors->SetBinContent( 0,2*0.0415707);
 SFb_errors->SetBinContent( 1, 0.0415707);
 SFb_errors->SetBinContent( 2, 0.0204209);
 SFb_errors->SetBinContent( 3, 0.0223227);
 SFb_errors->SetBinContent( 4, 0.0206655);
 SFb_errors->SetBinContent( 5, 0.0199325);
 SFb_errors->SetBinContent( 6, 0.0174121);
 SFb_errors->SetBinContent( 7, 0.0202332);
 SFb_errors->SetBinContent( 8, 0.0182446);
 SFb_errors->SetBinContent( 9, 0.0159777);
 SFb_errors->SetBinContent( 10 ,0.0218531);
 SFb_errors->SetBinContent( 11, 0.0204688);
 SFb_errors->SetBinContent( 12, 0.0265191);
 SFb_errors->SetBinContent( 13 ,0.0313175);
 SFb_errors->SetBinContent( 14 ,0.0415417);
 SFb_errors->SetBinContent( 15, 0.0740446);
 SFb_errors->SetBinContent( 16, 0.0596716); 
 SFb_errors->SetBinContent( 17,2*0.0596716);


    //INITIALIZATIONS
    
    char inputFiles[100]        ="UNDEF";
    char outputTag[100]         ="UNDEF";
    double xsec		        =1;
    double xsec_up		=1;
    double xsec_down		=1;
    double Ninit		=1;
    int flag =0;   //1 for data, 0 for background, 2 for TTJets, 3 for signal
    
    // Reading initialization parameters from hplus.ini file
    FILE *fINI;
    float value;
    char str[100];
    double num;
    // double dvalue;
    char filename[100],sdummy[400],sflag[60];
    sprintf(filename,"init/hplus_data.ini");

    // Opening the file with the initialization settings 
    fINI=fopen(filename,"r");
    if(fINI==NULL) {
     printf("File %s doesn't exist\n",filename);
     return;
    }
    //Reading strings
    rewind(fINI); //go to the beginning of the file
    fgets(sdummy,200,fINI); // Title line
    while(fgets(sdummy,200,fINI)!=NULL) {
	   sscanf(sdummy,"%s %s",sflag,str);
           if(strcmp(sflag,"inputFiles")==0) sprintf(inputFiles,str);
           if(strcmp(sflag,"outputTag")==0) sprintf(outputTag,str);
     }
    rewind(fINI); //go to the beginning of the file
    fgets(sdummy,200,fINI); // Title line
    while(fgets(sdummy,200,fINI)!=NULL) {
	   sscanf(sdummy,"%s %lf",sflag,&num);
           if(strcmp(sflag,"xsec")==0)  xsec=num;
           if(strcmp(sflag,"xsec_up")==0)  xsec_up=num;
           if(strcmp(sflag,"xsec_down")==0)  xsec_down=num;
           if(strcmp(sflag,"Ninit")==0) Ninit=num;
           if(strcmp(sflag,"flag")==0) flag=int(num);
    }
    cout<<"X SECTION "<<xsec<<" pb  down: "<<xsec_down<<" up: "<<xsec_up <<" flag "<<flag<<endl;
    cout<<"Ninit "<<Ninit<<endl;
 
    fclose(fINI);
    
    //Recording the input file
    char command[50];
    sprintf(command,"cp hplus.ini output/hplus.ini_%s",outputTag);
    system(command);
   
if (flag !=1){  //not for data!
	//Load Btag efficiencies
	cout<<"Load Btag efficiencies"<<endl;
	char Btagstring[30];
	sprintf(Btagstring,"efficiency/BTagEff_%s.root",outputTag);

	TFile *Btagin= new TFile(Btagstring,"READ");
	h2_EffMapB    = (TH2D*)Btagin->Get("Uh2_BTaggingEff_bS");
	h2_EffMapC    = (TH2D*)Btagin->Get("Uh2_BTaggingEff_cS");
	h2_EffMapUDSG = (TH2D*)Btagin->Get("Uh2_BTaggingEff_udsgS"); 
 }  
 else { cout<<"Not Load Btag efficiencies for data"<<endl; }  

  //Load files
    char element[600];
     TChain ch_analyzeStart("analyzeStart/HplusGenPartTree");
     TChain ch_analyzeStep0("analyzeStep0/HplusGenPartTree");
     TChain ch_analyzeStep4("analyzeStep4/HplusGenPartTree");
     TChain ch_analyzeStep6("analyzeStep6/HplusGenPartTree");
     TChain ch_analyzeStep8a("analyzeStep8a/HplusGenPartTree");
     TChain ch_analyzeStep8b("analyzeStep8b/HplusGenPartTree");
     TChain ch_analyzeStep9 ("analyzeStep9/HplusGenPartTree");  
    TChain ch_analyzeStep9b ("analyzeStep9b/HplusGenPartTree");  
   
    //Open list of input files    
    char listname[50];
    sprintf(listname,"input/%s",inputFiles);
    cout<<listname<<endl;
    std::ifstream inFile;
    inFile.open(listname); //or whatever the file name is
    
    while(!inFile.eof()){
        //Get input
        inFile>>element;
	//add file in chain
	if(strcmp(element,"check")!=0) { 
	   
	 ch_analyzeStart.Add(element);
	 ch_analyzeStep0.Add(element);
	 ch_analyzeStep4.Add(element);
	 ch_analyzeStep6.Add(element);
	 ch_analyzeStep8a.Add(element);
	 ch_analyzeStep8b.Add(element);
	 ch_analyzeStep9.Add(element);
	   ch_analyzeStep9b.Add(element);
	}
	sprintf(element,"check");
    }
    
     //Close file
    inFile.close();
    
    //Normalization weights
    //double xsec=252.9*1e-12*2*0.2*0.8;
    double lumi=19.7*1e+15;
    double NTOT=xsec*1e-12*lumi;
    cout<<"NTOT (number of events scaled for luminosity) "<<NTOT<<endl;
    
    cout<<"sono qui "<<endl;
   
  //Load branches
   int nevent = ch_analyzeStart.GetEntries();	       
  //  double Nw=NTOT/double(nevent);
  // double Nw=NTOT/double(Ninit);
   double Nw=NTOT/(double(nevent)*1.001);
   cout<<"nevent "<<nevent<<endl; 
   int nevent_Step0  = ch_analyzeStep0.GetEntries();
   int nevent_Step4  = ch_analyzeStep4.GetEntries();
   int nevent_Step6  = ch_analyzeStep6.GetEntries();
   int nevent_Step8a = ch_analyzeStep8a.GetEntries();
   int nevent_Step8b = ch_analyzeStep8b.GetEntries();
   int nevent_Step9  = ch_analyzeStep9.GetEntries();
  int nevent_Step9b = ch_analyzeStep9b.GetEntries();
     cout<<"sono qui 2"<<endl;

   cout<<" STATISTICS: "<<nevent<<endl;  
   cout<<" Numbers of events Step0 (trigger path): "<<nevent_Step0<<endl;  
   cout<<" Numbers of events Step4 (no veto elecs): "<<nevent_Step4<<endl;  
   cout<<" Numbers of events Step6 (4 good jet): "<<nevent_Step6<<endl;  
   cout<<" Numbers of events Step8a (1 bjet): "<<nevent_Step8a<<endl;  
   cout<<" Numbers of events Step8b (2 bjet): "<<nevent_Step8b<<endl;  
   cout<<" Numbers of events Step9 (3 bjet 2 medium + 1 loose): "<<nevent_Step9<<endl;  
  cout<<" Numbers of events Step9b (3 bjet medium): "<<nevent_Step9b<<endl;  
    cout<<"sono qui 3"<<endl;
   

   cout<<"Let's start..."<<endl; 
  
  //loading output file
   Char_t histofile[100];
   sprintf(histofile,"output/HplusHistos_%s_data9b.root",outputTag);
   TFile *fHistos;
   fHistos = new TFile(histofile,"RECREATE");
  
 char extS[10];
 char ext4[10];
 char ext6[10];
 char ext8a[10];
 char ext8b[10];
 char ext9[10];
 char ext9b[10];
 sprintf(extS, "Start");
 sprintf(ext4, "4");
 sprintf(ext6, "6");
 sprintf(ext8a, "8a");
 sprintf(ext8b, "8b");
 sprintf(ext9, "9");
 sprintf(ext9b, "9b");
 
 
//      gROOT->ProcessLine(".L analyze_data.C");

   //semmai sostituire con Step0
// 	TTree *t4 = (TTree*) ch_analyzeStart;
// 	analyze_data *t = new analyze_data(t4);
// 	t->Loop(fHistos, h2_EffMapB, h2_EffMapC, h2_EffMapUDSG,SFb_errors, extS ,flag);
  
//   cout<<"Start done"<<endl;
//  
//        TTree *rr4 = (TTree*) ch_analyzeStep4;
//        analyze_data *rr = new analyze_data(rr4);
//        rr->Loop(fHistos, h2_EffMapB, h2_EffMapC, h2_EffMapUDSG,SFb_errors, ext4 ,flag );
//   
//   cout<<"Step4 done"<<endl;
//        
//        TTree *rr4 = (TTree*) ch_analyzeStep6;
//        analyze_data *rr = new analyze_data(rr4);
//        rr->Loop(fHistos, h2_EffMapB, h2_EffMapC, h2_EffMapUDSG,SFb_errors, ext6 ,flag );
//   
//   cout<<"Step6 done"<<endl;
// 
//    
// 	TTree *rr4 = (TTree*) ch_analyzeStep8a;
// 	analyze_data *rr = new analyze_data(rr4);
// 	rr->Loop(fHistos, h2_EffMapB, h2_EffMapC, h2_EffMapUDSG,SFb_errors, ext8a,flag );
//  
//  cout<<"Step8a done"<<endl;
// 
// 
//       TTree *rr4 = (TTree*) ch_analyzeStep8b;
//       analyze_data *rr = new analyze_data(rr4);
//       rr->Loop(fHistos, h2_EffMapB, h2_EffMapC, h2_EffMapUDSG,SFb_errors, ext8b ,flag );
//  
//  cout<<"Step8b done"<<endl;
//   
    gROOT->ProcessLine(".L analyze_data_kinfit.C");

    TTree *rr4 = (TTree*) ch_analyzeStep9b;
    analyze_data_kinfit * rrk = new analyze_data_kinfit(rr4);
    rrk->Loop(fHistos, h2_EffMapB, h2_EffMapC, h2_EffMapUDSG,SFb_errors, ext9b ,flag );

 cout<<"Step9b done"<<endl;

cout<<"successfully ended"<<endl;
gApplication->Terminate();

}
