void LSTM::SetEnableTraining(TrainingState state) {
  if (state == TS_RE_ENABLE) {
    // Enable only from temp disabled.
    if (training_ == TS_TEMP_DISABLE) {
      training_ = TS_ENABLED;
    }
  } else if (state == TS_TEMP_DISABLE) {
    // Temp disable only from enabled.
    if (training_ == TS_ENABLED) {
      training_ = state;
    }
  } else {
    if (state == TS_ENABLED && training_ != TS_ENABLED) {
      for (int w = 0; w < WT_COUNT; ++w) {
        if (w == GFS && !Is2D()) {
          continue;
        }
        gate_weights_[w].InitBackward();
      }
    }
    training_ = state;
  }
  if (softmax_ != nullptr) {
    softmax_->SetEnableTraining(state);
  }
}