void LSTM::CountAlternators(const Network &other, TFloat *same, TFloat *changed) const {
  ASSERT_HOST(other.type() == type_);
  const LSTM *lstm = static_cast<const LSTM *>(&other);
  for (int w = 0; w < WT_COUNT; ++w) {
    if (w == GFS && !Is2D()) {
      continue;
    }
    gate_weights_[w].CountAlternators(lstm->gate_weights_[w], same, changed);
  }
  if (softmax_ != nullptr) {
    softmax_->CountAlternators(*lstm->softmax_, same, changed);
  }
}