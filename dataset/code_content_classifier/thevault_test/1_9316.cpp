void RecruitmentInfo::write(std::ostream & os){
    os<<NAME<<tb<<"#process name"<<endl;
    ParameterGroupInfo::write(os);
    
    if (nPCs>0){
        os<<"PARAMETERS"<<endl;

        int k=1;
        os<<lblPVs(k)<<tb<<"#"<<dscPVs(k)<<endl; k++;
        os<<(*pLnR)<<endl;
        os<<lblPVs(k)<<tb<<"#"<<dscPVs(k)<<endl; k++;
        os<<(*pRCV)<<endl;
        os<<lblPVs(k)<<tb<<"#"<<dscPVs(k)<<endl; k++;
        os<<(*pRX)<<endl;
        os<<lblPVs(k)<<tb<<"#"<<dscPVs(k)<<endl; k++;
        os<<(*pRa)<<endl;
        os<<lblPVs(k)<<tb<<"#"<<dscPVs(k)<<endl; k++;
        os<<(*pRb)<<endl;
        os<<lblPVs(k)<<tb<<"#"<<dscPVs(k)<<endl; k++;
        os<<(*pDevsLnR)<<endl;
    }
}