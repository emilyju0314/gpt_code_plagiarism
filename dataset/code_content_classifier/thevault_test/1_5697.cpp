void EchoBay::Reservoir::wr_crj_fill(SparseBO &Wr, int Nr, int jumps, std::unordered_set<std::pair<int, int>, pair_hash> &valid_idx_hash)
{
    // Initialize random generator
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine gen(seed);
    std::uniform_real_distribution<double> values(-1.0, 1.0);
    std::bernoulli_distribution probability(0);
    std::uniform_real_distribution<double> indexToReassign(0, Nr-1);

    // Allocate triplet list
    std::vector<TripletBO> tripletList;
    std::pair<UOMIterator, bool> result;

    // Fill Wr matrix
    int i;
    floatBO value;
    // Create Circle
    value = values(gen);
    tripletList.push_back(TripletBO( 0, Nr-1, value));
    //tripletList.push_back(TripletBO( Nr-1, 0, value));

    // Initial fill
    for(i = 0; i < Nr-1; i++){
        tripletList.push_back(TripletBO( i+1, i, value));
        //tripletList.push_back(TripletBO( i, i+1, value));
    }

    // Create Jumps
    value = values(gen);
    if (jumps > 0)
    {
        for (i = 0; i < Nr; i = i + jumps){
            int tempindex = i + jumps;
            tempindex = tempindex > Nr-1 ? tempindex - Nr : tempindex;
            tripletList.push_back(TripletBO( i, tempindex, value));
            tripletList.push_back(TripletBO( tempindex, i, value));
        }
    }

    // Allocate Wr
    try
    {
        Wr.setFromTriplets(tripletList.begin(), tripletList.end());
    }
    catch (const std::exception &e)
    {
        throw WrEx;
    }
}