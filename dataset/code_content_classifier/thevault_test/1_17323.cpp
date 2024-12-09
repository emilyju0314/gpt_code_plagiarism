weight_params_float_array(std::vector<size_t> shape, WeightParams* weights)
    : shape_(std::move(shape))
  {
    weights_.Swap(weights);

    size_t size_from_shape =
        std::accumulate(shape_.begin(), shape_.end(), 1u, multiply);
    ASSERT_MSG(weights_.floatvalue_size() == static_cast<int>(size_from_shape),
               "WeightParams size %d inconsistent with expected size %d",
               weights_.floatvalue_size(), static_cast<int>(size_from_shape));
  }