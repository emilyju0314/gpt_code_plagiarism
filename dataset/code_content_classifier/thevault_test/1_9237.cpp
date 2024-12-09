void VectorInfo::readPart1(cifstream & is){
    if (debug) rpt::echo<<"Starting VectorInfo::readPart1(cifstream & is) for "<<name<<endl;
    adstring str;
    is>>idxType;
    if (debug) rpt::echo<<idxType<<tb<<"#index type"<<endl;
    int imn; int imx; 
    tcsam::getIndexLimits(idxType,imn,imx);
    ptrIB = new IndexBlock(imn,imx);
    is>>(*ptrIB);
    if (debug) rpt::echo<<(*ptrIB)<<tb<<"#index block"<<endl;
    N = ptrIB->getSize();
    initVals.allocate(1,N);
    is>>str; readVals = wts::getBooleanType(str);
    if (debug) {
        rpt::echo<<"idxType    = "<<idxType<<endl;
        rpt::echo<<"IndexBlock = "<<(*ptrIB)<<endl;
        rpt::echo<<"N          = "<<N<<endl;
        rpt::echo<<"readVals   = "<<wts::getBooleanType(readVals)<<endl;
        rpt::echo<<"Finished VectorInfo::readPart1(cifstream & is) for "<<name<<endl;
    }
}