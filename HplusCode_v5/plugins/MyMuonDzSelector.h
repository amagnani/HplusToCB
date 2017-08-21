#ifndef PhysicsTools_PatAlgos_MyMuonDzSelector_h
#define PhysicsTools_PatAlgos_MyMuonDzSelector_h

#include "FWCore/Framework/interface/EDFilter.h"

#include "DataFormats/Common/interface/RefVector.h"

#include "CommonTools/UtilAlgos/interface/StringCutObjectSelector.h"
#include "CommonTools/UtilAlgos/interface/SingleObjectSelector.h"
#include "CommonTools/UtilAlgos/interface/ObjectSelector.h"
#include "CommonTools/UtilAlgos/interface/SingleElementCollectionSelector.h"

#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/PFParticle.h"
#include "DataFormats/PatCandidates/interface/GenericParticle.h"
#include "DataFormats/PatCandidates/interface/TriggerObjectStandAlone.h"
#include "DataFormats/PatCandidates/interface/CompositeCandidate.h"
#include "DataFormats/VertexReco/interface/Vertex.h"


#include <vector>


namespace pat {

  class MyMuonDzSelector : public edm::EDFilter {
  public:


  MyMuonDzSelector( edm::ParameterSet const & params ) : 
    edm::EDFilter( ),
      src_( params.getParameter<edm::InputTag>("src") ),
      cut_( params.getParameter<std::string>("cut") ),
      filter_(false),
      dzCut_( params.getParameter<double>("dzCut") ),
      selector_( cut_ )
      {
	produces< std::vector<pat::Muon> >();

	if ( params.exists("filter") ) {
	  filter_ = params.getParameter<bool>("filter");
	}
      }

    virtual ~MyMuonDzSelector() {}

    virtual void beginJob() {}
    virtual void endJob() {}
    
    virtual bool filter(edm::Event& iEvent, const edm::EventSetup& iSetup) {

      std::auto_ptr< std::vector<Muon> > patMuons ( new std::vector<Muon>() ); 

      edm::Handle< edm::View<pat::Muon> > h_muons;
      iEvent.getByLabel( src_, h_muons );
      
      
      //get Vertex for dz computation
      edm::Handle< std::vector<reco::Vertex> > handleVertex_;
      iEvent.getByLabel("goodOfflinePrimaryVertices", handleVertex_);
      reco::Vertex vertex;
      vertex = handleVertex_->at(0);

       
      // First loop over the products and make the secondary output collections
      for ( edm::View<pat::Muon>::const_iterator ibegin = h_muons->begin(),
	      iend = h_muons->end(), imuon = ibegin;
	    imuon != iend; ++imuon) {

	// Check the selection and dz cut
	if ( selector_(*imuon) && fabs((*imuon).muonBestTrack()->dz(vertex.position()))<dzCut_) {
	 
	  patMuons->push_back( *imuon );

	}
	
     }


      // put genEvt  in Event
      bool pass = patMuons->size() > 0;
      iEvent.put(patMuons);

      if ( filter_ ) 
	return pass;
      else 
	return true;
	
    }

  protected:
    edm::InputTag                  src_;
    std::string                    cut_;
    bool                           filter_;
    double                         dzCut_;
    StringCutObjectSelector<Muon>   selector_;
  };

}


#endif
