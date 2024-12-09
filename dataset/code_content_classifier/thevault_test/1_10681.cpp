StaticShape LSTM::OutputShape(const StaticShape &input_shape) const {
  StaticShape result = input_shape;
  result.set_depth(no_);
  if (type_ == NT_LSTM_SUMMARY) {
    result.set_width(1);
  }
  if (softmax_ != nullptr) {
    return softmax_->OutputShape(result);
  }
  return result;
}