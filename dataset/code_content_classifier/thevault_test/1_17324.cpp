void extract_network_params(const std::string& name,
                            ConvolutionLayerParams* convolution,
                            float_array_map* params_out) {
  ASSERT_EQ(2, convolution->kernelsize_size());
  const size_t n = convolution->outputchannels();
  const size_t c = convolution->kernelchannels();
  const size_t h = convolution->kernelsize(0);
  const size_t w = convolution->kernelsize(1);

  shared_float_array weights = weight_params_float_array::create_shared(
      {n, c, h, w}, convolution->mutable_weights());
  params_out->emplace(name + "_weight", std::move(weights));

  if (convolution->has_bias()) {
    shared_float_array bias = weight_params_float_array::create_shared(
        {n}, convolution->mutable_bias());
    params_out->emplace(name + "_bias", std::move(bias));
  }
}