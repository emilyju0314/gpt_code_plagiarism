StaticShape Reconfig::OutputShape(const StaticShape &input_shape) const {
  StaticShape result = input_shape;
  result.set_height(result.height() / y_scale_);
  result.set_width(result.width() / x_scale_);
  if (type_ != NT_MAXPOOL) {
    result.set_depth(result.depth() * y_scale_ * x_scale_);
  }
  return result;
}