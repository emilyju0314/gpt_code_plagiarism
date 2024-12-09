void BoundedVectorVectorInfo::writeFinalValsToR(ostream& os){
    if (nVIs){
        os<<"list("<<endl;
        for (int p=1;p<nVIs;p++) {os<<tb<<"'"<<p<<"'="; ppVIs[p-1]->writeFinalValsToR(os); os<<","<<endl;}
        int p=nVIs;               os<<tb<<"'"<<p<<"'="; ppVIs[p-1]->writeFinalValsToR(os); os<<")";
    } else {
        os<<"NULL";
    }
}