dvector NumberVectorInfo::getInitValsOnParamScales(){
    if (debug) rpt::echo<<"starting NumberVectorInfo::getInitValsOnParamScales()"<<this<<endl;
    dvector initVals(1,nNIs);
    for (int i=1;i<=nNIs;i++) initVals(i) = ppNIs[i-1]->getInitValOnParamScale();
    if (debug) rpt::echo<<"finished NumberVectorInfo::getInitValsOnParamScales()"<<this<<endl;
    return initVals;
}