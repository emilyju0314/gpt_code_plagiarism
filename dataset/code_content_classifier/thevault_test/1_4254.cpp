void PQ_quantizer::search_all(const size_t n, const float * query_data, idx_t * query_data_ids){
        std::vector<idx_t> query_group_labels(n  * nc_upper);
        std::vector<float> query_group_dists(n * nc_upper);
#pragma omp parallel for
        for (size_t i = 0; i < n; i++){
            for (size_t j = 0; j < nc_upper; j++){
                search_in_group(query_data + i * dimension, j, query_group_dists.data() + i * nc_upper + j, query_group_labels.data() + i * nc_upper + j, 1);
            }
        }

#pragma omp parallel for
        for (size_t i = 0; i < n; i++){
            float min_dis = query_group_dists[i * nc_upper];
            query_data_ids[i] = query_group_labels[i * nc_upper];

            for (size_t j = 1; j < nc_upper; j++){
                if (query_group_dists[i * nc_upper + j] < min_dis){
                    min_dis = query_group_dists[i * nc_upper + j];
                    query_data_ids[i] = query_group_labels[i *nc_upper + j];
                }
            }
        }
    }