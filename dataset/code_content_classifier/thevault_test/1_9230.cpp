dvar_vector VectorInfo::calcArithScaleVals(const dvar_vector& x){
    RETURN_ARRAYS_INCREMENT();
    if (debug) rpt::echo<<"starting VectorInfo::calcArithScaleVal(dvar_vector&) "<<this<<endl;
    dvar_vector z(x.indexmin(),x.indexmax());
    switch (scaleType){
        case tcsam::SCALE_ARITHM:
            z = x;
            break;
        case tcsam::SCALE_LOG:
            z = mfexp(x);
            break;
        case tcsam::SCALE_LOGIT:
            z = 1.0/(1.0+mfexp(-1.0*x));
            break;
        default:
            cout<<"VectorInfo::calcArithScaleVal(dvar_vector&) "<<this<<endl;
            cout<<"Parameter scale type "<<scaleType<<" not recognized!!"<<endl;
            ad_exit(1);
            break;
    }
    if (debug) rpt::echo<<"finished BoundedVectorInfo::calcArithScaleVal(dvar_vector&) "<<this<<endl;
    RETURN_ARRAYS_DECREMENT();
    return z;
}