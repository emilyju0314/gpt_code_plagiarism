idx_t PQ_quantizer::label_2_spaceID(idx_t label, idx_t * index){
        assert(label < layer_nc);
        
        idx_t group_id = 0;
        idx_t inner_group_id = 0;

        for (int i = nc_upper -1; i >= 0; i--){
            if (label - CentroidDistributionMap[i] >= 0){
                group_id = i;
                inner_group_id = label - CentroidDistributionMap[i];
                break;
            }
        }

        for (size_t i = 0; i < M; i++){
            index[i] = inner_group_id % exact_ksubs[group_id];
            inner_group_id = inner_group_id / exact_ksubs[group_id];
        }
        return group_id;
    }