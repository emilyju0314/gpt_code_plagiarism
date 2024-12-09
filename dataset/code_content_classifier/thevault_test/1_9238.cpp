void VectorInfo::writeToR(ostream& os){
    if (debug) rpt::echo<<"VectorInfo::writeToR for "<<this->name<<endl;
    if (!finlVals.allocated()) {
        finlVals.allocate(initVals.indexmin(),initVals.indexmax()); 
        finlVals = initVals;
    }
    os<<"list(";
    writeToR1(os);
    os<<")";
}