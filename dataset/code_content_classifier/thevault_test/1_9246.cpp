void BoundedVectorInfo::setInitVals(dvector& x){
    if (debug) {
        rpt::echo<<"starting BoundedVectorInfo::setInitVals(dvector& x) for "<<name<<endl;
        rpt::echo<<"input  x index limits: "<<x.indexmin()<<cc<<x.indexmax()<<endl;
        rpt::echo<<"initVals index limits: "<<initVals.indexmin()<<cc<<initVals.indexmax()<<endl;
    }
    initVals = 1.0*x;
    for (int i=1;i<=N;i++) {
        if (initVals(i)<=lower) initVals(i) = lower+(upper-lower)/1000000.0; else
        if (initVals(i)>=upper) initVals(i) = upper-(upper-lower)/1000000.0; 
    }
    if (debug) {
        rpt::echo<<"initVals: "<<initVals<<endl<<"vector x: "<<x<<endl;
        rpt::echo<<"finished BoundedVectorInfo::setInitVals(dvector& x) for "<<name<<endl;
    }
}