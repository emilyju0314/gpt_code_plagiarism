void LQ_quantizer::search_all(const size_t n, const size_t k, const float * query_data, idx_t * query_data_ids){
        if (LQ_type == 2){
            for (size_t i = 0; i < n; i++){
                std::vector<float> search_dist(layer_nc);
                std::vector<idx_t> search_idxs(layer_nc);
                for (size_t group_id = 0; group_id < nc_upper; group_id++){
                    float * upper_centroid = this->upper_centroids.data() + group_id * dimension;
                    for (size_t inner_group_id = 0; inner_group_id < max_nc_per_group; inner_group_id++){
                        
                        idx_t nn_centroid_id = this->nn_centroid_ids[group_id][inner_group_id];
                        float * nn_centroid = this->upper_centroids.data() + nn_centroid_id * dimension;
                        float nn_dist = this->nn_centroid_dists[group_id][inner_group_id];
                        auto result_pair = LQ0_distance(query_data + i * dimension, upper_centroid, nn_centroid, nn_dist);
                        search_dist[group_id * max_nc_per_group + inner_group_id] = result_pair.second;
                        search_idxs[group_id * max_nc_per_group + inner_group_id] = group_id * max_nc_per_group + inner_group_id;
                    }
                }
                std::vector<float> result_dist(k);
                keep_k_min(layer_nc, k, search_dist.data(), search_idxs.data(), result_dist.data(), query_data_ids + i * k);
            }
        }

        else if (use_all_HNSW){
            for (size_t i = 0; i < n; i++){
                auto result_queue = HNSW_all_quantizer->searchKnn(query_data + i * dimension, k);
                size_t result_size = result_queue.size();
                assert(result_size == k);
                for (size_t j = 0; j < result_size; j++){
                    query_data_ids[i * k + k - j - 1] = result_queue.top().second;
                    result_queue.pop();
                }
            }
        }        
        else{
            faiss::IndexFlatL2 centroid_index(dimension * k);
            std::vector<float> one_centroid(dimension * k);

            for (idx_t label = 0; label < layer_nc; label ++){
                compute_final_centroid(label, one_centroid.data());
                centroid_index.add(1, one_centroid.data());
            }

            std::vector<float> result_dists(n);
            centroid_index.search(n, query_data, k, result_dists.data(), query_data_ids);
        }
    }