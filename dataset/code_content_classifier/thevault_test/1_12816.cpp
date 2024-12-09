void
HiSignalParticleProducer::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  using namespace reco;

  auto signalGenParticles = std::make_unique<GenParticleCollection>();

  edm::Handle<edm::View<GenParticle> > genParticles;
  iEvent.getByToken(genParticleSrc_,genParticles);

  int genParticleSize = genParticles->size();

  vector<int> selection;
  for(int igenParticle = 0; igenParticle < genParticleSize; ++igenParticle){
    selection.push_back(-1);
  }

  vector<int> selectedIndices;
  vector<int> removedIndices;

  for(int igenParticle = 0; igenParticle < genParticleSize; ++igenParticle){

    const GenParticle* genParticle = &((*genParticles)[igenParticle]);
    if(genParticle->collisionId() == 0){
      signalGenParticles->push_back(*genParticle);
      selection[igenParticle] = 1;
    }else{
      selection[igenParticle] = 0;
      removedIndices.push_back(igenParticle);
    }
  }

  iEvent.put(std::move(signalGenParticles));

}