adstring tcsam::getScaleType(int sclType){
    adstring type = "<UNDEFINED>";
    if (sclType==SCALE_ARITHM) return STR_SCALE_ARITHM;
    if (sclType==SCALE_LOGIT)  return STR_SCALE_LOGIT;
    if (sclType==SCALE_LOG)    return STR_SCALE_LOG;
    if (sclType==SCALE_PROBIT) return STR_SCALE_PROBIT;
    std::cout<<"transform type integer '"<<sclType<<"' not recognized."<<std::endl;
    std::cout<<"Aborting..."<<std::endl;
    ad_exit(-1);
    return type;
}