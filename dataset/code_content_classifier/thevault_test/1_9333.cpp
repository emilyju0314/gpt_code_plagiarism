dvar_vector SelFcns::ascnormal(dvector& z, dvar_vector& params, double fsZ){
    RETURN_ARRAYS_INCREMENT();
    if (debug) cout<<"Starting SelFcns::ascnormal(...)"<<endl;
    dvariable n; n.initialize();
    dvar_vector s(z.indexmin(),z.indexmax()); s.initialize();
    dvar_vector ascN(z.indexmin(),z.indexmax()); ascN.initialize();
    dvar_vector ascJ(z.indexmin(),z.indexmax()); ascJ.initialize();
    double slp = 5.0;
    dvariable ascMnZ = params(1);//size at which ascending limb hits 1
    dvariable ascWdZ = params(2);//width of ascending limb
    ascN = mfexp(-0.5*square((z-ascMnZ)/ascWdZ));
    ascJ = 1.0/(1.0+mfexp(slp*(z-(ascMnZ))));
    s = elem_prod(ascJ,ascN)+(1.0-ascJ);
    if (debug) cout<<"Finished SelFcns::ascnormal(...)"<<endl;
    RETURN_ARRAYS_DECREMENT();
    return s;
}