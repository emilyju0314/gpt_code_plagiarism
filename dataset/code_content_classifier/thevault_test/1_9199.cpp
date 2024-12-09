void CatchInfo::setCaptureRates(dvar4_array& capFp_fmsz){
    if (debug) cout<<"starting CatchInfo::setCaptureRates(dvar4_array& capFp_fmsz)"<<endl;
    for (int f=1;f<=nFsh;f++) cpF_fmsz(f) = 1.0*capFp_fmsz(f);
    if (debug) cout<<"#--cpF_fmsz = "<<&cpF_fmsz<<endl<<"capFp_fmsz = "<<&capFp_fmsz<<endl;
    if (debug) cout<<"finished CatchInfo::setCaptureRates(dvar4_array& capFp_fmsz)"<<endl;
}