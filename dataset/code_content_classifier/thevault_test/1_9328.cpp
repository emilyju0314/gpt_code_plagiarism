dvariable OFL_Calculator::calcFofl(dvariable Bmsy, dvariable Fmsy, dvar3_array& n_msz, ostream& cout){
    if (debug) {
        cout<<"starting double OFL_Calculator::calcFofl(Bmsy, Fmsy,n_msz)"<<endl;
        cout<<"Bmsy = "<<Bmsy<<"; Fmsy = "<<Fmsy<<endl;
        cout<<"n_msz = "<<endl;wts::print(n_msz,cout,1); cout<<endl;        
    }
    RETURN_ARRAYS_INCREMENT();
    
    PopProjector* pPrjM = pTCM->pEC->pPP;
    
    //start with guess for Fofl based on currMMB
    dvariable currMMB = pPrjM->projectMatureBiomassAtMating(Fmsy,n_msz,cout);
    if (debug) cout<<"init currMMB = "<<currMMB<<"; B/Bmsy = "<<currMMB/Bmsy<<endl;
    dvariable Fofl = calcHCR(currMMB,Bmsy,Fmsy,cout);
    if (debug) cout<<"init Fofl = "<<Fofl<<endl;
    //now iterate until Fofl yields currMMB
    dvariable Foflp = 0.0;
    int i = 1;
    while (i++ < maxIts){
        if (debug&&(i==maxIts)) cout<<"HCR iteration for Fofl = "<<i<<endl;
        //calculate currMMB based on Fofl
        currMMB = pPrjM->projectMatureBiomassAtMating(Fofl,n_msz,cout);
        if (debug) cout<<"--updated prjMMB = "<<currMMB<<"; B/Bmsy = "<<currMMB/Bmsy<<endl;
        //update Fofl based on currMMB
        Foflp = Fofl;
        Fofl  = calcHCR(currMMB,Bmsy,Fmsy,cout);
        if (debug) cout<<"--updated Fofl = "<<Fofl<<"; delF = "<<Fofl - Foflp<<endl;
    }
    double criF = 0.001;
    if (sfabs(value(Fofl - Foflp))>criF){
        cout<<endl<<"-------ERROR!!-------"<<endl;
        cout<<"Convergence in calcFofl failed: |delF| = "<<sfabs(value(Fofl - Foflp))<<" > "<<criF<<endl;
        cout<<"-------ERROR!!-------"<<endl<<endl;
    }
    prjMMB = currMMB;
    if (debug) {
        cout<<"Fofl   = "<<Fofl<<endl;
        cout<<"prjMMB = "<<prjMMB<<endl;
        cout<<"finished double OFL_Calculator::calcFofl(Bmsy, Fmsy,n_msz)"<<endl;
    }
    RETURN_ARRAYS_DECREMENT();
    return Fofl;
}