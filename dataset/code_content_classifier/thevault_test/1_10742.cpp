void Plumbing::AddToStack(Network *network) {
  if (stack_.empty()) {
    ni_ = network->NumInputs();
    no_ = network->NumOutputs();
  } else if (type_ == NT_SERIES) {
    // ni is input of first, no output of last, others match output to input.
    ASSERT_HOST(no_ == network->NumInputs());
    no_ = network->NumOutputs();
  } else {
    // All parallel types. Output is sum of outputs, inputs all match.
    ASSERT_HOST(ni_ == network->NumInputs());
    no_ += network->NumOutputs();
  }
  stack_.push_back(network);
}