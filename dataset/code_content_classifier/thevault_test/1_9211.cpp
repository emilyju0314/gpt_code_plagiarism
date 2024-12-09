double NumberInfo::calcParamScaleVal(double x){
    if (debug) rpt::echo<<"starting NumberInfo::calcParamScaleVal(double&) "<<this<<endl;
    double y,z;
    switch (scaleType){
        case tcsam::SCALE_ARITHM:
            z = x;
            break;
        case tcsam::SCALE_LOG:
            z = log(x);//on log scale
            break;
        case tcsam::SCALE_LOGIT:
            z = log(x/(1.0-x));//on logit scale
            break;
        default:
            cout<<"NumberInfo::calcParamScaleVal(double) "<<this<<endl;
            cout<<"Parameter scale type "<<scaleType<<" not recognized for NumberInfo!!"<<endl;
            ad_exit(1);
            break;
    }
    if (debug) rpt::echo<<"finished BoundedNumberInfo::calcParamScaleVal(double&) "<<this<<endl;
    return z;
}