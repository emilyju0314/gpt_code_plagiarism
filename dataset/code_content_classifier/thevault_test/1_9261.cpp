dvector NumberVectorInfo::calcParamScaleVals(dvector& x){
    if (debug) rpt::echo<<"starting NumberVectorInfo::calcParamScaleVals(dvector&) "<<this<<endl;
    dvector asv(1,nNIs);
    asv.initialize();
    if (ppNIs) for (int i=1;i<=nNIs;i++) asv(i) = (ppNIs[i-1])->calcParamScaleVal(x(i));
    if (debug) rpt::echo<<"finished NumberVectorInfo::calcParamScaleVals(dvector&) "<<this<<endl;
    return asv;
}