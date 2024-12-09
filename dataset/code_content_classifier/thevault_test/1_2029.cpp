void genTridiag(int *I, int *J, float *val, int M, int N, int nz)
{
    I[0] = 0, J[0] = 0, J[1] = 1;
    val[0] = (float)rand()/RAND_MAX + 10.0;
    val[1] = (float)rand()/RAND_MAX;
    int start;
    for (int i = 1; i < N; i++) {
        if (i > 1) 
            I[i] = I[i-1]+3;
        else 
            I[1] = 2;
        start = (i-1)*3 + 2;
        J[start] = i - 1;
        J[start+1] = i;
        if (i < N-1) 
            J[start+2] = i + 1;
        val[start] = val[start-1];
        val[start+1] = (float)rand()/RAND_MAX + 10.0;
        if (i < N-1) 
            val[start+2] = (float)rand()/RAND_MAX;
    }
    I[N] = nz;
}