dvar3_array PopProjector::addRecruitment(dvariable R, dvar3_array& n_msz, ostream& cout){
    if (debug) cout<<"starting PopProjector::addRecruitment(R, n_msz)"<<endl;
    RETURN_ARRAYS_INCREMENT();
    dvar3_array np_msz = pPI->addRecruitment(R,n_msz,cout);
    if (debug) {
        cout<<"n_msz  = "<<&n_msz<<endl;
        cout<<"np_msz = "<<&np_msz<<endl;
    }
    if (debug) cout<<"finished PopProjector::addRecruitment(R, n_msz)"<<endl;
    RETURN_ARRAYS_DECREMENT();
    return np_msz;
}