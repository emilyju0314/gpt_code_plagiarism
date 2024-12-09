cache_block::cache_block(cache_id_type cache_id, size_t max_capacity, 
                           fixed_size_cache_manager* owning_cache_manager) :
    cache_id(cache_id),
    owning_cache_manager(owning_cache_manager) { 
      initialize_memory(max_capacity);
    }