MSE_Info::MSE_Info(){
    if (debug) cout<<"starting MSE_Info::MSE_Info()"<<endl;
    name = NAME;//assign static NAME to ParameterGroupInfo::name
    
    int k;
    //create "independent variables" for parameter group assignment
    nIVs = 1;//number of independent variables
    lblIVs.allocate(1,nIVs);
    k=1;
    lblIVs(k++) = tcsam::STR_FISHERY;
    //create index block sets for "BLOCKS" (e.g. year blocks)
    nIBSs = 0;
    ParameterGroupInfo::createIndexBlockSets();
    for (int i=1;i<=nIBSs;i++) ppIBSs[i-1]->setType(lblIVs(ibsIdxs(i)));
    
    nPVs=1;
    lblPVs.allocate(1,nPVs); dscPVs.allocate(1,nPVs);
    k=1;
    lblPVs(k) = "pMSE_LnC"; dscPVs(k++) = "ln-scale capture rate for directed fishery in MSE op mod";
    k=1;
    pMSE_LnC = new BoundedNumberVectorInfo(lblPVs(k));
    
    //create "extra indices"
    nXIs=0;
    
    if (debug) cout<<"finished MSE_Info::MSE_Info()"<<endl;
}