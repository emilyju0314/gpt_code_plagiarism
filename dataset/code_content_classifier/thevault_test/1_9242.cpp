dvar_vector BoundedVectorInfo::calcArithScaleVals(const dvar_vector& x){
    RETURN_ARRAYS_INCREMENT();
    if (debug) rpt::echo<<"starting BoundedVectorInfo::calcArithScaleVal(dvar_vector&) "<<this<<endl;
    dvar_vector z(x.indexmin(),x.indexmax());
    switch (scaleType){
        case tcsam::SCALE_ARITHM:
            z = x;
            break;
        case tcsam::SCALE_LOG:
            z = mfexp(x);
            break;
        case tcsam::SCALE_LOGIT:
            z = lower+(upper-lower)/(1.0+mfexp(-1.0*x));
            break;
        default:
            cout<<"BoundedVectorInfo::calcArithScaleVal(dvar_vector&) "<<this<<endl;
            cout<<"Parameter scale type "<<scaleType<<" not recognized!!"<<endl;
            ad_exit(1);
            break;
    }
    if (debug) rpt::echo<<"finished BoundedVectorInfo::calcArithScaleVal(dvar_vector&) "<<this<<endl;
    RETURN_ARRAYS_DECREMENT();
    return z;
}