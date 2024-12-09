void ChelaHeightData::writeToR(ostream& os, std::string nm, int indent) {
    if (debug) cout<<"ChelaHeightData::writing to R"<<std::endl;
    for (int n=0;n<indent;n++) os<<tb;
        os<<"`"<<name<<"`"<<"=list("<<std::endl;
        indent++; 
            for (int n=0;n<indent;n++) os<<tb;
            os<<"name="<<qt<<name<<qt<<cc;
            os<<"survey="<<qt<<survey<<qt<<cc;
            os<<"llType="<<qt<<tcsam::getLikelihoodType(llType)<<qt<<cc;
            os<<"llWgt="<<llWgt<<cc<<std::endl;
            for (int n=0;n<indent;n++) os<<tb;
            adstring colnames="'y','z','nIndivs','fraction mature'";
            os<<"data="; wts::writeToR(os,inpData_nc,colnames); os<<std::endl;
        indent--;
    for (int n=0;n<indent;n++) os<<tb; os<<")"<<std::endl;
    if (debug) cout<<"ChelaHeightData::done writing to R"<<std::endl;
}