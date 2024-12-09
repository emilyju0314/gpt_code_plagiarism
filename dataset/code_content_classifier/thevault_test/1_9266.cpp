dvar_vector NumberVectorInfo::calcLogPriors(dvar_vector & pv){
    RETURN_ARRAYS_INCREMENT();
    if (debug) rpt::echo<<"starting NumberVectorInfo::calcLogPriors(pv)"<<this<<tb<<name<<endl;
    dvar_vector lps(pv.indexmin(),pv.indexmax());
    lps.initialize();
    if (ppNIs) {
        dvariable x;
        for (int i=pv.indexmin();i<=pv.indexmax();i++) {
            x = pv(i);//have to copy pv(i) )
            lps(i) = ppNIs[i-1]->calcLogPrior(x);
        }
    }
    if (debug) {
        rpt::echo<<"logPriors: "<<lps<<endl;
        rpt::echo<<"finished NumberVectorInfo::calcLogPriors(pv)"<<this<<tb<<name<<endl;
    }
    RETURN_ARRAYS_DECREMENT();
    return lps;
}