void trace_samples(const scene* scn, image4f& img, int samples_min,
                     int samples_max, vector<rng_pcg32>& rngs, const trace_params& params) {
    auto blocks = trace_blocks(params);
    if (params.parallel) {
      parallel_for((int)blocks.size(), [&img, scn, samples_min, samples_max,
          &blocks, &params, &rngs](int idx) {
        trace_block(scn, img, blocks[idx].first, blocks[idx].second,
                    samples_min, samples_max, rngs, params);
      });
    } else {
      for (auto idx = 0; idx < (int)blocks.size(); idx++) {
        trace_block(scn, img, blocks[idx].first, blocks[idx].second,
                    samples_min, samples_max, rngs, params);
      }
    }
  }