void BoundedVectorInfo::setInitVals(double x){
    if (debug) rpt::echo<<"starting BoundedVectorInfo::setInitVals(double x) for "<<name<<endl;
    initVals = x;
    for (int i=1;i<=N;i++) {
        if (initVals(i)<=lower) initVals(i) = lower+(upper-lower)/1000000.0; else
        if (initVals(i)>=upper) initVals(i) = upper-(upper-lower)/1000000.0; 
    }
    if (debug) {
        rpt::echo<<"initVals: "<<initVals<<endl<<"vector x: "<<x<<endl;
        rpt::echo<<"finished BoundedVectorInfo::setInitVals(double x) for "<<name<<endl;
    }
}