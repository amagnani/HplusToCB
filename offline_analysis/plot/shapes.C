//***********************************************************
//******drawing the histograms from the Hplus.C macro******
//***********************************************************
#include <TH1F>
#include <iostream>
#include <string.h>
#include "TSystem.h"
#include "TMacro.h"


 void shapes(TString TargetName, TString generator){

int masses[9]={90,100,110,120,130,140,150,155,160};
 
   
  gROOT->LoadMacro("stackShapes.C");
  gROOT->LoadMacro("drawVariation.cc");

///Define main Stacks*********************************************************
     
     TFile *fDATA = new TFile("../output/HplusHistos_data.root","READ");
     TH1 *data_obs        = (TH1*)fDATA->Get(TargetName+"_sys0");
     TH1 *nontt =stackShapes(TargetName,generator,0,2);
     TH1 *tt   = stackShapes(TargetName,generator,0,1);
     TH1 *ch[9],
         *ch_jerDown[9],
	 *ch_jerUp[9],  
	 *ch_jesDown[9], 
	 *ch_jesUp[9] ;
      int value =0;
      for (int h=0;h<9;h++){
      ch[h] = stackShapes(TargetName,generator,0,masses[h]);
      value= masses[h]+int(1000); 
      ch_jerDown[h] = stackShapes(TargetName,generator,0,value); 
      value= masses[h]+int(2000);
      ch_jerUp[h]   = stackShapes(TargetName,generator,0,value);
      value= masses[h]+int(3000) ;
      ch_jesDown[h] = stackShapes(TargetName,generator,0,value);
      value= masses[h]+int(4000);
      ch_jesUp[h]   = stackShapes(TargetName,generator,0,value);     
    } 
  //systematics*********************************************************
  TH1 * tt_PUDown          =stackShapes(TargetName,generator,1,1); 
  TH1 * tt_PUUp            =stackShapes(TargetName,generator,2,1);
  TH1 * tt_muDown          =stackShapes(TargetName,generator,3,1);
  TH1 * tt_muUp            =stackShapes(TargetName,generator,4,1);
  TH1 * tt_BtagSFDown      =stackShapes(TargetName,generator,5,1);
  TH1 * tt_BtagSFUp        =stackShapes(TargetName,generator,6,1);
  TH1 * tt_topPtWeightDown =stackShapes(TargetName,generator,7,1);
  TH1 * tt_topPtWeightUp   =stackShapes(TargetName,generator,0,1);

  TH1 * tt_jerDown         =stackShapes(TargetName,generator,0,10);
  TH1 * tt_jerUp           =stackShapes(TargetName,generator,0,11);
  TH1 * tt_jesDown         =stackShapes(TargetName,generator,0,12);
  TH1 * tt_jesUp           =stackShapes(TargetName,generator,0,13);

  TH1 * tt_scaleDown       =stackShapes(TargetName,generator,0,14);
  TH1 * tt_scaleUp         =stackShapes(TargetName,generator,0,15);
  TH1 * tt_matchDown       =stackShapes(TargetName,generator,0,18);
  TH1 * tt_matchUp         =stackShapes(TargetName,generator,0,19);
  TH1 * tt_massDown        =stackShapes(TargetName,generator,0,16);
  TH1 * tt_massUp          =stackShapes(TargetName,generator,0,17);
  TH1 * tt_nloDown         =stackShapes(TargetName,generator,0,1);
  TH1 * tt_nloUp           =stackShapes(TargetName,generator,8,30);
  TH1 * tt_powDown         =stackShapes(TargetName,generator,0,1);
  TH1 * tt_powUp           =stackShapes(TargetName,generator,0,31);

  TH1 * nontt_PUDown       =stackShapes(TargetName,generator,1,2);
  TH1 * nontt_PUUp         =stackShapes(TargetName,generator,2,2);
  TH1 * nontt_muDown       =stackShapes(TargetName,generator,3,2);
  TH1 * nontt_muUp         =stackShapes(TargetName,generator,4,2);
  TH1 * nontt_BtagSFDown   =stackShapes(TargetName,generator,5,2);
  TH1 * nontt_BtagSFUp     =stackShapes(TargetName,generator,6,2);

  TH1 * nontt_jerDown      =stackShapes(TargetName,generator,0,20);
  TH1 * nontt_jerUp        =stackShapes(TargetName,generator,0,21);
  TH1 * nontt_jesDown      =stackShapes(TargetName,generator,0,22);
  TH1 * nontt_jesUp        =stackShapes(TargetName,generator,0,23);
 
  //systematics signal*******************************************************

  TH1 *ch_PUDown[9];
  TH1 *ch_PUUp[9];
  TH1 *ch_muDown[9];
  TH1 *ch_muUp[9];
  TH1 *ch_BtagSFDown[9];
  TH1 *ch_BtagSFUp[9];
  TH1 *ch_topPtWeightUp[9];
  TH1 *ch_topPtWeightDown[9];
//   TH1 *ch_scaleUp[9];
//   TH1 *ch_scaleDown[9];
//   TH1 *ch_matchUp[9];
//   TH1 *ch_matchDown[9];
//   TH1 *ch_massUp[9];
//   TH1 *ch_massDown[9];
  
  for (int h=0;h<9;h++){
   ch_PUDown[h]	     = stackShapes(TargetName,generator,1,masses[h]);
   ch_PUUp[h]  	     = stackShapes(TargetName,generator,2,masses[h]);
   ch_muDown[h]	     = stackShapes(TargetName,generator,3,masses[h]);
   ch_muUp[h]  	     = stackShapes(TargetName,generator,4,masses[h]);
   ch_BtagSFDown[h]	  = stackShapes(TargetName,generator,5,masses[h]);
   ch_BtagSFUp[h]	  = stackShapes(TargetName,generator,6,masses[h]);
   ch_topPtWeightDown[h]  = stackShapes(TargetName,generator,7,masses[h]);
   ch_topPtWeightUp[h]    = stackShapes(TargetName,generator,0,masses[h]);
//    ch_scaleUp [h] 	  = stackShapes(TargetName,generator,13,masses[h]);
//    ch_scaleDown [h] 	  = stackShapes(TargetName,generator,14,masses[h]);
//    ch_matchUp [h]	  = stackShapes(TargetName,generator,11,masses[h]);
//    ch_matchDown [h] 	  = stackShapes(TargetName,generator,12,masses[h]);
//    ch_massUp [h]          = stackShapes(TargetName,generator,9,masses[h]);
//    ch_massDown [h]        = stackShapes(TargetName,generator,10,masses[h]);
 } 
 
   //setShapesName*************************************************************************
   vector <TString> Masses;
   Masses.push_back("90");
   Masses.push_back("100");
   Masses.push_back("110");
   Masses.push_back("120");
   Masses.push_back("130");
   Masses.push_back("140");
   Masses.push_back("150");
   Masses.push_back("155");
   Masses.push_back("160");
   
   
   TString PrefixCh="WH";
   TString Name1;
   TString Name2;
   for (int h=0;h<9;h++){
       Name1=PrefixCh+"_";  Name1+=Masses[h];
   cout<<Name1<<endl;
      ch[h]->SetName(Name1);
 
      Name2=Name1+"_PUDown";	      ch_PUDown[h]->SetName(Name2);
      Name2=Name1+"_PUUp";	      ch_PUUp[h]->SetName(Name2);
      Name2=Name1+"_muDown";	      ch_muDown[h]->SetName(Name2);
      Name2=Name1+"_muUp";	      ch_muUp[h]->SetName(Name2);
      Name2=Name1+"_BtagSFDown";      ch_BtagSFDown[h]->SetName(Name2);
      Name2=Name1+"_BtagSFUp";        ch_BtagSFUp[h]->SetName(Name2);
      Name2=Name1+"_topPtWeightUp";   ch_topPtWeightUp[h]->SetName(Name2);
      Name2=Name1+"_topPtWeightDown"; ch_topPtWeightDown[h]->SetName(Name2);  
  //     Name2=Name1+"_scaleUp";         ch_scaleUp[h]->SetName(Name2);
//       Name2=Name1+"_scaleDown";       ch_scaleDown[h]->SetName(Name2);  
//       Name2=Name1+"_matchUp";         ch_matchUp[h]->SetName(Name2);
//       Name2=Name1+"_matchDown";       ch_matchDown[h]->SetName(Name2);  
//       Name2=Name1+"_massUp";          ch_massUp[h]->SetName(Name2);
//       Name2=Name1+"_massDown";        ch_massDown[h]->SetName(Name2);  


      Name2=Name1+"_jerUp"; cout<<Name2<<endl;  	      
      
      //cout<<ch_jerUp[h]->GetBinContent(12)<<endl;
      
      
      ch_jerUp[h]->SetName(Name2);
      Name2=Name1+"_jerDown";	      ch_jerDown[h]->SetName(Name2);  
      Name2=Name1+"_jesUp";	      ch_jesUp[h]->SetName(Name2);
      Name2=Name1+"_jesDown";	      ch_jesDown[h]->SetName(Name2);  
  
   }
 
   tt->SetName("tt");
   tt_PUDown->SetName("tt_PUDown");	  
   tt_PUUp->SetName("tt_PUUp"); 	  
   tt_muDown->SetName("tt_muDown");	 
   tt_muUp->SetName("tt_muUp"); 	       
   tt_BtagSFDown->SetName("tt_BtagSFDown ");	 
   tt_BtagSFUp->SetName("tt_BtagSFUp"); 	   
   tt_topPtWeightUp->SetName("tt_topPtWeightUp");   
   tt_topPtWeightDown->SetName("tt_topPtWeightDown"); 
   tt_jerUp->SetName("tt_jerUp");   
   tt_jerDown->SetName("tt_jerDown"); 
   tt_jesUp->SetName("tt_jesUp");   
   tt_jesDown->SetName("tt_jesDown"); 
   tt_scaleUp ->SetName("tt_scaleUp");
   tt_scaleDown       ->SetName("tt_scaleDown");
   tt_matchUp ->SetName("tt_matchUp");
   tt_matchDown       ->SetName("tt_matchDown");
   tt_massUp  ->SetName("tt_massUp");
   tt_massDown        ->SetName("tt_massDown");
   tt_nloUp   ->SetName("tt_nloUp");
   tt_nloDown ->SetName("tt_nloDown");
   tt_powUp   ->SetName("tt_powUp");
   tt_powDown ->SetName("tt_powDown");
 
   
   nontt->SetName("nontt");
   nontt_PUDown->SetName("nontt_PUDown");	  
   nontt_PUUp->SetName("nontt_PUUp");	  
   nontt_muDown->SetName("nontt_muDown");	 
   nontt_muUp->SetName("nontt_muUp");	       
   nontt_BtagSFDown->SetName("nontt_BtagSFDown ");     
   nontt_BtagSFUp->SetName("nontt_BtagSFUp");	   
   nontt_jerUp->SetName("nontt_jerUp"); 	   
   nontt_jerDown->SetName("nontt_jerDown ");	 
   nontt_jesUp->SetName("nontt_jesUp"); 	   
   nontt_jesDown->SetName("nontt_jesDown ");	 
   
    
   data_obs->SetName("data_obs");
 
 
   //fix ranges and fill bins with 0 bkg****************************************************
   for (int h=0;h<9;h++){
      ch[h]		      ->GetXaxis()->SetRangeUser(15,165);
      ch_PUDown[h]	      ->GetXaxis()->SetRangeUser(15,165);
      ch_PUUp[h]	      ->GetXaxis()->SetRangeUser(15,165);
      ch_muDown[h]	      ->GetXaxis()->SetRangeUser(15,165);
      ch_muUp[h]	      ->GetXaxis()->SetRangeUser(15,165);
      ch_BtagSFDown[h]        ->GetXaxis()->SetRangeUser(15,165);
      ch_BtagSFUp[h]	      ->GetXaxis()->SetRangeUser(15,165);
      ch_topPtWeightUp[h]     ->GetXaxis()->SetRangeUser(15,165);
      ch_topPtWeightDown[h]   ->GetXaxis()->SetRangeUser(15,165);
      ch_jerUp[h]	      ->GetXaxis()->SetRangeUser(15,165);
      ch_jerDown[h]	      ->GetXaxis()->SetRangeUser(15,165);
      ch_jesUp[h]	      ->GetXaxis()->SetRangeUser(15,165);
      ch_jesDown[h]	      ->GetXaxis()->SetRangeUser(15,165);
// 	ch_scaleUp [h] 	      ->GetXaxis()->SetRangeUser(15,165);
// 	ch_scaleDown [h] 	->GetXaxis()->SetRangeUser(15,165);
// 	ch_matchUp [h]	        ->GetXaxis()->SetRangeUser(15,165);
// 	ch_matchDown [h] 	->GetXaxis()->SetRangeUser(15,165);
// 	ch_massUp [h]		->GetXaxis()->SetRangeUser(15,165); 
// 	ch_massDown [h]  	->GetXaxis()->SetRangeUser(15,165); 
	
	  }
      tt->GetXaxis()->SetRangeUser(15,165);
      tt_PUDown       ->GetXaxis()->SetRangeUser(15,165);
      tt_PUUp	      ->GetXaxis()->SetRangeUser(15,165);
      tt_muDown       ->GetXaxis()->SetRangeUser(15,165);
      tt_muUp	      ->GetXaxis()->SetRangeUser(15,165);
      tt_BtagSFDown   ->GetXaxis()->SetRangeUser(15,165);
      tt_BtagSFUp     ->GetXaxis()->SetRangeUser(15,165);
      tt_topPtWeightUp->GetXaxis()->SetRangeUser(15,165);
      tt_topPtWeightDown->GetXaxis()->SetRangeUser(15,165);   
	tt_jerUp     ->GetXaxis()->SetRangeUser(15,165);
      tt_jerDown      ->GetXaxis()->SetRangeUser(15,165);
      tt_jesUp        ->GetXaxis()->SetRangeUser(15,165);
      tt_jesDown      ->GetXaxis()->SetRangeUser(15,165);
      tt_scaleUp      ->GetXaxis()->SetRangeUser(15,165);
      tt_scaleDown    ->GetXaxis()->SetRangeUser(15,165);
      tt_matchUp      ->GetXaxis()->SetRangeUser(15,165);
      tt_matchDown    ->GetXaxis()->SetRangeUser(15,165);
      tt_massUp       ->GetXaxis()->SetRangeUser(15,165);
      tt_massDown     ->GetXaxis()->SetRangeUser(15,165);
      tt_nloUp        -> GetXaxis()->SetRangeUser(15,165);
      tt_nloDown      -> GetXaxis()->SetRangeUser(15,165);
      tt_powUp        -> GetXaxis()->SetRangeUser(15,165);
      tt_powDown      -> GetXaxis()->SetRangeUser(15,165);
      nontt->GetXaxis()->SetRangeUser(15,165);
      nontt_PUDown    ->GetXaxis()->SetRangeUser(15,165);
      nontt_PUUp      ->GetXaxis()->SetRangeUser(15,165);
      nontt_muDown    ->GetXaxis()->SetRangeUser(15,165);
      nontt_muUp      ->GetXaxis()->SetRangeUser(15,165);
      nontt_BtagSFDown->GetXaxis()->SetRangeUser(15,165);
      nontt_BtagSFUp  ->GetXaxis()->SetRangeUser(15,165);
	 nontt_jerUp  ->GetXaxis()->SetRangeUser(15,165);
      nontt_jerDown   ->GetXaxis()->SetRangeUser(15,165);
      nontt_jesUp     ->GetXaxis()->SetRangeUser(15,165);
      nontt_jesDown   ->GetXaxis()->SetRangeUser(15,165);
  
 
	 data_obs->GetXaxis()->SetRangeUser(15,165);
 
 
     for (int bin=0; bin<tt->GetXaxis()->GetNbins(); bin++){
       if (tt		      ->GetBinContent(bin)==0) tt->SetBinContent(bin, 0.00001);
       if (tt_PUDown	      ->GetBinContent(bin)==0) tt_PUDown->SetBinContent(bin, 0.00001);    
       if (tt_PUUp	      ->GetBinContent(bin)==0) tt_PUUp ->SetBinContent(bin, 0.00001);	  
       if (tt_muDown	      ->GetBinContent(bin)==0) tt_muDown->SetBinContent(bin, 0.00001);    
       if (tt_muUp	      ->GetBinContent(bin)==0) tt_muUp->SetBinContent(bin, 0.00001);	  
       if (tt_BtagSFDown      ->GetBinContent(bin)==0) tt_BtagSFDown->SetBinContent(bin, 0.00001);
       if (tt_BtagSFUp  	      ->GetBinContent(bin)==0) tt_BtagSFUp->SetBinContent(bin, 0.00001);  
       if (tt_topPtWeightUp   ->GetBinContent(bin)==0) tt_topPtWeightUp->SetBinContent(bin, 0.00001);
       if (tt_topPtWeightDown ->GetBinContent(bin)==0) tt_topPtWeightDown->SetBinContent(bin, 0.00001);
       if (tt_jerUp	       ->GetBinContent(bin)==0) tt_jerUp      ->SetBinContent(bin, 0.00001);
       if (tt_jerDown	       ->GetBinContent(bin)==0) tt_jerDown    ->SetBinContent(bin, 0.00001);
       if (tt_jesUp	       ->GetBinContent(bin)==0) tt_jesUp      ->SetBinContent(bin, 0.00001);
       if (tt_jesDown	       ->GetBinContent(bin)==0) tt_jesDown    ->SetBinContent(bin, 0.00001);
       if (tt_scaleUp	       ->GetBinContent(bin)==0) tt_scaleUp    ->SetBinContent(bin, 0.00001);
       if (tt_scaleDown        ->GetBinContent(bin)==0) tt_scaleDown  ->SetBinContent(bin, 0.00001);
       if (tt_matchUp	       ->GetBinContent(bin)==0) tt_matchUp    ->SetBinContent(bin, 0.00001);
       if (tt_matchDown        ->GetBinContent(bin)==0) tt_matchDown  ->SetBinContent(bin, 0.00001);
       if (tt_massUp	       ->GetBinContent(bin)==0) tt_massUp     ->SetBinContent(bin, 0.00001);
       if (tt_massDown  	       ->GetBinContent(bin)==0) tt_massDown   ->SetBinContent(bin, 0.00001);
       if (tt_nloUp    -> GetBinContent(bin)==0)  tt_nloUp    ->SetBinContent(bin, 0.00001);
       if (tt_nloDown  -> GetBinContent(bin)==0)  tt_nloDown  ->SetBinContent(bin, 0.00001);
       if (tt_powUp    -> GetBinContent(bin)==0)  tt_powUp    ->SetBinContent(bin, 0.00001);
       if (tt_powDown  -> GetBinContent(bin)==0)  tt_powDown  ->SetBinContent(bin, 0.00001);
  
       if (nontt->GetBinContent(bin)==0) nontt->SetBinContent(bin, 0.00001);
       if (nontt_PUDown 	      ->GetBinContent(bin)==0) nontt_PUDown->SetBinContent(bin, 0.00001);    
       if (nontt_PUUp	      ->GetBinContent(bin)==0) nontt_PUUp ->SetBinContent(bin, 0.00001);     
       if (nontt_muDown 	      ->GetBinContent(bin)==0) nontt_muDown->SetBinContent(bin, 0.00001);    
       if (nontt_muUp	      ->GetBinContent(bin)==0) nontt_muUp->SetBinContent(bin, 0.00001);      
       if (nontt_BtagSFDown   ->GetBinContent(bin)==0) nontt_BtagSFDown->SetBinContent(bin, 0.00001);
       if (nontt_BtagSFUp     ->GetBinContent(bin)==0) nontt_BtagSFUp->SetBinContent(bin, 0.00001);  
       if (nontt_jerUp  	      ->GetBinContent(bin)==0) nontt_jerUp->SetBinContent(bin, 0.00001);
       if (nontt_jerDown	      ->GetBinContent(bin)==0) nontt_jerDown->SetBinContent(bin, 0.00001);
       if (nontt_jesUp  	      ->GetBinContent(bin)==0) nontt_jesUp->SetBinContent(bin, 0.00001);
       if (nontt_jesDown	      ->GetBinContent(bin)==0) nontt_jesDown->SetBinContent(bin, 0.00001);
       
    }
 
   TFile *fShapes= new TFile("simple_shapes3.root","RECREATE");
   TDirectory *Mu_nor_3b = fShapes->mkdir("Mu_nor_3b");
   Mu_nor_3b->cd();
 
 //Write shapes
   for (int h=0;h<9;h++){
      ch[h] ->Write();
      ch_PUDown[h] ->Write();	       
      ch_PUUp[h] ->Write();	       
      ch_muDown[h] ->Write();	       
      ch_muUp[h] ->Write();	       
      ch_BtagSFDown[h] ->Write();      
      ch_BtagSFUp[h] ->Write();        
      ch_topPtWeightUp[h] ->Write();   
      ch_topPtWeightDown[h]   ->Write();
      ch_jerUp[h]     ->Write();
      ch_jerDown[h]   ->Write();
      ch_jesUp[h]     ->Write();
      ch_jesDown[h]   ->Write();

// 	ch_scaleUp [h]   ->Write();
// 	ch_scaleDown [h]   ->Write();
// 	ch_matchUp [h]  ->Write();
// 	ch_matchDown [h]   ->Write();
// 	ch_massUp [h]	  ->Write(); 
// 	ch_massDown [h]   ->Write(); 

   }
 
 tt->Write();
 tt_PUDown->Write();	
 tt_PUUp->Write();	
 tt_muDown->Write();	
 tt_muUp->Write();	
 tt_BtagSFDown->Write();
 tt_BtagSFUp->Write();  
 tt_topPtWeightUp->Write();
 tt_topPtWeightDown->Write();  
 tt_jerUp     ->Write();
 tt_jerDown   ->Write();
 tt_jesUp     ->Write();
 tt_jesDown->Write();
 tt_scaleUp->Write();
 tt_scaleDown->Write();
 tt_matchUp->Write();
 tt_matchDown->Write();
 tt_massUp->Write();
 tt_massDown->Write();
 tt_nloUp   ->Write();
 tt_nloDown ->Write();
 tt_powUp   ->Write();
 tt_powDown ->Write();
 
 nontt->Write();
 nontt_PUDown->Write();    
 nontt_PUUp->Write();	   
 nontt_muDown->Write();    
 nontt_muUp->Write();	   
 nontt_BtagSFDown->Write();
 nontt_BtagSFUp->Write();  
 nontt_jerUp	 ->Write();
 nontt_jerDown   ->Write();
 nontt_jesUp	 ->Write();
 nontt_jesDown   ->Write();
 
 data_obs->Write(); 
   
   
   
   
  TFile *fShapes->Close();
    
 //produce datacards
 vector<TString> card; 
 for (int h=0; h<9;h++){
  card.push_back("mh");
 }
 for (int h=0; h<9;h++){
  card[h]+=masses[h];
  card[h]+=".txt";
 }
 ofstream out[9];
 
 
 //fill datacards
 for (int h=0; h<9;h++){
   out[h].open(card[h]);
   out[h]<<"imax    1	 number of categories"<<endl;
   out[h]<<"jmax    2	 number of samples minus one "<<endl;
   out[h]<<"kmax    *	 number of nuisance parameters"<<endl;
   out[h]<<"------------------------------------------------------------------------------"<<endl;
 //  out[h]<<"shapes * *    /afs/cern.ch/work/a/amagnani/private/COMBINE/CMSSW_7_4_7/src/HiggsAnalysis/CombinedLimit/data/ch_"<<TargetName<<"/simple_shapes2.root $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC"<<endl;
   out[h]<<"shapes * *    /afs/cern.ch/work/a/amagnani/private/COMBINE/CMSSW_7_4_7/src/HiggsAnalysis/CombinedLimit/data/SHAPES2/simple_shapes3.root $CHANNEL/$PROCESS $CHANNEL/$PROCESS_$SYSTEMATIC"<<endl;
   out[h]<<endl;
   out[h]<<"------------------------------------------------------------------------------"<<endl;
   out[h]<<"bin 			      Mu_nor_3b"<<endl;
   out[h]<<"observation 		      "<<data_obs->Integral()<<endl;
   out[h]<<"------------------------------------------------------------------------------"<<endl;
   out[h]<<"bin 				      Mu_nor_3b 	      Mu_nor_3b 	      Mu_nor_3b"<<endl;
   out[h]<<"process				      0 		      1 		      2"<<endl;
   out[h]<<"process				      WH_"<<masses[h]<<"		      tt		      nontt"<<endl;
   out[h]<<"rate				      "<<ch[h]->Integral()<<"		      "<<tt->Integral()<<"	      "<<nontt->Integral()<<endl;
   out[h]<<"------------------------------------------------------------------------------"<<endl;
   out[h]<<"lumi_8TeV  lnN		      1.026		      1.026		      1.026"<<endl;
   out[h]<<"ttxsec     lnN		      1.065		      1.065		      1.065"<<endl;
   out[h]<<"muon	  lnN			      1.02		      1.02		      1.02    "<<endl;
   out[h]<<"PU 		 	shape  		      1 		      1 		      1    "<<endl;
   out[h]<<"mu  	 	 shape 		      1 		      1 		      1    "<<endl;
   out[h]<<"BtagSF     		shape		      1 		      1 		      1    "<<endl;
   out[h]<<"topPtWeight        shape		      1 		      1 		      -    "<<endl;
   out[h]<<"jes 	       shape		      1 		      1 		      1    "<<endl;
   out[h]<<"jer 	       shape		      1 		      1 		      1    "<<endl;
   out[h]<<"mass	       shape		      - 		      1 		      -    "<<endl;
   out[h]<<"scale     	       shape		      -  		      1  		      -    "<<endl;
   out[h]<<"match     	       shape		      -  		      1  		      -    "<<endl;
   out[h]<<"nlo 	       shape		      - 		      1 		      -    "<<endl;
   out[h]<<"pow 	       shape		      - 		      1 		      -    "<<endl;
 
  }  
   
   cout<<" WH_90  "<<WH_90 ->Integral()<< endl;
   cout<<" WH_100 "<<WH_100->Integral()<< endl;
   cout<<" WH_110 "<<WH_110->Integral()<< endl;
   cout<<" WH_120 "<<WH_120->Integral()<< endl;
   cout<<" WH_130 "<<WH_130->Integral()<< endl;
   cout<<" WH_140 "<<WH_140->Integral()<< endl;
   cout<<" WH_150 "<<WH_150->Integral()<< endl;
   cout<<" WH_155 "<<WH_155->Integral()<< endl;
   cout<<" WH_160 "<<WH_160->Integral()<< endl;
 
   cout<<" tt "<<tt->Integral()<<" nontt "<<nontt->Integral()<<" observed "<<data_obs->Integral()<<endl;
 
   ///*****************************************************************
   // Draw variations 
   
    gROOT->ProcessLine(".L tdrstyle.C");  
    gStyle->SetOptStat(0);

    TLegend *legjer = new TLegend(0.12,0.7,0.40,0.89);
    legjer->SetBorderSize(0);
    legjer->SetLineColor(0);
    legjer->SetLineStyle(0);
    legjer->SetLineWidth(0);
    legjer->SetFillColor(0);
    legjer->SetFillStyle(1001);
    legjer->AddEntry(tt,"nominal","f");
    legjer->AddEntry(tt_jerUp,"JER up","f");
    legjer->AddEntry(tt_jerDown,"JER down","f");
 
    TLegend *legjes = new TLegend(0.12,0.7,0.40,0.89);
    legjes->SetBorderSize(0);
    legjes->SetLineColor(0);
    legjes->SetLineStyle(0);
    legjes->SetLineWidth(0);
    legjes->SetFillColor(0);
    legjes->SetFillStyle(1001);
    legjes->AddEntry(tt,"nominal","f");
    legjes->AddEntry(tt_jerUp,"JES up","f");
    legjes->AddEntry(tt_jerDown,"JES down","f");
 
 
    TLegend *legbtag = new TLegend(0.12,0.7,0.40,0.89);
    legbtag->SetBorderSize(0);
    legbtag->SetLineColor(0);
    legbtag->SetLineStyle(0);
    legbtag->SetLineWidth(0);
    legbtag->SetFillColor(0);
    legbtag->SetFillStyle(1001);
    legbtag->AddEntry(tt,"nominal","f");
    legbtag->AddEntry(tt_jerUp,"btag scale up","f");
    legbtag->AddEntry(tt_jerDown,"btag scale down","f");
 
    TLegend *legbtagl = new TLegend(0.12,0.7,0.40,0.89);
    legbtagl->SetBorderSize(0);
    legbtagl->SetLineColor(0);
    legbtagl->SetLineStyle(0);
    legbtagl->SetLineWidth(0);
    legbtagl->SetFillColor(0);
    legbtagl->SetFillStyle(1001);
    legbtagl->AddEntry(tt,"nominal","f");
    legbtagl->AddEntry(tt_jerUp,"mistag scale up","f");
    legbtagl->AddEntry(tt_jerDown,"mistag scale down","f");
 
    TLegend *legpileup = new TLegend(0.12,0.7,0.40,0.89);
    legpileup->SetBorderSize(0);
    legpileup->SetLineColor(0);
    legpileup->SetLineStyle(0);
    legpileup->SetLineWidth(0);
    legpileup->SetFillColor(0);
    legpileup->SetFillStyle(1001);
    legpileup->AddEntry(tt,"nominal","f");
    legpileup->AddEntry(tt_jerUp,"pileup up","f");
    legpileup->AddEntry(tt_jerDown,"pileup down","f");
 
    TLegend *legtoppt  = new TLegend(0.12,0.7,0.40,0.89);
    legtoppt ->SetBorderSize(0);
    legtoppt ->SetLineColor(0);
    legtoppt ->SetLineStyle(0);
    legtoppt ->SetLineWidth(0);
    legtoppt ->SetFillColor(0);
    legtoppt ->SetFillStyle(1001);
    legtoppt ->AddEntry(tt,"nominal","f");
    //legtoppt ->AddEntry(tt_jerUp,"top pt  up","f");
    legtoppt ->AddEntry(tt_jerDown,"w/o top pt weights","f");
 
 
    TLegend *legnlo = new TLegend(0.12,0.7,0.40,0.89);
    legnlo->SetBorderSize(0);
    legnlo->SetLineColor(0);
    legnlo->SetLineStyle(0);
    legnlo->SetLineWidth(0);
    legnlo->SetFillColor(0);
    legnlo->SetFillStyle(1001);
    legnlo->AddEntry(tt,"nominal","f");
    legnlo->AddEntry(tt_jerUp,"mc@nlo","f");
    //legnlo->AddEntry(tt_jerDown,"mc@nlo down","f");
 
 
    TLegend *legpow = new TLegend(0.12,0.7,0.40,0.89);
    legpow->SetBorderSize(0);
    legpow->SetLineColor(0);
    legpow->SetLineStyle(0);
    legpow->SetLineWidth(0);
    legpow->SetFillColor(0);
    legpow->SetFillStyle(1001);
    legpow->AddEntry(tt,"nominal","f");
    legpow->AddEntry(tt_jerUp,"powheg","f");
    //legpow->AddEntry(tt_jerDown,"powheg down","f");
 
    TLegend *legmass = new TLegend(0.12,0.7,0.40,0.89);
    legmass->SetBorderSize(0);
    legmass->SetLineColor(0);
    legmass->SetLineStyle(0);
    legmass->SetLineWidth(0);
    legmass->SetFillColor(0);
    legmass->SetFillStyle(1001);
    legmass->AddEntry(tt,"nominal","f");
    legmass->AddEntry(tt_jerUp,"top mass up","f");
    legmass->AddEntry(tt_jerDown,"top mass down","f");
 
    TLegend *legmatch = new TLegend(0.12,0.7,0.40,0.89);
    legmatch->SetBorderSize(0);
    legmatch->SetLineColor(0);
    legmatch->SetLineStyle(0);
    legmatch->SetLineWidth(0);
    legmatch->SetFillColor(0);
    legmatch->SetFillStyle(1001);
    legmatch->AddEntry(tt,"nominal","f");
    legmatch->AddEntry(tt_jerUp,"ME-PS matching up","f");
    legmatch->AddEntry(tt_jerDown,"ME-PS matching down","f");
 
    TLegend *legscale = new TLegend(0.12,0.7,0.40,0.89);
    legscale->SetBorderSize(0);
    legscale->SetLineColor(0);
    legscale->SetLineStyle(0);
    legscale->SetLineWidth(0);
    legscale->SetFillColor(0);
    legscale->SetFillStyle(1001);
    legscale->AddEntry(tt,"nominal","f");
    legscale->AddEntry(tt_jerUp,"renorm. scale up","f");
    legscale->AddEntry(tt_jerDown,"renorm. scale down","f");
    
    TCanvas *jer = new TCanvas("jer","jer",1600,400);
   jer->Divide(3,1);
   jer->cd(1);
   drawVariation(ch[3], ch_jerUp[3],ch_jerDown[3],1);
   legjer->Draw();
 
   double size=0;
   size=( ch_jerUp[3]->Integral()-ch[3]->Integral() )/ ch[3]->Integral();
   cout<<"jer ch "<<size<<endl;
   size=( ch_jerDown[3]->Integral()-ch[3]->Integral())/ch[3]->Integral();
   cout<<"jer ch "<<size<<endl;
 
   jer->cd(2);
   drawVariation(tt, tt_jerUp,tt_jerDown,2);

   legjer->Draw();
   cout<<"jer tt "<<(tt_jerUp->Integral()-tt->Integral())/tt->Integral()<<endl;
   cout<<"jer tt "<<(tt_jerDown->Integral()-tt->Integral())/tt->Integral()<<endl;
 
   jer->cd(3);
   drawVariation(nontt, nontt_jerUp, nontt_jerDown,3);

   legjer->Draw();
   cout<<"jer nontt "<<(nontt_jerUp->Integral()-nontt->Integral())/nontt->Integral()<<endl;
   cout<<"jer nontt "<<(nontt_jerDown->Integral()-nontt->Integral())/nontt->Integral()<<endl;
   
  jer->SaveAs("jer.png"); 
  
 
  
  ///**********************************************************
  
   TCanvas *jes = new TCanvas("jes","jes",1600,400);
   jes->Divide(3,1);
   jes->cd(1);
   drawVariation(ch[3], ch_jesUp[3],ch_jesDown[3],1);
    legjes->Draw();
   cout<<"jes ch "<<(ch_jesUp[3]->Integral()-ch[3]->Integral())/ch[3]->Integral()<<endl;
   cout<<"jes ch "<<(ch_jesDown[3]->Integral()-ch[3]->Integral())/ch[3]->Integral()<<endl;
 
   jes->cd(2);
   drawVariation(tt, tt_jesUp,tt_jesDown,2);
   legjes->Draw();
   cout<<"jes tt "<<(tt_jesUp->Integral()-tt->Integral())/tt->Integral()<<endl;
   cout<<"jes tt "<<(tt_jesDown->Integral()-tt->Integral())/tt->Integral()<<endl;
 
   jes->cd(3);
   drawVariation(nontt, nontt_jesUp,nontt_jesDown,3);
    legjes->Draw();
   cout<<"jes nontt "<<(nontt_jesUp->Integral()-nontt->Integral())/nontt->Integral()<<endl;
   cout<<"jes nontt "<<(nontt_jesDown->Integral()-nontt->Integral())/nontt->Integral()<<endl;
    
  jes->SaveAs("jes.png"); 
  ///**********************************************************
   
   TCanvas *btag = new TCanvas("btag","btag",1600,400);
   btag->Divide(3,1);
   btag->cd(1);
   drawVariation(ch[3], ch_BtagSFUp[3], ch_BtagSFDown[3],1);
   legbtag->Draw();
   cout<<"BtagSF ch "<<(ch_BtagSFUp[3]->Integral()-ch[3]->Integral())/ch[3]->Integral()<<endl;
   cout<<"BtagSF ch "<<(ch_BtagSFDown[3]->Integral()-ch[3]->Integral())/ch[3]->Integral()<<endl;
 
   btag->cd(2);
   drawVariation(tt, tt_BtagSFUp, tt_BtagSFDown,2);
   legbtag->Draw();
   cout<<"BtagSF tt "<<(tt_BtagSFUp->Integral()-tt->Integral())/tt->Integral()<<endl;
   cout<<"BtagSF tt "<<(tt_BtagSFDown->Integral()-tt->Integral())/tt->Integral()<<endl;
  
   btag->cd(3);
   drawVariation(nontt, nontt_BtagSFUp, nontt_BtagSFDown,3);
   legbtag->Draw();
   cout<<"BtagSF nontt "<<(nontt_BtagSFUp->Integral()-nontt->Integral())/nontt->Integral()<<endl;
   cout<<"BtagSF nontt "<<(nontt_BtagSFDown->Integral()-nontt->Integral())/nontt->Integral()<<endl;
   
  btag->SaveAs("btag.png"); 
  
   //
   ///*****************************************************************
   ///**********************************************************
   
   TCanvas *btagl = new TCanvas("btagl","btagl",1600,400);
   btagl->Divide(3,1);
   btagl->cd(1);
   drawVariation(ch[3], ch_muUp[3], ch_muDown[3],1);
   legbtagl->Draw();
   cout<<"BtagSFl ch "<<(ch_muUp[3]->Integral()-ch[3]->Integral())/ch[3]->Integral()<<endl;
   cout<<"BtagSFl ch "<<(ch_muDown[3]->Integral()-ch[3]->Integral())/ch[3]->Integral()<<endl;
 
   btagl->cd(2);
   drawVariation(tt, tt_muUp, tt_muDown,2);
   legbtagl->Draw();
   cout<<"BtagSFl  tt "<<(tt_muUp->Integral()-tt->Integral())/tt->Integral()<<endl;
   cout<<"BtagSFl  tt "<<(tt_muDown->Integral()-tt->Integral())/tt->Integral()<<endl;
 
   btagl->cd(3);
   drawVariation(nontt, nontt_muUp, nontt_muDown,3);
   legbtagl->Draw();
   cout<<"BtagSFl nontt "<<(nontt_muUp->Integral()-nontt->Integral())/nontt->Integral()<<endl;
   cout<<"BtagSFl nontt "<<(nontt_muDown->Integral()-nontt->Integral())/nontt->Integral()<<endl;
  
  btagl->SaveAs("btagl.png"); 
  
   //
   ///*****************************************************************
    
   TCanvas *PU = new TCanvas("PU","PU",1600,400);
   PU->Divide(3,1);
   PU->cd(1);
   drawVariation(ch[3], ch_PUUp[3], ch_PUDown[3],1);
   legpileup->Draw();
   cout<<"pu ch "<<(ch_PUUp[3]->Integral()-ch[3]->Integral())/ch[3]->Integral()<<endl;
   cout<<"pu ch "<<(ch_PUDown[3]->Integral()-ch[3]->Integral())/ch[3]->Integral()<<endl;
 
   PU->cd(2);
   drawVariation(tt, tt_PUUp, tt_PUDown,2);
   legpileup->Draw();
   cout<<"pu tt "<<(tt_PUUp->Integral()-tt->Integral())/tt->Integral()<<endl;
   cout<<"pu tt "<<(tt_PUDown->Integral()-tt->Integral())/tt->Integral()<<endl;
 
   PU->cd(3);
   drawVariation(nontt, nontt_PUUp, nontt_PUDown,3);
   legpileup->Draw();
   cout<<"pu nontt "<<(nontt_PUUp->Integral()-nontt->Integral())/nontt->Integral()<<endl;
   cout<<"pu nontt "<<(nontt_PUDown->Integral()-nontt->Integral())/nontt->Integral()<<endl;
   
  PU->SaveAs("PU.png"); 
  ///**********************************************************
   ///*****************************************************************
    
   TCanvas *topPtWeight = new TCanvas("topPtWeight","topPtWeight",1000,400);
   topPtWeight->Divide(2,1);
   topPtWeight->cd(1);
   drawVariation(ch[3],ch_topPtWeightUp[3] , ch_topPtWeightDown[3], 1);
   legtoppt->Draw();
   cout<<"toppt ch "<<ch[3]->Integral()<<endl;
   cout<<"toppt ch "<<(ch_topPtWeightUp[3]->Integral()-ch[3]->Integral())/ch[3]->Integral()<<endl;
   cout<<"topt ch "<<(ch_topPtWeightDown[3]->Integral()-ch[3]->Integral())/ch[3]->Integral()<<endl;
 
   topPtWeight->cd(2);
   drawVariation(tt, tt_topPtWeightUp , tt_topPtWeightDown, 2);
   legtoppt->Draw();
   cout<<"toppt tt "<<(tt_topPtWeightUp->Integral()-tt->Integral())/tt->Integral()<<endl;
   cout<<"topt tt "<<(tt_topPtWeightDown->Integral()-tt->Integral())/tt->Integral()<<endl;
 
   
  topPtWeight->SaveAs("topPtWeight.png"); 
  ///**********************************************************
   ///*****************************************************************
    
   TCanvas *gen = new TCanvas("gen","gen",1000,400);
   gen->Divide(2,1);
   gen->cd(1);
   drawVariation(tt, tt_nloUp, 2);
   legnlo->Draw();
   cout<<"nlo tt "<<(tt_nloUp->Integral()-tt->Integral())/tt->Integral()<<endl;
   cout<<"nlo tt "<<(tt_nloDown->Integral()-tt->Integral())/tt->Integral()<<endl;
 
  
   gen->cd(2);
   drawVariation(tt, tt_powUp, 2);
   legpow->Draw();
   cout<<"pow tt "<<(tt_powUp->Integral()-tt->Integral())/tt->Integral()<<endl;
   cout<<"pow tt "<<(tt_powDown->Integral()-tt->Integral())/tt->Integral()<<endl;
 
   
   gen->SaveAs("gen.png"); 

   ///**********************************************************
   ///*****************************************************************
    
   TCanvas *top = new TCanvas("top","top",1600,400);
   top->Divide(3,1);
 //   TCanvas *top = new TCanvas("top","top",1000,400);
//    top->Divide(2,1);
   top->cd(1);
   drawVariation(tt, tt_massUp,tt_massDown, 2);
   legmass->Draw();
   cout<<"mass tt "<<(tt_massUp->Integral()-tt->Integral())/tt->Integral()<<endl;
   cout<<"mass tt "<<(tt_massDown->Integral()-tt->Integral())/tt->Integral()<<endl;
 
    top->cd(2);
   drawVariation(tt, tt_matchUp,tt_matchDown, 2);
    legmatch->Draw();
    cout<<"match tt "<<(tt_matchUp->Integral()-tt->Integral())/tt->Integral()<<endl;
    cout<<"match tt "<<(tt_matchDown->Integral()-tt->Integral())/tt->Integral()<<endl;
  
   top->cd(3);
   drawVariation(tt, tt_scaleUp,tt_scaleDown, 2);
   legscale->Draw();
   cout<<"scale tt "<<(tt_scaleUp->Integral()-tt->Integral())/tt->Integral()<<endl;
   cout<<"scale tt "<<(tt_scaleDown->Integral()-tt->Integral())/tt->Integral()<<endl;
 
//     top->cd(4);
//    drawVariation(ch[3], ch_massUp[3],ch_massDown[3], 1);
//    legmass->Draw();
//    cout<<"mass ch "<<(ch_massUp[3]->Integral()-ch[3]->Integral())/ch[3]->Integral()<<endl;
//    cout<<"mass ch "<<(ch_massDown[3]->Integral()-ch[3]->Integral())/ch[3]->Integral()<<endl;
//  
//     top->cd(5);
//    drawVariation(ch[3], ch_matchUp[3],ch_matchDown[3], 1);
//     legmatch->Draw();
//     cout<<"match ch "<<(ch_matchUp[3]->Integral()-ch[3]->Integral())/ch[3]->Integral()<<endl;
//     cout<<"match ch "<<(ch_matchDown[3]->Integral()-ch[3]->Integral())/ch[3]->Integral()<<endl;
//   
//    top->cd(6);
//    drawVariation(ch[3], ch_scaleUp[3],ch_scaleDown[3], 1);
//    legscale->Draw();
//    cout<<"scale ch "<<(ch_scaleUp[3]->Integral()-ch[3]->Integral())/ch[3]->Integral()<<endl;
//    cout<<"scale ch "<<(ch_scaleDown[3]->Integral()-ch[3]->Integral())/ch[3]->Integral()<<endl;
//   
  top->SaveAs("top.png"); 
  ///**********************************************************
 
 //gApplication->Terminate();
	 
    

}//end drawHplus


