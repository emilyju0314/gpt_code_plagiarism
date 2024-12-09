ivector ParameterGroupInfo::getPCIDs(int pc){
    if (debug) cout<<"starting ParameterGroupInfo::getPCIDs(int pc)"<<endl;
    if (debug) {
        cout<<"pcids for "<<pc<<"th parameter combination: "<<in(pc)<<endl;
        cout<<"finished ParameterGroupInfo::getPCIDs(int pc)"<<endl;
        cout<<"Enter 1 to continue: ";
        cin>>debug;
        if (debug<0) exit(1);
    }
    return in(pc);
}