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


	     
 void drawPt(){
 
   gROOT->LoadMacro("tdrstyle.C");
   gStyle->SetOptStat(0);

      
 //Load Files
  TFile *f = new TFile("../output/pt_H120.root","READ");
  
 
 //LOAD HISTOGRAMS
   TH1 *topb         	= (TH1*)f->Get("topb");
   TH1 *antitopb    	= (TH1*)f->Get("antitopb");
   TH1 *b     		= (TH1*)f->Get("b");
   TH1 *c     		= (TH1*)f->Get("c");


	topb  	->GetXaxis()->SetTitle("pt (GeV)");  
	topb  	->GetYaxis()->SetTitle("a.u.");  
	topb  	->GetYaxis()->SetTitleOffset(1.2);  

	topb  	->SetLineColor(kBlue);  
	antitopb->SetLineColor(kGreen+1);
	b   	->SetLineColor(kOrange+7);  	
	c  	->SetLineColor(kOrange-2);   	
	topb  	->SetTitle("");
	antitopb->SetTitle("");
	b   	->SetTitle("");	    
	c  	->SetTitle("");	

// 	topb  	->SetLabelSize(0.05);
// 	antitopb->SetLabelSize(0.05);
// 	b   	->SetLabelSize(0.05);
// 	c  	->SetLabelSize(0.05);

// 	topb  	->GetYaxis()->SetLabelSize(0.5);
// 	antitopb->GetYaxis()->SetLabelSize(0.5);
// 	b   	->GetYaxis()->SetLabelSize(0.5); 
// 	c  	->GetYaxis()->SetLabelSize(0.5);

// 	topb  	->GetYaxis()->SetTitleSize(0.);
// 	antitopb->GetYaxis()->SetTitleSize(0.);
// 	b   	-> GetYaxis()->SetTitleSize(0.);
// 	c  	->GetYaxis()->SetTitleSize(0.);

// 	topb  	->GetXaxis()->SetTitleSize(0.05);
// 	antitopb->GetXaxis()->SetTitleSize(0.05);
// 	b   	-> GetXaxis()->SetTitleSize(0.05);
// 	c  	->GetXaxis()->SetTitleSize(0.05);

	    
topb->SetLineWidth(2);  	
antitopb->SetLineWidth(2);
b ->SetLineWidth(2);  	
c ->SetLineWidth(2); 		
  
     TLegend *leg;
     
     leg= new TLegend(0.6,0.6,0.89,0.89);
     leg->SetBorderSize(0);
     leg->SetLineColor(0);
     leg->SetLineStyle(0);
     leg->SetLineWidth(0);
     leg->SetFillColor(0);
     leg->SetFillStyle(1001);
     leg->AddEntry(topb,"b-jet from had top","f");
     leg->AddEntry(antitopb,"b-jet from lep top","f");
     leg->AddEntry(b,"b-jet from H+","f");
     leg->AddEntry(c,"c-jet from H+","f");
    // leg->AddEntry("H+ 120 GeV");

      
  
  KinFit2 = new TCanvas("KinFit2","Kinematic fit 9",800,800);
topb  	->Draw();
antitopb->Draw("same");
b   	->Draw("same");
c  	->Draw("same");  
leg->Draw();
  
 
}//end drawHplus
