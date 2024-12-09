void VectorInfo::addValueOnParameterScale(double val, int ibVal){
    if (debug) cout<<"starting VectorInfo::addValueOnParameterScale("<<val<<cc<<ibVal<<")"<<endl;
    double aval = calcArithScaleVals(val);
    addValueOnArithmeticScale(aval,ibVal);
    if (debug) cout<<"finished VectorInfo::addValueOnParameterScale("<<val<<cc<<ibVal<<")"<<endl;
}