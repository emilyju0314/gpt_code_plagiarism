inline void hilbert_blocked_parallel_for(size_t n,
                                  std::function<void(std::vector<std::pair<size_t, size_t> >) > preamble, 
                                  std::function<void(std::pair<size_t, size_t>)> fn,
                                  size_t parallel_limit = SGRAPH_HILBERT_CURVE_PARALLEL_FOR_NUM_THREADS) {
  for (size_t i = 0;i < n*n; i += parallel_limit) {
    std::vector<std::pair<size_t, size_t> >  coordinates;
    // accumulate the list of coordinates to run
    size_t lastcoord_this_pass = std::min(i + parallel_limit, n*n);
    for(size_t j = i; j < lastcoord_this_pass; ++j) {
      coordinates.push_back(hilbert_index_to_coordinate(j, n));
    }
    preamble(coordinates);
    parallel_for(coordinates.begin(), coordinates.end(), fn);
  }
}