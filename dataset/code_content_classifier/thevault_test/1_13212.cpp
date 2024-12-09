Maybe<one::TensorTuple> CheckAndInitOutGrads(const one::TensorTuple& outputs,
                                             const one::TensorTuple& out_grads) {
  auto gradients = std::make_shared<one::TensorTuple>(out_grads.size());
  TODO();  // Wang Yinggang. Checks all out_grads and push default value for empty item
  return gradients;
}