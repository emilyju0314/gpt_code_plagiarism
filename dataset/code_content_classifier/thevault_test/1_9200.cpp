void CatchInfo::setSelectivityFcns(dvar4_array& selFp_fmsz){
    if (debug) cout<<"starting CatchInfo::setSelectivityFcns(dvar3_array& selFp_fmsz)"<<endl;
    for (int f=1;f<=nFsh;f++) selF_fmsz(f) = 1.0*selFp_fmsz(f);
    if (debug) cout<<"#--selF_fmsz = "<<&selF_fmsz<<endl<<"selFp_fmsz = "<<&selFp_fmsz<<endl;
    if (debug) cout<<"finished CatchInfo::setSelectivityFcns(dvar3_array& selFp_fmsz)"<<endl;
}