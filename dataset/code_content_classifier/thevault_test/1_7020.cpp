void data::print()
{
    printf("nt=%d, dt=%lg, nrec=%d\n",nt,dt,nrec);
    for (int i=0; i<nrec; i++)
    {
        printf("recx=%lg, recy=%lg, recz=%lg\n",recx[i],recy[i],recz[i]);
    }
}