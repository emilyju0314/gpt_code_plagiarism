double mc::energy()
{
    /* Local variables. */
    double H;
    bool linearised=true; /* Misfit linearised or not. */
    
    /* Compute energy - model part. */
    if (linearised)
    {
        H=0.5*C;
    
        for (int i=0; i<Nq; i++)
        {
            H+=(q_new.q[i]-q.mean_q[i])*B[i];
            for (int j=0; j<Nq; j++)
            {
                H+=0.5*(q_new.q[i]-q.mean_q[i])*(q_new.q[j]-q.mean_q[j])*A[i][j];
            }
        }
    }
    else
    {
        H=0.0;
        syn.make_synthetics(q_new);
        for (int n=0; n<dat.nrec; n++)
        {
            for (int i=0; i<dat.nt; i++)
            {
                H+=pow(dat.ux[n][i]-syn.ux[n][i],2.0)*dat.cx[n][i]+pow(dat.uy[n][i]-syn.uy[n][i],2.0)*dat.cy[n][i]+pow(dat.uz[n][i]-syn.uz[n][i],2.0)*dat.cz[n][i];
            }
        }
        H=0.5*H*dat.dt;
        for (int i=0; i<Nq; i++)
        {
            H+=0.5*pow(q_new.q[i]-q.mean_q[i],2.0)/pow(q.sigma_q[i],2.0);
        }
    }
    
    /* Compute energy - momentum part. */
    for (int i=0; i<Nq; i++) H+=0.5*p_new[i]*p_new[i]/m[i];
    
    return H;
}