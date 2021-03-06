// -*- C++ -*-
//
// Package:    HplusAnalyzer_ttSignal
// Class:      HplusAnalyzer_ttSignal
// 
/**\class HplusAnalyzer_ttSignal HplusAnalyzer_ttSignal.cc HplusAnalysis/HplusAnalyzer_ttSignal/src/HplusAnalyzer_ttSignal.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Alice Magnani,,,
//         Created:  Fri Jan 15 10:59:18 CET 2016
// $Id$
//
//


#include "../interface/HplusAnalyzer_ttSignal.h"

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
// HplusAnalyzer_ttSignal::HplusAnalyzer_ttSignal(const edm::ParameterSet& params)
// 
// {
//    //now do what ever initialization is needed
// 
// }


HplusAnalyzer_ttSignal::~HplusAnalyzer_ttSignal()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
HplusAnalyzer_ttSignal::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  using namespace std;
  using namespace reco;
 //______________________________________________________________________________________


  float Tnpv = -1;
  int BX;
  lumiWeight=1;

  //HANDLES
  Handle< vector<pat::Jet> > handleJetForMCcat_; 
  iEvent.getByLabel("ttJets", handleJetForMCcat_);
  //iEvent.getByLabel("selectedPatJetsPFlow", handleJetForMCcat_);
  Handle< vector<pat::Jet> > handleJet_; 
  iEvent.getByLabel("goodJets", handleJet_);
  Handle< vector<pat::Muon> > handleMuon_;
  iEvent.getByLabel("tightMuons", handleMuon_);
  Handle< vector<reco::GenParticle> > handleGenPart_;
  iEvent.getByLabel("prunedGenParticles", handleGenPart_);
  Handle< vector<pat::Jet> > handlebJet_; 
  iEvent.getByLabel("bJets", handlebJet_);
  Handle< vector<pat::Jet> > handleloosebJet_; 
  iEvent.getByLabel("loosebJets", handleloosebJet_);
  Handle< vector<pat::Muon> > handleVetoMuon_;
  iEvent.getByLabel("vetoMuons", handleVetoMuon_);
  Handle< vector<pat::Electron> > handleEle_;
  iEvent.getByLabel("vetoElecs", handleEle_);
  Handle< vector<pat::MET> > handleMET_;
  iEvent.getByLabel("goodMETs", handleMET_);
  Handle< vector<reco::Vertex> > handleVertex_;
  iEvent.getByLabel("goodOfflinePrimaryVertices", handleVertex_);
  
  
 //Gen Particles initialization
  run=0; luminosityBlock=0; event=0; 
  
  MCcat=0;
 
  GenPart_daughterQuarkBarofHplus_pdgId=0;
  GenPart_daughterQuarkofHplus_pdgId=0;

  GenPart_top_pt=0;  GenPart_topBar_pt=0;
  GenPart_Hplus_mass=0;
  
  GenPart_Hmass=0;
  GenPart_Wmass=0;
  GenPart_Tmass=0;
  GenPart_formule_Tmass=0;
  GenPart_Tbarmass=0;
  

  vector<reco::GenParticle> Hdecay;
  vector<reco::GenParticle> Wdecay;
  vector<reco::GenParticle> Tdecay;
  vector<reco::GenParticle> Tbardecay;
  reco::GenParticle Hh; //generated Higgs
  reco::GenParticle gpart;
  
  TopJet_pt.clear();
  TopJet_eta.clear();
  TopJet_csv.clear();
  WJet_pt.clear();
  WJet_eta.clear();
  WJet_csv.clear();
  AddJet_pt.clear();
  AddJet_eta.clear();
  AddJet_csv.clear();


//--------------------------------------------------------------------------------------------------------------

  MatchJet_Hmass=0;
  MatchJet_Tmass=0;
  MatchJet_formule_Tmass=0;
  MatchJet_jetflag=0;
 
  MatchJet_daughterQuarkofTop_index=99999;
  MatchJet_daughterQuarkofTop_pt=99999; MatchJet_daughterQuarkofTop_recOverGenPt=99999; MatchJet_daughterQuarkofTop_eta=99999; MatchJet_daughterQuarkofTop_phi=99999;
  MatchJet_daughterQuarkofTop_bDiscrCSV=99999; 
 
  MatchJet_daughterQuarkofTopBar_index=99999;
  MatchJet_daughterQuarkofTopBar_pt=99999; MatchJet_daughterQuarkofTopBar_recOverGenPt=99999; MatchJet_daughterQuarkofTopBar_eta=99999; MatchJet_daughterQuarkofTopBar_phi=99999;
  MatchJet_daughterQuarkofTopBar_bDiscrCSV=99999; 

  MatchJet_daughterQuarkofHplus_index=99999;
  MatchJet_daughterQuarkofHplus_pt=99999; MatchJet_daughterQuarkofHplus_recOverGenPt=99999; MatchJet_daughterQuarkofHplus_eta=99999; MatchJet_daughterQuarkofHplus_phi=99999;
  MatchJet_daughterQuarkofHplus_bDiscrCSV=99999; 

  MatchJet_daughterQuarkBarofHplus_index=99999;
  MatchJet_daughterQuarkBarofHplus_pt=99999; MatchJet_daughterQuarkBarofHplus_recOverGenPt=99999; MatchJet_daughterQuarkBarofHplus_eta=99999; MatchJet_daughterQuarkBarofHplus_phi=99999;
  MatchJet_daughterQuarkBarofHplus_bDiscrCSV=99999; 


 
  pat::Jet jet;  
  vector<pat::Jet> Hjets;  
  pat::Jet Tbjet; //b jet coming from the top
  pat::Jet iijet;
  vector<int> jetpdg;
  vector<unsigned int> jetorder;
  int tbarjetf=0; int tjetf=0; 
  

  unsigned int nMuon= handleMuon_->size();
 

//___________________________________________________________________________________________________________


  nLep=0;
  
  nJet=4;  //used for dimension of vectors
  realnJet=0;
  Jpt.clear(); Jp.clear(); Jeta.clear(); Jphi.clear(); Jtheta.clear();
  Jpx.clear(); Jpy.clear(); Jpz.clear();
  JbDiscr.clear(); Jenergy.clear(); Jcharge.clear(); Jflavor.clear();
  
  METpt=0; METpx=0; METpy=0; METeta=0, METphi=0, METtheta=0;
  
  nVertex=0;
  nSimVertex=0;

  
  
  
  pat::Muon mu;  
  pat::Muon firstMuon; 
  pat::Jet mj;
  Int_t muflag=0;
  float chargedIso;
  float neutralIso;
  float photonIso; 
  
  pat::Electron ele;
  
  reco::Vertex vertex;
  
 
  pat::MET met;  

  vector<float> METpz;

   
  nLep=handleVetoMuon_->size()+handleEle_->size();

//___________________________________________________________________________________________________________
 
  KinFit_isValid=0;
 
  KinFit_prob.clear(); KinFit_chi2.clear();
  KinFit_lightP_index.clear(); KinFit_lightQ_index.clear(); KinFit_hadB_index.clear();
  KinFit_lepB_index.clear(); KinFit_lepton_index.clear();
  KinFit_hadW_mass.clear(); KinFit_hadW_pt.clear(); KinFit_hadW_eta.clear();KinFit_hadW_phi.clear();
  KinFit_lepW_mass.clear(); KinFit_lepW_pt.clear(); KinFit_lepW_eta.clear(); KinFit_lepW_phi.clear();
  KinFit_hadTop_mass.clear(); KinFit_hadTop_pt.clear(); KinFit_hadTop_eta.clear(); KinFit_hadTop_phi.clear();
  KinFit_lepTop_mass.clear(); KinFit_lepTop_pt.clear(); KinFit_lepTop_eta.clear(); KinFit_lepTop_phi.clear();
 
  KinFit_hadQuark_pt.clear(); KinFit_hadQuark_eta.clear(); KinFit_hadQuark_phi.clear();
  KinFit_hadQuarkBar_pt.clear(); KinFit_hadQuarkBar_eta.clear(); KinFit_hadQuarkBar_phi.clear();
  KinFit_hadB_pt.clear(); KinFit_hadB_eta.clear(); KinFit_hadB_phi.clear();
  KinFit_lepB_pt.clear(); KinFit_lepB_eta.clear(); KinFit_lepB_phi.clear();
  KinFit_prob.clear();
  KinFit_chi2.clear();

  

  
 const reco::Candidate* KinFit_lepTop;  
 const reco::Candidate* KinFit_lepW; 
 const reco::Candidate* KinFit_hadTop;  
 const reco::Candidate* KinFit_hadW; 
 const reco::Candidate* KinFit_hadQuark;
 const reco::Candidate* KinFit_hadQuarkBar;
 const reco::Candidate* KinFit_hadB;
 const reco::Candidate* KinFit_lepB;


//___________________________________________________________________________________________________________
  luminosityBlock=iEvent.luminosityBlock();
  run=iEvent.id().run();
  event=iEvent.id().event();
  
  //Filling GenPart variables
  

  //REMOVE GEN Wbb and Zbb events from WJets and ZJets samples
  if  (sampleFlag_=="WZJets" ) { 
    int bnumber=0;
    for(unsigned int igen = 0; igen < handleGenPart_->size(); igen++) {
      gpart = handleGenPart_->at(igen);
      if (gpart.status()==3 && abs(gpart.pdgId())==5) bnumber ++;
    } 

    if(bnumber==2 || (bnumber>2)){
      //cout<<"strange bnumber "<<bnumber<<endl;
      return;
     }
   

 if(bnumber==2) cout<<"Evento Wbb o Zbb, non dovrebbe essere qui"<<endl;
}
  //end REMOVE GEN Wbb and Zbb events from WJets and ZJets samples



   //STUDY Wbb Zbbb Backgound (temporary)
// 
//   if  (sampleFlag_=="Bkg" ) { 
//   cout<<"init event"<<endl;
//     for(unsigned int igen = 0; igen < handleGenPart_->size(); igen++) {
//       gpart = handleGenPart_->at(igen);
//      const Candidate* mot = gpart.mother();
//       if ((gpart.status()==3) && (abs(gpart.pdgId())==5 ) && (mot!=0) && ((*mot).pdgId()!=21)) cout<<" voglio andare a vivere in campagna "<<(*mot).pdgId()<<endl;
//       if ((gpart.status()==3) && (abs(gpart.pdgId())!=5)&& (mot!=0) &&((*mot).pdgId()==21 )) cout<<" chi sei "<<gpart.pdgId()<<endl;
//     } 
//  
// }
 
 
    //end STUDY Wbb Zbbb Backgound (temporary)

 
 if  (sampleFlag_=="MCsignal" || sampleFlag_=="MCttbar" ) { 

 //set particle in hadronic branch
 int hadID=0;
 if(sampleFlag_=="MCsignal" ) {hadID=37;}
 else {hadID=24;}
  

   for(unsigned int igen = 0; igen < handleGenPart_->size(); igen++) {
     gpart = handleGenPart_->at(igen);
     //get the particle's mother
     const Candidate* mot = gpart.mother();
         
      //if mother exsists
      if(mot!=0){ 
	     
	 // get the top quark
	if(gpart.pdgId()==6 && gpart.status()==3){
	  GenPart_top_pt=gpart.pt(); 
	}
    
       // get the topbar quark
       if(gpart.pdgId()==-6 && gpart.status()==3){
	 GenPart_topBar_pt=gpart.pt();
      }
 
       // get the W-
       if(gpart.pdgId()==-24 && gpart.status()==3){
      Tbardecay.push_back(gpart);
       }
 
	// get the H+
       if(gpart.pdgId()==hadID && gpart.status()==3){
	 GenPart_Hplus_mass=gpart.mass();
      Hh=gpart;
      Tdecay.push_back(gpart);
       }
    
	// get the  daughter quark of top
	if((*mot).pdgId()==6 && fabs(gpart.pdgId())<6 && gpart.status()==3){
       Tdecay.push_back(gpart);
	}
 
	// get the  daughter quark of topbar
	if((*mot).pdgId()==-6 && fabs(gpart.pdgId())<6 && gpart.status()==3){
       Tbardecay.push_back(gpart);
	}
	
	// get the  daughter quark of WMinus
	if((*mot).pdgId()==-24 && gpart.pdgId()>0 && gpart.pdgId()<6 && gpart.status()==3){
       Wdecay.push_back(gpart);
	}
	
	// get the  daughter quarkbar of WMinus
	if((*mot).pdgId()==-24 && gpart.pdgId()<0 && gpart.pdgId()>-6 && gpart.status()==3){
      Wdecay.push_back(gpart);
	}
   
	// get the  daughter quark of Hplus
	if((*mot).pdgId()==hadID && gpart.pdgId()>0 && gpart.status()==3){
	  GenPart_daughterQuarkofHplus_pdgId=gpart.pdgId(); 
	  
	//  if (abs(GenPart_daughterQuarkofHplus_pdgId )==5) cout<<"bjet "<<event<<endl;
	  
       Hdecay.push_back(gpart); 
       }

	// get the  daughter quarkbar of Hplus
	if((*mot).pdgId()==hadID && gpart.pdgId()<0 && gpart.status()==3){
	  GenPart_daughterQuarkBarofHplus_pdgId=gpart.pdgId(); 

	//  if (abs(GenPart_daughterQuarkBarofHplus_pdgId )==5) cout<<"bjet "<<event<<endl;

      Hdecay.push_back(gpart);
	}
    
 	// get the lepton from W
	if((*mot).pdgId()==-24 && (gpart.pdgId()==11 || gpart.pdgId()==13 || gpart.pdgId()==15) && gpart.status()==3){
       Wdecay.push_back(gpart);
      }
    
	 // get the neutrino from W
	if((*mot).pdgId()==-24 && (gpart.pdgId()==-12 || gpart.pdgId()==-14 || gpart.pdgId()==-16) && gpart.status()==3){
       Wdecay.push_back(gpart);
	}     
        
// 	//STORING b quarks at gen level
//         if( abs(gpart.pdgId())==5 ) {
//        
//       	GenPart_bJetMom.push_back((*mot).pdgId()); 
//       	GenPart_bJetPt.push_back(gpart.pt());  
//       	GenPart_bJetEta.push_back(gpart.eta());  
//       	GenPart_bJetPhi.push_back(gpart.phi());       
//      
//        }
//  

    }//end if mother exists 
   
   }//end loop on genparticles

 GenPart_Hmass=(Hdecay[0].p4()+Hdecay[1].p4()).M();
 GenPart_Wmass=(Wdecay[0].p4()+Wdecay[1].p4()).M();
 GenPart_Tmass=(Tdecay[0].p4()+Tdecay[1].p4()).M();
  
   GenPart_formule_Tmass=sqrt((Tdecay[0].energy()+Tdecay[1].energy())*(Tdecay[0].energy()+Tdecay[1].energy())
			 -(Tdecay[0].px()+Tdecay[1].px())*(Tdecay[0].px()+Tdecay[1].px())
			 -(Tdecay[0].py()+Tdecay[1].py())*(Tdecay[0].py()+Tdecay[1].py())
			 -(Tdecay[0].pz()+Tdecay[1].pz())*(Tdecay[0].pz()+Tdecay[1].pz())
			 );
  
  GenPart_Tbarmass=(Tbardecay[0].p4()+Tbardecay[1].p4()).M();


//___________________________________________________________________________________________
 
  for(unsigned int igen = 0; igen < handleGenPart_->size(); igen++) {
	gpart = handleGenPart_->at(igen);
	// get the H+
       if(gpart.pdgId()==hadID && gpart.status()==3){
      Hh=gpart;
       }
     }
 
   //T Invariant mass using gen H+ and the pat jet matched with with the gen jet coming from t
   
     for(unsigned int ijet=0; ijet<handleJet_->size(); ijet++){
      
       jet = handleJet_->at(ijet); 
       
       
       //get matched parton
       const reco::GenParticle *parton=jet.genParton();
       
       if(parton!=0) {  	 
       //get the mother of the matched parton
       const reco::Candidate *jmot=(*parton).mother();
       
       if(jmot!=0) {
       
	 
      //get the c-jet
      if((*jmot).pdgId()==hadID && (*parton).pdgId()>0){
	  
	Hjets.push_back(jet); 
	//jetpdg.push_back((*parton).pdgId());
	//jetorder.push_back(ijet); 
	MatchJet_jetflag=MatchJet_jetflag+1000*ijet;
	MatchJet_daughterQuarkofHplus_index=ijet;
	MatchJet_daughterQuarkofHplus_pt=jet.pt();
	MatchJet_daughterQuarkofHplus_recOverGenPt=jet.pt()/(*parton).pt();
	MatchJet_daughterQuarkofHplus_eta=jet.eta();
	MatchJet_daughterQuarkofHplus_phi=jet.phi();
	MatchJet_daughterQuarkofHplus_bDiscrCSV=jet.bDiscriminator("combinedSecondaryVertexBJetTags");
       	
      }
 
	  if((*jmot).pdgId()==hadID && (*parton).pdgId()<0){
	  
	Hjets.push_back(jet); 
	//jetpdg.push_back((*parton).pdgId());
	//jetorder.push_back(ijet); 
	MatchJet_jetflag=MatchJet_jetflag+100*ijet;
	MatchJet_daughterQuarkBarofHplus_index=ijet;
	MatchJet_daughterQuarkBarofHplus_pt=jet.pt();
	MatchJet_daughterQuarkBarofHplus_recOverGenPt=jet.pt()/(*parton).pt();
	MatchJet_daughterQuarkBarofHplus_eta=jet.eta();
	MatchJet_daughterQuarkBarofHplus_phi=jet.phi();
	MatchJet_daughterQuarkBarofHplus_bDiscrCSV=jet.bDiscriminator("combinedSecondaryVertexBJetTags");
       
      
      }
	
	  if((*jmot).pdgId()==6){
	 tjetf=1;
	 Tbjet=jet;
	 
	//jetpdg.push_back((*parton).pdgId());
	//jetorder.push_back(ijet); 
	MatchJet_jetflag=MatchJet_jetflag+10*ijet;
	MatchJet_daughterQuarkofTop_index=ijet;
	MatchJet_daughterQuarkofTop_pt=jet.pt();
	MatchJet_daughterQuarkofTop_recOverGenPt=jet.pt()/(*parton).pt();
	MatchJet_daughterQuarkofTop_eta=jet.eta();
	MatchJet_daughterQuarkofTop_phi=jet.phi();
	MatchJet_daughterQuarkofTop_bDiscrCSV=jet.bDiscriminator("combinedSecondaryVertexBJetTags");
       
       
       //Massa invariante tra gen H+ e jet proveniente da t 
		float jetTmass=(Tbjet.p4()+Hh.p4()).M();
	   MatchJet_Tmass=jetTmass; 
	float jet_formuleTmass=sqrt((Tbjet.energy()+Hh.energy())*(Tbjet.energy()+Hh.energy())
					    -(Tbjet.px()+Hh.px())*(Tbjet.px()+Hh.px())
					    -(Tbjet.py()+Hh.py())*(Tbjet.py()+Hh.py())
					    -(Tbjet.pz()+Hh.pz())*(Tbjet.pz()+Hh.pz())
				     );
				     
	   MatchJet_formule_Tmass=jet_formuleTmass; 
      
      }
       
	  if((*jmot).pdgId()==-6){
	  
	tbarjetf=1;
	MatchJet_jetflag=MatchJet_jetflag+ijet;
	MatchJet_daughterQuarkofTopBar_index=ijet;
	MatchJet_daughterQuarkofTopBar_pt=jet.pt();
	MatchJet_daughterQuarkofTopBar_recOverGenPt=jet.pt()/(*parton).pt();
	MatchJet_daughterQuarkofTopBar_eta=jet.eta();
	MatchJet_daughterQuarkofTopBar_phi=jet.phi();
	MatchJet_daughterQuarkofTopBar_bDiscrCSV=jet.bDiscriminator("combinedSecondaryVertexBJetTags");
       
      
      }
  
       }//end if mot  
	}//end if parton
  
     } //end loop on jets
    
     //fill invariant masses
     if(Hjets.size()==2){
	float jetHmass=(Hjets[0].p4()+Hjets[1].p4()).M();
	MatchJet_Hmass=jetHmass; 
      }
      
     if(Hjets.size()+tbarjetf+tjetf!=4) MatchJet_jetflag=99999;
    
    //********************************************************************************isolamento dal muone  

} //end if MCsignal or MCttbar



//**************************
//    MC categorization
//**************************

//categories: 	1 ttbb -
// 		2 ttbj - 
//		3 ttcc or ttcj  
//		4 ttqq -
//		5 all the rest


int Na=0;  //number of additional jets
int Nab=0; //number of additional b jets
int Nac=0; //number of additional c jets
MCcat=0; //
int additionalJets=1;
 
    for(unsigned int ijet=0; ijet<handleJetForMCcat_->size(); ijet++){
       
       additionalJets=1;
       jet = handleJetForMCcat_->at(ijet); 
       
       
       //get matched parton
       const reco::GenJet *gengiscan=jet.genJet();
       const reco::GenParticle *ppparton=jet.genParton();
       int partonFl=999;   
       //int partonFl=jet.partonFlavour(); //usata fino ad aprile
       //int hadronFl=jet.hadronFlavour();
    
       //se il get non ha un genjet associato non mi interessa
       if (gengiscan==0)  additionalJets=0;
       
       //se il jet viene dalla catena di decadimento del tt non mi interessa
       if(ppparton!=0) { 
       partonFl=(*ppparton).pdgId();
       //get the mother of the matched parton
       const reco::Candidate *jjjmot=(*ppparton).mother();
        if(jjjmot!=0) {
          if(  abs((*jjjmot).pdgId())==6 ){ additionalJets=0; TopJet_eta.push_back(jet.eta()); TopJet_pt.push_back(jet.pt()); TopJet_csv.push_back(jet.bDiscriminator("combinedSecondaryVertexBJetTags"));  }
	  if(  abs((*jjjmot).pdgId())==24  ||  abs((*jjjmot).pdgId())==37  ) { additionalJets=0; WJet_eta.push_back(jet.eta()); WJet_pt.push_back(jet.pt());  WJet_csv.push_back(jet.bDiscriminator("combinedSecondaryVertexBJetTags"));   }
       } }
       
       if (additionalJets) { Na++; AddJet_eta.push_back(jet.eta()); AddJet_pt.push_back(jet.pt()); AddJet_csv.push_back(jet.bDiscriminator("combinedSecondaryVertexBJetTags"));}
       if (additionalJets && abs(partonFl) ==5 ) Nab++;
       if (additionalJets && abs(partonFl) ==4 ) Nac++;
}
//decido la categoria	
if (Na>1 && Nab>1){ MCcat=1;  } //ttbb
if (Na>1 && Nab>0 && MCcat==0 ){ MCcat=2; } //ttbj
if (Na>1 && Nac>0 && MCcat==0){ MCcat=3; } //ttcc
if (Na>1 && MCcat==0){ MCcat=4; } //ttqq
if (MCcat==0){ MCcat=5; } //tt other


//**************************
//   end MC categorization
//**************************


//___________________________________________________________________________________________

 if(nMuon>0){
      mu = handleMuon_->at(0);
        firstMuon=mu;
	muflag=1;
  }
  else goto fill;
  
  vertex = handleVertex_->at(0);
  nVertex= handleVertex_->size();
  
   //se non ci sono muoni si passa al prossimo evento
     if(muflag==0){
      goodEvent=0;
      goto fill;
    }
     
   //parametri 
   MUpt = firstMuon.pt(); MUeta = firstMuon.eta(); MUphi = firstMuon.phi();
   MUtheta = firstMuon.theta(); 
   MUpx = firstMuon.px(); MUpy  = firstMuon.py();  MUpz  = firstMuon.pz(); 
   MUp = sqrt(MUpx*MUpx+MUpy*MUpy+MUpz*MUpz);

   //parameter for isolation cuts
   chargedIso = firstMuon.pfIsolationR04().sumChargedHadronPt;
   neutralIso = firstMuon.pfIsolationR04().sumNeutralHadronEt;
   photonIso = firstMuon.pfIsolationR04().sumPhotonEt;
   MUrelIso = (chargedIso + max(0., neutralIso + photonIso - 0.5 * firstMuon.pfIsolationR04().sumPUPt) ) /  MUpt; 

//INNER TRACK
  if(!firstMuon.innerTrack().isNull()){ 
   MUlayer = firstMuon.innerTrack()->hitPattern().trackerLayersWithMeasurement();
    MUnOfPixels= firstMuon.innerTrack()->hitPattern().numberOfValidPixelHits();
 } 
 else {
    MUlayer = -1;
    MUnOfPixels= -1;
 }
 //GLOBAL TRACK
  if(!firstMuon.globalTrack().isNull()){ 
      MUnormChi2=firstMuon.globalTrack()->normalizedChi2();
      MUnOfHits=firstMuon.globalTrack()->hitPattern().numberOfValidMuonHits();
  }
  else {
     MUnormChi2=-1;
     MUnOfHits=-1;
  }
    MUd0=fabs(firstMuon.dB());
//BEST TRACK
  if(!firstMuon.muonBestTrack().isNull()){ 
//    MUd0=fabs(firstMuon.muonBestTrack()->dxy(vertex.position()));
    MUdz=fabs(firstMuon.muonBestTrack()->dz(vertex.position()));
  } 
  else {
    cout<<"NO BEST TRACK"<<endl;
    MUd0=-1;
    MUdz=-1;
  }
  
     MUisGlobal=  firstMuon.isGlobalMuon();
     MUisPF=  firstMuon.isPFMuon();
     MUstations=  firstMuon.numberOfMatchedStations();
 
 //--------------------------------------------------------------------------jets

 
 //   if(handleJet_->size()<4) {
 //     goodEvent=0;
  //    goto fill;
  //  }
 
 realnJet= handleJet_->size();
 nbJet= handlebJet_->size();
 nbJetloose= handleloosebJet_->size();
  
 for(unsigned int l = 0; l< handleJet_->size(); l++){ 
   jet=handleJet_->at(l);
   Jpt.push_back(jet.pt()); Jeta.push_back(jet.eta()); Jphi.push_back(jet.phi());
   Jtheta.push_back(jet.theta());
   Jpx.push_back(jet.px()); Jpy.push_back(jet.py()); Jpz.push_back(jet.pz());
   Jp.push_back( sqrt(jet.px()*jet.px()+jet.py()*jet.py()+jet.pz()*jet.pz()));
   JbDiscr.push_back(jet.bDiscriminator("combinedSecondaryVertexBJetTags")); 
   Jcharge.push_back(jet.jetCharge());
   Jenergy.push_back(jet.energy());
   Jflavor.push_back(jet.partonFlavour());
 } 
  
 //--------------------------------------------------------------------------MET
   if(handleMET_->size()>0){
     met = handleMET_->at(0);
     METpt = met.pt(); METpx = met.px(); METpy = met.py();
     METeta = met.eta(); METphi = met.phi();
     METtheta = met.theta(); 
   }
   else goto fill;

fill:
//___________________________________________________________________________________________
 int countGoodcombs=0;
 
  if  ( stepFlag_=="9b" ) { 
  
  
  edm::Handle<TtSemiLeptonicEvent> semiLepEvt;
  iEvent.getByLabel("ttSemiLepEvent", semiLepEvt);

  ncomb= semiLepEvt->numberOfAvailableHypos("kKinFit");
  if (ncomb>0) KinFit_isValid=1;
 
  
   for (int h = 0; h < ncomb; ++h) {		 
    
    if (!semiLepEvt->isHypoValid("kKinFit", h)) break;
   

   KinFit_lepTop=semiLepEvt->leptonicDecayTop("kKinFit",h);
   KinFit_lepW=semiLepEvt->leptonicDecayW("kKinFit",h);
   KinFit_hadTop=semiLepEvt->hadronicDecayTop("kKinFit",h);
   KinFit_hadW=semiLepEvt->hadronicDecayW("kKinFit",h);
   KinFit_hadQuark=semiLepEvt->hadronicDecayQuark("kKinFit",h);
   KinFit_hadQuarkBar=semiLepEvt->hadronicDecayQuarkBar("kKinFit",h);
   KinFit_hadB=semiLepEvt->hadronicDecayB("kKinFit",h);
   KinFit_lepB=semiLepEvt->leptonicDecayB("kKinFit",h);
    

     //additional cuts to ignore very bad combinations
     if (semiLepEvt->fitChi2(h) >4.6) break;        //consider only solutions with fit probability at least 10-2 (true probability)
     //equivalent to if(TMath::Exp(-semiLepEvt->fitChi2(h))<0.01) break;

      countGoodcombs++;
  
   KinFit_chi2.push_back(semiLepEvt->fitChi2(h));
   KinFit_prob.push_back(semiLepEvt->fitProb(h)); 
  
   KinFit_lightP_index.push_back(semiLepEvt->jetLeptonCombination("kKinFit",h)[1]);
   KinFit_lightQ_index.push_back(semiLepEvt->jetLeptonCombination("kKinFit",h)[0]);
   KinFit_hadB_index.push_back(semiLepEvt->jetLeptonCombination("kKinFit",h)[2]);
   KinFit_lepB_index.push_back(semiLepEvt->jetLeptonCombination("kKinFit",h)[3]);
   KinFit_lepton_index.push_back(semiLepEvt->jetLeptonCombination("kKinFit",h)[4]);
   

   KinFit_hadW_mass.push_back(KinFit_hadW->mass()); KinFit_hadW_pt.push_back(KinFit_hadW->pt()); KinFit_hadW_eta.push_back(KinFit_hadW->eta());
   KinFit_hadW_phi.push_back(KinFit_hadW->phi());
   
   KinFit_lepW_mass.push_back(KinFit_lepW->mass()); KinFit_lepW_pt.push_back(KinFit_lepW->pt()); KinFit_lepW_eta.push_back(KinFit_lepW->eta());
   KinFit_lepW_phi.push_back(KinFit_lepW->phi());

   KinFit_hadTop_mass.push_back(KinFit_hadTop->mass()); KinFit_hadTop_pt.push_back(KinFit_hadTop->pt()); KinFit_hadTop_eta.push_back(KinFit_hadTop->eta());
   KinFit_hadTop_phi.push_back(KinFit_hadTop->phi());

   KinFit_lepTop_mass.push_back(KinFit_lepTop->mass()); KinFit_lepTop_pt.push_back(KinFit_lepTop->pt()); KinFit_lepTop_eta.push_back(KinFit_lepTop->eta());
   KinFit_lepTop_phi.push_back(KinFit_lepTop->phi());

   KinFit_hadQuark_pt.push_back(KinFit_hadQuark->pt());KinFit_hadQuark_eta.push_back(KinFit_hadQuark->eta()); KinFit_hadQuark_phi.push_back(KinFit_hadQuark->phi());
  
   KinFit_hadQuarkBar_pt.push_back(KinFit_hadQuarkBar->pt()); KinFit_hadQuarkBar_eta.push_back(KinFit_hadQuarkBar->eta()); KinFit_hadQuarkBar_phi.push_back(KinFit_hadQuarkBar->phi());
  
   KinFit_hadB_pt.push_back(KinFit_hadB->pt()); KinFit_hadB_eta.push_back(KinFit_hadB->eta()); KinFit_hadB_phi.push_back(KinFit_hadB->phi());
  
   KinFit_lepB_pt.push_back(KinFit_lepB->pt()); KinFit_lepB_eta.push_back(KinFit_lepB->eta()); KinFit_lepB_phi.push_back(KinFit_lepB->phi());



 } //loop sulle combinazioni 
   ncomb=countGoodcombs;
  } // per gli step che contemplano il fit
 

//___________________________________________________________________________________________

//PU REWEIGHTING

if ( sampleFlag_!="Data"){

 edm::LumiReWeighting LumiWeights_;
 edm::LumiReWeighting LumiWeights_up_;
 edm::LumiReWeighting LumiWeights_down_;
 std::vector< float > Summer2012 ;




 Double_t Summer2012_S10[60] = {
                         2.560E-06,
                         5.239E-06,
                         1.420E-05,
                         5.005E-05,
                         1.001E-04,
                         2.705E-04,
                         1.999E-03,
                         6.097E-03,
                         1.046E-02,
                         1.383E-02,
                         1.685E-02,
                         2.055E-02,
                         2.572E-02,
                         3.262E-02,
                         4.121E-02,
                         4.977E-02,
                         5.539E-02,
                         5.725E-02,
                         5.607E-02,
                         5.312E-02,
                         5.008E-02,
                         4.763E-02,
                         4.558E-02,
                         4.363E-02,
                         4.159E-02,
                         3.933E-02,
                         3.681E-02,
                         3.406E-02,
                         3.116E-02,
                         2.818E-02,
                         2.519E-02,
                         2.226E-02,
                         1.946E-02,
                         1.682E-02,
                         1.437E-02,
                         1.215E-02,
                         1.016E-02,
                         8.400E-03,
                         6.873E-03,
                         5.564E-03,
                         4.457E-03,
                         3.533E-03,
                         2.772E-03,
                         2.154E-03,
                         1.656E-03,
                         1.261E-03,
                         9.513E-04,
                         7.107E-04,
                         5.259E-04,
                         3.856E-04,
                         2.801E-04,
                         2.017E-04,
                         1.439E-04,
                         1.017E-04,
                         7.126E-05,
                         4.948E-05,
                         3.405E-05,
                         2.322E-05,
                         1.570E-05,
                         5.005E-06};

			 
std::vector< float > TrueDist2011;
std::vector< float > TrueDist2011_up;
std::vector< float > TrueDist2011_down;

    double TrueDist2011_f[60] = {
13531.5    ,
21824.9    ,
41057.6    ,
249375     ,
556933     ,
3.64488e+06,
2.02449e+07,
6.09322e+07,
1.43044e+08,
2.7625e+08 ,
4.71757e+08,
7.05494e+08,
8.86931e+08,
9.95894e+08,
1.06996e+09,
1.12383e+09,
1.15144e+09,
1.15618e+09,
1.15047e+09,
1.13586e+09,
1.11175e+09,
1.08239e+09,
1.05025e+09,
1.00951e+09,
9.5004e+08 ,
8.65895e+08,
7.60206e+08,
6.42339e+08,
5.22345e+08,
4.08583e+08,
3.07365e+08,
2.2243e+08 ,
1.54751e+08,
1.03333e+08,
6.61609e+07,
4.07415e+07,
2.43881e+07,
1.45026e+07,
8.86007e+06,
5.77937e+06,
4.13131e+06,
3.2326e+06 ,
2.70553e+06,
2.35647e+06,
2.09245e+06,
1.87106e+06,
1.67367e+06,
1.49242e+06,
1.32409e+06,
1.16753e+06,
1.02242e+06,
888685	   ,
766329	   ,
655326	   ,
555551	   ,
466746	   ,
388511	   ,
320315	   ,
261513	   ,
211371};

   double TrueDist2011_f_up[60] = {
12736	    ,
19974.4     ,
34759.7     ,
168674	    ,
485192	    ,
1.85955e+06 ,
1.23813e+07 ,
4.04781e+07 ,
9.876e+07   ,
1.99124e+08 ,
3.47748e+08 ,
5.50648e+08 ,
7.51601e+08 ,
8.88181e+08 ,
9.72565e+08 ,
1.03453e+09 ,
1.07834e+09 ,
1.0986e+09  ,
1.10089e+09 ,
1.09504e+09 ,
1.08136e+09 ,
1.05945e+09 ,
1.03293e+09 ,
1.00416e+09 ,
9.6895e+08  ,
9.18937e+08 ,
8.47995e+08 ,
7.56927e+08 ,
6.52564e+08 ,
5.43409e+08 ,
4.36934e+08 ,
3.39091e+08 ,
2.54039e+08 ,
1.83728e+08 ,
1.28143e+08 ,
8.60594e+07 ,
5.565e+07   ,
3.47935e+07 ,
2.12705e+07 ,
1.29822e+07 ,
8.15438e+06 ,
5.4492e+06  ,
3.95905e+06 ,
3.12366e+06 ,
2.62441e+06 ,
2.2921e+06  ,
2.04219e+06 ,
1.8344e+06  ,
1.65022e+06 ,
1.48144e+06 ,
1.3245e+06  ,
1.17798e+06 ,
1.04144e+06 ,
914731	    ,
797852	    ,
690802	    ,
593533	    ,
505909	    ,
427683	    ,
358500
};

    double TrueDist2011_f_down[60] = {
14431.4      ,
24008.9      ,
50968.8      ,
348054	     ,
756612	     ,
7.02321e+06  ,
3.24722e+07  ,
9.23709e+07  ,
2.06558e+08  ,
3.85003e+08  ,
6.33725e+08  ,
8.6826e+08   ,
1.01498e+09  ,
1.10577e+09  ,
1.17167e+09  ,
1.20875e+09  ,
1.21716e+09  ,
1.21175e+09  ,
1.19614e+09  ,
1.16947e+09  ,
1.13681e+09  ,
1.10058e+09  ,
1.05278e+09  ,
9.81329e+08  ,
8.81134e+08  ,
7.58614e+08  ,
6.26029e+08  ,
4.95049e+08  ,
3.74918e+08  ,
2.71971e+08  ,
1.88961e+08  ,
1.25551e+08  ,
7.96347e+07  ,
4.83004e+07  ,
2.82864e+07  ,
1.63559e+07  ,
9.69034e+06  ,
6.15218e+06  ,
4.3194e+06   ,
3.34989e+06  ,
2.79249e+06  ,
2.42473e+06  ,
2.1445e+06   ,
1.90739e+06  ,
1.69488e+06  ,
1.49956e+06  ,
1.31861e+06  ,
1.15116e+06  ,
997009	     ,
856125	     ,
728504	     ,
614043	     ,
512478	     ,
423365	     ,
346083	     ,
279862	     ,
223812	     ,
176962	     ,
138301	     ,
106809};
   
    
    
    
    for( int i=0; i<60; ++i) {
      TrueDist2011.push_back(TrueDist2011_f[i]);
      TrueDist2011_up.push_back(TrueDist2011_f_up[i]);
      TrueDist2011_down.push_back(TrueDist2011_f_down[i]);
      Summer2012.push_back(Summer2012_S10[i]);
    }

    LumiWeights_ = edm::LumiReWeighting(Summer2012, TrueDist2011); 
    LumiWeights_up_ = edm::LumiReWeighting(Summer2012, TrueDist2011_up); 
    LumiWeights_down_ = edm::LumiReWeighting(Summer2012, TrueDist2011_down); 
    
 
    
    Handle<std::vector< PileupSummaryInfo > >  PupInfo;
 iEvent.getByLabel(edm::InputTag("addPileupInfo"), PupInfo);

 std::vector<PileupSummaryInfo>::const_iterator PVI;

 for(PVI = PupInfo->begin(); PVI != PupInfo->end(); ++PVI) {

   BX = PVI->getBunchCrossing();

   if(BX == 0) { 
     Tnpv = PVI->getTrueNumInteractions();
     continue;
   }

} 

 lumiWeight = LumiWeights_.weight( Tnpv );
 lumiWeight_up = LumiWeights_up_.weight( Tnpv );
 lumiWeight_down = LumiWeights_down_.weight( Tnpv );
 nSimVertex = Tnpv;
 


} 



//___________________________________________________________________________________________


  HplusTree->Fill();
//  HplusGenPartTree->Print();
 
 


#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void 
HplusAnalyzer_ttSignal::beginJob()
{
      //external functions:
      std::vector<float> nuPz(float, float, float, float, float, float);
      edm::Service<TFileService> fs;
      
      HplusTree = fs->make<TTree>("HplusGenPartTree","HplusGenPartTree");
 
      HplusTree->Branch("run",&run,"run/I");
      HplusTree->Branch("luminosityBlock",&luminosityBlock,"luminosityBlock/I");
      HplusTree->Branch("event",&event,"event/I");

      HplusTree->Branch("lumiWeight",&lumiWeight,"lumiWeight/D");
      HplusTree->Branch("lumiWeight_up",&lumiWeight_up,"lumiWeight_up/D");
      HplusTree->Branch("lumiWeight_down",&lumiWeight_down,"lumiWeight_down/D");
     
      HplusTree->Branch("MCcat",&MCcat, "MCcat/i");
    
      HplusTree->Branch("GenPart_daughterQuarkBarofHplus_pdgId",&GenPart_daughterQuarkBarofHplus_pdgId, "GenPart_daughterQuarkBarofHplus_pdgId/I");
      HplusTree->Branch("GenPart_daughterQuarkofHplus_pdgId",&GenPart_daughterQuarkofHplus_pdgId, "GenPart_daughterQuarkofHplus_pdgId/I");

      HplusTree->Branch("GenPart_top_pt",&GenPart_top_pt, "GenPart_top_pt/F");
      HplusTree->Branch("GenPart_topBar_pt",&GenPart_topBar_pt, "GenPart_topBar_pt/F");
   
      HplusTree->Branch("GenPart_Hplus_mass",&GenPart_Hplus_mass, "GenPart_Hplus_mass/F");

      HplusTree->Branch("GenPart_Hmass",&GenPart_Hmass, "GenPart_Hmass/F");
      HplusTree->Branch("GenPart_Wmass",&GenPart_Wmass, "GenPart_Wmass/F");
      HplusTree->Branch("GenPart_Tmass",&GenPart_Tmass, "GenPart_Tmass/F");
      HplusTree->Branch("GenPart_formule_Tmass",&GenPart_formule_Tmass, "GenPart_formule_Tmass/F");
      HplusTree->Branch("GenPart_Tbarmass",&GenPart_Tbarmass, "GenPart_Tbarmass/F");

      
      pTopJet_pt=&TopJet_pt;
      pTopJet_eta=&TopJet_eta;
      pTopJet_csv=&TopJet_csv;
      pWJet_pt=&WJet_pt;
      pWJet_eta=&WJet_eta;
      pWJet_csv=&WJet_csv;
      pAddJet_pt=&AddJet_pt;
      pAddJet_eta=&AddJet_eta;
      pAddJet_csv=&AddJet_csv;    
     
      HplusTree->Branch("TopJet_pt",&pTopJet_pt);
      HplusTree->Branch("TopJet_eta",&pTopJet_eta);
      HplusTree->Branch("TopJet_csv", &pTopJet_csv);
      HplusTree->Branch("WJet_pt",&pWJet_pt);
      HplusTree->Branch("WJet_eta",&pWJet_eta);
      HplusTree->Branch("WJet_csv", &pWJet_csv);
      HplusTree->Branch("AddJet_pt",&pAddJet_pt);
      HplusTree->Branch("AddJet_eta",&pAddJet_eta);
      HplusTree->Branch("AddJet_csv", &pAddJet_csv);
  
 
   //----------------------------------------------------------------------------------------------------------------- 
         
      HplusTree->Branch("MatchJet_Hmass",&MatchJet_Hmass, "MatchJet_Hmass/F");
      HplusTree->Branch("MatchJet_Tmass",&MatchJet_Tmass, "MatchJet_Tmass/F");
      HplusTree->Branch("MatchJet_formule_Tmass",&MatchJet_formule_Tmass, "MatchJet_formule_Tmass/F");
      HplusTree->Branch("MatchJet_jetflag",&MatchJet_jetflag, "MatchJet_jetflag/I");
 
      
      HplusTree->Branch("MatchJet_daughterQuarkofTop_index",&MatchJet_daughterQuarkofTop_index,"MatchJet_daughterQuarkofTop_index/I");
      HplusTree->Branch("MatchJet_daughterQuarkofTop_pt",&MatchJet_daughterQuarkofTop_pt, "MatchJet_daughterQuarkofTop_pt/F");
      HplusTree->Branch("MatchJet_daughterQuarkofTop_recOverGenPt",&MatchJet_daughterQuarkofTop_recOverGenPt, "MatchJet_daughterQuarkofTop_recOverGenPt/F");
      HplusTree->Branch("MatchJet_daughterQuarkofTop_eta",&MatchJet_daughterQuarkofTop_eta, "MatchJet_daughterQuarkofTop_eta/F");
      HplusTree->Branch("MatchJet_daughterQuarkofTop_phi",&MatchJet_daughterQuarkofTop_phi, "MatchJet_daughterQuarkofTop_phi/F");
      HplusTree->Branch("MatchJet_daughterQuarkofTop_bDiscrCSV",&MatchJet_daughterQuarkofTop_bDiscrCSV, "MatchJet_daughterQuarkofTop_dbDiscrCSV/F");
 
      HplusTree->Branch("MatchJet_daughterQuarkofTopBar_index",&MatchJet_daughterQuarkofTopBar_index,"MatchJet_daughterQuarkofTopBar_index/I");
      HplusTree->Branch("MatchJet_daughterQuarkofTopBar_pt",&MatchJet_daughterQuarkofTopBar_pt, "MatchJet_daughterQuarkofTopBar_pt/F");
      HplusTree->Branch("MatchJet_daughterQuarkofTopBar_recOverGenPt",&MatchJet_daughterQuarkofTopBar_recOverGenPt, "MatchJet_daughterQuarkofTopBar_recOverGenPt/F");
      HplusTree->Branch("MatchJet_daughterQuarkofTopBar_eta",&MatchJet_daughterQuarkofTopBar_eta, "MatchJet_daughterQuarkofTopBar_eta/F");
      HplusTree->Branch("MatchJet_daughterQuarkofTopBar_phi",&MatchJet_daughterQuarkofTopBar_phi, "MatchJet_daughterQuarkofTopBar_phi/F");
      HplusTree->Branch("MatchJet_daughterQuarkofTopBar_bDiscrCSV",&MatchJet_daughterQuarkofTopBar_bDiscrCSV, "MatchJet_daughterQuarkofTopBar_dbDiscrCSV/F");
      
      HplusTree->Branch("MatchJet_daughterQuarkofHplus_index",&MatchJet_daughterQuarkofHplus_index,"MatchJet_daughterQuarkofHplus_index/I");
      HplusTree->Branch("MatchJet_daughterQuarkofHplus_pt",&MatchJet_daughterQuarkofHplus_pt, "MatchJet_daughterQuarkofHplus_pt/F");
      HplusTree->Branch("MatchJet_daughterQuarkofHplus_recOverGenPt",&MatchJet_daughterQuarkofHplus_recOverGenPt, "MatchJet_daughterQuarkofHplus_recOverGenPt/F");
      HplusTree->Branch("MatchJet_daughterQuarkofHplus_eta",&MatchJet_daughterQuarkofHplus_eta, "MatchJet_daughterQuarkofHplus_eta/F");
      HplusTree->Branch("MatchJet_daughterQuarkofHplus_phi",&MatchJet_daughterQuarkofHplus_phi, "MatchJet_daughterQuarkofHplus_phi/F");
      HplusTree->Branch("MatchJet_daughterQuarkofHplus_bDiscrCSV",&MatchJet_daughterQuarkofHplus_bDiscrCSV, "MatchJet_daughterQuarkofHplus_dbDiscrCSV/F");
      
      HplusTree->Branch("MatchJet_daughterQuarkBarofHplus_index",&MatchJet_daughterQuarkBarofHplus_index,"MatchJet_daughterQuarkBarofHplus_index/I");
      HplusTree->Branch("MatchJet_daughterQuarkBarofHplus_pt",&MatchJet_daughterQuarkBarofHplus_pt, "MatchJet_daughterQuarkBarofHplus_pt/F");
      HplusTree->Branch("MatchJet_daughterQuarkBarofHplus_recOverGenPt",&MatchJet_daughterQuarkBarofHplus_recOverGenPt, "MatchJet_daughterQuarkBarofHplus_recOverGenPt/F");
      HplusTree->Branch("MatchJet_daughterQuarkBarofHplus_eta",&MatchJet_daughterQuarkBarofHplus_eta, "MatchJet_daughterQuarkBarofHplus_eta/F");
      HplusTree->Branch("MatchJet_daughterQuarkBarofHplus_phi",&MatchJet_daughterQuarkBarofHplus_phi, "MatchJet_daughterQuarkBarofHplus_phi/F");
      HplusTree->Branch("MatchJet_daughterQuarkBarofHplus_bDiscrCSV",&MatchJet_daughterQuarkBarofHplus_bDiscrCSV, "MatchJet_daughterQuarkBarofHplus_dbDiscrCSV/F");
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

       HplusTree->Branch("MUpt",&MUpt, "MUpt/F");
       HplusTree->Branch("MUeta",&MUeta, "MUeta/F");
       HplusTree->Branch("MUphi",&MUphi, "MUphi/F");
       HplusTree->Branch("MUtheta",&MUtheta, "MUtheta/F");
       HplusTree->Branch("MUp",&MUp, "MUp/F");
       HplusTree->Branch("MUpx",&MUpx, "MUpx/F");
       HplusTree->Branch("MUpy",&MUpy, "MUpy/F");
       HplusTree->Branch("MUpz",&MUpz, "MUpz/F");
       HplusTree->Branch("MUrelIso",&MUrelIso, "MUrelIso/F");
       HplusTree->Branch("MUd0",&MUd0, "MUd0/F");
       HplusTree->Branch("MUdz",&MUdz, "MUdz/F");
       HplusTree->Branch("MUnormChi2",&MUnormChi2, "MUnormChi2/F");
       HplusTree->Branch("MUnOfHits",&MUnOfHits, "MUnOfHits/I"); //number of valid hits
       HplusTree->Branch("MUlayer",&MUlayer, "MUlayer/I");  //number of tracker layer with measurement
       HplusTree->Branch("MUnOfPixels",&MUnOfPixels, "MUnOfPixels/I"); //number of pixels with valid hits
       HplusTree->Branch("MUisGlobal",&MUisGlobal, "MUisGlobal/I");
       HplusTree->Branch("MUisPF",&MUisPF, "MUisPF/I");
       HplusTree->Branch("MUstations",&MUstations, "MUstations/I"); 
  
       HplusTree->Branch("nLep",&nLep, "nLep/I"); // number of leptons (VetoMuons + VetoElecs)
       
       
pJpt=&Jpt;
pJeta=&Jeta;
pJphi=&Jphi;
pJtheta=&Jtheta;
pJp=&Jp;
pJpx=&Jpx;
pJpy=&Jpy;
pJpz=&Jpz;
pJbDiscr=&JbDiscr;
pJenergy=&Jenergy;
pJcharge=&Jcharge;
pJflavor=&Jflavor;
     
       //JETS
       HplusTree->Branch("nJet",&realnJet, "nJet/I");
       HplusTree->Branch("nbJet",&nbJet, "nbJet/I");
       HplusTree->Branch("nbJetloose",&nbJetloose, "nbJetloose/I");
       HplusTree->Branch("Jpt",&pJpt);
       HplusTree->Branch("Jeta",&pJeta);
       HplusTree->Branch("Jphi",&pJphi);
       HplusTree->Branch("Jtheta",&pJtheta);
       HplusTree->Branch("Jp",&pJp);
       HplusTree->Branch("Jpx",&pJpx);
       HplusTree->Branch("Jpy",&pJpy);
       HplusTree->Branch("Jpz",&pJpz);
       HplusTree->Branch("JbDiscr",&pJbDiscr);
       HplusTree->Branch("Jenergy",&pJenergy);
       HplusTree->Branch("Jcharge",&pJcharge);
       HplusTree->Branch("Jflavor",&pJflavor);
 
       //MET
       HplusTree->Branch("METpt",&METpt, "METpt/F");
       HplusTree->Branch("METpx",&METpx, "METpx/F");
       HplusTree->Branch("METpy",&METpy, "METpy/F");
       HplusTree->Branch("METeta",&METeta, "METeta/F");
       HplusTree->Branch("METphi",&METphi, "METphi/F");
       HplusTree->Branch("METtheta",&METtheta, "METtheta/F");

       //VERTEX MULTIPLICITY
       HplusTree->Branch("nVertex",&nVertex, "nVertex/I"); 

//---------------------------------------------------------------------------------------------------------

  if  (stepFlag_=="9b" ) { 


	pKinFit_prob		=      &KinFit_prob		;
	pKinFit_chi2		=      &KinFit_chi2		;
	pKinFit_lightP_index	=      &KinFit_lightP_index	;
	pKinFit_lightQ_index	=      &KinFit_lightQ_index	;
	pKinFit_hadB_index	=      &KinFit_hadB_index	;
	pKinFit_lepB_index	=      &KinFit_lepB_index	;
	pKinFit_lepton_index	=      &KinFit_lepton_index	;
	pKinFit_hadW_mass	=      &KinFit_hadW_mass	;
	pKinFit_hadW_pt		=      &KinFit_hadW_pt  	;
	pKinFit_hadW_eta 	=      &KinFit_hadW_eta 	;
	pKinFit_hadW_phi 	=      &KinFit_hadW_phi 	;
	pKinFit_lepW_mass	=      &KinFit_lepW_mass	;
	pKinFit_lepW_pt		=      &KinFit_lepW_pt  	;
	pKinFit_lepW_eta 	=      &KinFit_lepW_eta 	;
	pKinFit_lepW_phi 	=      &KinFit_lepW_phi 	;
	pKinFit_hadTop_mass	=      &KinFit_hadTop_mass	;
	pKinFit_hadTop_pt	=      &KinFit_hadTop_pt	;
	pKinFit_hadTop_eta	=      &KinFit_hadTop_eta	;
	pKinFit_hadTop_phi	=      &KinFit_hadTop_phi	;
	pKinFit_lepTop_mass	=      &KinFit_lepTop_mass	;
	pKinFit_lepTop_pt	=      &KinFit_lepTop_pt	;
	pKinFit_lepTop_eta	=      &KinFit_lepTop_eta	;
	pKinFit_lepTop_phi	=      &KinFit_lepTop_phi	;
	pKinFit_hadQuark_pt	=      &KinFit_hadQuark_pt	;
	pKinFit_hadQuark_eta	=      &KinFit_hadQuark_eta	;
	pKinFit_hadQuark_phi	=      &KinFit_hadQuark_phi	;
	pKinFit_hadQuarkBar_pt	=      &KinFit_hadQuarkBar_pt	;
	pKinFit_hadQuarkBar_eta	=      &KinFit_hadQuarkBar_eta	;
	pKinFit_hadQuarkBar_phi	=      &KinFit_hadQuarkBar_phi	;
	pKinFit_hadB_pt		=      &KinFit_hadB_pt  	;
	pKinFit_hadB_eta 	=      &KinFit_hadB_eta 	;
	pKinFit_hadB_phi 	=      &KinFit_hadB_phi 	;
	pKinFit_lepB_pt		=      &KinFit_lepB_pt  	;
	pKinFit_lepB_eta 	=      &KinFit_lepB_eta 	;
	pKinFit_lepB_phi 	=      &KinFit_lepB_phi 	;


      HplusTree->Branch("KinFit_isValid",&KinFit_isValid, "KinFit_isValid/I");
      HplusTree->Branch("ncomb",&ncomb, "ncomb/I");
      HplusTree->Branch("KinFit_prob",&pKinFit_prob);
      HplusTree->Branch("KinFit_chi2",&pKinFit_chi2);
      HplusTree->Branch("KinFit_lightP_index",&pKinFit_lightP_index);
      HplusTree->Branch("KinFit_lightQ_index",&pKinFit_lightQ_index);
      HplusTree->Branch("KinFit_hadB_index",&pKinFit_hadB_index);
      HplusTree->Branch("KinFit_lepB_index",&pKinFit_lepB_index);
      HplusTree->Branch("KinFit_lepton_index",&pKinFit_lepton_index);
  
      HplusTree->Branch("KinFit_hadW_mass",&pKinFit_hadW_mass);
      HplusTree->Branch("KinFit_hadW_pt",&pKinFit_hadW_pt);
      HplusTree->Branch("KinFit_hadW_eta",&pKinFit_hadW_eta);
      HplusTree->Branch("KinFit_hadW_phi",&pKinFit_hadW_phi);
 
      HplusTree->Branch("KinFit_lepW_mass",&pKinFit_lepW_mass);
      HplusTree->Branch("KinFit_lepW_pt",&pKinFit_lepW_pt);
      HplusTree->Branch("KinFit_lepW_eta",&pKinFit_lepW_eta);
      HplusTree->Branch("KinFit_lepW_phi",&pKinFit_lepW_phi);
     
      HplusTree->Branch("KinFit_hadTop_mass",&pKinFit_hadTop_mass);
      HplusTree->Branch("KinFit_hadTop_pt",&pKinFit_hadTop_pt);
      HplusTree->Branch("KinFit_hadTop_eta",&pKinFit_hadTop_eta);
      HplusTree->Branch("KinFit_hadTop_phi",&pKinFit_hadTop_phi);
     
      HplusTree->Branch("KinFit_lepTop_mass",&pKinFit_lepTop_mass);
      HplusTree->Branch("KinFit_lepTop_pt",&pKinFit_lepTop_pt);
      HplusTree->Branch("KinFit_lepTop_eta",&pKinFit_lepTop_eta);
      HplusTree->Branch("KinFit_lepTop_phi",&pKinFit_lepTop_phi);

      HplusTree->Branch("KinFit_hadQuark_pt",&pKinFit_hadQuark_pt);
      HplusTree->Branch("KinFit_hadQuark_eta",&pKinFit_hadQuark_eta);
      HplusTree->Branch("KinFit_hadQuark_phi",&pKinFit_hadQuark_phi);
 
      HplusTree->Branch("KinFit_hadQuarkBar_pt",&pKinFit_hadQuarkBar_pt);
      HplusTree->Branch("KinFit_hadQuarkBar_eta",&pKinFit_hadQuarkBar_eta);
      HplusTree->Branch("KinFit_hadQuarkBar_phi",&pKinFit_hadQuarkBar_phi);

      HplusTree->Branch("KinFit_hadB_pt",&pKinFit_hadB_pt);
      HplusTree->Branch("KinFit_hadB_eta",&pKinFit_hadB_eta);
      HplusTree->Branch("KinFit_hadB_phi",&pKinFit_hadB_phi);
   
      HplusTree->Branch("KinFit_lepB_pt",&pKinFit_lepB_pt);
      HplusTree->Branch("KinFit_lepB_eta",&pKinFit_lepB_eta);
      HplusTree->Branch("KinFit_lepB_phi",&pKinFit_lepB_phi);
}

}

// ------------ method called once each job just after ending the event loop  ------------
void 
HplusAnalyzer_ttSignal::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
void 
HplusAnalyzer_ttSignal::beginRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void 
HplusAnalyzer_ttSignal::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
HplusAnalyzer_ttSignal::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
HplusAnalyzer_ttSignal::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
HplusAnalyzer_ttSignal::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(HplusAnalyzer_ttSignal);
