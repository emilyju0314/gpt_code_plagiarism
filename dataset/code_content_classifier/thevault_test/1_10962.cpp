StaticShape FullyConnected::OutputShape(const StaticShape &input_shape) const {
  LossType loss_type = LT_NONE;
  if (type_ == NT_SOFTMAX) {
    loss_type = LT_CTC;
  } else if (type_ == NT_SOFTMAX_NO_CTC) {
    loss_type = LT_SOFTMAX;
  } else if (type_ == NT_LOGISTIC) {
    loss_type = LT_LOGISTIC;
  }
  StaticShape result(input_shape);
  result.set_depth(no_);
  result.set_loss_type(loss_type);
  return result;
}