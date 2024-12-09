dvector BoundedVectorVectorInfo::getLowerBounds(void){
    if (debug) rpt::echo<<"starting BoundedVectorVectorInfo::getLowerBounds(void) "<<this<<endl;
    dvector bnds(1,nVIs);
    bnds.initialize();
    if (ppVIs) for (int i=1;i<=nVIs;i++) bnds(i) = (static_cast<BoundedVectorInfo*>(ppVIs[i-1]))->getLowerBound();
    if (debug) rpt::echo<<"finished BoundedVectorVectorInfo::getLowerBounds(void) "<<this<<endl;
    return bnds;
}