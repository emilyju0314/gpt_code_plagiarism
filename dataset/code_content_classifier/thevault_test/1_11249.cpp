explicit inline countsketch(size_t bits = 16, size_t depth = 5, size_t seed = 1000):
    num_hash(depth), num_bits(bits), num_bins(1 << num_bits) {
      ASSERT_GE(num_bins, 16);

      random::generator gen;
      gen.seed(seed);
      // Initialize hash functions and count matrix
      for (size_t j = 0; j < num_hash; ++j) {
        seeds.push_back(gen.fast_uniform<size_t>(0, std::numeric_limits<size_t>::max()));
        seeds_binary.push_back(gen.fast_uniform<size_t>(0, std::numeric_limits<size_t>::max()));

        counts.push_back(std::vector<counter_int>(num_bins));
      }
   }