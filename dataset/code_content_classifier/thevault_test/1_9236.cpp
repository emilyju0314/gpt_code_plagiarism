void VectorInfo::read(cifstream & is){
    if (debug) rpt::echo<<"Starting VectorInfo::read(cifstream & is) for "<<name<<endl;
    readPart1(is);
    readPart2(is);
    if (debug) rpt::echo<<"Finished VectorInfo::read(cifstream & is) for "<<name<<endl;
}