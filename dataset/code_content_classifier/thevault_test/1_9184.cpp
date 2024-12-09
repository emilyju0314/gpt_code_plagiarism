adstring tcsamDims::getSCsForR(int mn,int mx){
    adstring dms = "s=c("+qt+formatForR(getShellType(mn))+qt;
    for (int i=(mn+1);i<=mx;i++) {
        dms += cc+qt+formatForR(getShellType(i))+qt;
    }
    dms += ")";
    return dms;
}