adstring_array NumberVectorInfo::getLabels(void){
    adstring_array arr(1,1);
    if (nNIs){
        adstring_array arr(1,nNIs);
        for (int i=1;i<=nNIs;i++) arr(i) = ppNIs[i-1]->label;
        return(arr);
    }
    return(arr);
}