dvector VectorInfo::calcParamScaleVals(dvector& x){
    if (debug) rpt::echo<<"starting VectorInfo::calcParamScaleVal(dvector&) "<<this<<endl;
    dvector z(x.indexmin(),x.indexmax());
    switch (scaleType){
        case tcsam::SCALE_ARITHM:
            z = x;
            break;
        case tcsam::SCALE_LOG:
            z = log(x);//on log scale
            break;
        case tcsam::SCALE_LOGIT:
            z = log(elem_div(x,1.0-x));//on logit scale
            break;
        default:
            cout<<"VectorInfo::calcParamScaleVal(dvector&) "<<this<<endl;
            cout<<"Parameter scale type "<<scaleType<<" not recognized!!"<<endl;
            ad_exit(1);
            break;
    }
    if (debug) rpt::echo<<"finished VectorInfo::calcParamScaleVal(dvector&) "<<this<<endl;
    return z;
}