LQ_quantizer::LQ_quantizer(size_t dimension, size_t nc_upper, size_t max_nc_per_group, const float * upper_centroids,
                               const idx_t * upper_centroid_ids, const float * upper_centroid_dists, size_t LQ_type, bool use_all_HNSW):
            Base_quantizer(dimension,  nc_upper, max_nc_per_group){

            this->use_all_HNSW = use_all_HNSW;
            this->alphas.resize(nc_upper);
            this->upper_centroids.resize(dimension * nc_upper);
            this->nn_centroid_ids.resize(nc_upper);
            this->nn_centroid_dists.resize(nc_upper);
            this->LQ_type = LQ_type;

            // Need to store all upper layer centroids
            for (size_t i = 0; i < dimension * nc_upper; i++){
                this->upper_centroids[i] = upper_centroids[i];
            }

            for (size_t i = 0; i < nc_upper; i++){
                for (size_t j = 0; j < max_nc_per_group; j++){
                    this->nn_centroid_ids[i].push_back(upper_centroid_ids[i * max_nc_per_group + j]);
                    this->nn_centroid_dists[i].push_back(upper_centroid_dists[i * max_nc_per_group + j]);
                }
                assert(this->nn_centroid_ids[i].size() == max_nc_per_group && this->nn_centroid_dists[i].size() == max_nc_per_group);
            }
        }