void LQ_quantizer::compute_alpha(const float * centroid_vectors, const float * points, const float * centroid,
                                      const float * centroid_vector_norms_L2sqr, size_t group_size, float * alpha_list){
        if (group_size <= 0){
            std::cout << "No enough data point (0 point) for computing alpha in this group " << std::endl;
            exit(-1);
        }
        
        float group_numerator = 0.0;   
        float group_denominator = 0.0; 
        std::vector<float> sum_group_alpha(max_nc_per_group, 0);
        std::vector<float> sum_group_vectors(max_nc_per_group, 0);

        std::vector<float> point_vectors(group_size * dimension); 
        for (size_t i = 0; i < group_size; i++) 
            faiss::fvec_madd(dimension, points + i * dimension, -1.0, centroid, point_vectors.data() + i * dimension); 
        
        for (size_t i = 0; i < group_size; i++){ 
            const float * point_vector = point_vectors.data() + i * dimension; 
            const float * point = points + i * dimension; 

            std::priority_queue<std::pair<float, std::pair<size_t, std::pair<float, float>>>> maxheap; 

            for (size_t subc = 0; subc < max_nc_per_group; subc++){
                const float * centroid_vector = centroid_vectors + subc * dimension; 
                float numerator = faiss::fvec_inner_product(centroid_vector, point_vector, dimension); 
                numerator = (numerator > 0) ? numerator : 0.0; 

                const float denominator = centroid_vector_norms_L2sqr[subc]; 
                const float alpha = numerator / denominator; 

                std::vector<float> subcentroid(dimension); 
                faiss::fvec_madd(dimension, centroid, alpha, centroid_vector, subcentroid.data()); 

                const float dist = faiss::fvec_L2sqr(point, subcentroid.data(), dimension); 
                maxheap.emplace(-dist, std::make_pair(subc, std::make_pair(numerator, denominator))); 
            }

            sum_group_alpha[maxheap.top().second.first] +=  (maxheap.top().second.second.second > 0) ? maxheap.top().second.second.first / maxheap.top().second.second.second : 0.0;
            sum_group_vectors[maxheap.top().second.first] ++;
            group_numerator += maxheap.top().second.second.first;
            group_denominator += maxheap.top().second.second.second;
        }
        if (LQ_type == 0){
            float LQ0_alpha = (group_denominator > 0) ? group_numerator / group_denominator : 0.0;
            for (size_t i = 0; i < max_nc_per_group; i++){
                alpha_list[i] = LQ0_alpha;
            }
        }
        else{
            float sum_alpha = 0;
            for (size_t i = 0; i < max_nc_per_group; i++){sum_alpha += sum_group_alpha[i];} float avg_alpha = sum_alpha / group_size;
            for (size_t i = 0; i < max_nc_per_group; i++){
                if (sum_group_vectors[i] > 0){alpha_list[i] = sum_group_alpha[i] / sum_group_vectors[i];}
                else{alpha_list[i] = avg_alpha;}
            }
        }
    }