void 
HiFJRhoFlowModulationProducer::endJob() {
    if(doFlatTest_) delete randGen_p;
    if(doEvtPlane_) delete hiEvtPlane;
}