void mc::leap_frog(bool verbose)
{
    /* Local variables and setup. -------------------------------------------------*/
    
    double *p_half, *p_init, *out;
    double angle1, angle2;
    parameters q_init;
    
    out=new double[Nq];
    p_half=new double[Nq];
    p_init=new double[Nq];
    
    FILE *pfile;
    if (verbose) pfile=fopen("OUTPUT/trajectory.txt","w");
    
    /* Set initial values. --------------------------------------------------------*/
    
    q_init=q;
    q_new=q;
    for (int i=0; i<Nq; i++) p_init[i]=p[i];
    
    /* March forward. -------------------------------------------------------------*/
    
    if (verbose) fprintf(pfile,"%d %d\n",2*Nq,nt);
    dHdq(q_init,out);
    
    for (int it=0; it<nt; it++)
    {
        /* Some output. */
        if (verbose)
        {
            for (int i=0; i<Nq; i++) fprintf(pfile,"%lg ",q_init.q[i]);
            for (int i=0; i<Nq; i++) fprintf(pfile,"%lg ",p_init[i]);
            fprintf(pfile,"\n");
        }
        
        /* First half step in momentum. */
        for (int i=0; i<Nq; i++)
        {
            p_half[i]=p_init[i]-0.5*dt*out[i];
        }
        
        /* Full step in position. */
        dHdp(p_half,out);
        for (int i=0; i<Nq; i++)
        {
            q_new.q[i]=q_init.q[i]+dt*out[i];
        }
        
        /* Second half step in momentum. */
        dHdq(q_new,out);
        for (int i=0; i<Nq; i++)
        {
            p_new[i]=p_half[i]-0.5*dt*out[i];
        }
        
        /* Update position and momentum. */
        for (int i=0; i<Nq; i++)
        {
            p_init[i]=p_new[i];
            q_init.q[i]=q_new.q[i];
        }
        
        /* Check no-U-turn criterion. */
        angle1=0.0;
        angle2=0.0;
        for (int i=0; i<Nq; i++)
        {
            angle1+=p_new[i]*(q_new.q[i]-q.q[i]);
            angle2+=p[i]*(q.q[i]-q_new.q[i]);
        }
        
        if (angle1<0.0 && angle2<0.0)
        {
            if (verbose) printf("steps: %d\n",it);
            break;
        }
    }
    
    /* Clean up. ------------------------------------------------------------------*/
    
    if (verbose) fclose(pfile);
    
    delete[] p_half;
    delete[] p_init;
    delete[] out;
}