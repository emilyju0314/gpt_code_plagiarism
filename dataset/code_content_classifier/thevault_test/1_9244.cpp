dvector BoundedVectorInfo::calcParamScaleVals(dvector& x){
    if (debug) rpt::echo<<"starting BoundedVectorInfo::calcParamScaleVal(dvector&) "<<this<<endl;
    dvector z(x.indexmin(),x.indexmax());
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
                dvector xp(x.indexmin(),x.indexmax()); xp = x;
                //replace x "near" bounds with values equivalent to z = -25 or +25
                for (int i=xp.indexmin();i<=xp.indexmax();i++){
                    if (xp(i)<=lower) xp(i) = lower+(upper-lower)/(1+mfexp( 25.0));
                    if (xp(i)>=upper) xp(i) = lower+(upper-lower)/(1+mfexp(-25.0));
                }
                dvector y = (xp-lower)/(upper-lower);//scaled from [lower,upper] to [0,1]
                z = log(elem_div(y,1.0-y));//on logit scale
                break;
            }
        default:
            cout<<"BoundedVectorInfo::calcParamScaleVal(dvector&) "<<this<<endl;
            cout<<"Parameter scale type "<<scaleType<<" not recognized!!"<<endl;
            ad_exit(1);
            break;
    }
    if (debug) rpt::echo<<"finished BoundedVectorInfo::calcParamScaleVal(dvector&) "<<this<<endl;
    return z;
}