	void drawVariation( const   TH1 * nominal,  const TH1  *up, const  TH1  *down, int histoType ){  

    up	->SetLineColor(kRed);   
    down->SetLineColor(kBlue);  
    nominal->SetLineColor(kBlack);  
    up	->SetLineWidth(2);   
    down->SetLineWidth(2);  
    nominal->SetLineWidth(2);  

    if(histoType==1){ up ->SetTitle("signal m=120 GeV");}
    else if (histoType==2){ up ->SetTitle("tt background");}
    else if (histoType==3){ up ->SetTitle("non tt background");}
    
    float max1=std::max(up->GetMaximum(),  down->GetMaximum());
    float max =std::max(max1,  nominal->GetMaximum());
    
    if(histoType==3){up        ->GetYaxis()->SetRangeUser(0,max+1);}
    else {up        ->GetYaxis()->SetRangeUser(0,max+10);}
    up        ->GetXaxis()->SetTitle("di-jet invariant mass (GeV)");
    up        ->GetXaxis()->SetTitleSize(0.05);
    up        ->GetXaxis()->SetLabelSize(0.05);
    up        ->GetYaxis()->SetLabelSize(0.05);
    up        ->SetMarkerSize(20);
    up        ->Draw();
    down      ->Draw("same");
    nominal   ->Draw("same");
			
	}
	
	void drawVariation( const   TH1 * nominal,  const TH1  *var, int histoType ){  
    var	->SetLineColor(kRed);   
    nominal->SetLineColor(kBlack);  
    var	->SetLineWidth(2);   
    nominal->SetLineWidth(2);  

    if(histoType==1){ var ->SetTitle("signal m=120 GeV");}
    else if (histoType==2){ var ->SetTitle("tt background");}
    else if (histoType==3){ var ->SetTitle("non tt background");}
    
    float max =std::max(var->GetMaximum(),  nominal->GetMaximum());
    
    if(histoType==1){var        ->GetYaxis()->SetRangeUser(0,max+1);}
    else {var        ->GetYaxis()->SetRangeUser(0,max+10);}
    var        ->GetYaxis()->SetRangeUser(0,max+5);
    var        ->GetXaxis()->SetTitle("di-jet invariant mass (GeV)");
    var        ->GetXaxis()->SetTitleSize(0.05);
    var        ->GetXaxis()->SetLabelSize(0.05);
    var        ->GetYaxis()->SetLabelSize(0.05);
    var        ->SetMarkerSize(20);
    var        ->Draw();
    nominal   ->Draw("same");
			
	}
