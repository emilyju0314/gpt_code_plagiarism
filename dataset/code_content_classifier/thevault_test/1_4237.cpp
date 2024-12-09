void LQ_quantizer::compute_final_centroid(idx_t label, float * final_centroid){
        if (LQ_type == 2){
            std::cout << " There is no centroid in LQ type2 " << std::endl;
            exit(0);
        }
        idx_t group_id, inner_group_id;
        get_group_id(label, group_id, inner_group_id);
        
        std::vector<float> centroid_vector(dimension);
        const float * nn_centroid = this->upper_centroids.data() + nn_centroid_ids[group_id][inner_group_id] * dimension;
        const float * centroid = this->upper_centroids.data() + group_id * dimension;
        faiss::fvec_madd(dimension, nn_centroid, -1.0, centroid, centroid_vector.data());
        faiss::fvec_madd(dimension, centroid, alphas[group_id][inner_group_id], centroid_vector.data(), final_centroid);
    }