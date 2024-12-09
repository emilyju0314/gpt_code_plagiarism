void BoundedNumberInfo::writeToR(ostream& os){
    os<<"list(";
    writeToR1(os);
    os<<")";
}