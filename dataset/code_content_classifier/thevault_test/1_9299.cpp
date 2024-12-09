void ChelaHeightData::read(cifstream & is){
    if (debug){
        cout<<"start ChelaHeightData::read(...) "<<this<<std::endl;
        cout<<"#------------------------------------------"<<std::endl;
        cout<<"#file name is "<<is.get_file_name()<<std::endl;
        cout<<"#------------------------------------------"<<std::endl;
    }
    if (!is) {
        cout<<"Apparent error reading ChelaHeightData."<<std::endl;
        cout<<"#file name is "<<is.get_file_name()<<std::endl;
        cout<<"File stream is 'bad'--file may not exist!"<<std::endl;
        cout<<"Terminating!!"<<std::endl;
        exit(-1);
    }
    
    adstring str;
    is>>str;
    if (!(str==KW_CHELAHEIGHT_DATA)){
        cout<<"#Error reading effort data from "<<is.get_file_name()<<std::endl;
        cout<<"Expected keyword '"<<KW_CHELAHEIGHT_DATA<<"' but got '"<<str<<"'"<<std::endl;
        cout<<"Aborting..."<<std::endl;
        exit(-1);
    }
    is>>name;
    rpt::echo<<name<<tb<<"#dataset name"<<endl;
    is>>survey;
    rpt::echo<<survey<<tb<<"#survey name"<<endl;
    is>>str; llType = tcsam::getLikelihoodType(str);
    rpt::echo<<tcsam::getLikelihoodType(llType)<<tb<<"#likelihood function type"<<std::endl;
    is>>llWgt;
    rpt::echo<<llWgt<<tb<<"#likelihood weight (multiplier)"<<std::endl;
    is>>nObs;//number of observations
    rpt::echo<<nObs<<tb<<"#number of observations"<<std::endl;
    inpData_nc.allocate(1,nObs,1,4);
    is>>inpData_nc;
    rpt::echo<<"#year    size    nIndivs     fraction mature"<<std::endl<<inpData_nc<<std::endl;
    
    obsYear_n.allocate(1,nObs);
    obsSize_n.allocate(1,nObs);
    obsSS_n.allocate(1,nObs);
    obsPrMat_n.allocate(1,nObs);
    obsSizeBinIndex_n.allocate(1,nObs);
   
    obsYear_n  = wts::to_ivector(column(inpData_nc,1));
    obsSize_n  = column(inpData_nc,2);
    obsSS_n    = column(inpData_nc,3);
    obsPrMat_n = column(inpData_nc,4);
    obsSizeBinIndex_n = 0;//can't fill this in yet, need to use calcSizeBinIndices(zCs)
    
    rpt::echo<<"obsYear_n  = "<<obsYear_n<<endl;
    rpt::echo<<"obsSize_n  = "<<obsSize_n<<endl;
    rpt::echo<<"obsSS_n    = "<<obsSS_n  <<endl;
    rpt::echo<<"obsPrMat_n = "<<obsPrMat_n<<endl;
    
    if (debug) cout<<"end ChelaHeightData::read(...) "<<this<<std::endl;    
}