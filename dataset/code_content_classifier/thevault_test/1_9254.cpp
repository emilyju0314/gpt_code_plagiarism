void DevsVectorInfo::setInitVals(dvector& x){
    if (debug) {
        rpt::echo<<"starting DevsVectorInfo::setInitVals(dvector& x) for "<<name<<endl;
        BoundedVectorInfo::debug=1;
    }
    BoundedVectorInfo::setInitVals(x);
    initVals -= mean(initVals);
    if (max(fabs(initVals))>max(fabs(lower),fabs(upper))) initVals *= max(fabs(lower),fabs(upper))/max(fabs(initVals));
    if (debug) {
        BoundedVectorInfo::debug=0;
        rpt::echo<<"initVals: "<<initVals<<endl<<"vector x: "<<x<<endl;
        rpt::echo<<"finished BoundedVectorInfo::setInitVals(dvector& x) for "<<name<<endl;
    }
}