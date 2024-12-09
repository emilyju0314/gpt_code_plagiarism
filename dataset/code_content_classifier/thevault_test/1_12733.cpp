static void seed(struct ClassSig *Sig, int nbands, double Rmin, int option)
{
     int     i,b1,b2;
     double  period;
     double  *mean,**R;

     /* Compute the mean of variance for each band */
     mean = G_alloc_vector(nbands);
     R = G_alloc_matrix(nbands,nbands);

     for(b1=0; b1<nbands; b1++) {
       mean[b1] = 0.0;
       for(i=0; i<Sig->classData.npixels; i++) {
         mean[b1] += (Sig->classData.x[i][b1])*(Sig->classData.w[i]);
       }
       mean[b1] /= Sig->classData.SummedWeights;
     }

     for(b1=0; b1<nbands; b1++) 
     for(b2=0; b2<nbands; b2++) {
       R[b1][b2] = 0.0;
       for(i=0; i<Sig->classData.npixels; i++) {
         R[b1][b2] += (Sig->classData.x[i][b1])*(Sig->classData.x[i][b2])*(Sig->classData.w[i]);
       }
       R[b1][b2] /= Sig->classData.SummedWeights;
       R[b1][b2] -= mean[b1]*mean[b2];
     }

     /* If diagonal clustering is desired, then diagonalize matrix */
     if(option==CLUSTER_DIAG) DiagonalizeMatrix(R,nbands);

     /* Compute the sampling period for seeding */
     if(Sig->nsubclasses>1) {
       period = (Sig->classData.npixels-1)/(Sig->nsubclasses-1.0);
     }
     else period =0;


     /* Seed the means and set the covarience components */
     for(i=0; i<Sig->nsubclasses; i++) {
       for(b1=0; b1<nbands; b1++) {
         Sig->subSig[i].means[b1] = Sig->classData.x[(int)(i*period)][b1];
       }

       for(b1=0; b1<nbands; b1++)
       for(b2=0; b2<nbands; b2++) {
         Sig->subSig[i].R[b1][b2] = R[b1][b2];
       }
       for(b1=0; b1<nbands; b1++) {
         Sig->subSig[i].R[b1][b1] += Rmin;
       }
       Sig->subSig[i].pi = 1.0/Sig->nsubclasses;
     }

     G_free_vector(mean);
     G_free_matrix(R);

     compute_constants(Sig,nbands);
     normalize_pi(Sig);
}