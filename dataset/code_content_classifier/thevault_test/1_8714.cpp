void FarMemManager::pick_from_regions() {
  from_regions_.clear();
  auto ratio_per_gc_round =
      std::max(kMinRatioRegionsPerGCRound,
               std::min(kMaxRatioRegionsPerGCRound,
                        kFreeCacheHighThresh -
                            cache_region_manager_.get_free_region_ratio()));
  auto num_regions_per_gc_round =
      std::min(kMaxNumRegionsPerGCRound,
               static_cast<uint32_t>(ratio_per_gc_round *
                                     cache_region_manager_.get_num_regions()));
  do {
    auto optional_region = pop_cache_used_region();
    if (unlikely(!optional_region)) {
      break;
    }
    preempt_disable();
    from_regions_.push_back(std::move(*optional_region));
    preempt_enable();
  } while (from_regions_.size() < num_regions_per_gc_round);
}