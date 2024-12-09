ivector VectorVectorInfo::getMaxIndices(void){
    if (debug) rpt::echo<<"starting VectorVectorInfo::getMaxIndices(void) for "<<name<<endl;
    ivector idxs(1,nVIs);
    idxs.initialize();
    if (ppVIs) for (int i=1;i<=nVIs;i++) idxs(i) = ppVIs[i-1]->getSize();
    if (debug) rpt::echo<<"finished VectorVectorInfo::getMaxIndices(void) for "<<name<<endl;
    return idxs;
}