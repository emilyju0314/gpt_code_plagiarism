int FullyConnected::RemapOutputs(int old_no, const std::vector<int> &code_map) {
  if (type_ == NT_SOFTMAX && no_ == old_no) {
    num_weights_ = weights_.RemapOutputs(code_map);
    no_ = code_map.size();
  }
  return num_weights_;
}