xla::Shape NodeOutputShape(const Value& input, const Value& weight,
                           absl::Span<const xla::int64> stride,
                           absl::Span<const xla::int64> padding,
                           absl::Span<const xla::int64> dilation,
                           bool transposed,
                           absl::Span<const xla::int64> output_padding,
                           xla::int64 groups) {
  auto lower_for_shape_fn =
      [stride, padding, dilation, output_padding, transposed,
       groups](absl::Span<const xla::XlaOp> operands) -> xla::XlaOp {
    XLA_CHECK(operands.size() == 2 || operands.size() == 3);
    return BuildConvolutionOverrideable(operands[0], operands[1], stride,
                                        padding, dilation, transposed,
                                        output_padding, groups);
  };
  return InferOutputShape({input.shape(), weight.shape()}, lower_for_shape_fn);
}