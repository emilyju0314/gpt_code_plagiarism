void GrowthData::writeToR(ostream& os, std::string nm, int indent) {
    if (debug) cout<<"GrowthData::writing to R"<<std::endl;
    for (int n=0;n<indent;n++) os<<tb;
        os<<"`"<<name<<"`"<<"=list("<<std::endl;
        indent++; 
            for (int n=0;n<indent;n++) os<<tb;
            os<<"name="<<qt<<name<<qt<<cc;
            os<<"llType="<<qt<<tcsam::getLikelihoodType(llType)<<qt<<cc;
            os<<"llWgt="<<llWgt<<cc<<std::endl;
            adstring colnames="'y','z','zp'";
            for (int x=1;x<=tcsam::nSXs;x++){
                if (nObs_x(x)>0){
                    for (int n=0;n<indent;n++) os<<tb;
                    os<<tcsam::getSexType(x)<<"="; wts::writeToR(os,trans(inpData_xcn(x)),colnames); os<<cc<<std::endl;
                }
            }//x
            os<<"NULL"<<std::endl;
        indent--;
    for (int n=0;n<indent;n++) os<<tb; os<<")"<<std::endl;
    if (debug) cout<<"GrowthData::done writing to R"<<std::endl;
}