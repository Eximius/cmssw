// -*- C++ -*-
//
// Package:    MyCalibrations/MyPedestalsMaker
// Class:      MyPedestalsMaker
// 
/**\class MyPedestalsMaker MyPedestalsMaker.cc MyCalibrations/MyPedestalsMaker/plugins/MyPedestalsMaker.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Vytautas Mickus
//         Created:  Mon, 25 Jul 2016 10:40:34 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "CondFormats/CondTest/interface/MyPedestals.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CondCore/DBOutputService/interface/PoolDBOutputService.h"
//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.

class MyPedestalsMaker : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit MyPedestalsMaker(const edm::ParameterSet&);
      ~MyPedestalsMaker();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

      // ----------member data ---------------------------
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
MyPedestalsMaker::MyPedestalsMaker(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
   usesResource("TFileService");

}


MyPedestalsMaker::~MyPedestalsMaker()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
MyPedestalsMaker::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;

   MyPedestals* pMyPedestals = new MyPedestals();

   edm::Service<cond::service::PoolDBOutputService> poolDbService;
   if( poolDbService.isAvailable() )
      poolDbService->WriteOne(pMyPedestals, poolDbService->currentTime(), "myPedestal_test");
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void 
MyPedestalsMaker::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
MyPedestalsMaker::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
MyPedestalsMaker::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(MyPedestalsMaker);
