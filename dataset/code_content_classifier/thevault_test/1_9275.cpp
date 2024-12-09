void BoundedNumberVectorInfo::write(ostream & os){
    if (debug) rpt::echo<<"Starting BoundedNumberVectorInfo::write(ostream & os) for "<<name<<endl;
    os<<tb<<nNIs<<"  #number of bounded parameters"<<endl;
    os<<"#           lower  upper  initial param        resample  prior   prior  prior   prior"<<endl;
    os<<"#id jitter? bounds bounds  value  scale  phase  values?  weight  type   params  consts  label"<<endl;
    if (nNIs){
        for (int p=0;p<(nNIs-1);p++) os<<(p+1)<<tb<<(*ppNIs[p])<<endl;
        os<<nNIs<<tb<<(*ppNIs[nNIs-1]);
    }
    if (debug) rpt::echo<<endl<<"Finished BoundedNumberVectorInfo::write(ostream & os)"<<endl;
}