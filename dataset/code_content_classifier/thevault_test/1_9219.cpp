double BoundedNumberInfo::calcArithScaleVal(double x){
    if (debug) rpt::echo<<"starting BoundedNumberInfo::calcArithScaleVal(double&) "<<this<<endl;
    double y, z;
    switch (scaleType){
        case tcsam::SCALE_ARITHM:
            z = x;
            break;
        case tcsam::SCALE_LOG:
            z = mfexp(x);
            break;
        case tcsam::SCALE_LOGIT:
            y = 1.0/(1.0+exp(-x));//scaled to [0,1]
            z = lower+(upper-lower)*y;
            break;
        default:
            cout<<"BoundedNumberInfo::calcArithScaleVal(double&) "<<this<<endl;
            cout<<"Parameter scale type "<<scaleType<<" not recognized!!"<<endl;
            ad_exit(1);
            break;
    }
    if (debug) rpt::echo<<"starting BoundedNumberInfo::calcArithScaleVal(double&) "<<this<<endl;
    return z;
}