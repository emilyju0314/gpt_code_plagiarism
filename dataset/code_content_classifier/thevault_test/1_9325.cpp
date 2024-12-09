dvar3_array Equilibrium_Calculator::calcEqNatZFM(dvariable R, dvariable dirF, ostream& cout){
    if (debug) {
        cout<<"starting dvar3_array Equilibrium_Calculator::calcEqNatZFM(double R)"<<endl;
        cout<<"R = "<<R<<". dirF = "<<dirF<<endl;
    }
    RETURN_ARRAYS_INCREMENT();
    
    double dtM = pPP->dtM;//time to mating
    double dtF = pPP->dtF;//time to fisheries
    
    dvar3_array S1_msz(1,nMSs,1,nSCs,1,nZBs);//survival until molting/mating
    dvar3_array S2_msz(1,nMSs,1,nSCs,1,nZBs);//survival after molting/mating
    dvar3_array n_msz(1,nMSs,1,nSCs,1,nZBs); //equilibrium size distribution on July 1
    
    if (dtF<=dtM){
        //fisheries occur BEFORE molting/growth/maturity 
        dvar3_array S1a_msz = pPP->pPI->calcSurvival(dtF,cout);     //survival prior to fisheries
        dvar3_array S1F_msz = pPP->pCI->calcSurvival(dirF,cout);    //survival of fisheries
        dvar3_array S1b_msz = pPP->pPI->calcSurvival(dtM-dtF,cout); //survival after fisheries, before mating
        if (debug){
            cout<<"#--S1a_msz = "<<&S1a_msz<<endl;
            cout<<"#--S1F_msz = "<<&S1F_msz<<endl;
            cout<<"#--S1b_msz = "<<&S1b_msz<<endl;
        }
        S1_msz = elem_prod(S1b_msz,elem_prod(S1F_msz,S1a_msz));//total survival before mating
        S2_msz = pPP->pPI->calcSurvival(1.0-dtM,cout);//survival after mating/molting/growth
    } else {
        //fisheries occur AFTER molting/growth/maturity 
        S1_msz = pPP->pPI->calcSurvival(dtM,cout);                   //survival before mating/molting/growth
        dvar3_array S2a_msz = pPP->pPI->calcSurvival(dtF-dtM,cout);     //survival afterMGM, before fisheries
        dvar3_array S2F_msz = pPP->pCI->calcSurvival(dirF,cout);        //survival of fisheries
        dvar3_array S2b_msz = pPP->pPI->calcSurvival(1.0-dtF,cout);     //survival after fisheries, to year end
        if (debug){
            cout<<"#--S2a_msz = "<<&S2a_msz<<endl;
            cout<<"#--S2F_msz = "<<&S2F_msz<<endl;
            cout<<"#--S2b_msz = "<<&S2b_msz<<endl;
        }
        S2_msz = elem_prod(S2b_msz,elem_prod(S2F_msz,S2a_msz)); //total survival after MGM to year end
    }
    dvar_vector R_zp = R*pPP->pPI->R_z;
    n_msz = calcEqNatZ(R_zp, S1_msz, pPP->pPI->Th_sz, pPP->pPI->T_szz, S2_msz, cout);
    
    if (debug) {
        cout<<"n_msz = "<<endl; wts::print(n_msz,cout,1);
        cout<<"finished dvar3_array Equilibrium_Calculator::calcEqNatZFM(double R)"<<endl;
    }
    RETURN_ARRAYS_DECREMENT();
    return n_msz; 
}