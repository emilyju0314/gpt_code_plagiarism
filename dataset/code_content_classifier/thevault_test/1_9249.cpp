dvar_vector BoundedVectorInfo::calcLogPrior(dvar_vector & pv){
    RETURN_ARRAYS_INCREMENT();
    if (debug) rpt::echo<<"starting BoundedVectorInfo::calcLogPrior(pv) for "<<name<<endl;
    dvar_vector lps;
    if (pMPI->canCalcLogPDF(pv)) {
        lps = pMPI->calcLogPDF(pv,priorParams,priorConsts);
    } else {
        lps.allocate(pv.indexmin(),pv.indexmax());
        lps.initialize();
        dvariable x;
        for (int i=pv.indexmin();i<=pv.indexmax();i++) {
            x = pv(i);//have to copy pv(i) )
            lps(i) = pMPI->calcLogPDF(x,priorParams,priorConsts);
        }
    }
    if (debug) {
        rpt::echo<<"logPrior: "<<lps<<endl;
        rpt::echo<<"finished BoundedVectorInfo::calcLogPriors(pv) for "<<name<<endl;
    }
    RETURN_ARRAYS_DECREMENT();
    return lps;
}