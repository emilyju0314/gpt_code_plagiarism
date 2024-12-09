void
HiSignalGenJetProducer::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   using namespace reco;

   auto jets = std::make_unique<GenJetCollection>();

   edm::Handle<edm::View<GenJet> > genjets;
   iEvent.getByToken(jetSrc_,genjets);

   int jetsize = genjets->size();

   vector<int> selection;
   for(int ijet = 0; ijet < jetsize; ++ijet){
      selection.push_back(-1);
   }

   vector<int> selectedIndices;
   vector<int> removedIndices;

   for(int ijet = 0; ijet < jetsize; ++ijet){

     const GenJet* jet1 = &((*genjets)[ijet]);

     const GenParticle* gencon = jet1->getGenConstituent(0);

     if(gencon == 0) throw cms::Exception("GenConstituent","GenJet is missing its constituents");
     else if(gencon->collisionId() == 0){
       jets->push_back(*jet1);
       selection[ijet] = 1;
     }else{
       selection[ijet] = 0;
       removedIndices.push_back(ijet);
     }
   }

   iEvent.put(std::move(jets));

}