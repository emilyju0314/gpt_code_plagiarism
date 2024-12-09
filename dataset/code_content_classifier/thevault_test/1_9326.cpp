dvariable Equilibrium_Calculator::calcEqMatureBiomassAtMatingFM(dvariable R, dvariable dirF, ostream& cout){
    if (debug) {
        cout<<"starting Equilibrium_Calculator::calcEqMatureBiomassAtMatingFM(double R, double dirF)"<<endl;
        cout<<"R = "<<R<<". dirF = "<<dirF<<endl;
    }
    RETURN_ARRAYS_INCREMENT();
    //calculate equilibrium size distribution on July 1
    dvar3_array n_msz = calcEqNatZFM(R,dirF,cout);
    
    //equilibrium MMB
    dvariable eqMB = 0;//dummy value    
    //advance to population to time of mating
    if (pPP->dtF<=pPP->dtM){ //fisheries occur BEFORE molting/growth/maturity 
        if (debug) {cout<<"dtF<=dtM"<<endl;}
        //apply natural mortality BEFORE fisheries
        dvar3_array n1_msz = pPP->pPI->applyNM(pPP->dtF,n_msz,cout);
        if (debug) {cout<<"n1_msz ="<<endl; wts::print(n1_msz,cout,1);}
        //apply fisheries
        dvar3_array n2_msz = pPP->pCI->applyFM(dirF, n1_msz, cout);
        if (debug) {cout<<"n2_msz ="<<endl; wts::print(n2_msz,cout,1);}
        //apply natural mortality after fisheries but before molting/growth
        dvar3_array n3_msz(1,nMSs,1,nSCs,1,nZBs);
        if (pPP->dtF==pPP->dtM){
            if (debug) cout<<"dtF=dtM"<<endl;
            n3_msz = n2_msz;
        } else {
            if (debug) cout<<"dtF<dtM"<<endl;
            n3_msz = pPP->pPI->applyNM(pPP->dtM-pPP->dtF,n2_msz,cout);
        }
        if (debug) {cout<<"n3_msz ="<<endl; wts::print(n3_msz,cout,1);}
        
        //calculate mature biomass at mating
        eqMB = pPP->pPI->calcMatureBiomass(n3_msz,cout);
    } else { //fisheries occur AFTER molting/growth/maturity 
        if (debug) cout<<"dtF>dtM"<<endl;
        //apply natural mortality BEFORE molting/growth
        dvar3_array n1_msz = pPP->pPI->applyNM(pPP->dtM,n_msz,cout);
        if (debug) {cout<<"n1_msz ="<<endl; wts::print(n1_msz,cout,1);}
        
        //calculate mature biomass at mating
        eqMB = pPP->pPI->calcMatureBiomass(n1_msz,cout);
    }
    if (debug) {
        cout<<"eqMB = "<<eqMB<<endl;
        cout<<"finished Equilibrium_Calculator::calcEqMatureBiomassAtMatingFM(dvariable R, dvariable dirF)"<<endl;
    }
    RETURN_ARRAYS_DECREMENT();
    return eqMB;
}