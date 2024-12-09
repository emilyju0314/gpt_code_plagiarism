dvariable BoundedNumberInfo::calcArithScaleVal(const prevariable& x){
    RETURN_ARRAYS_INCREMENT();
    if (debug) rpt::echo<<"starting BoundedNumberInfo::calcArithScaleVal(prevariable&) "<<this<<endl;
    dvariable y, z;
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
            cout<<"BoundedNumberInfo::calcArithScaleVal(dvariable&) "<<this<<endl;
            cout<<"Parameter scale type "<<scaleType<<" not recognized!!"<<endl;
            ad_exit(1);
            break;
    }
    if (debug) rpt::echo<<"finished BoundedNumberInfo::calcArithScaleVal(prevariable&) "<<this<<endl;
    RETURN_ARRAYS_DECREMENT();
    return z;
}