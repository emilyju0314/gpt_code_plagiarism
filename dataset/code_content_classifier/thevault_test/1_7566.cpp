realtype hist_diff(vector<realtype> &in1, vector<realtype> &in2)
{
    int size=in1.size();

    realtype diff_accum = 0.0;
    for(int x=0; x<size; x++)
    {
        realtype diff = in1[x]-in2[x];
        diff_accum+=fabs(diff);
    }
    return diff_accum/size;
}