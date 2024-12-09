void RecruitmentInfo::writeToR(std::ostream & os){
    int indent=0;
    os<<"rec=list("<<endl;
        ParameterGroupInfo::writeToR(os);   
        if (nPCs) {
            os<<cc<<endl;
            pLnR->writeToR(os,"pLnR",indent+1); os<<cc<<endl;
            pRCV->writeToR(os,"pRCV",indent+1); os<<cc<<endl;
            pRX->writeToR(os, "pRX", indent+1); os<<cc<<endl;
            pRa->writeToR(os, "pRa", indent+1); os<<cc<<endl;
            pRb->writeToR(os, "pRb", indent+1); os<<cc<<endl;
            pDevsLnR->writeToR(os,"pDevsLnR",indent+1); os<<endl;
        }
    os<<")";
}