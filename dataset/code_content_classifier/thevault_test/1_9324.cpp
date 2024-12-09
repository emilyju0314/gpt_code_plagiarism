dvar3_array Equilibrium_Calculator::calcEqNatZF0(dvariable R, ostream& cout){
    if (debug) {
        cout<<"starting dvar3_array Equilibrium_Calculator::calcEqNatZF0(double R)"<<endl;
        cout<<"R = "<<R<<endl;
    }
    RETURN_ARRAYS_INCREMENT();

    dvar3_array S1_msz = pPP->pPI->calcSurvival(pPP->dtM,cout);
    dvar3_array S2_msz = pPP->pPI->calcSurvival(1.0-pPP->dtM,cout);
    if (debug){
        cout<<"#--S1_msz = "<<&S1_msz<<endl;
        cout<<"#--S2_msz = "<<&S2_msz<<endl;
    }
    
    dvar_vector R_zp = R*pPP->pPI->R_z;
    
    dvar3_array n_msz = calcEqNatZ(R_zp, S1_msz, pPP->pPI->Th_sz, pPP->pPI->T_szz, S2_msz,cout);
    
    if (debug) {
        cout<<"Equilibrium_Calculator::calcEqNatZF0: n_msz = "<<endl; wts::print(n_msz,cout,1); cout<<endl;
        cout<<"finished dvar3_array Equilibrium_Calculator::calcEqNatZF0(double R)"<<endl;
    }
    RETURN_ARRAYS_DECREMENT();
    return n_msz;
}