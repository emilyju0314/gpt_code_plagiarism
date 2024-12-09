dvector NumberVectorInfo::calcArithScaleVals(const dvector& x){
    if (debug) rpt::echo<<"starting NumberVectorInfo::calcArithScaleVals(dvector&) "<<this<<endl;
    dvector asv(1,nNIs);
    asv.initialize();
    if (ppNIs) for (int i=1;i<=nNIs;i++) asv(i) = (ppNIs[i-1])->calcArithScaleVal(x(i));
    if (debug) rpt::echo<<"finished NumberVectorInfo::calcArithScaleVals(dvector&) "<<this<<endl;
    return asv;
}