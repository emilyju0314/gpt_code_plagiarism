void EchoBay::Reservoir::wr_random_fill(SparseBO &Wr, int Nr, int active_units, std::unordered_set<std::pair<int, int>, pair_hash> &valid_idx_hash)
{
    // Initialize random generator
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine gen(seed);
    std::uniform_real_distribution<double> values(-1.0, 1.0);
    std::uniform_real_distribution<double> indexes(0.0, 1.0);

    std::vector<TripletBO> tripletList;
    tripletList.reserve(active_units);

    std::pair<UOMIterator, bool> result;

    // Fill Wr matrix
    int i, j, k;
    floatBO value;
    for (k = 0; k < active_units;)
    {
        i = floor(indexes(gen) * Nr);
        j = floor(indexes(gen) * Nr);

        value = values(gen);

        // Inserting an element through value_type
        result = valid_idx_hash.insert({i, j});
        if (result.second == true)
        {
            tripletList.push_back(TripletBO(i, j, value));
            k++;
        }
    }
    try
    {
        Wr.setFromTriplets(tripletList.begin(), tripletList.end());
    }
    catch (const std::exception &e)
    {
        throw WrEx;
    }
}