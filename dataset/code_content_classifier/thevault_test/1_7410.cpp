xla::PaddingConfig MakeXlaPaddingConfig(
    absl::Span<const xla::int64> padding, const xla::Shape& input_shape,
    absl::Span<const xla::int64> kernel_size,
    absl::Span<const xla::int64> stride, bool ceil_mode) {
  xla::PaddingConfig padding_config;
  for (int i = 0; i < 2; ++i) {
    padding_config.add_dimensions();
  }
  const auto ceil_mode_padding =
      CeilModePadding(padding, input_shape, kernel_size, stride, ceil_mode);
  for (int i = 0; i < padding.size(); ++i) {
    xla::PaddingConfig::PaddingConfigDimension* dims =
        padding_config.add_dimensions();
    const auto dim_padding = ceil_mode_padding[i];
    dims->set_edge_padding_low(dim_padding.first);
    dims->set_edge_padding_high(dim_padding.second);
  }
  return padding_config;
}