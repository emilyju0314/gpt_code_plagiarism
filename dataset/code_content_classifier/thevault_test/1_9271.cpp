dvector BoundedNumberVectorInfo::getLowerBounds(void){
    if (debug) rpt::echo<<"starting BoundedNumberVectorInfo::getLowerBounds(void) "<<this<<endl;
    dvector lbs(1,nNIs);
    lbs.initialize();
    if (ppNIs) for (int i=1;i<=nNIs;i++) lbs(i) = (static_cast<BoundedNumberInfo*>(ppNIs[i-1]))->getLowerBound();
    if (debug) rpt::echo<<"finished BoundedNumberVectorInfo::getLowerBounds(void) "<<this<<endl;
    return lbs;
}