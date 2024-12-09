xla::Shape NodeOutputShape(const Value& input,
                           absl::Span<const xla::int64> filter_sizes,
                           const Value& out_backprop, bool depthwise,
                           absl::Span<const xla::int64> strides,
                           tensorflow::Padding padding,
                           absl::Span<const xla::int64> explicit_paddings,
                           tensorflow::TensorFormat data_format,
                           absl::Span<const xla::int64> dilations) {
  auto lower_for_shape_fn =
      [&](absl::Span<const xla::XlaOp> operands) -> xla::XlaOp {
    CHECK_EQ(operands.size(), 2)
        << "Unexpected number of operands: " << operands.size();
    return BuildTfConvBackpropFilter(/*input=*/operands[0],
                                     /*filter_sizes=*/filter_sizes,
                                     /*out_backprop=*/operands[1],
                                     /*depthwise=*/depthwise,
                                     /*strides=*/strides, /*padding=*/padding,
                                     /*explicit_paddings=*/explicit_paddings,
                                     /*data_format=*/data_format,
                                     /*dilations=*/dilations);
  };
  return InferOutputShape({input.shape(), out_backprop.shape()},
                          lower_for_shape_fn);
}