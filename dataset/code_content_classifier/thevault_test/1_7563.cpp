void pdf(vector<realtype> &input, vector<realtype> &bins, vector<realtype> &hist,bool clear)
{
    //if clear flag set
    if(clear)
        hist.clear();

    int end_index = hist.size();
    int bin_size = bins.size();
    int input_size = input.size();
    int counted = 0;
    //for(int i=0;i<=bin_size;i++)
    //	hist.push_back(0.0);

    //roll back modifications to make zero values count
    hist.insert(hist.end(),bin_size+1,0.0);
    //hist.insert(hist.end(),bin_size,0.0);

    for(int j=0; j<input_size; j++)
    {
        realtype val=input[j];
        if (val==-1) continue;
        counted++;
        int k;
        for(k=end_index; k<end_index+bin_size; k++)
        {
            if(val<bins[k-end_index])
                break;
        }
        //roll back modifications to make zero values count
        //if(k>end_index)
        //	hist[k-1]+=1.0;
        hist[k]+=1.0;
    }

    if(input.size()!=0)
        //roll back modifications to make zero values count
        for(int i=end_index; i<=end_index+bin_size; i++)
            hist[i]/=(realtype)input.size();
    //for(int i=end_index;i<end_index+bin_size;i++)

}