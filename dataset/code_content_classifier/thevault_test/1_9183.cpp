adstring tcsamDims::getMSsForR(int mn,int mx){
    adstring dms = "m=c("+qt+formatForR(getMaturityType(mn))+qt;
    for (int i=(mn+1);i<=mx;i++) {
        dms += cc+qt+formatForR(getMaturityType(i))+qt;
    }
    dms += ")";
    return dms;
}