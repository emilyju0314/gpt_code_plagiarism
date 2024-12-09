void CatchInfo::setHandlingMortality(dvar_vector& pHM_f){
    if (debug) cout<<"starting CatchInfo::setHandlingMortality(dvar_vector& pHM_f)"<<endl;
    hm_f = 1.0*pHM_f;
    if (debug) cout<<"#--hm_f = "<<&hm_f<<endl<<"pHM_f = "<<&pHM_f<<endl;
    if (debug) cout<<"finished CatchInfo::setHandlingMortality(dvar_vector& pHM_f)"<<endl;
}