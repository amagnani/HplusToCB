#include <TH1F.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <fstream>
#include <vector>

TH1F *pileup_weight; TH1F *test;

void PUWeight(){
  
    
     //Getting data Nvertex distribution------------------------------------------------------ 
     Char_t Filename0[100];
     sprintf(Filename0,"MyDataPileupHistogram.root");
     TFile *f0 = new TFile(Filename0);
     TH1 *pileup_weight_init  = (TH1*)f0->Get("pileup");
      
     pileup_weight= new TH1F("pileup_weight","Nvertex",70,0,70);     
     double f=0;
     for(int b=1;b<71;b++){
       f=pileup_weight_init->GetBinContent(b);
       pileup_weight->Fill(b-1,f);
     }
	
    //INITIALIZATIONS
    
    char inputFiles[50]        ="UNDEF";
    char outputTag[50]         ="UNDEF";
    // Reading initialization parameters from hplus.ini file
    FILE *fINI;
    float value;
    char str[50];
    // double dvalue;
    char filename[50],sdummy[200],sflag[30];
    sprintf(filename,"../hplus_QCD.ini");

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

	//Getting MC Nvertex distribution--------------------------------------------------------- 
	Char_t Filename[100];
  	sprintf(Filename,"Pileup_%s.root",outputTag);
 	TFile *f1   = new TFile(Filename);
	TH1 *pileup_MC  = (TH1*)f1->Get("pileup");
        
	//Initializing output file----------------------------------------------------------------
	Char_t filename[100];
	sprintf(filename,"PUweight_%s.root",outputTag);
	TFile *fHistos;
	fHistos = new TFile(filename,"RECREATE"); //______________________________________________
        
	const double nevent= pileup_weight->Integral();
	const double neventBkg= pileup_MC->Integral();
        pileup_weight->Scale(1/nevent);
        pileup_MC->Scale(1/neventBkg);
	
        pileup_weight->Divide(&(*pileup_MC));
  	pileup_weight->Write();
	
	
	//TEST
	test  =new TH1F("test","Nvertex",70,0,70);
        for(int b=1;b<71;b++){
	f=pileup_weight->GetBinContent(b);
	test->Fill(b-1,f);
	cout<<f<<endl;
         }
	test->Multiply(&(*pileup_MC));
	test->Write();
	//______________________________________________
        fHistos->Close();
        
	ofstream PUout;
	char PUstring[20];
        sprintf(PUstring,"PUbin_%s.txt",outputTag);
        PUout.open(PUstring);
	float *PUbin = pileup_weight->GetArray();
        for(int b=0;b<70;b++){
	//PUout<<PUbin[b]<<endl;
	cout<<PUbin[b]<<endl;
         }

gApplication->Terminate();
}
