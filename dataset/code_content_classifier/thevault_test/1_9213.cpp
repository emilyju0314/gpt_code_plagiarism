dvariable NumberInfo::calcLogPrior(prevariable& x){
    RETURN_ARRAYS_INCREMENT();
    if (debug) rpt::echo<<"starting NumberInfo::calcLogPrior(prevariable& x)"<<this<<endl;
    dvariable val = pMPI->calcLogPDF(x,priorParams,priorConsts);
    if (debug) {
        if (pMPI->getNumParams()) rpt::echo<<"priorParams = "<<priorParams<<tb;
        if (pMPI->getNumConsts()) rpt::echo<<"priorConsts = "<<priorConsts<<tb;
        rpt::echo<<endl;
        rpt::echo<<"x = "<<x<<"; ln(pdf(x)) = "<<val<<endl;
        rpt::echo<<"finished NumberInfo::calcLogPrior(prevariable& x)"<<this<<endl;
    }
    RETURN_ARRAYS_DECREMENT();
    return val;
}