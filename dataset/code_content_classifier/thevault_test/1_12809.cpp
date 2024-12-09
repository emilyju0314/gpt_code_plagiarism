void 
HiFJRhoFlowModulationProducer::beginJob()
{
  if(doFlatTest_) randGen_p = new TRandom3(0);
  if(doEvtPlane_){
    const int kMaxEvtPlanes = 1000;
    hiEvtPlane = new float[kMaxEvtPlanes];
  }
}