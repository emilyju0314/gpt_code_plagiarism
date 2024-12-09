void VQ_quantizer::build_centroids(const float * train_data, size_t train_set_size, idx_t * train_data_ids){
        std::cout << "Adding " << train_set_size << " train set data into " << nc_upper << " groups " << std::endl;
        std::vector<std::vector<float>> train_set(this->nc_upper);

        for (size_t i = 0; i < train_set_size; i++){
            idx_t group_id = train_data_ids[i];
            assert(group_id <= this->nc_upper);
            for (size_t j = 0; j < dimension; j++)
                train_set[group_id].push_back(train_data[i*dimension + j]);
        }

        std::cout << "Building group quantizers for vq_quantizer " << std::endl;
        size_t min_train_size = train_set[0].size() / dimension; 
        for (size_t i = 0; i < nc_upper; i++){if (min_train_size > train_set[i].size() / dimension) min_train_size = train_set[i].size() / dimension; if (i <= 1000) {std::cout << train_set[i].size() / dimension <<" ";}}


        std::cout <<  std::endl << "The min size for sub train set is: " << min_train_size << std::endl;


#pragma omp parallel for
        for (size_t i = 0; i < nc_upper; i++){

            size_t nt_sub = train_set[i].size() / this->dimension;
            //std::cout << "Clustering " << nt_sub << " train vectors into " << nc_per_group << " groups " << std::endl;
            if (nt_sub == 0){
                std::cout << "No enough training point, reduce the number of cluster or add more training points" << std::endl;
                exit(0);
            }

            size_t exact_nc_in_group;
            if (nt_sub < max_nc_per_group * min_train_size_per_group){
                //Shrink the nc size in this group by dividing min trainset size for each cluster 
                exact_nc_in_group = nt_sub / min_train_size_per_group;

                if (exact_nc_in_group <= 0){ exact_nc_in_group = 1;} //Ensure there is at least one centroid in this cluster
            }
            else{
                exact_nc_in_group = max_nc_per_group;
            }
            exact_nc_in_groups[i] = exact_nc_in_group;

            std::vector<float> centroids(dimension * exact_nc_in_group);

            if (exact_nc_in_group == 1){
                for (size_t temp1 = 0; temp1 < nt_sub; temp1++){
                    for (size_t temp2 = 0; temp2 < dimension; temp2++){
                        centroids[temp2] += train_set[i][temp1 * dimension + temp2];
                    }
                }
                for (size_t temp1 = 0; temp1 < dimension; temp1 ++){
                    centroids[temp1] /= nt_sub;
                }
            }
            else{
                bool verbose = nc_upper > 1 ? false : true;
                faiss::kmeans_clustering(dimension, nt_sub, exact_nc_in_group, train_set[i].data(), centroids.data(), 30, verbose);
            }

            //Adding centroids into quantizers
            if (use_HNSW){
                hnswlib::HierarchicalNSW * centroid_quantizer = new hnswlib::HierarchicalNSW(dimension, exact_nc_in_group, M, 2 * M, efConstruction);
                for (size_t j = 0; j < exact_nc_in_group; j++){
                    centroid_quantizer->addPoint(centroids.data() + j * dimension);
                }
                this->HNSW_quantizers[i] = centroid_quantizer;
            }
            else
            {
                faiss::IndexFlatL2 * centroid_quantizer = new faiss::IndexFlatL2(dimension);
                centroid_quantizer->add(exact_nc_in_group, centroids.data());
                this->L2_quantizers[i] = centroid_quantizer;
            }
        }

        size_t num_centroids = 0;
        for (size_t i = 0; i < nc_upper; i++){
            CentroidDistributionMap[i] = num_centroids;
            num_centroids += exact_nc_in_groups[i];
        }
        
        if (num_centroids < layer_nc){
            std::cout << "The number of centroids is shrinked in VQ layer from " << layer_nc << " to " << num_centroids << std::endl;
            layer_nc = num_centroids;
        }

        std::cout << "Finished computing centoids with final centroids: " << layer_nc <<std::endl;
    }