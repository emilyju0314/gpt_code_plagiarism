StaticShape Series::OutputShape(const StaticShape &input_shape) const {
  StaticShape result(input_shape);
  int stack_size = stack_.size();
  for (int i = 0; i < stack_size; ++i) {
    result = stack_[i]->OutputShape(result);
  }
  return result;
}