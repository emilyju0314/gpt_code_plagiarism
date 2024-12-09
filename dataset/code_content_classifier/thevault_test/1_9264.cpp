void NumberVectorInfo::setInitValsFromParamVals(const dvar_vector& x){
    if (debug) rpt::echo<<"starting NumberVectorInfo::setInitValsFromParamVals(x)"<<this<<endl;
    for (int i=1;i<=nNIs;i++) ppNIs[i-1]->setInitValFromParamVal(x(i));
    if (debug) rpt::echo<<"finished NumberVectorInfo::setInitValsFromParamVals(x)"<<this<<endl;
}