void mc::write_sample(FILE *pfile, double misfit, int iteration)
{
    if (iteration==0) fprintf(pfile,"%d %d\n",Nq,iterations+1);
    
    for (int i=0; i<Nq; i++) fprintf(pfile,"%lg ",q.q[i]);
    fprintf(pfile,"%lg ",misfit);
    fprintf(pfile,"\n");
}