int Plumbing::InitWeights(float range, TRand *randomizer) {
  num_weights_ = 0;
  for (auto &i : stack_) {
    num_weights_ += i->InitWeights(range, randomizer);
  }
  return num_weights_;
}