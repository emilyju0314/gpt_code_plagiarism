void SelectivityInfo::setToWriteVectorInitialValues(bool flag){
    if (pDevsS1){
        for (int i=1;i<=pDevsS1->getSize();i++){
            BoundedVectorInfo* vi = (*pDevsS1)[i];
            if (flag) vi->readVals = INT_TRUE; else vi->readVals = INT_FALSE;        
        }
    }
    if (pDevsS2){
        for (int i=1;i<=pDevsS2->getSize();i++){
            BoundedVectorInfo* vi = (*pDevsS2)[i];
            if (flag) vi->readVals = INT_TRUE; else vi->readVals = INT_FALSE;        
        }
    }
    if (pDevsS3){
        for (int i=1;i<=pDevsS3->getSize();i++){
            BoundedVectorInfo* vi = (*pDevsS3)[i];
            if (flag) vi->readVals = INT_TRUE; else vi->readVals = INT_FALSE;        
        }
    }
    if (pDevsS4){
        for (int i=1;i<=pDevsS4->getSize();i++){
            BoundedVectorInfo* vi = (*pDevsS4)[i];
            if (flag) vi->readVals = INT_TRUE; else vi->readVals = INT_FALSE;        
        }
    }
    if (pDevsS5){
        for (int i=1;i<=pDevsS5->getSize();i++){
            BoundedVectorInfo* vi = (*pDevsS5)[i];
            if (flag) vi->readVals = INT_TRUE; else vi->readVals = INT_FALSE;        
        }
    }
    if (pDevsS6){
        for (int i=1;i<=pDevsS6->getSize();i++){
            BoundedVectorInfo* vi = (*pDevsS6)[i];
            if (flag) vi->readVals = INT_TRUE; else vi->readVals = INT_FALSE;        
        }
    }
    if (pvNPSel){
        for (int i=1;i<=pvNPSel->getSize();i++){
            BoundedVectorInfo* vi = (*pvNPSel)[i];
            if (flag) vi->readVals = INT_TRUE; else vi->readVals = INT_FALSE;        
        }
    }
}