//***********************************************************
//******drawing the histograms from the Hplus.C macro******
//***********************************************************
#include <TH1F>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

TH1 *  spitSYS(TString TargetName, TString generator, int SYSnumber){

   
   gROOT->ProcessLine(".L tdrstyle.C");
   gROOT->LoadMacro("stackShapes.C");
   //  gStyle->SetOptStat("emr");
   gStyle->SetOptStat(0);
   //gStyle->SetOptLogx(1);
   gStyle->SetOptLogy(1);
   gStyle->SetOptLogz(0);

 
 //************************************************nominal stack
     TH1 *nominal_tt=stackShapes(TargetName,generator,0,1);
     TH1 *nominal_nontt=stackShapes(TargetName,generator,0,2);
     THStack *nominal_Target;	
     nominal_Target= new THStack("nominal_Target","");
    
     nominal_Target->Add(nominal_tt);  
     nominal_Target->Add(nominal_nontt);  
     TH1 *sum_Target = nominal_Target->GetStack()->Last();


  //*********************************************************varied  stack 
     if (SYSnumber<7){
     TH1 *tt=stackShapes(TargetName,generator,SYSnumber,1);
     TH1 *nontt=stackShapes(TargetName,generator,SYSnumber,2);
    }
    else if (SYSnumber==7) {
     TH1 *tt=stackShapes(TargetName,generator,SYSnumber,1);
     TH1 *nontt=stackShapes(TargetName,generator,0,2);
     } 
    else if (SYSnumber>9 && SYSnumber<14){
     TH1 *tt=stackShapes(TargetName,generator,0,SYSnumber);
     TH1 *nontt=stackShapes(TargetName,generator,0,SYSnumber+10);
    }
     else if (SYSnumber>13 && SYSnumber<20){
     TH1 *tt=stackShapes(TargetName,generator,0,SYSnumber);
     TH1 *nontt=stackShapes(TargetName,generator,0,2);
    }
     else if (SYSnumber==30 ){
     TH1 *tt=stackShapes(TargetName,generator,8,SYSnumber);
     TH1 *nontt=stackShapes(TargetName,generator,0,2);
    }
     else if (SYSnumber==31 ){
     TH1 *tt=stackShapes(TargetName,generator,0,SYSnumber);
     TH1 *nontt=stackShapes(TargetName,generator,0,2);
    }
    else if (SYSnumber==100) {
     TH1 *tt=stackShapes(TargetName,generator,0,1);
     tt->Scale(0.973);//1-0.027
     TH1 *nontt=stackShapes(TargetName,generator,0,2);
     nontt->Scale(0.973);//1-0.027
     } 
    else if (SYSnumber==101) {
     TH1 *tt=stackShapes(TargetName,generator,0,1);
     tt->Scale(1.027);
     TH1 *nontt=stackShapes(TargetName,generator,0,2);
     nontt->Scale(1.027);
     } 
     else if (SYSnumber==102) {
     TH1 *tt=stackShapes(TargetName,generator,0,1);
     tt->Scale(0.935);  //1-0.065
     TH1 *nontt=stackShapes(TargetName,generator,0,2);
     } 
    else if (SYSnumber==103) {
     TH1 *tt=stackShapes(TargetName,generator,0,1);
     tt->Scale(1.065);
     TH1 *nontt=stackShapes(TargetName,generator,0,2);
     } 
 
    THStack *Target;	
    Target= new THStack("Target","");
    
    Target->Add(tt);  
    Target->Add(nontt);  


    TH1 *resultTarget = Target->GetStack()->Last();
    
    //subtract the nominal stack
    resultTarget ->Add(sum_Target,-1);
  
    //squared uncertainty
    resultTarget->Multiply(resultTarget);
    
    
    //return the squared uncertainty
    return resultTarget;

}//end spitSYS


