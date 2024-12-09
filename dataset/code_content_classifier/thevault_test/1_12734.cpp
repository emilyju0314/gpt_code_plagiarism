static double refine_clusters(
    struct ClassSig *Sig, 
    int nbands, 
    double Rmin, 
    int option)
{
     int nparams_clust;
     int num_params;
     int ndata_points;
     int repeat;
     double rissanen_const;
     double change,ll_new,ll_old;
     double epsilon;

     /* compute number of parameters per cluster */
     nparams_clust = 1+nbands+0.5*(nbands+1)*nbands;
     if(option==CLUSTER_DIAG) nparams_clust = 1+nbands+nbands;

     /* compute number of data points */
     ndata_points = Sig->classData.npixels*nbands;

     /* compute epsilon */
     epsilon = nparams_clust*log((double)ndata_points);
     epsilon *= 0.01;

     /* Perform initial regrouping */
     ll_new = regroup(Sig,nbands);

     /* Perform EM algorithm */
     change = 2*epsilon;
     do {
       ll_old = ll_new;
       reestimate(Sig,nbands,Rmin,option);

       ll_new = regroup(Sig,nbands);
       change = ll_new-ll_old;
       repeat = change>epsilon;
     } while(repeat);

     /* compute Rissanens expression */
     if(Sig->nsubclasses>0) {
       num_params = Sig->nsubclasses*nparams_clust - 1;
       rissanen_const = -ll_new + 0.5*num_params*log((double)ndata_points);
       return(rissanen_const);
     }
     else {
       return((double)0);
     }
}