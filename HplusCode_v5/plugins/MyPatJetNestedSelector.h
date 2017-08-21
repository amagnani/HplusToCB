#ifndef PhysicsTools_PatAlgos_MyPatJetNestedSelector_h
#define PhysicsTools_PatAlgos_MyPatJetNestedSelector_h

#include "FWCore/Framework/interface/EDFilter.h"

#include "DataFormats/Common/interface/RefVector.h"

#include "CommonTools/UtilAlgos/interface/StringCutObjectSelector.h"
#include "CommonTools/UtilAlgos/interface/SingleObjectSelector.h"
#include "CommonTools/UtilAlgos/interface/ObjectSelector.h"
#include "CommonTools/UtilAlgos/interface/SingleElementCollectionSelector.h"

#include "DataFormats/PatCandidates/interface/Jet.h"


#include <vector>


namespace pat {

  class MyPatJetNestedSelector : public edm::EDFilter {
  public:


  MyPatJetNestedSelector( edm::ParameterSet const & params ) : 
    edm::EDFilter( ),
      src_( params.getParameter<edm::InputTag>("src") ),
      cut1_( params.getParameter<std::string>("cut1") ),
      cut2_( params.getParameter<std::string>("cut2") ),
      filter_(false),
      selector1_( cut1_ ),
      selector2_( cut2_ )
      {
	produces< std::vector<pat::Jet> >();
	produces<reco::GenJetCollection> ("genJets");
	produces<std::vector<CaloTower>  > ("caloTowers");
	produces<reco::PFCandidateCollection > ("pfCandidates");
	produces<edm::OwnVector<reco::BaseTagInfo> > ("tagInfos");

	if ( params.exists("filter") ) {
	  filter_ = params.getParameter<bool>("filter");
	}
      }

    virtual ~MyPatJetNestedSelector() {}

    virtual void beginJob() {}
    virtual void endJob() {}
    
