void NumberVectorInfo::setFinalValsFromParamVals(const dvar_vector& x){
    if (debug) rpt::echo<<"starting NumberVectorInfo::setFinalVals(x)"<<this<<endl;
    for (int i=1;i<=nNIs;i++) ppNIs[i-1]->setFinalValFromParamVal(x(i));
    if (debug) rpt::echo<<"finished NumberVectorInfo::setFinalVals(x)"<<this<<endl;
}