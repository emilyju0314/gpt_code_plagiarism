void CatchInfo::setRetentionFcns(dvar4_array& retFp_fmsz){
    if (debug) cout<<"finished CatchInfo::setRetentionFcns(dvar3_array& retFp_fmsz)"<<endl;
    for (int f=1;f<=nFsh;f++) retF_fmsz(f) = retFp_fmsz(f);
    if (debug) cout<<"#--retF_fmsz = "<<&retF_fmsz<<endl<<"retFp_fmsz = "<<&retFp_fmsz<<endl;
    if (debug) cout<<"finished CatchInfo::setRetentionFcns(dvar3_array& retFp_fmsz)"<<endl;
}