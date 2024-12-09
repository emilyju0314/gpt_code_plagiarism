void VQ_quantizer::compute_nn_centroids(size_t k, float * nn_centroids, float * nn_dists, idx_t * nn_ids){
        std::vector<float> target_centroid(dimension);

        std::cout << "searching the idx for centroids' nearest neighbors " << std::endl;
        bool use_group_neighbor = true;

        if (use_group_neighbor){
            for (size_t group_id = 0; group_id < nc_upper; group_id++){
                assert(exact_nc_in_groups[group_id] >= k+1);
                faiss::IndexFlatL2 group_quantizer(dimension);

                for (size_t inner_group_id = 0; inner_group_id < exact_nc_in_groups[group_id]; inner_group_id++){
                    idx_t label = CentroidDistributionMap[group_id] + inner_group_id;
                    std::vector<float> centroid(dimension);
                    compute_final_centroid(label, centroid.data());
                    memcpy(nn_centroids + label * dimension, centroid.data(), dimension * sizeof(float));
                    group_quantizer.add(1, centroid.data());
                }

                std::vector<idx_t> search_nn_ids (exact_nc_in_groups[group_id] * (k+1));
                std::vector<float> search_nn_dis (exact_nc_in_groups[group_id] * (k+1));
                group_quantizer.search(exact_nc_in_groups[group_id], group_quantizer.xb.data(), k+1, search_nn_dis.data(), search_nn_ids.data());
                for (size_t inner_group_id = 0; inner_group_id < exact_nc_in_groups[group_id]; inner_group_id++){
                    idx_t label = CentroidDistributionMap[group_id] + inner_group_id;
                    for (size_t j = 0; j < k; j++){
                        nn_ids[label * k + j] = CentroidDistributionMap[group_id] + search_nn_ids[inner_group_id * (k+1) + j + 1];
                        nn_dists[label * k + j] = search_nn_dis[inner_group_id * (k+1) + j + 1];
                    }
                }
            }
        }
        //Add all centroids to the all_quantizer
        else{
            faiss::IndexFlatL2 all_quantizer(dimension);
            for (size_t label = 0; label < layer_nc; label++){
                compute_final_centroid(label, target_centroid.data());
                all_quantizer.add(1, target_centroid.data());
            }

            for (size_t i = 0; i < this->layer_nc * this->dimension; i++){
                nn_centroids[i] = all_quantizer.xb[i];
            }

            std::vector<idx_t> search_nn_ids(this->layer_nc * (k+1));
            std::vector<float> search_nn_dis (this->layer_nc * (k+1));
            all_quantizer.search(layer_nc, all_quantizer.xb.data(), k+1, search_nn_dis.data(), search_nn_ids.data());


            for (size_t i = 0; i < this->layer_nc; i++){
                for (size_t j = 0; j < k; j++){
                    nn_dists[i * k + j] = search_nn_dis[i * (k + 1) + j + 1];
                    nn_ids [i * k + j] = search_nn_ids[i * (k + 1) + j + 1];
                }
            }
        }
    }