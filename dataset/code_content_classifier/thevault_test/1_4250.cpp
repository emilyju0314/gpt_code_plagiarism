idx_t PQ_quantizer::spaceID_2_label(const idx_t * index, const idx_t group_id){
        idx_t idx = 0;

        for (size_t i = 0; i < M; i++){
            idx += index[i] * new_pow(exact_ksubs[group_id], i);
        }
        idx_t result_idx = CentroidDistributionMap[group_id] + idx; 
        if (result_idx >= layer_nc){
            std::cout << group_id << " " << CentroidDistributionMap[group_id] << " " << idx << " " << layer_nc << std::endl;
        }
        assert(result_idx < layer_nc);
        return result_idx;
    }