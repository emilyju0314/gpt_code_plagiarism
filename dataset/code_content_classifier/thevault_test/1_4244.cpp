void VQ_quantizer::compute_final_centroid(idx_t label, float * final_centroid){

        idx_t group_id;
        idx_t inner_group_id;
        get_group_id(label, group_id, inner_group_id);

        if (use_HNSW){
            const float * target_centroid = this->HNSW_quantizers[group_id]->getDataByInternalId(inner_group_id);
            for (size_t i = 0; i < dimension; i++){
                final_centroid[i] = target_centroid[i];
            }
        }
        else{
            if (this->L2_quantizers[group_id]->xb.size() < (inner_group_id + 1) * dimension){
                std::cout << label << " " << group_id << " " << inner_group_id << " " << L2_quantizers[group_id]->xb.size() << std::endl;
            }
            assert(this->L2_quantizers[group_id]->xb.size() >= (inner_group_id + 1) * dimension);
            for (size_t i = 0; i < dimension; i++){
                final_centroid[i] = this->L2_quantizers[group_id]->xb[inner_group_id * this->dimension + i];
            }
        }
    }