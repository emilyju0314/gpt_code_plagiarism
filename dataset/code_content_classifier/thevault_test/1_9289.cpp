dvector BoundedVectorVectorInfo::getUpperBoundsOnParamScales(void){
    if (debug) rpt::echo<<"starting BoundedVectorVectorInfo::getUpperBoundsOnParamScales(void) "<<this<<endl;
    dvector bnds(1,nVIs);
    bnds.initialize();
    if (ppVIs) for (int i=1;i<=nVIs;i++) bnds(i) = (static_cast<BoundedVectorInfo*>(ppVIs[i-1]))->getUpperBoundOnParamScale();
    if (debug) rpt::echo<<"finished BoundedVectorVectorInfo::getUpperBoundsOnParamScales(void) "<<this<<endl;
    return bnds;
}