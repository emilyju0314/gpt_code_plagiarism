void data::make_synthetics(parameters &q)
{
    double *outx, *outy, *outz;
    outx=new double[nt];
    outy=new double[nt];
    outz=new double[nt];
    
    for (int i=0; i<nrec; i++)
    {
        ffp(0,q,recx[i],recy[i],recz[i],dt,nt,outx);
        ffp(1,q,recx[i],recy[i],recz[i],dt,nt,outy);
        ffp(2,q,recx[i],recy[i],recz[i],dt,nt,outz);
        
        for (int j=0; j<nt; j++)
        {
            /* Synthetic time series. */
            ux[i][j]=outx[j];
            uy[i][j]=outy[j];
            uz[i][j]=outz[j];
            /* Synthetic inverse covariances zero. */
            cx[i][j]=0.0;
            cy[i][j]=0.0;
            cz[i][j]=0.0;
        }
    }
    
    delete[] outx; delete[] outy; delete[] outz;
}