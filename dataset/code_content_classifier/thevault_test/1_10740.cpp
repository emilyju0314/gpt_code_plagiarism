void Plumbing::ConvertToInt() {
  for (auto &i : stack_) {
    i->ConvertToInt();
  }
}