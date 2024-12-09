bool
HiEcalRecHitSpikeFilter::filter(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  //using namespace edm;
  //using namespace std;
  //using namespace reco;

  //grab rechits
  edm::Handle<EcalRecHitCollection> EBReducedRecHits;
  iEvent.getByLabel(ebReducedRecHitCollection_, EBReducedRecHits);
  const EcalRecHitCollection *rechits = EBReducedRecHits.product();

  //get the rechit geometry
  edm::ESHandle<CaloGeometry> theCaloGeom;
  iSetup.get<CaloGeometryRecord>().get(theCaloGeom);
  const CaloGeometry* caloGeom = theCaloGeom.product();

  double rhEt;
  if(rechits) {
    for(EcalRecHitCollection::const_iterator it=rechits->begin(); it!=rechits->end(); it++) {
      const GlobalPoint &position = caloGeom->getPosition(it->id());
      rhEt = it->energy()/cosh(position.eta());
      double  swissCrx = EcalTools::swissCross  (it->id(), *rechits, 0.,avoidIeta85_);
      if(   (rhEt > minEt_) &&  (    (swissCrx > swissThreshold_)     ||     ( abs(it->time()) > timeThreshold_) )     )
      {
	return false;
      }
    }
  }
  return true;
}