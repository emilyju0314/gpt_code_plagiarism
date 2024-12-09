void LQ_quantizer::build_centroids(const float * train_data, size_t train_set_size, idx_t * train_data_ids){
        if (LQ_type == 2){
            std::cout << " LQ type 2, no need to compute the alpha" << std::endl;
            
            this->alphas.resize(0);

            std::cout << "Computing the centroid norm and centroid product" << std::endl;
            upper_centroid_product.resize(nc_upper * max_nc_per_group);
            for (size_t i = 0; i < nc_upper; i++){
                const float * base_centroid = upper_centroids.data() + i * dimension;
                for (size_t j = 0; j < max_nc_per_group; j++){
                    idx_t neighbor_id = nn_centroid_ids[i][j];
                    const float * neighbor_centroid = upper_centroids.data() + neighbor_id * dimension;
                    std::vector<float> centroid_vector(dimension);
                    faiss::fvec_madd(dimension, neighbor_centroid, -1.0, base_centroid, centroid_vector.data());
                    upper_centroid_product[i * max_nc_per_group + j] = faiss::fvec_inner_product(centroid_vector.data(), base_centroid, dimension);
                }
            }
            return;
        }
        std::cout << "Adding " << train_set_size << " train set data into " << nc_upper << " groups " << std::endl;
        std::vector<std::vector<float>> train_set(this->nc_upper);

        for(size_t i = 0; i < train_set_size; i++){
            idx_t group_id = train_data_ids[i];
            assert(group_id <= this->nc_upper);
            for (size_t j = 0; j < this->dimension; j++){
                train_set[group_id].push_back(train_data[i * dimension + j]);
            }
        }

        size_t min_train_size = train_set[0].size() / dimension; 
        for (size_t i = 0; i < nc_upper; i++){if (min_train_size > train_set[i].size() / dimension) min_train_size = train_set[i].size() / dimension; if (i <= 1000) {std::cout << train_set[i].size() / dimension <<" ";}}
        std::cout <<  std::endl << "The min size for sub train set is: " << min_train_size << std::endl;

        std::cout << "Computing alphas for lq_quantizer with upper centroids: " << this->upper_centroids.size() / dimension << " nc_per_group: " << max_nc_per_group << std::endl;
        std::cout << "The size of upper_centroids: " << this->upper_centroids.size() / this->dimension << std::endl;
        std::cout << "The size of nn_centroid_ids: " << this->nn_centroid_ids.size() << std::endl;
        alphas.resize(nc_upper);

#pragma omp parallel for
        for (size_t i = 0; i < nc_upper; i++){
            alphas[i].resize(max_nc_per_group);
            std::vector<float> centroid_vectors(max_nc_per_group * dimension);
            const float * centroid = this->upper_centroids.data() + i * dimension;
            for (size_t j = 0; j < max_nc_per_group; j++){
                const float * nn_centroid = this->upper_centroids.data() + this->nn_centroid_ids[i][j] * dimension;
                faiss::fvec_madd(dimension, nn_centroid, -1.0, centroid, centroid_vectors.data()+ j * dimension);
            }
            size_t train_group_size = train_set[i].size() / this->dimension;
            compute_alpha(centroid_vectors.data(), train_set[i].data(), centroid, this->nn_centroid_dists[i].data(), train_group_size, alphas[i].data());
        }
        std::cout << "finished computing centoids" <<std::endl;

    }