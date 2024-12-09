void RecruitmentInfo::addNextYearToInfo(int closed){
    if (debug) cout<<"starting void RecruitmentInfo::project("<<closed<<")"<<endl;
    int idxDevsLnR = nIVs+6;
    //find pcs corresponding to mxYr
    int mxYr = ModelConfiguration::mxYr;
    ivector pcs = ParameterGroupInfo::getPCsForYear(mxYr);
    if (debug) {
        if (pcs.size()) cout<<"PCs "<<pcs<<" apply to "<<mxYr<<endl;
        else cout<<"No PCs apply to <<"<<mxYr<<endl;
    }
    //define ivector to track which vectors in pDevsLnR have been modified
    ivector idsDevsLnR(pcs.indexmin(),pcs.indexmax());
    idsDevsLnR = 0;
    for (int i=pcs.indexmin();i<=pcs.indexmax();i++){
        ParameterGroupInfo::addYearToPC(pcs[i],mxYr+1);

        ivector ids = ParameterGroupInfo::getPCIDs(pcs[i]);
        if (debug) cout<<"PC IDs for pc "<<pcs[i]<<" = "<<ids<<endl;
        if (pDevsLnR->getSize()){
            if (debug) cout<<"extending pDevsLnR["<<ids[idxDevsLnR]<<"]"<<endl<<(*pDevsLnR)[ids[idxDevsLnR]]->getInitVals()<<endl;
            //Need to make sure not to addValue multiple times to same devs vector.
            int sumdsp = 0;//if sumdsp>0, then already added value to indexed devs vector
            for (int j=pcs.indexmin();j<=pcs.indexmax();j++) sumdsp += (idsDevsLnR[j]==ids[idxDevsLnR]);
            if (!sumdsp){
                if (debug) cout<<"Adding value to pDevsLnR["<<ids[idxDevsLnR]<<"]"<<endl;
                idsDevsLnR[i] = ids[idxDevsLnR];
                DevsVectorInfo* pDVI = (*pDevsLnR)[ids[idxDevsLnR]];
                if (debug) DevsVectorInfo::debug=1;
                pDVI->addValueOnParameterScale(0.0,mxYr+1);
                if (debug) DevsVectorInfo::debug=0;
            } else {
                if (debug) cout<<"Already added value to pDevsLnR["<<ids[idxDevsLnR]<<"]"<<endl;
            }
        }
    }
    if (debug) cout<<"finished void RecruitmentInfo::project("<<closed<<")"<<endl; 
}