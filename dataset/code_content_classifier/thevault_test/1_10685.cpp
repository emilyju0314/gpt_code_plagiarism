void LSTM::ConvertToInt() {
  for (int w = 0; w < WT_COUNT; ++w) {
    if (w == GFS && !Is2D()) {
      continue;
    }
    gate_weights_[w].ConvertToInt();
  }
  if (softmax_ != nullptr) {
    softmax_->ConvertToInt();
  }
}