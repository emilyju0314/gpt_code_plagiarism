void
MoveFlatParamsToDB::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  //check which centrality binning is available
  bool cent1 = kFALSE;
  bool cent2 = kFALSE;
  bool cent5 = kFALSE;
  bool cent10 = kFALSE;
  bool cent20 = kFALSE;
  bool cent25 = kFALSE;
  bool cent30 = kFALSE;
  bool cent40 = kFALSE;

  for(int i = 0; i<nRP; i++) {
    if(GetRescor(1.0,EPNames[i],res1[i],eres1[i])) cent1 = kTRUE;
    if(GetRescor(2.0,EPNames[i],res2[i],eres2[i])) cent2 = kTRUE;
    if(GetRescor(5.0,EPNames[i],res5[i],eres5[i])) cent5 = kTRUE;
    if(GetRescor(10.0,EPNames[i],res10[i],eres10[i])) cent10 = kTRUE;
    if(GetRescor(20.0,EPNames[i],res20[i],eres20[i])) cent20 = kTRUE;
    if(GetRescor(25.0,EPNames[i],res25[i],eres25[i])) cent25 = kTRUE;
    if(GetRescor(30.0,EPNames[i],res30[i],eres30[i])) cent30 = kTRUE;
    if(GetRescor(40.0,EPNames[i],res40[i],eres40[i])) cent40 = kTRUE;
  }

  int centreserve = 0;
  if(cent1)  centreserve+=100 + 1;
  if(cent2)  centreserve+=50 + 1;
  if(cent5)  centreserve+=20 + 1;
  if(cent10) centreserve+=10 + 1;
  if(cent20) centreserve+=5 + 1;
  if(cent25) centreserve+=4 + 1;
  if(cent30) centreserve+=3 + 1;
  if(cent40) centreserve+=2 + 1;

  rpFlat->m_table.reserve(x[0]->GetNbinsX() + centreserve);
  for(int j = 0; j<x[0]->GetNbinsX();j++) {
    RPFlatParams::EP * thisBin = new RPFlatParams::EP();
    for(int i = 0; i<nRP; i++) {
      thisBin->x[i] = x[i]->GetBinContent(j+1);
      thisBin->y[i] = y[i]->GetBinContent(j+1);
      thisBin->RPNameIndx[i]=RPNameIndx[i];
    }
    rpFlat->m_table.push_back(*thisBin);
    if(thisBin) delete thisBin;
  }
  if(cent1) AddCentralityBins( 1.0, 100);
  if(cent2) AddCentralityBins( 2.0, 50);
  if(cent5) AddCentralityBins( 5.0, 20);
  if(cent10) AddCentralityBins(10.0, 10);
  if(cent20) AddCentralityBins(20.0, 5);
  if(cent25) AddCentralityBins(25.0, 4);
  if(cent30) AddCentralityBins(30.0, 3);
  if(cent40) AddCentralityBins(40.0, 2);
  edm::Service<cond::service::PoolDBOutputService> pool;
  if(pool.isAvailable()){
    if(pool->isNewTagRequest("HeavyIonRPRcd") ) {
      pool->createNewIOV<RPFlatParams>(rpFlat,pool->beginOfTime(), pool->endOfTime(),"HeavyIonRPRcd");
    } else {
      pool->appendSinceTime<RPFlatParams>(rpFlat, pool->currentTime(),"HeavyIonRPRcd");
    }
  }
}