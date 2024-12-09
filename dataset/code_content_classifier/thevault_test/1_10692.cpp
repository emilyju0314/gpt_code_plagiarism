void LSTM::ResizeForward(const NetworkIO &input) {
  int rounded_inputs = gate_weights_[CI].RoundInputs(na_);
  source_.Resize(input, rounded_inputs);
  which_fg_.ResizeNoInit(input.Width(), ns_);
  if (IsTraining()) {
    state_.ResizeFloat(input, ns_);
    for (int w = 0; w < WT_COUNT; ++w) {
      if (w == GFS && !Is2D()) {
        continue;
      }
      node_values_[w].ResizeFloat(input, ns_);
    }
  }
}