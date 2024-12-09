ivector VectorVectorInfo::getMinIndices(void){
    if (debug) rpt::echo<<"starting VectorVectorInfo::getMinIndices(void) for "<<name<<endl;
    ivector idxs(1,nVIs);
    idxs.initialize();
    if (ppVIs) idxs=1;
    if (debug) rpt::echo<<"finished VectorVectorInfo::getMinIndices(void) for "<<name<<endl;
    return idxs;
}