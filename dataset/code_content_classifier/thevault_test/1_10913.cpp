void RecodeBeamSearch::ComputeTopN(const float *outputs, int num_outputs,
                                   int top_n) {
  top_n_flags_.clear();
  top_n_flags_.resize(num_outputs, TN_ALSO_RAN);
  top_code_ = -1;
  second_code_ = -1;
  top_heap_.clear();
  for (int i = 0; i < num_outputs; ++i) {
    if (top_heap_.size() < top_n || outputs[i] > top_heap_.PeekTop().key()) {
      TopPair entry(outputs[i], i);
      top_heap_.Push(&entry);
      if (top_heap_.size() > top_n) {
        top_heap_.Pop(&entry);
      }
    }
  }
  while (!top_heap_.empty()) {
    TopPair entry;
    top_heap_.Pop(&entry);
    if (top_heap_.size() > 1) {
      top_n_flags_[entry.data()] = TN_TOPN;
    } else {
      top_n_flags_[entry.data()] = TN_TOP2;
      if (top_heap_.empty()) {
        top_code_ = entry.data();
      } else {
        second_code_ = entry.data();
      }
    }
  }
  top_n_flags_[null_char_] = TN_TOP2;
}