std::unique_ptr<std::map<uint64_t, uint64_t>> SetAssociativeCache::getActiveLifetimes()
    const {
  auto active_lifetimes = std::make_unique<std::map<uint64_t, uint64_t>>();
  for (auto const& set : cache_sets)
    for (auto const& line : set)
      if (line.valid) (*active_lifetimes)[clock_->current_cycle() - line.loaded_at]++;

  return active_lifetimes;
}