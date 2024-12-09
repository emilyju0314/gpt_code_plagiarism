int FullyConnected::InitWeights(float range, TRand *randomizer) {
  Network::SetRandomizer(randomizer);
  num_weights_ = weights_.InitWeightsFloat(no_, ni_ + 1, TestFlag(NF_ADAM), range, randomizer);
  return num_weights_;
}