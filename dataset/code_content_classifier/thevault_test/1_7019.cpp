void data::write(const char *filename)
{
    FILE *fid;
    
    fid=fopen(filename,"w");
    
    fprintf(fid,"%d %lg %d\n",nt,dt,nrec);
    
    for (int i=0; i<nrec; i++)
    {
        for (int j=0; j<nt; j++) fprintf(fid,"%lg ",ux[i][j]);
        fprintf(fid,"\n");
        for (int j=0; j<nt; j++) fprintf(fid,"%lg ",cx[i][j]);
        fprintf(fid,"\n");
        for (int j=0; j<nt; j++) fprintf(fid,"%lg ",uy[i][j]);
        fprintf(fid,"\n");
        for (int j=0; j<nt; j++) fprintf(fid,"%lg ",cy[i][j]);
        fprintf(fid,"\n");
        for (int j=0; j<nt; j++) fprintf(fid,"%lg ",uz[i][j]);
        fprintf(fid,"\n");
        for (int j=0; j<nt; j++) fprintf(fid,"%lg ",cz[i][j]);
        fprintf(fid,"\n");
    }
    
    fclose(fid);
}