void EchoBay::Reservoir::wr_swt_fill(SparseBO &Wr, int Nr,  int edges, std::unordered_set<std::pair<int, int>, pair_hash> &valid_idx_hash)
{
    // Initialize random generator
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine gen(seed);
    std::uniform_real_distribution<double> values(-1.0, 1.0);
    std::bernoulli_distribution probability(0.1);
    std::uniform_real_distribution<double> indexToReassign(0, Nr-1);

    // Allocate triplet list
    std::vector<TripletBO> tripletList;
    std::pair<UOMIterator, bool> result;

    // Fill Wr matrix
    int i, j;
    floatBO value;

    // Check on maximum number of edges
    if(edges >= ceil(Nr/4))
    {
        std::cout << "WARNING! Limiting SWT Edges to Nr/4 to avoid bad rewiring." << std::endl;
        edges = ceil(Nr/4);
    }

    // Allocate fixed connections
    for ( i = 0; i < Nr; ++i)
    {
        for (j = 1  ; j <= edges; ++j)
        {
            // Pick value
            value = values(gen);

            int tempIndex = i + j;
            tempIndex = tempIndex > Nr-1 ? tempIndex - Nr : tempIndex;
            tripletList.push_back(TripletBO(i, tempIndex, value));
            tripletList.push_back(TripletBO( tempIndex, i, value));
        }
    }

    // Set initial Wr
    try
    {
        Wr.setFromTriplets(tripletList.begin(), tripletList.end());
    }
    catch (const std::exception &e)
    {
        throw WrEx;
    }

    // Move edges according to rewiring probability
    for ( j = 1; j <= edges; ++j)
    {
        // int tempIndexLeft = i - j;
        // tempIndexLeft = tempIndexLeft < 0 ? tempIndexLeft + Nr : tempIndexLeft;
        for ( i = 0; i < Nr; ++i )
        {
            int tempIndexRight = i + j;
            tempIndexRight = tempIndexRight > Nr-1 ? tempIndexRight - Nr : tempIndexRight;
            if(probability(gen)){
                Wr.coeffRef(i,tempIndexRight) = 0;
                Wr.coeffRef(tempIndexRight,i) = 0;
                int newConnection = ceil(indexToReassign(gen));

                while(Wr.coeffRef(i, newConnection))
                {
                    while (Wr.coeffRef(i,newConnection) != 0)
                    {
                        newConnection = ceil(indexToReassign(gen));
                    }
                }
                // Move connection
                value = values(gen);
                if (!Wr.coeffRef(i, newConnection))
                {
                    Wr.coeffRef(i, newConnection) = value;
                    Wr.coeffRef(newConnection,i) = value;
                }else{
                    Wr.insert(i, newConnection) = value;
                    Wr.insert(newConnection, i) = value;
                }
            }
        }
    }
}