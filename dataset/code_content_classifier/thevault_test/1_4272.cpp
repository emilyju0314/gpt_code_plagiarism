long arrayManipulation(int n, vector<vector<int>> queries) {
    struct record
    {
        int pos;
        long value;
    };
    std::vector<record> incs;
    std::vector<record> decs;

    for(auto&& op : queries)
    {
        incs.push_back({op[0], op[2]});
        decs.push_back({op[1] + 1, -op[2]});
    }

    std::sort(incs.begin(), incs.end(), [](auto&a,auto&b){return a.pos < b.pos;});
    std::sort(decs.begin(), decs.end(), [](auto&a,auto&b){return a.pos < b.pos;});

    long value = 0;
    long max = 0;

    auto inci = incs.begin();
    auto decsi = decs.begin();
    while(inci != incs.end())
    {
        if(decsi->pos <= inci->pos)
        {
            value += decsi->value;
            ++decsi;
        }
        else
        {
            value += inci->value;
            ++inci;
        }
       
        if(value > max) max = value;        
    }

    return max;
}