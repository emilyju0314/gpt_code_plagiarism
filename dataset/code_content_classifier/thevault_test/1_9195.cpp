dvar3_array PopDyInfo::applyNM(double dt, dvar3_array& n_msz, ostream& cout){
    if (debug) cout<<"starting PopDyInfo::applyNM(dt,n_msz)"<<endl;
    RETURN_ARRAYS_INCREMENT();
    np_msz.initialize();
    for (int s=1;s<=nSCs;s++){
        for (int m=1;m<=nMSs;m++){ 
            np_msz(m,s) = elem_prod(exp(-M_msz(m,s)*dt),n_msz(m,s)); //survival over dt
        }//m
    }//s  
    if (debug) {
        cout<<"#--np_msz = "<<&np_msz<<endl;
        cout<<"np_msz = "<<endl; wts::print(np_msz,cout,1); cout<<endl;
    }
    if (debug) cout<<"finished PopDyInfo::applyNM(dt,n_msz)"<<endl;
    RETURN_ARRAYS_DECREMENT();
    return 1.0*np_msz;
}