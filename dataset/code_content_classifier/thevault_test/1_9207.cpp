void MultiYearPopProjector::project(int n, dvariable R, dvariable dirF, dvar3_array& n_msz, ostream& cout){
    if (debug) cout<<"Starting MultiYearPopProjector::project(n,R,n_msz)"<<endl;
    if (debug) cout<<"nFsh = "<<pPP->nFsh<<endl;
    n_ymsz.deallocate(); matBio_y.deallocate(); rm_yf.deallocate(); dm_yf.deallocate(); totCM_y.deallocate();
    n_ymsz.allocate(0,n,1,pPP->nMSs,1,pPP->nSCs,1,pPP->nZBs);
    matBio_y.allocate(1,n);
    totCM_y.allocate(1,n);
    cp_yf.allocate(0,n,1,pPP->nFsh);
    rm_yf.allocate(0,n,1,pPP->nFsh);
    dm_yf.allocate(0,n,1,pPP->nFsh);
    n_ymsz.initialize();
    matBio_y.initialize();
    totCM_y.initialize();
    cp_yf.initialize();
    rm_yf.initialize();
    dm_yf.initialize();
    n_ymsz(0) = n_msz;
//    if (debug){PopProjector::debug=1;PopDyInfo::debug=1;}
    for (int y=1;y<=n;y++){
        dvar3_array np_msz = pPP->project(dirF,n_ymsz(y-1),cout);
        if (debug) cout<<"n_ymsz(y-1) = "<<&(n_ymsz(y-1))<<endl<<"np_msz = "<<&np_msz<<endl;
        matBio_y(y) = pPP->matBio;
        for (int f=1;f<=pPP->nFsh;f++) {
            cp_yf(y,f) = pPP->pPI->calcTotalBiomass(pPP->pCI->cpN_fmsz(f),cout);
            rm_yf(y,f) = pPP->pPI->calcTotalBiomass(pPP->pCI->rmN_fmsz(f),cout);
            dm_yf(y,f) = pPP->pPI->calcTotalBiomass(pPP->pCI->dmN_fmsz(f),cout);
        }
        totCM_y(y) = pPP->pPI->calcTotalBiomass(pPP->pCI->cmN_msz,cout);
        n_ymsz(y)  = pPP->addRecruitment(R,np_msz,cout);
    }
//    if (debug){PopProjector::debug=0;PopDyInfo::debug=0;}
    if (debug){
        cout<<"matBio_y = "<<endl<<matBio_y<<endl;
        cout<<"totCM_y  = "<<endl<<totCM_y<<endl;
        cout<<"cp_yf    = "<<endl<<cp_yf<<endl;
        cout<<"rm_yf    = "<<endl<<rm_yf<<endl;
        cout<<"dm_yf    = "<<endl<<dm_yf<<endl;
    }
    if (debug) cout<<"Finished MultiYearPopProjector::project(n,R,n_msz)"<<endl;
}