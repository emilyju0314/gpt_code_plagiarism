imatrix ParameterGroupInfo::getModelIndices(int pc){
    if (debug) cout<<"starting ParameterGroupInfo::getModelIndices(int pc)"<<endl;
    if (pc>nPCs) {
        cout<<"Error in ParameterGroupInfo::getModelIndices(int pc) for "<<name<<endl;
        cout<<"pc was "<<pc<<" but max defined is "<<nPCs<<endl;
        cout<<"Aborting..."<<endl;
        exit(-1);
    }
    imatrix idxs = (*ppIdxs[pc-1]);
    if (debug) {
        cout<<"imatrix idxs has rows "<<idxs.indexmin()<<":"<<idxs.indexmax()<<endl;
        cout<<"finished ParameterGroupInfo::getModelIndices(int pc)"<<endl;
        cout<<"Enter 1 to continue: ";
        cin>>debug;
        if (debug<0) exit(1);
    }
    return idxs;
}