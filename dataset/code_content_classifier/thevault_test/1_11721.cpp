inline float sample_next1f(sampler& smp) {
      switch (smp.rtype) {
        case trace_rng_type::uniform: {
          return clamp(next_rand1f(smp.rng), 0.0f, 1 - flt_eps);
        } break;
        case trace_rng_type::stratified: {
          smp.d += 1;
          auto p = hash_uint64_32(
              (uint64_t)smp.pixel_hash | (uint64_t)smp.d << 32);
          auto s = hash_permute(smp.s, smp.ns, p);
          return clamp(
              (s + next_rand1f(smp.rng)) / smp.ns, 0.0f, 1 - flt_eps);
        } break;
        default: {
          assert(false);
          return 0;
        }
      }
    }