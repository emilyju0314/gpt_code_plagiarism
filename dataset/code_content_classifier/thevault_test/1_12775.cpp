void
GenParticleCounter::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;

  // Get the primary event vertex
  recoVtxZ = -100;
  //  edm::Handle<reco::VertexCollection> vertexHandle;
  //  iEvent.getByLabel(InputTag(vertexProducer_), vertexHandle);
  //  reco::VertexCollection vertexCollection = *(vertexHandle.product());
  //  if (vertexCollection.size()>0) {
  //   recoVtxZ = vertexCollection.begin()->position().Z();
  //   }


  edm::Handle<reco::GenParticleCollection> inputHandle;
  iEvent.getByLabel(InputTag(mSrc),inputHandle);
  const reco::GenParticleCollection *collection1 = inputHandle.product();

  int maxindex = (int)collection1->size();

  nPar = 0 ;
  for(int i = 0; i < maxindex; i++)
  {
    const reco::GenParticle &c1 = (*collection1)[i];

    if ( c1.et() < 14 )  continue;

    et[nPar] = c1.et();
    eta[nPar] = c1.eta();
    phi[nPar] = c1.phi();
    status[nPar] = c1.status();
    id[nPar]    = c1.pdgId();
    momId[nPar] = -1;
    if ( c1.mother()!=0 )
      momId[nPar] = c1.mother()->pdgId();
    collId[nPar] = c1.collisionId();
    nPar++;
  }
  theTree->Fill();

}