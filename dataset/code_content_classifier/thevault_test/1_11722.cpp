inline vec2f sample_next2f(sampler& smp) {
      switch (smp.rtype) {
        case trace_rng_type::uniform: {
          return {next_rand1f(smp.rng), next_rand1f(smp.rng)};
        } break;
        case trace_rng_type::stratified: {
          smp.d += 2;
          auto p = hash_uint64_32(
              (uint64_t)smp.pixel_hash | (uint64_t)smp.d << 32);
          auto s = hash_permute(smp.s, smp.ns, p);
          return {clamp((s % smp.ns2 + next_rand1f(smp.rng)) / smp.ns2, 0.0f,
                        1 - flt_eps),
                  clamp((s / smp.ns2 + next_rand1f(smp.rng)) / smp.ns2, 0.0f,
                        1 - flt_eps)};
        } break;
        default: {
          assert(false);
          return {0, 0};
        }
      }
    }