void RecruitmentInfo::setToWriteVectorInitialValues(bool flag){
    if (pDevsLnR){
        for (int i=1;i<=pDevsLnR->getSize();i++){
            DevsVectorInfo* dvi = (*pDevsLnR)[i];
            if (flag) dvi->readVals = INT_TRUE; else dvi->readVals = INT_FALSE;        
        }
    }
}