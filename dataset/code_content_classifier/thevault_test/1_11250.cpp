hash_bucket_container(
    size_t num_buckets,
    comparator_type comparator = std::less<value_type>()
    ) {
    sarray_sink.reset(new sink_type());
    sarray_sink->open_for_write(num_buckets);
    for (size_t i = 0; i < num_buckets; ++i) {
      buckets.push_back(new hash_bucket<value_type>(buffer_size, sarray_sink, i, comparator));
    }
  }