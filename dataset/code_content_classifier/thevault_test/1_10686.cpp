bool LSTM::Serialize(TFile *fp) const {
  if (!Network::Serialize(fp)) {
    return false;
  }
  if (!fp->Serialize(&na_)) {
    return false;
  }
  for (int w = 0; w < WT_COUNT; ++w) {
    if (w == GFS && !Is2D()) {
      continue;
    }
    if (!gate_weights_[w].Serialize(IsTraining(), fp)) {
      return false;
    }
  }
  if (softmax_ != nullptr && !softmax_->Serialize(fp)) {
    return false;
  }
  return true;
}