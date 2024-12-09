int LSTM::InitWeights(float range, TRand *randomizer) {
  Network::SetRandomizer(randomizer);
  num_weights_ = 0;
  for (int w = 0; w < WT_COUNT; ++w) {
    if (w == GFS && !Is2D()) {
      continue;
    }
    num_weights_ +=
        gate_weights_[w].InitWeightsFloat(ns_, na_ + 1, TestFlag(NF_ADAM), range, randomizer);
  }
  if (softmax_ != nullptr) {
    num_weights_ += softmax_->InitWeights(range, randomizer);
  }
  return num_weights_;
}