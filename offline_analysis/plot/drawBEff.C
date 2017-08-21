//***********************************************************
//******drawing the histograms from the Hplus.C macro******
//***********************************************************

	     
 void drawBEff(){
   
    
// Reading initialization parameters from hplus.ini file
    char  inputFiles[50]       ="UNDEF";
    char  outputTag[50]        ="UNDEF";
     FILE *fINI;
    float value;
    char str[50];
   // double dvalue;
    char filename[50],sdummy[200],sflag[30];
    sprintf(filename,"../init/hplus_TTJetsSplit.ini");

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
 
    
   //--------------------------------------------------------------------
	//Opening the root file  
	Char_t filename[100];
	sprintf(filename,"../efficiency/BTagEff_%s.root",outputTag);
	TFile *fname = TFile::Open(filename);
	
	gROOT->Reset();
	gROOT->ProcessLine(".L tdrstyle.C");
	setTDRStyle();
	gStyle->SetOptStat(0);
	gStyle->SetPalette(1);
	
	Float_t ymax;
	
	//setting figures names
	char btag[100];			sprintf(btag,"btag_%s.png",outputTag);
	char btagW[100];		sprintf(btagW,"btagW_%s.png",outputTag);


//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
       TCanvas *Cut;
       Cut = new TCanvas("Cut","BtagEff",1200,800);
       Cut->Divide(3,2);
       
       Cut->cd(1);
        Uh2_BTaggingEff_bS->SetTitle("b-jets tagging efficiency");
       Uh2_BTaggingEff_bS->SetMaximum(0.9);
       Uh2_BTaggingEff_bS->GetYaxis()->SetNdivisions(505);
        Uh2_BTaggingEff_bS->SetMinimum(0.2);
       Uh2_BTaggingEff_bS->GetYaxis()->SetTitleOffset(0.3);
       Uh2_BTaggingEff_bS->GetXaxis()->SetTitleOffset(1.2);
       Uh2_BTaggingEff_bS->Draw("colz");
       Cut->cd(2);
       Uh2_BTaggingEff_cS->SetTitle("c-jets mistagging efficiency");
       Uh2_BTaggingEff_cS->SetMaximum(0.5);
       Uh2_BTaggingEff_cS->SetMinimum(0);
       Uh2_BTaggingEff_cS->GetYaxis()->SetNdivisions(505);
        Uh2_BTaggingEff_cS->GetYaxis()->SetTitleOffset(0.3);
        Uh2_BTaggingEff_cS->GetXaxis()->SetTitleOffset(1.2);
       Uh2_BTaggingEff_cS->Draw("colz");
       Cut->cd(3);
        Uh2_BTaggingEff_udsgS->SetTitle("light jets mistagging efficiency");
       Uh2_BTaggingEff_udsgS->GetYaxis()->SetNdivisions(505);
       Uh2_BTaggingEff_udsgS->SetMaximum(0.2);
        Uh2_BTaggingEff_udsgS->GetYaxis()->SetTitleOffset(0.3);
        Uh2_BTaggingEff_udsgS->GetXaxis()->SetTitleOffset(1.2);
       Uh2_BTaggingEff_udsgS->SetMinimum(0);
       Uh2_BTaggingEff_udsgS->Draw("colz");
      
       Cut->SaveAs(btag);
       
	
  	

}//end drawHplus
