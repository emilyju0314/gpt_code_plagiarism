void NumberVectorInfo::write(ostream & os){
    os<<tb<<nNIs<<"  #number of parameters"<<endl;
    os<<"#     param initial       resample  prior   prior  prior   prior"<<endl;
    os<<"#id   scale  value  phase  values?  weight  type   params  consts  label"<<endl;
    if (nNIs){
        for (int p=0;p<(nNIs-1);p++) os<<(p+1)<<tb<<(*ppNIs[p])<<endl;
        os<<nNIs<<tb<<(*ppNIs[nNIs-1]);
    }
}