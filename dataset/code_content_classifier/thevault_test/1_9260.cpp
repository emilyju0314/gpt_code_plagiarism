dvar_vector NumberVectorInfo::calcArithScaleVals(const dvar_vector& x){
    RETURN_ARRAYS_INCREMENT();
    if (debug) rpt::echo<<"starting NumberVectorInfo::calcArithScaleVals(dvar_vector&) "<<this<<endl;
    dvar_vector asv(1,nNIs);
    asv.initialize();
    if (ppNIs) for (int i=1;i<=nNIs;i++) asv(i) = (ppNIs[i-1])->calcArithScaleVal(x(i));
    if (debug) rpt::echo<<"finished NumberVectorInfo::calcArithScaleVals(dvar_vector&) "<<this<<endl;
    RETURN_ARRAYS_DECREMENT();
    return asv;
}