adstring_array VectorVectorInfo::getScaleTypes(void){
    if (debug) rpt::echo<<"starting VectorVectorInfo::getScaleTypes(void) for "<<name<<endl;
    adstring_array v(1,nVIs);
    if (ppVIs) for (int i=1;i<=nVIs;i++) v(i) = ppVIs[i-1]->getScaleType();
    if (debug) rpt::echo<<"finished VectorVectorInfo::getScaleTypes(void) for "<<name<<endl;
    return v;
}