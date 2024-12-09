void PQ_quantizer::search_in_group(const float * query, const idx_t group_id, float * result_dists, idx_t * result_labels, size_t keep_space){
        assert(keep_space <= exact_ksubs[group_id]);
        std::vector<float> distance_table(this->M * exact_ksubs[group_id]);
        this->PQs[group_id]->compute_distance_table(query, distance_table.data());
        multi_sequence_sort(group_id, distance_table.data(), keep_space, result_dists, result_labels);

    }