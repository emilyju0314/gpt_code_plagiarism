int Series::InitWeights(float range, TRand *randomizer) {
  num_weights_ = 0;
  tprintf("Num outputs,weights in Series:\n");
  for (auto &i : stack_) {
    int weights = i->InitWeights(range, randomizer);
    tprintf("  %s:%d, %d\n", i->spec().c_str(), i->NumOutputs(), weights);
    num_weights_ += weights;
  }
  tprintf("Total weights = %d\n", num_weights_);
  return num_weights_;
}