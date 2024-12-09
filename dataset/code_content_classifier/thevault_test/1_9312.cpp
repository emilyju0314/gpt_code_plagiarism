void ParameterGroupInfo::write(std::ostream& os){
    if (debug) cout<<"starting ParameterGroupInfo::write(std::ostream& os)"<<endl;
//    os<<(*ptrIBSs)<<endl;
    os<<"PARAMETER_COMBINATIONS"<<endl;
    os<<nPCs<<tb<<"#number of parameter combinations"<<endl;
    if (nPCs>0){
        os<<"#id  "; 
        for (int i=1;i<=nIVs;i++) os<<lblIVs(i)<<tb; 
        for (int i=1;i<=nPVs;i++) os<<lblPVs(i)<<tb; 
        for (int i=1;i<=nXIs;i++) os<<lblXIs(i)<<tb; 
        os<<"label"<<tb;
        os<<endl;
        for (int r=1;r<=nPCs;r++){//loop over rows
            os<<r<<tb;
            int ibsIdx = 1;
            for (int i=1;i<=nIVs;i++){//loop over index variables           
                if (lblIVs(i)==tcsam::STR_SEX)             {os<<tcsam::getSexType(in(r,i))<<tb;} else
                if (lblIVs(i)==tcsam::STR_MATURITY_STATE)  {os<<tcsam::getMaturityType(in(r,i))<<tb;} else
                if (lblIVs(i)==tcsam::STR_SHELL_CONDITION) {os<<tcsam::getShellType(in(r,i))<<tb;} else 
                if ((ibsIdxs.allocated())&&(i==ibsIdxs(ibsIdx))){
                    os<<(*ppIBSs[ibsIdx-1]->getIndexBlock(r))<<tb;
                    if (ibsIdx<nIBSs) ibsIdx++;//increment to next
                } else {os<<in(r,i)<<tb;}
            }
            for (int p=1;p<=nPVs;p++) os<<in(r,nIVs+p)<<tb;      //loop over parameter variables
            for (int x=1;x<=nXIs;x++) { //loop over extra indices
                if (lblXIs(x)==tcsam::STR_SELFCN) os<<SelFcns::getSelFcnID(in(r,nIVs+nPVs+x))<<tb; else
                os<<xd(r,x)<<tb;
        //        os<<in(r,nIVs+nPVs+x)<<tb;

            }
            os<<pcLabels(r)<<tb;
            os<<endl;
        }//--r
    }//nPCs>0
    if (debug) cout<<"finished ParameterGroupInfo::write(std::ostream& os)"<<endl;
}