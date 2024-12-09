void LQ_quantizer::search_in_group(const float * query, idx_t * upper_result_labels, const float * upper_result_dists, 
                const size_t upper_search_space, const idx_t group_id, float * result_dists, idx_t * result_labels, float * vector_alpha){        

        /*
        std::cout << "Search result: ";
        for (size_t i = 0; i < upper_search_space; i++){
            std::cout << upper_result_labels[i] << " " << upper_result_dists[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Neighbor result: ";
        for (size_t i = 0; i < max_nc_per_group; i++){
            std::cout << nn_centroid_ids[group_id][i] << " " << nn_centroid_dists[group_id][i] << " ";
        }
        std::cout << std::endl;
        */


        for (size_t inner_group_id = 0; inner_group_id < max_nc_per_group; inner_group_id++){

            result_labels[inner_group_id] = CentroidDistributionMap[group_id] + inner_group_id;
            idx_t nn_id = nn_centroid_ids[group_id][inner_group_id];
            float query_nn_dist = Not_Found;
            float query_group_dist = Not_Found;

            /*
            bool query_nn_flag = false;
            bool query_group_flag = false;
            for(size_t index = 0; index < upper_search_space; index ++){
                if  (!query_nn_flag && upper_result_labels[index] == nn_id){
                    query_nn_dist = upper_result_dists[index];
                    query_nn_flag = true;
                }

                if (!query_group_flag && upper_result_labels[index] == group_id){
                    query_group_dist = upper_result_dists[index];
                    query_group_flag = true;
                }

                if (query_nn_flag && query_group_flag){
                    break;
                }
            }
            */
            // There are many ways for finding whether the nn_id exists in the upper search result, try different ways

            idx_t * nn_id_index = std::find(upper_result_labels, upper_result_labels+ upper_search_space, nn_id);
            idx_t nn_index = nn_id_index - upper_result_labels;

            if (nn_index < upper_search_space){
                idx_t * group_id_index = std::find(upper_result_labels, upper_result_labels+ upper_search_space, group_id);
                idx_t group_index = group_id_index - upper_result_labels;
                assert(group_index < upper_search_space);
                
                //assert(query_nn_dist != Not_Found && query_group_dist != Not_Found);
                query_group_dist = upper_result_dists[group_index];
                query_nn_dist =upper_result_dists[nn_index];

                float group_nn_dist = nn_centroid_dists[group_id][inner_group_id];

                if (LQ_type == 2){
                    auto result_pair = LQ0_fast_distance(group_nn_dist, query_group_dist, query_nn_dist);
                    result_dists[inner_group_id] = result_pair.second;
                    vector_alpha[inner_group_id] = result_pair.first;
                }
                else{
                    float alpha = alphas[group_id][inner_group_id];
                    result_dists[inner_group_id] = alpha*(alpha-1)*group_nn_dist + (1-alpha)*query_group_dist + alpha*query_nn_dist;  

                    //if (!(result_dists[inner_group_id] >=0)){
                    //    std::cout << result_dists[inner_group_id] << " " << alpha << " " << group_nn_dist << " " << query_group_dist << " " << query_nn_dist << std::endl;
                    //}
                }
            }
            else{
                std::cout << nn_id << " Not Found  " << std::endl;;
                std::vector<float> query_sub_centroid_vector(dimension);
                float * nn_centroid = upper_centroids.data() + nn_centroid_ids[group_id][inner_group_id] * dimension;
                float * group_centroid = upper_centroids.data() + group_id * dimension;
                float nn_dist = nn_centroid_dists[group_id][inner_group_id];

                if (LQ_type == 2){
                    auto result_pair = LQ0_distance(query, group_centroid, nn_centroid, nn_dist);

                    result_dists[inner_group_id] = result_pair.second;
                    assert(result_pair.second >=0);
                    vector_alpha[inner_group_id] = result_pair.first;
                }
                
                //std::vector<float> sub_centroid(dimension);
                //compute_final_centroid(group_id, j, sub_centroid.data());
                //faiss::fvec_madd(dimension, sub_centroid.data(), -1.0, query, query_sub_centroid_vector.data());
                else{
                    float alpha = alphas[group_id][inner_group_id];
                    for (size_t k = 0; k < dimension; k++){
                        query_sub_centroid_vector[k] = alpha * nn_centroid[k] + (1-alpha)*group_centroid[k]-query[k];
                    }
                    result_dists[inner_group_id] = faiss::fvec_norm_L2sqr(query_sub_centroid_vector.data(), dimension);
                    assert(result_dists[inner_group_id]);
                }
            }
        }


        /*
        for (size_t i = 0; i < n; i++){
            idx_t group_id = group_ids[i];
            query_sequence_set[group_id].push_back(i);
        }

//#pragma omp parallel for
        for (size_t group_id = 0; group_id < this->nc_upper; group_id++){
            if (query_sequence_set[group_id].size() == 0)
                continue;
            else{
                std::vector<std::vector<float>> sub_centroids(this->nc_per_group, std::vector<float>(dimension));
                std::vector<bool> sub_centroids_computed(this->nc_per_group, false);
                float alpha = this->alphas[group_id];

                for (size_t train_group_id = 0; train_group_id < query_sequence_set[group_id].size(); train_group_id++){
                    idx_t sequence_id = query_sequence_set[group_id][train_group_id];
                    std::vector<float> query_sub_centroids_dists(this->nc_per_group, 0);

                    for (size_t inner_group_id = 0; inner_group_id < this->nc_per_group; inner_group_id++){
                        float query_nn_dist = Not_Found;
                        float query_group_dist = Not_Found;
                        idx_t nn_id = this->nn_centroid_ids[group_id][inner_group_id];

                        for (size_t search_id = 0; search_id < upper_search_space; search_id++){
                            if (upper_result_labels[sequence_id * upper_search_space  + search_id] == nn_id){
                                query_nn_dist = upper_result_dists[sequence_id * upper_search_space + search_id];
                            }

                            else if (upper_result_labels[sequence_id * upper_search_space + search_id] == group_id){
                                query_group_dist = upper_result_dists[sequence_id * upper_search_space + search_id];
                            }

                            if (query_nn_dist != Not_Found && query_group_dist != Not_Found)
                                break;
                        }
                        assert (query_group_dist != Not_Found);

                        if (query_nn_dist != Not_Found){
                            float group_nn_dist = this->nn_centroid_dists[group_id][inner_group_id];

                            query_sub_centroids_dists[inner_group_id] = alpha*(alpha-1)*group_nn_dist + (1-alpha)*query_group_dist + alpha*query_nn_dist;
                        }
                        else{
                        if (! sub_centroids_computed[inner_group_id]){
                            compute_final_centroid(group_id, inner_group_id, sub_centroids[inner_group_id].data());
                            sub_centroids_computed[inner_group_id] = true;
                        }
                        
                        const float * query = queries + sequence_id * dimension;
                        std::vector<float> query_sub_centroid_vector(dimension);
                        faiss::fvec_madd(dimension, sub_centroids[inner_group_id].data(), -1.0, query, query_sub_centroid_vector.data());
                        query_sub_centroids_dists[inner_group_id] = faiss::fvec_norm_L2sqr(query_sub_centroid_vector.data(), dimension);
                        }
                    }

                    for (size_t inner_group_id = 0; inner_group_id < this->nc_per_group; inner_group_id++){
                        result_dists[sequence_id * this->nc_per_group + inner_group_id] = query_sub_centroids_dists[inner_group_id];
                        result_labels[sequence_id * this->nc_per_group + inner_group_id] = CentroidDistributionMap[group_id] + inner_group_id;
                    }
                }
            }
        }
        */
    }