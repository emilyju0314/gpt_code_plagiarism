int SelFcns::getSelFcnID(adstring str){
    int id = 0;
    str.to_lower();
    if (str==STR_ASCLOGISTIC)         return ID_ASCLOGISTIC;
    if (str==STR_ASCLOGISTICLN50)     return ID_ASCLOGISTICLN50;
    if (str==STR_ASCLOGISTIC5095)     return ID_ASCLOGISTIC5095;
    if (str==STR_ASCLOGISTIC5099)     return ID_ASCLOGISTIC5099;
    if (str==STR_ASCLOGISTIC50LN95)   return ID_ASCLOGISTIC50LN95;
    if (str==STR_ASCLOGISTICLN50LN95) return ID_ASCLOGISTICLN50LN95;
    if (str==STR_DBLLOGISTIC)         return ID_DBLLOGISTIC;
    if (str==STR_DBLLOGISTICLND50)    return ID_DBLLOGISTICLND50;
    if (str==STR_DBLLOGISTIC5095)     return ID_DBLLOGISTIC5095;
    if (str==STR_DBLLOGISTIC50LN95)   return ID_DBLLOGISTIC50LN95;
    if (str==STR_DBLLOGISTICLN50LN95) return ID_DBLLOGISTICLN50LN95;
    if (str==STR_ASCLOGISTIC5099)     return ID_ASCLOGISTIC5099;
    if (str==STR_ASCLOGISTIC95LN50)   return ID_ASCLOGISTIC95LN50;
    if (str==STR_ASCNORMAL)           return ID_ASCNORMAL;
    if (str==STR_DBLNORMAL4)          return ID_DBLNORMAL4;
    if (str==STR_DBLNORMAL6)          return ID_DBLNORMAL6;
    if (str==STR_NONPARAMETRIC)       return ID_NONPARAMETRIC;
    cout<<"Error in SelFcns::getSelFcnID(adstring str)"<<endl;
    cout<<"Function name '"<<str<<"' not a valid selectivity function name."<<endl;
    cout<<"Aborting..."<<endl;
    exit(-1);
    return id;
}