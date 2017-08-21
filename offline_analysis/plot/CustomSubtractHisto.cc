	TH1F * CustomSubtractHisto(const char * TargetName, const TH1 * h1, const TH1 * h2){
	
	//h1= background
	//h2=data
	
		TH1F * Target;
		//First we see what is the histogram with the lower number of bins;i
		int nBins=h1->GetNbinsX();
		
		//Now we create a new histogram;
		Target=new TH1F(TargetName, TargetName, nBins, h1->GetBinLowEdge(1), h1->GetBinLowEdge(nBins)+h1->GetBinWidth(1));
		for(int i=1; i<=nBins+1; i++){
                        float ratio=0;
			std::cout << "Bin: " << i << " Sim: " << h1->GetBinContent(i) << " Data: " << h2->GetBinContent(i) << std::endl;
			float factor= (float)(h1->GetBinContent(i));
			if(factor!=0){
	  		    ratio=(float)(h2->GetBinContent(i))/(float)(h1->GetBinContent(i));
			} 
				Target->SetBinContent(i, ratio);
				
				//alice per la stima degli errori
				float ErrorOnRatio = (float)(h1->GetBinError(i)) / (float)(h2->GetBinContent(i)) ; 
                                //float ErrorOnRatio = 0.5 ; 
				
Target->SetBinError(i, ErrorOnRatio);
		 }
			
			//if(Target->GetBinContent(i)<999){
			//	float ErrorOnRatio = h1->GetBinError(i) / h2->GetBinContent(i) - 
			//		h1->GetBinContent(i)/TMath::Power(h2->GetBinContent(i), 2) * h2->GetBinError(i);
			//	Target->SetBinError(i, ErrorOnRatio);
			//} else {
			//	Target->SetBinError(i, 1000);
			//}



		
		return Target;
	}
	
