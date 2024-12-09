StaticShape Parallel::OutputShape(const StaticShape &input_shape) const {
  StaticShape result = stack_[0]->OutputShape(input_shape);
  int stack_size = stack_.size();
  for (int i = 1; i < stack_size; ++i) {
    StaticShape shape = stack_[i]->OutputShape(input_shape);
    result.set_depth(result.depth() + shape.depth());
  }
  return result;
}