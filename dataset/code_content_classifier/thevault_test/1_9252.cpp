void BoundedVectorInfo::writeToR(ostream& os){
    if (debug) rpt::echo<<"BoundedVectorInfo::writeToR for "<<this->name<<endl;
    if (!finlVals.allocated()) {
        finlVals.allocate(initVals.indexmin(),initVals.indexmax()); 
        finlVals = initVals;
    }
    os<<"list(";
        os<<"jitter='"<<wts::getOnOffType(jitter)<<"',lower="<<lower<<",upper="<<upper<<cc;
        VectorInfo::writeToR1(os);
    os<<")";
}