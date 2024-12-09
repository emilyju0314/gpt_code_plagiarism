dvar3_array PopProjector::projectUnFished(dvar3_array& n_msz, ostream& cout){
    if (debug) cout<<"starting PopProjector::projectUnFished(dirF, n_msz)"<<endl;
    RETURN_ARRAYS_INCREMENT();
    n1_msz.initialize();
    n2_msz.initialize();
    n3_msz.initialize();
    pCI->cmN_msz.initialize(); //set to 0's
    pCI->cpN_fmsz.initialize();//set to 0's
    pCI->rmN_fmsz.initialize();//set to 0's
    pCI->dmN_fmsz.initialize();//set to 0's
    //d3_array n1_msz(1,nMSs,1,nSCs,1,nZBs);
    //apply natural mortality BEFORE molting/growth/maturity
    n1_msz = pPI->applyNM(dtM, n_msz,cout);
    //apply molting/growth
    n2_msz = pPI->applyMG(n1_msz,cout);
    //apply natural mortality AFTER molting/growth
    n3_msz = pPI->applyNM(1.0-dtM, n2_msz,cout);

    //calculate mature biomass-at-mating from pre-molting/growth abundance
    matBio = pPI->calcMatureBiomass(n1_msz,cout);

    if (debug) {
        cout<<"matBio = "<<matBio<<endl;
        cout<<"finished PopProjector::projectUnFished(n_msz)"<<endl;   
    }
    RETURN_ARRAYS_DECREMENT();
    return 1.0*n3_msz;
}