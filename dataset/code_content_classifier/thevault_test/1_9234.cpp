void VectorInfo::addValueOnArithmeticScale(double val, int ibVal){
    if (debug) cout<<"starting VectorInfo::addValueOnArithmeticScale("<<val<<cc<<ibVal<<")"<<endl;
    ptrIB->addElement(ibVal);
    dvector tmp = 1.0*initVals;
    N++;
    initVals.deallocate(); initVals.allocate(1,N);
    initVals(1,N-1) = tmp;
    initVals(N) = val;
    if (debug){
        cout<<"initVals orig: "<<tmp<<endl;
        cout<<"initVals updt: "<<initVals<<endl;
    }
    if (finlVals.allocated()){
        dvector tmp = 1.0*finlVals;
        finlVals.deallocate(); finlVals.allocate(1,N);
        finlVals(1,N-1) = tmp;
        finlVals(N) = val;
        if (debug){
            cout<<"finlVals orig: "<<tmp<<endl;
            cout<<"finlVals updt: "<<finlVals<<endl;
        }
    }
    if (debug) cout<<"finished VectorInfo::addValueOnArithmeticScale("<<val<<cc<<ibVal<<")"<<endl;
}