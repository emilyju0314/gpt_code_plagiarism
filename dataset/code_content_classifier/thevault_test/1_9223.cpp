void BoundedNumberInfo::read(cifstream & is){
    if (debug) {
        rpt::echo<<"Starting BoundedNumberInfo::read(cifstream & is) "<<this<<endl;
        NumberInfo::debug=1;
    }
    adstring str;
    is>>str;   if (debug) rpt::echo<<str<<tb<<"#jitter"<<endl; jitter=wts::getOnOffType(str);
    is>>lower; if (debug) rpt::echo<<lower<<tb<<"#lower"<<endl;
    is>>upper; if (debug) rpt::echo<<upper<<tb<<"#upper"<<endl;
    NumberInfo::read(is);//finish reading
    if (debug) {
        NumberInfo::debug=0;
        rpt::echo<<"Done BoundedNumberInfo::read(cifstream & is) "<<this<<endl;
    }
}