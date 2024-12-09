std::vector<xla::int64> AdaptiveAvgPoolKernelSize(
    absl::Span<const xla::int64> input_size,
    absl::Span<const xla::int64> output_size) {
  // Create a NCHW kernel size with 1 for batch size and feature.
  std::vector<xla::int64> kernel_size(2, 1);
  xla::int64 spatial_dim_off = input_size.size() - 2;
  for (int spatial_dim = 0; spatial_dim < 2; ++spatial_dim) {
    XLA_CHECK_EQ(
        input_size[spatial_dim_off + spatial_dim] % output_size[spatial_dim], 0)
        << "Target output size " << output_size[spatial_dim]
        << " doesn't divide the input size "
        << input_size[spatial_dim_off + spatial_dim];
    kernel_size.push_back(input_size[spatial_dim_off + spatial_dim] /
                          output_size[spatial_dim]);
  }
  return kernel_size;
}