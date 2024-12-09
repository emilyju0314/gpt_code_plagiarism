dvector BoundedNumberVectorInfo::getUpperBoundsOnParamScales(void){
    if (debug) rpt::echo<<"starting BoundedNumberVectorInfo::getUpperBounds(void) "<<this<<endl;
    dvector ubs(1,nNIs);
    ubs.initialize();
    if (ppNIs) for (int i=1;i<=nNIs;i++) ubs(i) = (static_cast<BoundedNumberInfo*>(ppNIs[i-1]))->getUpperBoundOnParamScale();
    if (debug) rpt::echo<<"finished BoundedNumberVectorInfo::getUpperBounds(void) "<<this<<endl;
    return ubs;
}