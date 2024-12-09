void FisheriesInfo::setToWriteVectorInitialValues(bool flag){
    if (pDevsLnC){
        for (int i=1;i<=pDevsLnC->getSize();i++){
            BoundedVectorInfo* vi = (*pDevsLnC)[i];
            if (flag) vi->readVals = INT_TRUE; else vi->readVals = INT_FALSE;        
        }
    }
}