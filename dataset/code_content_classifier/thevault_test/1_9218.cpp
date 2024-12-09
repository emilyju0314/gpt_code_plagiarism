void BoundedNumberInfo::setInitVal(double x){
    if (debug) rpt::echo<<"starting BoundedNumberInfo::setInitVal(double x)"<<this<<endl;
    if (x<lower) {initVal = lower+(upper-lower)/1000000.0;} else
    if (x>upper) {initVal = upper-(upper-lower)/1000000.0;} else
    {initVal=x;}
    if (debug) rpt::echo<<"finished BoundedNumberInfo::setInitVal(double x)"<<this<<endl;
}