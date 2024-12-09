void
EcalEscaleShiftPFProducer::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;

   edm::Handle<reco::PFCandidateCollection> inputsHandle;
   iEvent.getByToken(src_, inputsHandle);

   const reco::PFCandidateCollection pfcand = *(inputsHandle.product());


   auto prod = std::make_unique<reco::PFCandidateCollection>();
   
   for(reco::PFCandidateCollection::const_iterator pfcItr=pfcand.begin();
       pfcItr!=pfcand.end(); pfcItr++) {
     
     reco::PFCandidate scaledPFCand  = *pfcItr;
     
       
     if(pfcItr->particleId()==4){     
       if(fabs(pfcItr->eta())< 1.48) scaledPFCand.rescaleMomentum(scaleEB_);
       else{
	 if(!removePreshower_ || !(pfcItr->pS1Energy() + pfcItr->pS2Energy() >0 ) ) scaledPFCand.rescaleMomentum(scaleEE_);
	 else scaledPFCand.rescaleMomentum(scaleEE_*(1. - (pfcItr->pS1Energy() + pfcItr->pS2Energy())/pfcItr->energy()));
       }       
     }
     
     prod->push_back(scaledPFCand);
     
   }
   
   
   iEvent.put(std::move(prod));


}