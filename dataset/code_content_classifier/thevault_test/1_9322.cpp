void ModelParametersInfo::setToWriteVectorInitialValues(bool flag){
    if (ptrRec) ptrRec->setToWriteVectorInitialValues(flag);
    if (ptrNM)  ptrNM ->setToWriteVectorInitialValues(flag);
    if (ptrGrw) ptrGrw->setToWriteVectorInitialValues(flag);
    if (ptrM2M) ptrM2M->setToWriteVectorInitialValues(flag);
    if (ptrSel) ptrSel->setToWriteVectorInitialValues(flag);
    if (ptrFsh) ptrFsh->setToWriteVectorInitialValues(flag);
    if (ptrSrv) ptrSrv->setToWriteVectorInitialValues(flag); //not needed for SurveysInfo
    if (ptrMSE) ptrMSE->setToWriteVectorInitialValues(flag); //not needed for MSE_Info
}