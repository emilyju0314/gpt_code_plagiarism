bool Series::Backward(bool debug, const NetworkIO &fwd_deltas, NetworkScratch *scratch,
                      NetworkIO *back_deltas) {
  if (!IsTraining()) {
    return false;
  }
  int stack_size = stack_.size();
  ASSERT_HOST(stack_size > 1);
  // Revolving intermediate buffers.
  NetworkScratch::IO buffer1(fwd_deltas, scratch);
  NetworkScratch::IO buffer2(fwd_deltas, scratch);
  // Run each network in reverse order, giving the back_deltas output of n as
  // the fwd_deltas input to n-1, with the 0 network providing the real output.
  if (!stack_.back()->IsTraining() ||
      !stack_.back()->Backward(debug, fwd_deltas, scratch, buffer1)) {
    return false;
  }
  for (int i = stack_size - 2; i >= 0; i -= 2) {
    if (!stack_[i]->IsTraining() ||
        !stack_[i]->Backward(debug, *buffer1, scratch, i > 0 ? buffer2 : back_deltas)) {
      return false;
    }
    if (i == 0) {
      return needs_to_backprop_;
    }
    if (!stack_[i - 1]->IsTraining() ||
        !stack_[i - 1]->Backward(debug, *buffer2, scratch, i > 1 ? buffer1 : back_deltas)) {
      return false;
    }
  }
  return needs_to_backprop_;
}