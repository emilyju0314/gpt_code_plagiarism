dvar3_array PopDyInfo::applyMG(dvar3_array& n_msz, ostream& cout){
    if (debug) cout<<"starting PopDyInfo::applyMG(n_msz)"<<endl;
    RETURN_ARRAYS_INCREMENT();
    np_msz.initialize();
    np_msz(IMMATURE,NEW_SHELL) = elem_prod(1.0-Th_sz(NEW_SHELL),T_szz(NEW_SHELL)*n_msz(IMMATURE,NEW_SHELL));
//    np_msz(IMMATURE,OLD_SHELL) = 0.0;
    np_msz(MATURE,NEW_SHELL)   = elem_prod(    Th_sz(NEW_SHELL),T_szz(NEW_SHELL)*n_msz(IMMATURE,NEW_SHELL));
    np_msz(MATURE,OLD_SHELL)   = n_msz(MATURE,NEW_SHELL)+n_msz(MATURE,OLD_SHELL);
    if (debug) {
        cout<<"#--np_msz = "<<&np_msz<<endl;
        cout<<"np_msz = "<<endl; wts::print(np_msz,cout,1); cout<<endl;
    }
    if (debug) cout<<"finished PopDyInfo::applyMG(n_msz)"<<endl;
    RETURN_ARRAYS_DECREMENT();
    return 1.0*np_msz;
}