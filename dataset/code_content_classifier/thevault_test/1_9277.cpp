void VectorVectorInfo::deallocate(void){
    if (debug) rpt::echo<<"starting VectorVectorInfo::deallocate(void) for "<<name<<endl;
    if (ppVIs) {
        for (int p=0;p<nVIs;p++) if (ppVIs[p]!=0) delete ppVIs[p];
        delete[] ppVIs;
        ppVIs = 0;
    }
    if (debug) rpt::echo<<"finished VectorVectorInfo::deallocate(void) for "<<name<<endl;
}