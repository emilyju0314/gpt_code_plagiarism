void PQ_quantizer::compute_final_centroid(const idx_t label, float * final_centroid){
        
        std::vector<idx_t> group_index(this->M);
        idx_t group_id = label_2_spaceID(label, group_index.data());

        for (size_t i = 0; i < this->M; i++){
            for (size_t j = 0; j < this->dsub; j++){
                final_centroid[i * dsub + j] = this->PQs[group_id]->centroids[i * exact_ksubs[group_id] * dsub + group_index[i] * dsub + j];
            }
        }
    }