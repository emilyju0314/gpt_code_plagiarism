KMeans(std::vector< std::pair<std::string, std::vector<double> > > data, int K = 2)
        : m_K{ K }, m_data{ data }, m_centroids{ K }
    {
        /*for (int i = 0; i < data.size(); ++i)
        {
            for (int j = 0; j < data[i].size(); ++j)
            {
                std::cout << "Vec " << i << ": " << m_data[i][j] << std::endl;
            }
        }*/
        // Initialize current cluster of every vector
        for (int i = 0; i < data.size(); ++i)
            m_current_clusters.push_back(-1);

        for (int i = 0; i < K; ++i)
        {
            Cluster_t new_cluster;
            m_clusters.push_back(new_cluster);
            // debug
            // int rand_idx = static_cast<double>( ( (rand() + 1) / static_cast<double>((32 * 1024) ) ) + 0.5 ) * (data.size() - 1);
            std::vector<double> rand_vector = data.at(data.size() - 1).second;
            // Delete it, so that we don't get identical centroids
            data.erase(data.begin() + (data.size() - 1));
            m_centroids[i] = rand_vector;
        }
    }