inline sampler make_sampler(
        rng_pcg32& rng, int i, int j, int s, int ns, trace_rng_type rtype) {
      // we use various hashes to scramble the pixel values
      return {rng, hash_uint32((uint32_t)(j + 1) << 16 | (uint32_t)(i + 1)), s, 0,
              ns, (int)round(sqrt((float)ns)), rtype};
    }