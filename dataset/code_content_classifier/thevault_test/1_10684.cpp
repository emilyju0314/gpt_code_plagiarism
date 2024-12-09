int LSTM::RemapOutputs(int old_no, const std::vector<int> &code_map) {
  if (softmax_ != nullptr) {
    num_weights_ -= softmax_->num_weights();
    num_weights_ += softmax_->RemapOutputs(old_no, code_map);
  }
  return num_weights_;
}