dvector BoundedNumberVectorInfo::getLowerBoundsOnParamScales(void){
    if (debug) rpt::echo<<"starting BoundedNumberVectorInfo::getLowerBoundsOnParamScales(void) "<<this<<endl;
    dvector lbs(1,nNIs);
    lbs.initialize();
    if (ppNIs) for (int i=1;i<=nNIs;i++) lbs(i) = (static_cast<BoundedNumberInfo*>(ppNIs[i-1]))->getLowerBoundOnParamScale();
    if (debug) rpt::echo<<"finished BoundedNumberVectorInfo::getLowerBoundsOnParamScales(void) "<<this<<endl;
    return lbs;
}