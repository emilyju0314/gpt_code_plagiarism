void Series::Forward(bool debug, const NetworkIO &input, const TransposedArray *input_transpose,
                     NetworkScratch *scratch, NetworkIO *output) {
  int stack_size = stack_.size();
  ASSERT_HOST(stack_size > 1);
  // Revolving intermediate buffers.
  NetworkScratch::IO buffer1(input, scratch);
  NetworkScratch::IO buffer2(input, scratch);
  // Run each network in turn, giving the output of n as the input to n + 1,
  // with the final network providing the real output.
  stack_[0]->Forward(debug, input, input_transpose, scratch, buffer1);
  for (int i = 1; i < stack_size; i += 2) {
    stack_[i]->Forward(debug, *buffer1, nullptr, scratch, i + 1 < stack_size ? buffer2 : output);
    if (i + 1 == stack_size) {
      return;
    }
    stack_[i + 1]->Forward(debug, *buffer2, nullptr, scratch,
                           i + 2 < stack_size ? buffer1 : output);
  }
}