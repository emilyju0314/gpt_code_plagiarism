dvariable NumberInfo::calcArithScaleVal(const prevariable& x){
    RETURN_ARRAYS_INCREMENT();
    if (debug) rpt::echo<<"starting NumberInfo::calcArithScaleVal(prevariable&) "<<this<<endl;
    dvariable z;
    switch (scaleType){
        case tcsam::SCALE_ARITHM:
            z = x;
            break;
        case tcsam::SCALE_LOG:
            z = mfexp(x);//scaled to [0,1]
            break;
        case tcsam::SCALE_LOGIT:
            z = 1.0/(1.0+mfexp(-x));//scaled to [0,1]
            break;
        default:
            cout<<"NumberInfo::calcArithScaleVal(dvariable&) "<<this<<endl;
            cout<<"Parameter scale type "<<scaleType<<" not recognized!!"<<endl;
            ad_exit(1);
            break;
    }
    if (debug) rpt::echo<<"finished NumberInfo::calcArithScaleVal(prevariable&) "<<this<<endl;
    RETURN_ARRAYS_DECREMENT();
    return z;
}