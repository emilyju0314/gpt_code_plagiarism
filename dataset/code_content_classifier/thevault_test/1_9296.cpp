void GrowthData::read(cifstream & is){
    if (debug){
        cout<<"start GrowthData::read(...) "<<this<<std::endl;
        cout<<"#------------------------------------------"<<std::endl;
        cout<<"#file name is "<<is.get_file_name()<<std::endl;
        cout<<"#------------------------------------------"<<std::endl;
    }
    if (!is) {
        cout<<"Apparent error reading GrowthData."<<std::endl;
        cout<<"#file name is "<<is.get_file_name()<<std::endl;
        cout<<"File stream is 'bad'--file may not exist!"<<std::endl;
        cout<<"Terminating!!"<<std::endl;
        exit(-1);
    }
    
    adstring str;
    is>>str;
    if (!(str==KW_GROWTH_DATA)){
        cout<<"#Error reading effort data from "<<is.get_file_name()<<std::endl;
        cout<<"Expected keyword '"<<KW_GROWTH_DATA<<"' but got '"<<str<<"'"<<std::endl;
        cout<<"Aborting..."<<std::endl;
        exit(-1);
    }
    is>>name;
    rpt::echo<<name<<tb<<"#dataset name"<<endl;
    is>>str; llType = tcsam::getLikelihoodType(str);
    rpt::echo<<tcsam::getLikelihoodType(llType)<<tb<<"#likelihood function type"<<std::endl;
    is>>llWgt;
    rpt::echo<<llWgt<<tb<<"#likelihood weight (multiplier)"<<std::endl;
    is>>nSXs;//number of sex categories
    rpt::echo<<nSXs<<tb<<"#number of sex categories"<<std::endl;
    nObs_x.initialize();
    for (int x=1;x<=nSXs;x++){
        is>>str; int xp = tcsam::getSexType(str);
        rpt::echo<<tcsam::getSexType(xp)<<tb<<"#sex"<<std::endl;
        is>>nObs_x(xp);
        rpt::echo<<nObs_x(xp)<<tb<<"#number of observations"<<std::endl;
        dmatrix tmp(1,nObs_x(xp),1,3);
        is>>tmp;
        rpt::echo<<"#year"<<tb<<"pre-molt size"<<tb<<"post-molt size"<<std::endl;
        rpt::echo<<tmp<<std::endl;
        inpData_xcn(xp,1).allocate(1,nObs_x(xp));
        inpData_xcn(xp,2).allocate(1,nObs_x(xp));
        inpData_xcn(xp,3).allocate(1,nObs_x(xp));
        inpData_xcn(xp) = trans(tmp);
        obsYears_xn(xp).allocate(1,nObs_x(xp));
        ivector itmp(inpData_xcn(xp,1));
        obsYears_xn(xp) = itmp;
    }
    
    if (debug) cout<<"end GrowthData::read(...) "<<this<<std::endl;
}