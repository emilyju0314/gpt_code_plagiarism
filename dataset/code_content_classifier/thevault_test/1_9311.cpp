void ParameterGroupInfo::read(cifstream& is){
    if (debug) cout<<"starting void ParameterGroupInfo::read(is)"<<endl;
    adstring str; 
    //read parameter combinations
    is>>str;
    if (debug) cout<<str<<tb<<"#Required keyword (PARAMETER_COMBINATIONS)"<<endl;
    rpt::echo<<str<<tb<<"#Required keyword (PARAMETER_COMBINATIONS)"<<endl;
    if (str=="PARAMETER_COMBINATIONS"){
        is>>nPCs;
        if (debug) cout<<nPCs<<tb<<"#number of parameter combinations"<<endl;
        rpt::echo<<nPCs<<tb<<"#number of parameter combinations"<<endl;
        if (nPCs>0){
            if (debug){
                cout<<"#id  ";
                for (int i=1;i<=nIVs;i++) cout<<lblIVs(i)<<tb; 
                for (int i=1;i<=nPVs;i++) cout<<lblPVs(i)<<tb; 
                for (int i=1;i<=nXIs;i++) cout<<lblXIs(i)<<tb; 
            }
            rpt::echo<<"#id  "; 
            for (int i=1;i<=nIVs;i++) rpt::echo<<lblIVs(i)<<tb; 
            for (int i=1;i<=nPVs;i++) rpt::echo<<lblPVs(i)<<tb; 
            for (int i=1;i<=nXIs;i++) rpt::echo<<lblXIs(i)<<tb; 
            if (debug) cout<<tb<<"label"<<tb<<endl;
            rpt::echo<<tb<<"label"<<tb<<endl;
            if (debug) cout<<"About to allocate ppIBSs"<<endl;
            for (int i=0;i<nIBSs;i++) ppIBSs[i]->allocate(nPCs);
            if (debug) cout<<"Finished allocating ppIBSs"<<endl;
            //read parameters combinations definition matrix
            int ibsIdx=1;
            in.allocate(1,nPCs,1,nIVs+nPVs+nXIs);
            if (nXIs) xd.allocate(1,nPCs,1,nXIs);
            pcLabels.allocate(1,nPCs);
            for (int r=1;r<=nPCs;r++){//loop over rows
                is>>str; //read id
                rpt::echo<<str<<tb;
                if (debug) cout<<"pc = "<<r<<tb<<"looping over index variables"<<endl;
                for (int i=1;i<=nIVs;i++){//loop over index variables
                    is>>str;
                    if (debug) cout<<tb<<"index variable"<<tb<<i<<tb<<str<<endl;
                    rpt::echo<<str<<tb;
                    if (lblIVs(i)==tcsam::STR_SEX)             {in(r,i) = tcsam::getSexType(str);}      else
                    if (lblIVs(i)==tcsam::STR_MATURITY_STATE)  {in(r,i) = tcsam::getMaturityType(str);} else
                    if (lblIVs(i)==tcsam::STR_SHELL_CONDITION) {in(r,i) = tcsam::getShellType(str);}    else
                    if ((ibsIdxs.allocated())&&(i==ibsIdxs(ibsIdx))){//variable is a block
                        ppIBSs[ibsIdx-1]->getIndexBlock(r)->parse(str);
                        in(r,i)=ibsIdx;//index to associated IndexBlockSet
                        if (ibsIdx<nIBSs) ibsIdx++;//increment to next IBS
                    } else {in(r,i)=::atoi(str);}
                }
                if (debug) cout<<"looping over parameter indices"<<endl;
                for (int p=1;p<=nPVs;p++) {is>>in(r,nIVs+p); rpt::echo<<in(r,nIVs+p)<<tb;}  
                if (debug) cout<<"looping over extra variables"<<endl;
                for (int x=1;x<=nXIs;x++) {//loop over "extra" variables
                    is>>str;
                    if (debug) cout<<str<<endl;
                    rpt::echo<<str<<tb;
                    if (lblXIs(x)==tcsam::STR_SELFCN){
                        //identify selectivity function and return function index
                        in(r,nIVs+nPVs+x) = SelFcns::getSelFcnID(str);
                    } else {
                        in(r,nIVs+nPVs+x)=::atoi(str);
                        xd(r,x)=::atof(str);
                    }
                    //rpt::echo<<"x = "<<x<<tb<<"str = "<<str<<tb<<"in() = "<<in(r,nIVs+nPVs+x)<<tb<<"xd() = "<<xd(r,x)<<endl;
                }
                is>>pcLabels(r);
                if (debug) cout<<pcLabels(r)<<endl;
                rpt::echo<<pcLabels(r)<<tb;
                rpt::echo<<endl;
                if (debug) {
                    cout<<"pc row "<<r<<": "<<in(r);
                    if (nXIs) cout<<tb<<"xd: "<<xd(r);
                    cout<<endl;
                }
            }//--r
            //revert reading back to sub-class to read values for parameters
        }//nPCs>0
    } else {
        cout<<"Reading ParameterGroupInfo for '"<<name<<"' from file "<<is.get_file_name()<<endl;
        cout<<"Expected 'PARAMETER_COMBINATIONS' keyword but got '"<<str<<"'."<<endl;
        cout<<"Aborting..."<<endl;
        exit(-1);
    }
    if (debug) ParameterGroupInfo::write(cout);        
    
    if (nIVs) createIndices();
    
    //now back to sub-class to read values for parameters
    if (debug) cout<<"finished void ParameterGroupInfo::read(is)"<<endl;
}