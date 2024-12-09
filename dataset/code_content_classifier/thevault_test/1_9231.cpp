double VectorInfo::calcParamScaleVals(double x){
    if (debug) rpt::echo<<"starting VectorInfo::calcParamScaleVal(double) "<<this<<endl;
    double z = 0;
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
            cout<<"VectorInfo::calcParamScaleVal(double) "<<this<<endl;
            cout<<"Parameter scale type "<<scaleType<<" not recognized!!"<<endl;
            ad_exit(1);
            break;
    }
    if (debug) rpt::echo<<"finished VectorInfo::calcParamScaleVal(double) "<<this<<endl;
    return z;
}