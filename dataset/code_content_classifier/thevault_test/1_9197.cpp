dvar3_array PopDyInfo::addRecruitment(dvariable R, dvar3_array& n_msz, ostream& cout){
    if (debug) cout<<"starting PopDyInfo::addRecruitment(R, n_msz)"<<endl;
    RETURN_ARRAYS_INCREMENT();
    np_msz = 1.0*n_msz;
    np_msz(IMMATURE,NEW_SHELL) += R*R_z;
    if (debug) {
        cout<<"#--n_msz  = "<<&n_msz<<endl;
        cout<<"#--np_msz = "<<&np_msz<<endl;
        cout<<"np_msz = "<<endl; wts::print(np_msz,cout,1); cout<<endl;
    }

    if (debug) cout<<"finished PopDyInfo::addRecruitment(R, n_msz)"<<endl;
    RETURN_ARRAYS_DECREMENT();
    return 1.0*np_msz;
}