adstring tcsam::getFitType(int i){
    if (i==FIT_NONE)    return STR_FIT_NONE;
    if (i==FIT_BY_TOT)  return STR_FIT_BY_TOT;
    if (i==FIT_BY_X)    return STR_FIT_BY_X;
    if (i==FIT_BY_XM)   return STR_FIT_BY_XM;
    if (i==FIT_BY_XS)   return STR_FIT_BY_XS;
    if (i==FIT_BY_XMS)  return STR_FIT_BY_XMS;
    if (i==FIT_BY_XE)   return STR_FIT_BY_XE;
    if (i==FIT_BY_X_ME) return STR_FIT_BY_X_ME;
    if (i==FIT_BY_X_SE) return STR_FIT_BY_X_SE;
    if (i==FIT_BY_XME)  return STR_FIT_BY_XME;
    if (i==FIT_BY_XM_SE) return STR_FIT_BY_X_MSE;
    if (i==FIT_BY_X_MSE) return STR_FIT_BY_XM_SE;
    if (i==FIT_BY_X_MATONLY) return STR_FIT_BY_X_MATONLY;
    std::cout<<"Unrecognized fit type '"<<i<<"'"<<std::endl;
    std::cout<<"Aborting..."<<std::endl;
    exit(-1);
    return adstring("");
}