void Plumbing::CacheXScaleFactor(int factor) {
  for (auto &i : stack_) {
    i->CacheXScaleFactor(factor);
  }
}