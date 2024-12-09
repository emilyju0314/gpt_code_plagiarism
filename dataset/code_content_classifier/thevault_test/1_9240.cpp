double BoundedVectorInfo::calcArithScaleVals(double x){
   if (debug) rpt::echo<<"starting BoundedVectorInfo::calcArithScaleVals(double) "<<this<<endl;
    double z=0.0;
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
            cout<<"BoundedVectorInfo::calcArithScaleVal(double) "<<this<<endl;
            cout<<"Parameter scale type "<<scaleType<<" not recognized!!"<<endl;
            ad_exit(1);
            break;
    }
    if (debug) rpt::echo<<"finished BoundedVectorInfo::calcArithScaleVals(double) "<<this<<endl;
    return z;
}