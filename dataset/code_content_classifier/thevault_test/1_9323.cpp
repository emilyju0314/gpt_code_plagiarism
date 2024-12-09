Equilibrium_Calculator::Equilibrium_Calculator(PopProjector* pPPp){
    pPP = pPPp;
    nMSs = pPP->pPI->nMSs;
    nSCs = pPP->pPI->nSCs;
    nZBs = pPP->pPI->nZBs;
    I_z = identity_matrix(1,nZBs);
}