ivector ParameterGroupInfo::getPCsForYear(int y){
    if (debug) cout<<"starting ParameterGroupInfo::getPCforYear("<<y<<") for "<<name<<endl;
    IndexBlockSet* pIBS = getIndexBlockSet("YEAR_BLOCK");
    int pcy = 0;
    int nPCs = pIBS->getSize();
    if (debug) cout<<"nPCs = "<<nPCs<<endl;
    //count pc's that include year
    int k = 0;
    for (int pc=1;pc<=nPCs;pc++){
        ivector iv = pIBS->getFwdIndexVector(pc);
        if (debug) cout<<pc<<": "<<iv<<endl;
        for (int i=iv.indexmin();i<=iv.indexmax();i++) 
            if (iv(i)==y) k++;
    }
    ivector pcs; 
    if (debug) cout<<"Found "<<k<<" PCs that include "<<y<<endl;
    if (k) {
        //now collect the pc's
        pcs.allocate(1,k);
        k = 1;//reset counter
        for (int pc=1;pc<=nPCs;pc++){
            ivector iv = pIBS->getFwdIndexVector(pc);
            if (debug) cout<<pc<<": "<<iv<<endl;
            for (int i=iv.indexmin();i<=iv.indexmax();i++) 
                if (iv(i)==y) pcs(k++) = pc;
        }
    }
    if (debug) {
        if (pcs.allocated()) 
            cout<<"pcs corresponding to "<<y<<" are "<<pcs<<" for "<<name<<endl; 
        else
            cout<<"No pcs corresponding to "<<y<<" were found for "<<name<<endl; 
        cout<<"finished ParameterGroupInfo::getPCforYear("<<y<<") for "<<name<<endl;
    }
    return(pcs);
}