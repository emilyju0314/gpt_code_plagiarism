int tcsam::getScaleType(adstring sclType){
    int type = -1;
    sclType.to_upper();
    if (sclType==STR_SCALE_NONE)   return SCALE_ARITHM;
    if (sclType==STR_SCALE_ARITHM) return SCALE_ARITHM;
    if (sclType==STR_SCALE_LOGIT)  return SCALE_LOGIT;
    if (sclType==STR_SCALE_LOG)    return SCALE_LOG;
    if (sclType==STR_SCALE_PROBIT) return SCALE_PROBIT;
    std::cout<<"transform type keyword '"<<sclType<<"' not recognized."<<std::endl;
    std::cout<<"Aborting..."<<std::endl;
    ad_exit(-1);
    return type;
}