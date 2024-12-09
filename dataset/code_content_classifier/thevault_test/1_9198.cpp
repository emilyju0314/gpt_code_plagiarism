void PopDyInfo::writeToR(ostream& os, ModelConfiguration* ptrMC, adstring name, int dbg){
    if (dbg) std::cout<<"Starting PopDyInfo::writeToR()"<<endl;
    adstring mDms  = ptrMC->dimMSsToR;//maturity
    adstring sDms  = ptrMC->dimSCsToR;//shell condition
    adstring zDms  = ptrMC->dimZBsToR;//size bin midpoints
    adstring zpDms = ptrMC->dimZPsToR;//size bin midpoints
    os<<name<<"=list(";
    os<<"R_z="; wts::writeToR(os,value(R_z),zDms);                os<<cc<<endl;
    os<<"w_mz="; wts::writeToR(os,w_mz,mDms,zDms);                os<<cc<<endl;
    os<<"M_msz="; wts::writeToR(os,value(M_msz),mDms,sDms,zDms);  os<<cc<<endl;
    os<<"Th_sz="; wts::writeToR(os,value(Th_sz),sDms,zDms);       os<<cc<<endl;
    os<<"T_szz="; wts::writeToR(os,value(T_szz),sDms,zDms,zpDms); os<<endl;
    os<<")";
    if (dbg) std::cout<<"Finished PopDyInfo::writeToR()"<<endl;
}