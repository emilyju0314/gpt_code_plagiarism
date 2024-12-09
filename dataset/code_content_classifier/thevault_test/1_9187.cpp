int tcsam::getFitType(adstring s){
    if (s==STR_FIT_NONE)    return FIT_NONE;
    if (s==STR_FIT_BY_TOT)  return FIT_BY_TOT;
    if (s==STR_FIT_BY_X)    return FIT_BY_X;
    if (s==STR_FIT_BY_XM)   return FIT_BY_XM;
    if (s==STR_FIT_BY_XS)   return FIT_BY_XS;
    if (s==STR_FIT_BY_XMS)  return FIT_BY_XMS;
    if (s==STR_FIT_BY_XE)   return FIT_BY_XE;
    if (s==STR_FIT_BY_X_ME) return FIT_BY_X_ME;
    if (s==STR_FIT_BY_X_SE) return FIT_BY_X_SE;
    if (s==STR_FIT_BY_XME)  return FIT_BY_XME;
    if (s==STR_FIT_BY_XM_SE) return FIT_BY_XM_SE;
    if (s==STR_FIT_BY_X_MSE) return FIT_BY_X_MSE;
    if (s==STR_FIT_BY_X_MATONLY) return FIT_BY_X_MATONLY;
    std::cout<<"Unrecognized fit type '"<<s<<"'"<<std::endl;
    std::cout<<"Aborting..."<<std::endl;
    exit(-1);
    return -1;
}