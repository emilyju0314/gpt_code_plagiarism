double BoundedVectorInfo::calcParamScaleVals(double x){
    if (debug) rpt::echo<<"starting BoundedVectorInfo::calcParamScaleVal(double) "<<this<<endl;
    double z = 0;
    switch (scaleType){
        case tcsam::SCALE_ARITHM:
            z = x;
            break;
        case tcsam::SCALE_LOG:
            z = log(x);
            break;
        case tcsam::SCALE_LOGIT:
            {
                //copy x
                double xp = x;
                //replace x "near" bounds with values equivalent to z = -25 or +25
                if (xp<=lower) xp = lower+(upper-lower)/(1+mfexp( 25.0));
                if (xp>=upper) xp = lower+(upper-lower)/(1+mfexp(-25.0));
                double y = (xp-lower)/(upper-lower);//scaled from [lower,upper] to [0,1]
                z = log(y/(1.0-y));//on logit scale
                break;
            }
        default:
            cout<<"BoundedVectorInfo::calcParamScaleVal(double) "<<this<<endl;
            cout<<"Parameter scale type "<<scaleType<<" not recognized!!"<<endl;
            ad_exit(1);
            break;
    }
    if (debug) rpt::echo<<"finished BoundedVectorInfo::calcParamScaleVal(double) "<<this<<endl;
    return z;
}