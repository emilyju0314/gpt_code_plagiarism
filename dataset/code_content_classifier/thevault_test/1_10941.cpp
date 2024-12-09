int Series::XScaleFactor() const {
  int factor = 1;
  for (auto i : stack_) {
    factor *= i->XScaleFactor();
  }
  return factor;
}