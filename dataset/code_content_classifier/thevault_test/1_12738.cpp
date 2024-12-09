void Clust::ClassSig::seed(double Rmin, int option)
{
	struct ClassSig *Sig=this;
     int     i,b1,b2;
     double  period;

 	 static vectorn mean;
	 static matrixn R;
	 R.setSize(nbands(), nbands());

     /* Compute the mean of variance for each band */
	 mean .setSize(nbands());

     for(b1=0; b1<nbands(); b1++) {
       mean[b1] = 0.0;
       for(i=0; i<Sig->classData.npixels(); i++) {
         mean[b1] += (Sig->classData.x[i][b1])*(Sig->classData.w[i]);
       }
       mean[b1] /= Sig->classData.SummedWeights;
     }

     if(option==CLUSTER_FULL)
	 {
		 for(b1=0; b1<nbands(); b1++)
		 for(b2=0; b2<nbands(); b2++) {
		   R[b1][b2] = 0.0;
		   for(i=0; i<Sig->classData.npixels(); i++) {
			 R[b1][b2] += (Sig->classData.x[i][b1])*(Sig->classData.x[i][b2])*(Sig->classData.w[i]);
		   }
		   R[b1][b2] /= Sig->classData.SummedWeights;
		   R[b1][b2] -= mean[b1]*mean[b2];
		 }
	 }
	 else if(option==CLUSTER_DIAG)
	 {
		 // non-diagonal elements are assumed to be zero.
		 for(b1=0; b1<nbands(); b1++)
		{
		   R[b1][b1] = 0.0;
		   for(i=0; i<Sig->classData.npixels(); i++) {
			 R[b1][b1] += (Sig->classData.x[i][b1])*(Sig->classData.x[i][b1])*(Sig->classData.w[i]);
		   }
		   R[b1][b1] /= Sig->classData.SummedWeights;
		   R[b1][b1] -= mean[b1]*mean[b1];
		 }
	 }
	 else
	 {
		 m_real var=0;
		// non-diagonal elements are assumed to be zero.
		 for(i=0; i<Sig->classData.npixels(); i++)
		 {
			 var+=m::ss(Sig->classData.x.row(i), mean)*Sig->classData.w[i];
		 }
		 var/=Sig->classData.SummedWeights;

		 R[0][0]=var;
	 }

     /* Compute the sampling period for seeding */
     if(Sig->nsubclasses()>1) {
       period = (Sig->classData.npixels()-1)/(Sig->nsubclasses()-1.0);
     }
     else period =0;


     /* Seed the means and set the covarience components */
     for(i=0; i<Sig->nsubclasses(); i++) {
       for(b1=0; b1<nbands(); b1++) {
         Sig->mSubSig[i].means[b1] = Sig->classData.x[(int)(i*period)][b1];
       }

	   Sig->mSubSig[i].setCov(R, Rmin);

       Sig->mSubSig[i].pi = 1.0/Sig->nsubclasses();
     }


     compute_constants();

	normalize_pi();


}