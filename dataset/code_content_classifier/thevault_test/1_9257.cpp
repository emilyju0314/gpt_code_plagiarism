adstring_array NumberVectorInfo::getScaleTypes(void){
    if (debug) rpt::echo<<"starting NumberVectorInfo::getScaleTypes(void) "<<this<<endl;
    adstring_array types(1,nNIs);
    if (ppNIs) for (int i=1;i<=nNIs;i++) types(i) = ppNIs[i-1]->getScaleType();
    if (debug) rpt::echo<<"finished NumberVectorInfo::getScaleTypes(void) "<<this<<endl;
    return types;
}