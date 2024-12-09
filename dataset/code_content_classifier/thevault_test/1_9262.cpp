dvector NumberVectorInfo::getInitVals(){
    if (debug) rpt::echo<<"starting NumberVectorInfo::getInitVals()"<<this<<endl;
    dvector initVals(1,nNIs);
    for (int i=1;i<=nNIs;i++) initVals(i) = ppNIs[i-1]->getInitVal();
    if (debug) rpt::echo<<"finished NumberVectorInfo::getInitVals()"<<this<<endl;
    return initVals;
}