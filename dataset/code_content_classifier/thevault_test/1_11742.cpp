void trace_filtered_samples(const scene* scn, image4f& img, image4f& acc,
                              image4f& weight, int samples_min, int samples_max, vector<rng_pcg32>& rngs,
                              const trace_params& params) {
    auto blocks = trace_blocks(params);
    std::mutex image_mutex;
    if (params.parallel) {
      parallel_for((int)blocks.size(),
                   [&img, &acc, &weight, scn, samples_min, samples_max, &blocks,
                       &params, &image_mutex, &rngs](int idx) {
                     trace_block_filtered(scn, img, acc, weight, blocks[idx].first,
                                          blocks[idx].second, samples_min, samples_max, rngs,
                                          image_mutex, params);
                   });
    } else {
      for (auto idx = 0; idx < (int)blocks.size(); idx++) {
        trace_block_filtered(scn, img, acc, weight, blocks[idx].first,
                             blocks[idx].second, samples_min, samples_max, rngs, image_mutex,
                             params);
      }
    }
  }