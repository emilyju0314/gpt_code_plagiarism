dvector BoundedVectorVectorInfo::getUpperBounds(void){
    if (debug) rpt::echo<<"starting BoundedVectorVectorInfo::getUpperBounds(void) "<<this<<endl;
    dvector bnds(1,nVIs);
    bnds.initialize();
    if (ppVIs) for (int i=1;i<=nVIs;i++) bnds(i) = (static_cast<BoundedVectorInfo*>(ppVIs[i-1]))->getUpperBound();
    if (debug) rpt::echo<<"finished BoundedVectorVectorInfo::getUpperBounds(void) "<<this<<endl;
    return bnds;
}