xla::Shape NodeOutputShape(const Value& input, xla::int64 spatial_dim_count,
                           absl::Span<const xla::int64> kernel_size,
                           absl::Span<const xla::int64> stride,
                           absl::Span<const xla::int64> padding, bool ceil_mode,
                           bool count_include_pad) {
  auto lower_for_shape_fn =
      [&](absl::Span<const xla::XlaOp> operands) -> xla::XlaOp {
    XLA_CHECK_EQ(operands.size(), 1)
        << "Unexpected number of operands: " << operands.size();
    return BuildAvgPoolNd(operands[0], spatial_dim_count, kernel_size, stride,
                          padding, ceil_mode, count_include_pad);
  };
  return InferOutputShape({input.shape()}, lower_for_shape_fn);
}