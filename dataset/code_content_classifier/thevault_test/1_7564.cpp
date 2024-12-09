void window_filter(vector<realtype> &input, int winsize, vector<realtype> &res)
{
    res.clear();

    int inpSize=input.size();
    for(int i=0; i<=inpSize-winsize; i++)
    {
        realtype accum=0.0;
        //int badcount=0;
        for(int j=i; j<winsize+i; j++)
        {
            if(input[j]==-1) continue;
            accum+=input[j];
        }
        accum/=(realtype)winsize;
        res.push_back(accum);
    }
}