IndexBlockSet* ParameterGroupInfo::getIndexBlockSet(adstring type){
    if (debug) cout<<"starting  IndexBlockSets::getIndexBlockSet("<<type<<")"<<endl;
    IndexBlockSet* p = 0;
    int s=0;
    while(s<nIBSs){
        p = ppIBSs[s];
        if (p->getType()==type) break;
        s++;
    }
    if (debug) cout<<"finished  IndexBlockSets::getIndexBlockSet("<<type<<")"<<endl;
    return p;
}