    virtual bool filter(edm::Event& iEvent, const edm::EventSetup& iSetup) {

      std::auto_ptr< std::vector<Jet> > patJets ( new std::vector<Jet>() ); 
      std::auto_ptr< std::vector<Jet> > tempPatJets ( new std::vector<Jet>() ); 
      std::auto_ptr< std::vector<Jet> > temp2PatJets ( new std::vector<Jet>() ); 

      std::auto_ptr<reco::GenJetCollection > genJetsOut ( new reco::GenJetCollection() );
      std::auto_ptr<std::vector<CaloTower>  >  caloTowersOut( new std::vector<CaloTower> () );
      std::auto_ptr<reco::PFCandidateCollection > pfCandidatesOut( new reco::PFCandidateCollection() );
      std::auto_ptr<edm::OwnVector<reco::BaseTagInfo> > tagInfosOut ( new edm::OwnVector<reco::BaseTagInfo>() );  


      edm::RefProd<reco::GenJetCollection > h_genJetsOut = iEvent.getRefBeforePut<reco::GenJetCollection >( "genJets" );
      edm::RefProd<std::vector<CaloTower>  >  h_caloTowersOut = iEvent.getRefBeforePut<std::vector<CaloTower>  > ( "caloTowers" );
      edm::RefProd<reco::PFCandidateCollection > h_pfCandidatesOut = iEvent.getRefBeforePut<reco::PFCandidateCollection > ( "pfCandidates" );
      edm::RefProd<edm::OwnVector<reco::BaseTagInfo> > h_tagInfosOut = iEvent.getRefBeforePut<edm::OwnVector<reco::BaseTagInfo> > ( "tagInfos" );


      edm::Handle< edm::View<pat::Jet> > h_jets;
      iEvent.getByLabel( src_, h_jets );

       unsigned int maxNumber=4;
       unsigned int mynumber=0;
       pat::Jet ttjet;
       pat::Jet ttfjet;
     
      // loop over the products to collect at most 4 jets satisfying cut1 condition
      for ( edm::View<pat::Jet>::const_iterator ibegin = h_jets->begin(),
	      iend = h_jets->end(), ijet = ibegin;
	    ijet != iend; ++ijet ) {

	// Check the selection
	if ( selector1_(*ijet) ) {
	   mynumber++;	  
	  tempPatJets->push_back( *ijet );
	}
	
	if(mynumber==maxNumber) break;
 	
       }
	  
//------------------
      
      // First loop over the 4 products to check cut2 condition and make the  output collections
      for ( std::vector<pat::Jet>::const_iterator tt=tempPatJets->begin(); tt!= tempPatJets->end(); ++tt ) {
        	 
	// Check the selection
	if ( selector2_(*tt) ) {
	   
	   temp2PatJets->push_back( *tt );
	  
	  // Copy over the calo towers
	  for ( CaloTowerFwdPtrVector::const_iterator itowerBegin =
	  tt->caloTowersFwdPtr().begin(),
		itowerEnd = tt->caloTowersFwdPtr().end(), itower = itowerBegin;
		itower != itowerEnd; ++itower ) {
	    // Add to global calo tower list
	    caloTowersOut->push_back( **itower );
	  }

	  
	  // Copy over the pf candidates
	  for ( reco::PFCandidateFwdPtrVector::const_iterator icandBegin = tt->pfCandidatesFwdPtr().begin(),
		  icandEnd = tt->pfCandidatesFwdPtr().end(), icand = icandBegin;
		icand != icandEnd; ++icand ) {
	    // Add to global pf candidate list
	    pfCandidatesOut->push_back( **icand );
	  }
	  
	  // Copy the tag infos
	  for ( TagInfoFwdPtrCollection::const_iterator iinfoBegin = tt->tagInfosFwdPtr().begin(),
		  iinfoEnd = tt->tagInfosFwdPtr().end(), iinfo = iinfoBegin;
		iinfo != iinfoEnd; ++iinfo ) {
	    // Add to global calo tower list
	    tagInfosOut->push_back( **iinfo );
	  }

	  // Copy the gen jet
	  if ( tt->genJet() != 0 ) {
	    genJetsOut->push_back( *(tt->genJet()) );
	  }

	}
	
      }
//---------------------

      // Output the secondary collections. 
      edm::OrphanHandle<reco::GenJetCollection>  oh_genJetsOut = iEvent.put( genJetsOut, "genJets" );
      edm::OrphanHandle<std::vector<CaloTower> > oh_caloTowersOut = iEvent.put( caloTowersOut, "caloTowers" );
      edm::OrphanHandle<reco::PFCandidateCollection> oh_pfCandidatesOut = iEvent.put( pfCandidatesOut, "pfCandidates" );
      edm::OrphanHandle<edm::OwnVector<reco::BaseTagInfo> > oh_tagInfosOut = iEvent.put( tagInfosOut, "tagInfos" );

      unsigned int caloTowerIndex = 0;
      unsigned int pfCandidateIndex = 0;
      unsigned int tagInfoIndex = 0;
      unsigned int genJetIndex = 0;
   
      // Now set the Ptrs with the orphan handles. 
      for ( std::vector<pat::Jet>::const_iterator ttf=temp2PatJets->begin(); ttf!= temp2PatJets->end(); ++ttf) {
	   
	   patJets->push_back(*ttf);
	  
	  // Copy over the calo towers
	  for ( CaloTowerFwdPtrVector::const_iterator itowerBegin = ttf->caloTowersFwdPtr().begin(),
		  itowerEnd = ttf->caloTowersFwdPtr().end(), itower = itowerBegin;
		itower != itowerEnd; ++itower ) {
	    // Update the "forward" bit of the FwdPtr to point at the new tower collection. 

	    //  ptr to "this" tower in the global list	
	    edm::Ptr<CaloTower> outPtr( oh_caloTowersOut, caloTowerIndex);     
	    patJets->back().updateFwdCaloTowerFwdPtr( itower - itowerBegin,// index of "this" tower in the jet 
						      outPtr
						      );
	    ++caloTowerIndex;
	  }

	  
	  // Copy over the pf candidates
	  for ( reco::PFCandidateFwdPtrVector::const_iterator icandBegin = ttf->pfCandidatesFwdPtr().begin(),
		  icandEnd = ttf->pfCandidatesFwdPtr().end(), icand = icandBegin;
		icand != icandEnd; ++icand ) {
	    // Update the "forward" bit of the FwdPtr to point at the new tower collection. 

	    // ptr to "this" cand in the global list
	    edm::Ptr<reco::PFCandidate> outPtr( oh_pfCandidatesOut, pfCandidateIndex );
	    patJets->back().updateFwdPFCandidateFwdPtr( icand - icandBegin,// index of "this" tower in the jet 
							outPtr
							);
	    ++pfCandidateIndex;
	  }
	  
	  // Copy the tag infos
	  for ( TagInfoFwdPtrCollection::const_iterator iinfoBegin = ttf->tagInfosFwdPtr().begin(),
		  iinfoEnd = ttf->tagInfosFwdPtr().end(), iinfo = iinfoBegin;
		iinfo != iinfoEnd; ++iinfo ) {
	    // Update the "forward" bit of the FwdPtr to point at the new tower collection. 

	    // ptr to "this" info in the global list
	    edm::Ptr<reco::BaseTagInfo > outPtr( oh_tagInfosOut, tagInfoIndex );
	    patJets->back().updateFwdTagInfoFwdPtr( iinfo - iinfoBegin,// index of "this" tower in the jet 
						    outPtr
						    );
	    ++tagInfoIndex;
	  }

	  // Copy the gen jet
	  if ( ttf->genJet() != 0 ) {
	    patJets->back().updateFwdGenJetFwdRef( edm::Ref<reco::GenJetCollection>( oh_genJetsOut, genJetIndex) // ref to "this" genjet in the global list
						   );
	    ++genJetIndex;
	  }

	}
     


      // put genEvt  in Event
      bool pass = patJets->size() > 0;
      iEvent.put(patJets);

      if ( filter_ ) 
	return pass;
      else 
	return true;
	
    }

  protected:
    edm::InputTag                  src_;
    std::string                    cut1_;
    std::string                    cut2_;
    bool                           filter_;
    StringCutObjectSelector<Jet>   selector1_;
    StringCutObjectSelector<Jet>   selector2_;
  };

}


#endif
