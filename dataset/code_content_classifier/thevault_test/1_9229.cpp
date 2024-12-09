dvector VectorInfo::calcArithScaleVals(const dvector& x){
    if (debug) rpt::echo<<"starting VectorInfo::calcArithScaleVal(dvector&) "<<this<<endl;
    dvector z(x.indexmin(),x.indexmax());
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
            cout<<"VectorInfo::calcArithScaleVal(dvector&) "<<this<<endl;
            cout<<"Parameter scale type "<<scaleType<<" not recognized!!"<<endl;
            ad_exit(1);
            break;
    }
    if (debug) rpt::echo<<"finished VectorInfo::calcArithScaleVal(dvector&) "<<this<<endl;
    return z;
}