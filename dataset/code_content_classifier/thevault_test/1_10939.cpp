int Series::RemapOutputs(int old_no, const std::vector<int> &code_map) {
  num_weights_ = 0;
  tprintf("Num (Extended) outputs,weights in Series:\n");
  for (auto &i : stack_) {
    int weights = i->RemapOutputs(old_no, code_map);
    tprintf("  %s:%d, %d\n", i->spec().c_str(), i->NumOutputs(), weights);
    num_weights_ += weights;
  }
  tprintf("Total weights = %d\n", num_weights_);
  no_ = stack_.back()->NumOutputs();
  return num_weights_;
}