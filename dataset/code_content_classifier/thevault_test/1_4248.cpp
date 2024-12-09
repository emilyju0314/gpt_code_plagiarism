void keep_k_min(const size_t m, const size_t k, const float * all_dists, const idx_t * all_labels, float * sub_dists, idx_t * sub_labels){
        if (k < m){
            faiss::maxheap_heapify(k, sub_dists, sub_labels);
            for (size_t i = 0; i < m; i++){
                if (all_dists[i] < sub_dists[0]){
                    faiss::maxheap_pop(k, sub_dists, sub_labels);
                    faiss::maxheap_push(k, sub_dists, sub_labels, all_dists[i], all_labels[i]);
                }
            }
        }
        else if (k == m){
            memcpy(sub_dists, all_dists, k * sizeof(float));
            memcpy(sub_labels, all_labels, k * sizeof(idx_t));
        }
        else{
            std::cout << "k (" << k << ") should be smaller than m (" << m << ") in keep_k_min function " << std::endl;
            exit(0);
        }
    }