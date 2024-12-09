gl_sframe _generate_random_classification_sframe(size_t n_rows, std::string column_types,
                                                 size_t random_seed, size_t num_classes,
                                                 size_t num_extra_class_bins,
                                                 double misclassification_spread) {

  // Set up the bin mapping. 
  size_t n_bins = num_classes + num_extra_class_bins;
  std::vector<size_t> bin_to_class_map(n_bins);

  gl_sframe X = _generate_random_sframe(n_rows, column_types, random_seed, true,
                                        misclassification_spread / n_bins);
  
  random::seed(random_seed);
  
  for(size_t i = 0; i < num_classes; ++i) {
    bin_to_class_map[i] = i;
  }
  
  for(size_t i = num_classes; i < n_bins; ++i) {
    bin_to_class_map[i] = random::fast_uniform<size_t>(0, num_classes - 1);
  }

  random::shuffle(bin_to_class_map);
  
  std::function<flexible_type(const flexible_type&)> classify
      = [=](const flexible_type& x) {
    size_t b = std::min<flex_int>(n_bins - 1,
        std::max<flex_int>(0,
            flex_int(std::floor(x.get<flex_float>() * n_bins))));
    
    return bin_to_class_map[b];
  };
      
  X["target"] = X["target"].apply(classify, flex_type_enum::INTEGER, false); 

  return X;
}