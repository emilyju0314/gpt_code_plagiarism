void FullyConnected::SetupForward(const NetworkIO &input, const TransposedArray *input_transpose) {
  // Softmax output is always float, so save the input type.
  int_mode_ = input.int_mode();
  if (IsTraining()) {
    acts_.Resize(input, no_);
    // Source_ is a transposed copy of input. It isn't needed if provided.
    external_source_ = input_transpose;
    if (external_source_ == nullptr) {
      source_t_.ResizeNoInit(ni_, input.Width());
    }
  }
}