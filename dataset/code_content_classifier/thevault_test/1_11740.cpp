void trace_block_filtered(const scene* scn, image4f& img, image4f& acc,
                            image4f& weight, const vec2i& block_min, const vec2i& block_max,
                            int samples_min, int samples_max, vector<rng_pcg32>& rngs,
                            std::mutex& image_mutex, const trace_params& params) {
    _impl_trace::trace_block_filtered(scn, img, acc, weight, block_min,
                                      block_max, samples_min, samples_max, rngs, image_mutex, params);
  }