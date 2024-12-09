dvector NumberVectorInfo::getPriorWgts(){
    if (debug) rpt::echo<<"starting NumberVectorInfo::getPriorWgts()"<<this<<endl;
    dvector wts(1,nNIs);
    for (int i=1;i<=nNIs;i++) wts(i) = ppNIs[i-1]->getPriorWgt();
    if (debug) rpt::echo<<"finished NumberVectorInfo::getPriorWgts()"<<this<<endl;
    return wts;
}