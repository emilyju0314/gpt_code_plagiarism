void ParameterGroupInfo::writeToR(std::ostream& os){
    adstring lbls = "";
//    if (nIVs) lbls += wts::to_qcsv(lblIVs);
//    if (nPVs) {if (lbls=="") lbls += wts::to_qcsv(lblPVs); else lbls += cc+wts::to_qcsv(lblPVs);}
    if (nPVs) lbls += wts::to_qcsv(lblPVs);
    if (nXIs) {if (lbls=="") lbls += wts::to_qcsv(lblXIs); else lbls += cc+wts::to_qcsv(lblXIs);}
    os<<"pgi=list(name="<<qt<<name<<qt;
    if (nPCs>0) {
        os<<cc<<endl;
        os<<"pcs=list("<<endl;
            for (int p=1;p<=nPCs;p++){
                os<<qt<<p<<qt<<"=list(";
                os<<"label='"<<pcLabels(p)<<"',"<<endl;
                int ibsIdx = 1;
                for (int i=1;i<=nIVs;i++){//loop over index variables
                    os<<lblIVs(i)<<"='";
                    if (lblIVs(i)==tcsam::STR_SEX)             {os<<tcsam::getSexType(in(p,i))     <<"',";} else
                    if (lblIVs(i)==tcsam::STR_MATURITY_STATE)  {os<<tcsam::getMaturityType(in(p,i))<<"',";} else
                    if (lblIVs(i)==tcsam::STR_SHELL_CONDITION) {os<<tcsam::getShellType(in(p,i))   <<"',";} else 
                    if ((ibsIdxs.allocated())&&(i==ibsIdxs(ibsIdx))){
                        os<<(*ppIBSs[ibsIdx-1]->getIndexBlock(p))<<"',";
                        if (ibsIdx<nIBSs) ibsIdx++;//increment to next
                    } else {os<<in(p,i)<<"',";}
                }
                ivector iv = getPCIDs(p);
                imatrix im = getModelIndices(p);
                os<<"ids.PC="; wts::writeToR(os,iv(nIVs+1,nIVs+nPVs+nXIs),lbls); os<<cc<<endl;
                adstring ids = "index=c(1:"+str(im.indexmax())+")";
                adstring tps = "type=c("+wts::to_qcsv(lblIVs)+")";
                os<<"ids.Mod="; wts::writeToR(os,im,ids,tps); os<<"),"<<endl;
            }
        os<<"NULL)"<<endl;
    }//nPCs>0
    os<<")";
}