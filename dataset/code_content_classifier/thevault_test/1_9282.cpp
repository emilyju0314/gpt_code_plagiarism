dvector VectorVectorInfo::getPriorWgts(){
    if (debug) rpt::echo<<"starting VectorVectorInfo::getPriorWgts() for "<<name<<endl;
    dvector wts(1,nVIs);
    for (int i=1;i<=nVIs;i++) wts(i) = ppVIs[i-1]->getPriorWgt();
    if (debug) rpt::echo<<"finished VectorVectorInfo::getPriorWgts() for "<<name<<endl;
    return wts;
}