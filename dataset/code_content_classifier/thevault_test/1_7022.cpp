void mc::propose_hamilton()
{
    /* Draw random prior momenta. */
    for (int i=0; i<Nq; i++) p[i]=randn(0.0,sqrt(m[i]));
    
    /* Integrate Hamilton's equations. */
    leap_frog(verbose);
}