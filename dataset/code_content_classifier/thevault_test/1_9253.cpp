void BoundedVectorInfo::writeFinalValsToR(ostream& os){
    if (debug) rpt::echo<<"starting BoundedVectorInfo::writeFinalValsToR for "<<this->name<<endl;
    if (!finlVals.allocated()) {
        finlVals.allocate(initVals.indexmin(),initVals.indexmax()); 
        finlVals = initVals;
    }
    wts::writeToR(os,finlVals,wts::to_qcsv(ptrIB->getFwdIndexVector()));
    if (debug) rpt::echo<<"finished BoundedVectorInfo::writeFinalValsToR for "<<this->name<<endl;
}