adstring tcsam::getErrorScaleType(int i){
    if (i==SCLTYPE_VAR) return STR_VAR;
    if (i==SCLTYPE_STD) return STR_STD;
    if (i==SCLTYPE_CV)  return STR_CV;
    std::cout<<"Unrecognized scale type '"<<i<<"'"<<std::endl;
    std::cout<<"Aborting..."<<std::endl;
    exit(-1);
    return adstring("");
}