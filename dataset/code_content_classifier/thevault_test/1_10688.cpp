void LSTM::Update(float learning_rate, float momentum, float adam_beta, int num_samples) {
#if DEBUG_DETAIL > 3
  PrintW();
#endif
  for (int w = 0; w < WT_COUNT; ++w) {
    if (w == GFS && !Is2D()) {
      continue;
    }
    gate_weights_[w].Update(learning_rate, momentum, adam_beta, num_samples);
  }
  if (softmax_ != nullptr) {
    softmax_->Update(learning_rate, momentum, adam_beta, num_samples);
  }
#if DEBUG_DETAIL > 3
  PrintDW();
#endif
}