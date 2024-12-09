void VQ_quantizer::search_in_group(const float * query, const idx_t group_id, float * result_dists, idx_t * result_labels, size_t k){
        
        assert(group_id < nc_upper);
        //If no enough centroids, return error, need to check before use
        if (k > exact_nc_in_groups[group_id]){
            std::cout << "No enough centroids in group " << group_id << " in VQ layer" << std::endl;
            exit(0);
        }
        if (use_HNSW){
            //The distance result for search kNN is in reverse 
            size_t search_para = k > this->HNSW_quantizers[group_id]->efSearch ? k : this->HNSW_quantizers[group_id]->efSearch;

            auto result_queue = this->HNSW_quantizers[group_id]->searchBaseLayer(query, search_para);

            // The result of search result
            for (size_t j = 0; j < this->max_nc_per_group; j++){
                if (j < search_para){
                    result_dists[search_para - j - 1] = result_queue.top().first;
                    result_labels[search_para - j -1] = CentroidDistributionMap[group_id] + result_queue.top().second;
                    result_queue.pop();           
                }
                else{
                    result_dists[j] = MAX_DIST;
                    result_labels[j] = INVALID_ID;
                }
            }
        }
        else{
//#pragma omp parallel for
            for (size_t j = 0; j < this->max_nc_per_group; j++){
                if (j < exact_nc_in_groups[group_id]){
                    const float * target_centroid = this->L2_quantizers[group_id]->xb.data() + j * this->dimension;
                    result_dists[j] = faiss::fvec_L2sqr(target_centroid, query, dimension);
                    result_labels[j] = CentroidDistributionMap[group_id] + j;
                }
                else{
                    result_dists[j] = MAX_DIST;
                    result_labels[j] = INVALID_ID;
                }
            }
        }
    }