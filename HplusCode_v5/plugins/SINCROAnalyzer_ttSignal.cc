// -*- C++ -*-
//
// Package:    SINCROAnalyzer_ttSignal
// Class:      SINCROAnalyzer_ttSignal
// 
/**\class SINCROAnalyzer_ttSignal SINCROAnalyzer_ttSignal.cc HplusAnalysis/SINCROAnalyzer_ttSignal/src/SINCROAnalyzer_ttSignal.cc

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


#include "../interface/SINCROAnalyzer_ttSignal.h"

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
// SINCROAnalyzer_ttSignal::SINCROAnalyzer_ttSignal(const edm::ParameterSet& params)
// 
// {
//    //now do what ever initialization is needed
// 
// }


SINCROAnalyzer_ttSignal::~SINCROAnalyzer_ttSignal()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
SINCROAnalyzer_ttSignal::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  using namespace std;
  using namespace reco;
 //______________________________________________________________________________________



  //HANDLES
   Handle< vector<pat::Jet> > handleJet_; 
  iEvent.getByLabel("goodJets", handleJet_);
  Handle< vector<pat::Muon> > handleMuon_;
  iEvent.getByLabel("tightMuons", handleMuon_);
  Handle< vector<pat::Jet> > handlebJet_; 
  iEvent.getByLabel("bJets", handlebJet_);
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
  

//--------------------------------------------------------------------------------------------------------------



 
  pat::Jet jet;  
 
  unsigned int nMuon= handleMuon_->size();
 

//___________________________________________________________________________________________________________


  nLep=0;
  
  nJet=4;  //used for dimension of vectors
  realnJet=0;
  Jpt.clear(); Jp.clear(); Jeta.clear(); Jphi.clear(); Jtheta.clear();
  Jpx.clear(); Jpy.clear(); Jpz.clear();
  JbDiscr.clear(); Jenergy.clear(); Jcharge.clear(); Jflavor.clear();
  
  METpt=0; METpx=0; METpy=0; METeta=0, METphi=0, METtheta=0;
  
  
  
  
  pat::Muon mu;  
  pat::Muon firstMuon; 
  pat::Jet mj;
 
  pat::Electron ele;
  
  reco::Vertex vertex;
  
 
  pat::MET met;  

  vector<float> METpz;

   
  nLep=handleVetoMuon_->size()+handleEle_->size();
 

//___________________________________________________________________________________________________________
  luminosityBlock=iEvent.luminosityBlock();
  run=iEvent.id().run();
  event=iEvent.id().event();

//___________________________________________________________________________________________

 if(nMuon>0){
      mu = handleMuon_->at(0);
        firstMuon=mu;
  }
  
     
   //parametri 
   MUpt = firstMuon.pt(); MUeta = firstMuon.eta(); MUphi = firstMuon.phi();
   MUtheta = firstMuon.theta(); 
   MUpx = firstMuon.px(); MUpy  = firstMuon.py();  MUpz  = firstMuon.pz(); 
   MUp = sqrt(MUpx*MUpx+MUpy*MUpy+MUpz*MUpz);

 
 //--------------------------------------------------------------------------jets

 
 realnJet= handleJet_->size();
 nbJet= handlebJet_->size();
 
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
//_________________________________________________________________________________________

vector<int> event_list_1;
event_list_1.push_back( 17664056 );
event_list_1.push_back( 17672866 );
event_list_1.push_back( 17675674);
event_list_1.push_back( 17680004);
event_list_1.push_back( 17681680);
event_list_1.push_back( 17778586);
event_list_1.push_back( 17778915);
event_list_1.push_back( 20644242);
event_list_1.push_back( 20656055);
event_list_1.push_back( 21813601);
event_list_1.push_back( 27339250);
event_list_1.push_back( 27339871);
event_list_1.push_back( 28280569);
event_list_1.push_back( 28281428);
event_list_1.push_back( 28281877);
event_list_1.push_back( 28303304);
event_list_1.push_back( 28304465);
event_list_1.push_back( 28304479);
vector<int> event_list_2;
event_list_2.push_back( 17667211 );
event_list_2.push_back( 17670027 );
event_list_2.push_back( 17684491);
event_list_2.push_back( 20644222);
event_list_2.push_back( 20647176);
event_list_2.push_back( 20656469);
event_list_2.push_back( 20657720);
event_list_2.push_back( 20659128);
event_list_2.push_back( 21818065);
event_list_2.push_back( 28129479);
event_list_2.push_back( 28130897);
event_list_2.push_back( 28130976);
event_list_2.push_back( 28272962);
event_list_2.push_back( 28281676);
event_list_2.push_back( 28288143);
event_list_2.push_back( 28303152);
event_list_2.push_back( 28305665);



//   if( event==20658780 || event== 28130976){
 //  if( std::find(event_list_1.begin(),event_list_1.end(), event) != event_list_1.end() ){
 //  if( std::find(event_list_2.begin(),event_list_2.end(), event )!= event_list_2.end() ){
//}

//count step
int CSV=0;
 if (realnJet>0 && Jpt[0]>=55) {Nstep4++;}
 else {return;}
 if (realnJet>1 && Jpt[1]>=45) {Nstep4b++;}
 else {return;} 
 if (realnJet>2 && Jpt[2]>=35) {Nstep4c++;}
 else {return;} 
 if (realnJet>3 && Jpt[3]>=20) {Nstep5++;}
 else {return;} 
 for(unsigned int l = 0; l< handleJet_->size(); l++){ 
    if (JbDiscr[l]>0.679) CSV++;
 }
 
 if (CSV>0 ) {Nstep6++;}
 if (CSV>1 ) {Nstep7++;}
 if (CSV>2 ) {Nstep8++;}

//    if(CSV>=3)	    {cout<<"event "<<event<<" has at least 3 bjets"<<endl; }
//    else if (CSV==2) {cout<<"event "<<event<<" has exactly  2 bjets "<<endl;}
//    else if (CSV==1) {cout<<"event "<<event<<" has exactly  1 bjets "<<endl;}
//    else if (CSV==0) {cout<<"event "<<event<<" has no bjets (but it passed 4th jet pt cut)"<<endl;}
//  

     cout<<"========================================================="<<endl;
     
     
     cout<<"luminosityBlock  "<< luminosityBlock<<" run "<< run<< " event "<<event<<endl;
     cout<<" MET "<<METpt<<" muon pt "<< MUpt <<" muon eta "<<MUeta<<endl;
     cout<<" # jets "<<realnJet<<endl;
       for(unsigned int l = 0; l< handleJet_->size(); l++){ 
	 cout<<" jet "<<l<<" : pt (JES) " << Jpt[l] <<" eta " << Jeta[l] << " CSV "<< JbDiscr[l] <<endl;
       }  


//___________________________________________________________________________________________

//  HplusTree->Fill();
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
SINCROAnalyzer_ttSignal::beginJob()
{
       edm::Service<TFileService> fs;
      
 
}

// ------------ method called once each job just after ending the event loop  ------------
void 
SINCROAnalyzer_ttSignal::endJob() 
{

std::cout <<" Nstep4 "<< Nstep4 <<" Nstep4b "<< Nstep4b <<" Nstep4c "<< Nstep4c <<" Nstep5 "<< Nstep5 <<"  Nstep6 "<< Nstep6 <<" Nstep7 "<< Nstep7 <<" Nstep8 "<< Nstep8
<<std::endl;
}

// ------------ method called when starting to processes a run  ------------
void 
SINCROAnalyzer_ttSignal::beginRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void 
SINCROAnalyzer_ttSignal::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
SINCROAnalyzer_ttSignal::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
SINCROAnalyzer_ttSignal::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
SINCROAnalyzer_ttSignal::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(SINCROAnalyzer_ttSignal);
