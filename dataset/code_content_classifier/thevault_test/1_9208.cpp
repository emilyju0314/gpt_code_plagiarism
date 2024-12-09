void MultiYearPopProjector::projectUnFished(int n, dvariable R, dvar3_array& n_msz, ostream& cout){
    if (debug) cout<<"Starting MultiYearPopProjector::projectUnFished(n,R,n_msz)"<<endl;
    n_ymsz.deallocate(); matBio_y.deallocate(); rm_yf.deallocate(); dm_yf.deallocate(); totCM_y.deallocate();
    n_ymsz.allocate(0,n,1,pPP->nMSs,1,pPP->nSCs,1,pPP->nZBs);
    matBio_y.allocate(1,n);
    rm_yf.allocate(0,n,1,pPP->nFsh);
    dm_yf.allocate(0,n,1,pPP->nFsh);
    totCM_y.allocate(1,n);
    n_ymsz.initialize();
    matBio_y.initialize();
    rm_yf.initialize();
    dm_yf.initialize();
    totCM_y.initialize();
    n_ymsz(0) = n_msz;
    for (int y=1;y<=n;y++){
        dvar3_array np_msz = pPP->projectUnFished(n_ymsz(y-1),cout);
        if (debug) cout<<"n_ymsz(y-1) = "<<&(n_ymsz(y-1))<<endl<<"np_msz = "<<&np_msz<<endl;
        matBio_y(y) = pPP->matBio;
        n_ymsz(y) = pPP->addRecruitment(R,np_msz,cout);
        if (debug) cout<<"n_ymsz(y) = "<<&(n_ymsz(y))<<endl;
    }
    if (debug){
        cout<<"matBio = "<<endl<<matBio_y<<endl;
        cout<<"Finished MultiYearPopProjector::projectUnFished(n,R,n_msz)"<<endl;
    }
}