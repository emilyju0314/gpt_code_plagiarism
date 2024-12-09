wts::adstring_matrix tcsam::convertPCs(ParameterGroupInfo * pgi){
    //cout<<"starting tcsam::convertPCs for "<<pgi->name<<endl;
    int nIVs = pgi->nIVs;
    int nPCs = pgi->nPCs;
    //cout<<"nIVs = "<<nIVs<<"; nPCs = "<<nPCs<<endl;
    //wts::adstring_matrix::debug = 1;
    wts::adstring_matrix a(1,nIVs,0,nPCs);
    //wts::adstring_matrix::debug = 0;
    //cout<<"allocated a"<<endl;
    int ibsIdx = 1;
    for (int i=1;i<=nIVs;i++){
        if (pgi->lblIVs(i)==tcsam::STR_SEX)             {a(i,0)=pgi->lblIVs(i);} else
        if (pgi->lblIVs(i)==tcsam::STR_MATURITY_STATE)  {a(i,0)=pgi->lblIVs(i);} else
        if (pgi->lblIVs(i)==tcsam::STR_SHELL_CONDITION) {a(i,0)=pgi->lblIVs(i);} else 
        if ((pgi->ibsIdxs.allocated())&&(i==pgi->ibsIdxs(ibsIdx))){
            a(i,0)=pgi->ppIBSs[ibsIdx-1]->getType();
            if (ibsIdx<pgi->nIBSs) ibsIdx++;//increment to next
        }
    }
    for (int r=1;r<=nPCs;r++){//loop over rows
        //cout<<"r = "<<r<<endl;
        int ibsIdx = 1;
        for (int i=1;i<=nIVs;i++){//loop over index variables
            //cout<<tb<<"i = "<<i<<" "<<pgi->lblIVs(i)<<tb<<pgi->in(r,i)<<endl;
            if (pgi->lblIVs(i)==tcsam::STR_SEX)             {a(i,r)=tcsam::getSexType(pgi->in(r,i));}      else
            if (pgi->lblIVs(i)==tcsam::STR_MATURITY_STATE)  {a(i,r)=tcsam::getMaturityType(pgi->in(r,i));} else
            if (pgi->lblIVs(i)==tcsam::STR_SHELL_CONDITION) {a(i,r)=tcsam::getShellType(pgi->in(r,i));}    else 
            if ((pgi->ibsIdxs.allocated())&&(i==pgi->ibsIdxs(ibsIdx))){
                a(i,r)=pgi->ppIBSs[ibsIdx-1]->getIndexBlock(r)->asString();
                if (ibsIdx<pgi->nIBSs) ibsIdx++;//increment to next
            } else {a(i,r)=str(pgi->in(r,i));}
        }
    }
    //cout<<a<<endl;
    //cout<<"finished tcsam::convertPCs for "<<pgi->name<<endl;
    return a;
}