adstring_array VectorVectorInfo::getLabels(void){
    adstring_array arr(1,1);
    if (nVIs){
        adstring_array arr(1,nVIs);
        for (int i=1;i<=nVIs;i++) arr(i) = (*this)[i]->label;
        return(arr);
    }
    return(arr);
}