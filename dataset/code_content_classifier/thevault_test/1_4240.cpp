void LQ_quantizer::compute_nn_centroids(size_t k, float * nn_centroids, float * nn_dists, idx_t * nn_ids){
        
        if (LQ_type == 2){
            std::cout << " There is no centroid in LQ type2 " << std::endl;
            exit(0);
        }
        std::vector<float> target_centroid(dimension);
        if (use_all_HNSW){
            for (idx_t label = 0; label < layer_nc;label++){
                compute_final_centroid(label, target_centroid.data());
                auto result_queue = HNSW_all_quantizer->searchKnn(target_centroid.data(), k+1);
                assert(result_queue.size() == k+1);
                // The centroid with smallest size should be itself
                // We just start from the top (As the search result is from large distance to small distance)
                // And get the first k results (from k+1 results)
                for (size_t temp = 0; temp < k; temp ++){
                    hnswlib::idx_t search_centroid_id = label;
                    assert(search_centroid_id != result_queue.top().second);
                    nn_ids[search_centroid_id * k + k - temp -1] = result_queue.top().second;
                    nn_dists[search_centroid_id * k + k - temp - 1] = result_queue.top().first;  
                    result_queue.pop();
                }
            }
        }
        else{
            faiss::IndexFlatL2 all_quantizer(dimension);

            for (idx_t label = 0; label < layer_nc; label++){
                compute_final_centroid(label, target_centroid.data());
                all_quantizer.add(1, target_centroid.data());
            }

            std::cout << "searching the idx for centroids' nearest neighbors " << std::endl;
            for (size_t i = 0; i < this->layer_nc * this->dimension; i ++){
                nn_centroids[i] = all_quantizer.xb[i];
            }

            std::vector<idx_t> search_nn_ids(this->layer_nc * (k+1));
            std::vector<float> search_nn_dis(this->layer_nc * (k+1));
            all_quantizer.search(this->layer_nc, all_quantizer.xb.data(), k+1, search_nn_dis.data(), search_nn_ids.data());
            
            for (size_t i = 0; i < this->layer_nc; i++){
                for (size_t j = 0; j < k; j++){
                    assert(i != search_nn_ids[i * (k + 1) + j + 1 ]);
                    nn_dists[i * k + j] = search_nn_dis[i * (k + 1) + j + 1];
                    nn_ids[i * k + j] = search_nn_ids[i * (k + 1) + j + 1 ];
                }
            }
        }
    }