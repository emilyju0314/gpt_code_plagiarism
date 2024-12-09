void LQ_quantizer::recover_residual_group_id(size_t n, const idx_t * labels, const float * residuals, float * x, const float * vector_alpha){
#pragma omp parallel for
        for (size_t i = 0; i < n; i++){
            if (LQ_type == 2){
                idx_t group_id, inner_group_id;
                get_group_id(labels[i], group_id, inner_group_id);
                float * group_centroid = this->upper_centroids.data() + group_id * dimension;
                idx_t nn_id = this->nn_centroid_ids[group_id][inner_group_id];
                float * nn_centroid = this->upper_centroids.data() + nn_id * dimension;
                std::vector<float> centroid_vector(dimension);
                faiss::fvec_madd(dimension, nn_centroid, -1.0, group_centroid, centroid_vector.data());
                std::vector<float> subcentroid(dimension); 
                faiss::fvec_madd(dimension, group_centroid, vector_alpha[i], centroid_vector.data(), subcentroid.data()); 
                faiss::fvec_madd(dimension, residuals + i * dimension, 1.0, subcentroid.data(), x + i * dimension);
            }
            else{
                std::vector<float> final_centroid(dimension);
                compute_final_centroid(labels[i], final_centroid.data());
                faiss::fvec_madd(dimension, residuals + i * dimension, 1.0, final_centroid.data(), x + i * dimension);
            }
        }
    }