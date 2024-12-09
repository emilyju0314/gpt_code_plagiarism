std::vector<std::pair<xla::int64, xla::int64>> CeilModePadding(
    absl::Span<const xla::int64> padding, const xla::Shape& input_shape,
    absl::Span<const xla::int64> kernel_size,
    absl::Span<const xla::int64> stride, bool ceil_mode) {
  std::vector<std::pair<xla::int64, xla::int64>> ceil_mode_padding;
  for (int i = 0; i < padding.size(); ++i) {
    xla::int64 left_padding = padding[i];
    xla::int64 input_size = input_shape.dimensions(2 + i);
    xla::int64 output_size_rem =
        (input_size + 2 * left_padding - kernel_size[i]) % stride[i];
    xla::int64 right_padding = left_padding;
    if (ceil_mode && output_size_rem != 0) {
      right_padding += stride[i] - output_size_rem;
    }
    ceil_mode_padding.emplace_back(left_padding, right_padding);
  }
  return ceil_mode_padding;
}