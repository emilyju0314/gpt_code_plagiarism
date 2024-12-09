bool LSTM::DeSerialize(TFile *fp) {
  if (!fp->DeSerialize(&na_)) {
    return false;
  }
  if (type_ == NT_LSTM_SOFTMAX) {
    nf_ = no_;
  } else if (type_ == NT_LSTM_SOFTMAX_ENCODED) {
    nf_ = ceil_log2(no_);
  } else {
    nf_ = 0;
  }
  is_2d_ = false;
  for (int w = 0; w < WT_COUNT; ++w) {
    if (w == GFS && !Is2D()) {
      continue;
    }
    if (!gate_weights_[w].DeSerialize(IsTraining(), fp)) {
      return false;
    }
    if (w == CI) {
      ns_ = gate_weights_[CI].NumOutputs();
      is_2d_ = na_ - nf_ == ni_ + 2 * ns_;
    }
  }
  delete softmax_;
  if (type_ == NT_LSTM_SOFTMAX || type_ == NT_LSTM_SOFTMAX_ENCODED) {
    softmax_ = static_cast<FullyConnected *>(Network::CreateFromFile(fp));
    if (softmax_ == nullptr) {
      return false;
    }
  } else {
    softmax_ = nullptr;
  }
  return true;
}