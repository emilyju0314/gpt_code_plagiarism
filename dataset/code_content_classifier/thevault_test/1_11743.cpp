void trace_async_start(const scene* scn, image4f& img, vector<rng_pcg32>& rngs,
                         const trace_params& params, thread_pool* pool,
                         const function<void(int)>& callback) {
    auto blocks = trace_blocks(params);
    for (auto sample = 0; sample < params.nsamples; sample++) {
      for (auto& block : blocks) {
        auto is_last = (block == blocks.back());
        run_async(pool, [&img, scn, sample, block, &params, callback, &rngs,
            is_last]() {
          trace_block(scn, img, block.first, block.second, sample,
                      sample + 1, rngs, params);
          if (is_last) callback(sample);
        });
      }
    }
  }