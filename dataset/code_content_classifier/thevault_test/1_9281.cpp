ivector VectorVectorInfo::getPhases(void){
    if (debug) rpt::echo<<"starting VectorVectorInfo::getPhases(void) for "<<name<<endl;
    ivector phases(1,nVIs);
    phases.initialize();
    if (ppVIs) for (int i=1;i<=nVIs;i++) phases(i) = ppVIs[i-1]->getPhase();
    if (debug) rpt::echo<<"finished VectorVectorInfo::getPhases(void) for "<<name<<endl;
    return phases;
}