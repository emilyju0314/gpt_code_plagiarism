void NumberVectorInfo::writeFinalValsToR(ostream& os){
    if (nNIs){
        os<<"list("<<endl;
        for (int p=1;p<nNIs;p++) {os<<tb<<"'"<<p<<"'="<<ppNIs[p-1]->getFinalVal()<<","<<endl;}
        int p=nNIs;               os<<tb<<"'"<<p<<"'="<<ppNIs[p-1]->getFinalVal()<<")";
    } else {
        os<<"NULL";
    }
}