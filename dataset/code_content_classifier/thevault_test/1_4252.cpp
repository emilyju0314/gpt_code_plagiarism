bool PQ_quantizer::traversed(const idx_t * visited_index, const idx_t * index_check, const size_t index_num){
        for (size_t i = 0; i < index_num; i++){
            bool index_flag = true;
            for (size_t j = 0; j < this->M; j++){
                if (visited_index[i * M + j] != index_check[j]){
                    index_flag = false;
                    break;
                }
            }
            if (index_flag == true)
                return true;
        }
        return false;
    }