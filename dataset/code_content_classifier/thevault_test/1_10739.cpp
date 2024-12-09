int Plumbing::RemapOutputs(int old_no, const std::vector<int> &code_map) {
  num_weights_ = 0;
  for (auto &i : stack_) {
    num_weights_ += i->RemapOutputs(old_no, code_map);
  }
  return num_weights_;
}