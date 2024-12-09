void
HiRecHitSpikeCleaner::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;

  // Get the RecHits from the event
  Handle<EcalRecHitCollection> pRecHitsB;
  try {
    iEvent.getByLabel(rHInputProducerB_, pRecHitsB);
  } catch ( cms::Exception& ex ) {
    edm::LogError("EgammaSCCorrectionMakerError")
      << "Error! can't get the RecHits "
      << rHInputProducerB_.label();
  }
  const EcalRecHitCollection *ebRecHits = pRecHitsB.product();

  // Define a collection of corrected SuperClusters to put back into the event
  auto corRecHitsEB = std::make_unique<EcalRecHitCollection>();

  //get the rechit geometry
  edm::ESHandle<CaloGeometry> theCaloGeom;
  iSetup.get<CaloGeometryRecord>().get(theCaloGeom);
  const CaloGeometry* caloGeom = theCaloGeom.product();

  //  Loop over raw clusters and make corrected ones
  EcalRecHitCollection::const_iterator it;
  for(it = ebRecHits->begin(); it != ebRecHits->end(); it++)
  {
    const GlobalPoint &position = caloGeom->getPosition(it->id());
    double rhEt = it->energy()/cosh(position.eta());
    //	 std::cout << " et of SC = " << theEt << std::endl;

    bool flagS = true;
    float swissCrx(0);

    swissCrx = EcalTools::swissCross   (it->id(), *ebRecHits, 0.,avoidIeta85_); //EcalSeverityLevelAlgo::swissCross(it->id(), *ebRecHits, 0.,avoidIeta85_);
    //	    std::cout << "swissCross = " << swissCrx <<std::endl;
    // std::cout << " timing = " << it->time() << std::endl;

    if(rhEt > etCut_) {
      if (fabs(it->time()) > TimingCut_ ) {
	flagS = false;
	//std::cout<<"cut on time: " << it->time() << std::endl;
      }
      if ( swissCrx > (float)swissCutThr_ ) {
	flagS = false ;     // swissCross cut
	//std::cout<<"cut on swissCross: " << swissCrx << std::endl;
      }
    }

    EcalRecHit newRecHit;
    if ( flagS == true)
      newRecHit=*it;
    else
      continue;
    if(rhEt > 3)
      std::cout<<"ADDING RECHIT - time: " << it->time() << " swiss: " << swissCrx << std::endl;
    //std::cout<<"ADDING CLEAN RECHIT"<<std::endl;
    corRecHitsEB->push_back(newRecHit);
  }

  // Put collection of corrected SuperClusters into the event
  iEvent.put(std::move(corRecHitsEB), ebOutputCollection_);
}