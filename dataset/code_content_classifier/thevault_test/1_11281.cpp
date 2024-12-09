vector_dht(distributed_control &dc,
             const options_map& opt_map = options_map(_DHT::_dht_default_options_old))
      : Base(dc, opt_map)
      , _default_element_value(_DHT::get_option_old<NumericValueType>(opt_map, "default_value", 0))
      , _default_vector_size(_DHT::get_option_old<size_t>(opt_map, "vector_size", 0))
      , _total_table_sizes(0)
  {
  }