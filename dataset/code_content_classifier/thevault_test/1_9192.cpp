int tcsam::getLikelihoodType(adstring llType){
    int type = 0;
    if (llType==STR_LL_BINOMIAL)    return LL_BINOMIAL;
    if (llType==STR_LL_GAMMA)       return LL_GAMMA;
    if (llType==STR_LL_LOGNORMAL)   return LL_LOGNORMAL;
    if (llType==STR_LL_MULTINOMIAL) return LL_MULTINOMIAL;
    if (llType==STR_LL_NONE)        return LL_NONE;
    if (llType==STR_LL_NORM2)       return LL_NORM2;
    if (llType==STR_LL_NORMAL)      return LL_NORMAL;
    std::cout<<"Likelihood type keyword '"<<llType<<"' not recognized."<<std::endl;
    std::cout<<"Aborting..."<<std::endl;
    exit(-1);
    return type;
}