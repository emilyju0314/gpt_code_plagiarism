void Molt2MaturityInfo::setToWriteVectorInitialValues(bool flag){
    if (pvLgtPrM2M){
        for (int i=1;i<=pvLgtPrM2M->getSize();i++){
            BoundedVectorInfo* vi = (*pvLgtPrM2M)[i];
            if (flag) vi->readVals = INT_TRUE; else vi->readVals = INT_FALSE;        
        }
    }
}