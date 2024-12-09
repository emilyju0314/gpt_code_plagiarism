double NumberInfo::calcArithScaleVal(double x){
    if (debug) rpt::echo<<"starting NumberInfo::calcArithScaleVal(double&) "<<this<<endl;
    double z;
    switch (scaleType){
        case tcsam::SCALE_ARITHM:
            z = x;
            break;
        case tcsam::SCALE_LOG:
            z = mfexp(x);
            break;
        case tcsam::SCALE_LOGIT:
            z = 1.0/(1.0+mfexp(-x));//scaled to [0,1]
            break;
        default:
            cout<<"NumberInfo::calcArithScaleVal(double) "<<this<<endl;
            cout<<"Parameter scale type "<<scaleType<<" not recognized!!"<<endl;
            ad_exit(1);
            break;
    }
    if (debug) rpt::echo<<"starting NumberInfo::calcArithScaleVal(double&) "<<this<<endl;
    return z;
}