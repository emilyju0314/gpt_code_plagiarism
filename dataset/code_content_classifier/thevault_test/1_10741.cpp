void Plumbing::SetRandomizer(TRand *randomizer) {
  for (auto &i : stack_) {
    i->SetRandomizer(randomizer);
  }
}