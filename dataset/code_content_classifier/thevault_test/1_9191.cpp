adstring tcsam::getLikelihoodType(int llType){
    adstring type = STR_LL_NONE;
    if (llType==LL_BINOMIAL)    return STR_LL_BINOMIAL;
    if (llType==LL_GAMMA)       return STR_LL_GAMMA;
    if (llType==LL_LOGNORMAL)   return STR_LL_LOGNORMAL;
    if (llType==LL_MULTINOMIAL) return STR_LL_MULTINOMIAL;
    if (llType==LL_NONE)        return STR_LL_NONE;
    if (llType==LL_NORM2)       return STR_LL_NORM2;
    if (llType==LL_NORMAL)      return STR_LL_NORMAL;
    std::cout<<"Likelihood type integer '"<<llType<<"' not recognized."<<std::endl;
    std::cout<<"Aborting..."<<std::endl;
    exit(-1);
    return type;
}