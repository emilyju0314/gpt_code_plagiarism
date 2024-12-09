dvar_vector SelFcns::nonparametric(dvector& z, dvar_vector& params, int idZ){
    RETURN_ARRAYS_INCREMENT();
    if (debug) cout<<"Starting SelFcns::nonparametric(...)"<<endl;
    dvariable n; n.initialize();
    dvar_vector s(z.indexmin(),z.indexmax()); s.initialize();
    s = 1.0/(1.0+mfexp(-params));//unnormalized
    if (idZ>0) s *= (1.0+mfexp(-params[idZ]));//normalized to 1
    if (debug) cout<<"Finished SelFcns::nonparametric(...)"<<endl;
    RETURN_ARRAYS_DECREMENT();
    return s;
}