BoundedNumberVectorInfo* ParameterGroupInfo::read(cifstream& is, adstring& lbl, BoundedNumberVectorInfo* pBNVI){
    adstring param;
    is>>param;
    if (param==lbl){
        if (debug) cout<<"Reading "<<lbl<<endl;
        pBNVI = new BoundedNumberVectorInfo(lbl);
        is>>(*pBNVI);
        if (debug) cout<<"ptr to "<<lbl<<": "<<pBNVI<<endl<<(*pBNVI)<<endl;
    } else {
        tcsam::readError(is,lbl,param);
        exit(-1);
    }
    return pBNVI;
}