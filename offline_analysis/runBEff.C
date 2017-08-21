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

void runBEff()
{
 
    //INITIALIZATIONS
    
    char inputFiles[100]        ="UNDEF";
    char outputTag[100]         ="UNDEF";
    // Reading initialization parameters from hplus.ini file
    FILE *fINI;
    float value;
    char str[100];
    double num;
    // double dvalue;
    char filename[100],sdummy[400],sflag[60];
    sprintf(filename,"init/hplus_TTJetsSplit_scaledown.ini"); 
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
 
    fclose(fINI);
    
    //Recording the input file
    char command[50];
    sprintf(command,"cp hplus.ini output/hplus.ini_%s",outputTag);
    system(command);
   
   
   //Load files
   char element[600];
   TChain ch_analyzeStart("analyzeStart/HplusGenPartTree");
   
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
	}
	sprintf(element,"check");
    }
    
     //Close file
    inFile.close();
    
 
   cout<<"Let's start..."<<endl; 
  
  //loading output file
   Char_t histofile[100];
   sprintf(histofile,"efficiency/BTagEff2_%s.root",outputTag);
   TFile *fHistos;
   fHistos = new TFile(histofile,"RECREATE");
   
  
//    cout<<"Gen particles"<<endl; 
 int flag =0;   //1 for data, 0 for MC
  
 char extS[10];
sprintf(extS,"S");

 cout<<"starting "<<endl;

   gROOT->ProcessLine(".L BEff.C");
   TTree *rrS = (TTree*) ch_analyzeStart;
   BEff *rr = new BEff(rrS);
   rr->Loop(fHistos, extS, flag, outputTag  );

gApplication->Terminate();
}
