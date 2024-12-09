void CatchInfo::writeToR(ostream& os, ModelConfiguration* ptrMC, adstring name, int debug){
    if (debug) std::cout<<"Starting CatchInfo::writeToR()"<<endl;
    adstring xDms = ptrMC->dimSXsToR;//sex
    adstring mDms = ptrMC->dimMSsToR;//maturity
    adstring sDms = ptrMC->dimSCsToR;//shell condition
    adstring zDms = ptrMC->dimZBsToR;//size bin midpoints
    adstring fDms = ptrMC->dimFshToR;//fisheries
    os<<name<<"=list(";
    os<<"hm_f="; wts::writeToR(os,value(hm_f),fDms); os<<cc<<endl;
    os<<"capF_fms="; wts::writeToR(os,value(cpF_fms),fDms,mDms,sDms); os<<cc<<endl;
    os<<"capF_fmsz="; wts::writeToR(os,wts::value(cpF_fmsz),fDms,mDms,sDms,zDms); os<<cc<<endl;
    os<<"selF_fmsz="; wts::writeToR(os,wts::value(selF_fmsz),fDms,mDms,sDms,zDms); os<<cc<<endl;
    os<<"retF_fmsz="; wts::writeToR(os,wts::value(retF_fmsz),fDms,mDms,sDms,zDms); os<<endl;
    os<<")";
    if (debug) std::cout<<"Finished CatchInfo::writeToR()"<<endl;
}