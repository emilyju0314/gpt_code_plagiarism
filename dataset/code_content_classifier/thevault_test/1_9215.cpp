void NumberInfo::read(cifstream & is){
    if (debug) rpt::echo<<"Starting NumberInfo::read(cifstream & is) "<<this<<endl;
    adstring str;
    is>>initVal;
    is>>str; scaleType=tcsam::getScaleType(str);
    if (debug) rpt::echo<<name<<tb<<str<<tb<<scaleType<<tb<<tcsam::getScaleType(scaleType)<<endl;
    is>>phase;
    is>>str; resample=wts::getOnOffType(str);
    is>>priorWgt;
    is>>priorType;//prior type
    if (debug){
        rpt::echo<<initVal<<tb<<"#initVal"<<endl;
        rpt::echo<<phase  <<tb<<"#phase"<<endl;
        rpt::echo<<wts::getOnOffType(resample)<<tb<<"#resample"<<endl;
        rpt::echo<<priorWgt<<tb<<"#priorWgt"<<endl;
        rpt::echo<<priorType<<tb<<"#prior type"<<endl;
    }
    setPriorType(priorType);
    if (pMPI->getNumParams()) {
        is>>priorParams;
        if (debug) rpt::echo<<priorParams<<tb<<"#prior params"<<endl;
    } else {
        is>>str; str.to_upper();
        if (str!=tcsam::STR_NONE){
            rpt::echo<<"no prior params, so input should be 'none', but got '"<<str<<"'"<<endl;
            rpt::echo<<"Please fix!!"<<endl;
            exit(-1);
        }
        if (debug) rpt::echo<<"#no prior params"<<endl;
    }
    if (pMPI->getNumConsts()) {
        is>>priorConsts;
        if (debug) rpt::echo<<priorConsts<<tb<<"#prior consts"<<endl;
    } else {
        is>>str; str.to_upper();
        if (str!=tcsam::STR_NONE){
            rpt::echo<<"no prior consts, so input should be 'none', but got '"<<str<<"'"<<endl;
            rpt::echo<<"Please fix!!"<<endl;
            exit(-1);
        }
        if (debug) rpt::echo<<"#no prior consts"<<endl;
    }
    is>>label;
    if (debug) rpt::echo<<label<<tb<<"#label"<<endl;
    if (debug) rpt::echo<<"Done NumberInfo::read(cifstream & is) "<<this<<endl;
}