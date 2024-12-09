void data::read_data(const char *filename)
{
    /* Local variables. */
    FILE *fid;
    char str[1000];
    
    /* Open file and read header. */
    fid=fopen(filename,"r");
    
    fscanf(fid,"%d %lg %d",&nt,&dt,&nrec);
    fgets(str,1000,fid);
    
    /* Read traces. */
    for (int i=0; i<nrec; i++)
    {
        for (int j=0; j<nt; j++) fscanf(fid,"%lg",&(ux[i][j]));
        fgets(str,1000,fid);
        for (int j=0; j<nt; j++) fscanf(fid,"%lg",&(cx[i][j]));
        fgets(str,1000,fid);
        for (int j=0; j<nt; j++) fscanf(fid,"%lg",&(uy[i][j]));
        fgets(str,1000,fid);
        for (int j=0; j<nt; j++) fscanf(fid,"%lg",&(cy[i][j]));
        fgets(str,1000,fid);
        for (int j=0; j<nt; j++) fscanf(fid,"%lg",&(uz[i][j]));
        fgets(str,1000,fid);
        for (int j=0; j<nt; j++) fscanf(fid,"%lg",&(cz[i][j]));
        fgets(str,1000,fid);
    }
    
    /* Clean up. */
    fclose(fid);
}