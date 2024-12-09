void ParameterGroupInfo::addYearToPC(int pc, int y){
    if (debug) cout<<"starting ParameterGroupInfo::addYearToPC("<<pc<<cc<<y<<") for "<<name<<endl;
    IndexBlockSet* pIBS = getIndexBlockSet("YEAR_BLOCK");
    IndexBlock* pIB  = pIBS->getIndexBlock(pc);
    if (debug) IndexBlock::debug=1;
    pIB->addElement(y);
    if (debug) IndexBlock::debug=0;
    createIndices();
    if (debug) cout<<"finished ParameterGroupInfo::addYearToPC("<<pc<<cc<<y<<") for "<<name<<endl;
}