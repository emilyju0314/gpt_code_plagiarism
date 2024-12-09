OFLResults* OFL_Calculator::calcOFLResults(dvar_vector R, dvar4_array& n_xmsz, ostream& cout){
    if (debug) cout<<"starting OFLResults OFL_Calculator::calcOFLResults(R,n_xmsz,cout)"<<endl;
    int nFsh = pTCM->pEC->pPP->pCI->nFsh;
    OFLResults* res = new OFLResults();
    
    res->avgRec_x = R;
    res->finlNatZ_xmsz.allocate(1,tcsam::nSXs,
                                1,tcsam::nMSs,
                                1,tcsam::nSCs,
                                1,pTCM->pEC->pPP->nZBs);
    res->finlNatZ_xmsz = n_xmsz;
    res->pPDIM = pTCM->pEC->pPP->pPI;
    res->pCIM  = pTCM->pEC->pPP->pCI;
    if (tcsam::nSXs>1){
        res->pPDIF = pTCF->pEC->pPP->pPI;
        res->pCIF  = pTCF->pEC->pPP->pCI;
    }
    res->curB     = pTCM->pEC->pPP->pPI->calcMatureBiomass(n_xmsz(MALE),cout);
    if (debug) cout<<"calcOFLResults: calculated curB"<<endl;
        
    res->eqNatZF0_xmsz.allocate(1,tcsam::nSXs,
                                1,tcsam::nMSs,
                                1,tcsam::nSCs,
                                1,pTCM->pEC->pPP->nZBs);
    res->eqNatZF0_xmsz(MALE) = pTCM->pEC->calcEqNatZF0(R(MALE),cout);
    if (debug) cout<<"calcOFLResults: calculated eq NatZ(MALE) for F=0"<<endl;
    if (tcsam::nSXs>1) {
        res->eqNatZF0_xmsz(FEMALE) = pTCF->pEC->calcEqNatZF0(R(FEMALE),cout);
        if (debug) cout<<"calcOFLResults: calculated eq NatZ(FEMALE) for F=0"<<endl;
    }
            
    res->Fmsy = pTCM->calcFmsy(R(MALE),cout);//also calculates B0 and Bmsy
    res->B0   = pTCM->B0;
    res->Bmsy = pTCM->Bmsy;
    res->MSY  = calcMSY(R,res->Fmsy,cout);
    if (debug) cout<<"calcOFLResults: calculated MSY"<<endl;
    
    res->eqNatZFM_xmsz.allocate(1,tcsam::nSXs,
                                1,tcsam::nMSs,
                                1,tcsam::nSCs,
                                1,pTCM->pEC->pPP->nZBs);
    if (debug) {
        cout<<"calcOFLResults: allocated eq NatZ for F=Fmsy"<<endl;
    }
    res->eqNatZFM_xmsz(MALE) = pTCM->pEC->calcEqNatZFM(R(MALE),res->Fmsy,cout);
    if (debug) cout<<"calcOFLResults: calculated eq NatZ(MALE) for F=Fmsy"<<endl;
    if (tcsam::nSXs>1) {
        res->eqNatZFM_xmsz(FEMALE) = pTCF->pEC->calcEqNatZFM(R(FEMALE),res->Fmsy,cout);
        if (debug) cout<<"calcOFLResults: calculated eq NatZ(FEMALE) for F=Fmsy"<<endl;
    }
            
    res->Fofl = calcFofl(res->Bmsy,res->Fmsy,n_xmsz(MALE),cout);
    if (debug) cout<<"calcOFLResults: calculated Fofl"<<endl;
    res->prjB = prjMMB;
    res->OFL  = calcOFL(res->Fofl,n_xmsz,cout);
    if (debug) cout<<"calcOFLResults: calculated OFL"<<endl;
    
    res->ofl_fx.allocate(0,nFsh,1,tcsam::nSXs);
    res->ofl_fx = ofl_fx;
    if (debug) cout<<"finished OFLResults* OFL_Calculator::calcOFLResults(R,n_xmsz,cout)"<<endl;
    return res;
}