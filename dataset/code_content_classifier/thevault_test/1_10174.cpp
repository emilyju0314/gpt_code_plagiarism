void print_array(void *x,int nElems,enum data_types dt)
{
    printf("\n");
    for(int i = 0 ; i < nElems ; i++)
    {        
        switch(dt)
        {
            case chr :
            {
                    char *c = (char *)x;                    
                    printf("%c ",c[i]);
                    break;
            }
            case intg :
            {
                    int *g = (int *)x;                    
                    printf("%d ",g[i]);
                    break;
            }
            case flt :
            {
                    float *f = (float *)x;                    
                    printf("%f ",f[i]);
                    break;
            }
            case dbl:
            {
                    double *d = (double *)x;                    
                    printf("%lf ",d[i]);
                    break;
            }
        }
    }
    printf("\n");
}