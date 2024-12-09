double BoundedNumberInfo::calcParamScaleVal(double x){
    if (debug) rpt::echo<<"starting BoundedNumberInfo::calcParamScaleVal(double&) "<<this<<endl;
    double y,z;
    switch (scaleType){
        case tcsam::SCALE_ARITHM:
            z = x;
            break;
        case tcsam::SCALE_LOG:
            z = log(x);
            break;
        case tcsam::SCALE_LOGIT:
            if (x<=lower) return -25.0;
            if (x>=upper) return 25.0;
            y = (x-lower)/(upper-lower);//scaled from [lower,upper] to [0,1]
            z = log(y/(1.0-y));//on logit scale
            break;
        default:
            cout<<"BoundedNumberInfo::calcParamScaleVal(double) "<<this<<endl;
            cout<<"Parameter scale type "<<scaleType<<" not recognized!!"<<endl;
            ad_exit(1);
            break;
    }
    if (debug) rpt::echo<<"finished BoundedNumberInfo::calcParamScaleVal(double&) "<<this<<endl;
    return z;
}