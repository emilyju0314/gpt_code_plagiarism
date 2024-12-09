void BoundedVectorInfo::write(ostream & os){
    VectorInfo::writePart1(os);
    os<<wts::getOnOffType(jitter)<<tb;
    os<<lower<<tb;
    os<<upper<<tb;
    VectorInfo::writePart2(os);
}