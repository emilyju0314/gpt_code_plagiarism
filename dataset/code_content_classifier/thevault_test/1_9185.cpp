int tcsam::getErrorScaleType(adstring s){
    if (s==STR_VAR) return SCLTYPE_VAR;
    if (s==STR_STD) return SCLTYPE_STD;
    if (s==STR_CV)  return SCLTYPE_CV;
    std::cout<<"Unrecognized scale type '"<<s<<"'"<<std::endl;
    std::cout<<"Aborting..."<<std::endl;
    exit(-1);
    return 0;
}