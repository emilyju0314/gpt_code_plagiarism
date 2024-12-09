dvector ParameterGroupInfo::getPCXDs(int pc){
    if (debug) cout<<"starting ParameterGroupInfo::getPCXDs(int pc)"<<endl;
    if (debug) {
        cout<<"pcids for "<<pc<<"th parameter combination: "<<xd(pc)<<endl;
        cout<<"finished ParameterGroupInfo::getPCXDs(int pc)"<<endl;
        cout<<"Enter 1 to continue: ";
        cin>>debug;
        if (debug<0) exit(1);
    }
    return xd(pc);
}