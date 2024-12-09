void HugeInteger::subtraction(HugeInteger &subtrahend) {
  if (equal(subtrahend)) {
    reset();
    return;
  }
  int Cal = 0;
  int Car = 0;
  int fsubstrahend = 0;
  for (int i = 0; i < size; i++) {
    fsubstrahend = (i >= subtrahend.size) ? 0 : subtrahend.elems[i];
    Cal = elems[i] - fsubstrahend + Car;
    Car = (Cal < 0) ? -1 : 0;
    elems[i] = (Cal < 0) ? Cal + 10 : Cal;
  }
  for (int i = size - 1; i >= 0; i--) {
    if (elems[i] == 0) {
      size--;
    }
    if (elems[i] != 0) {
      break;
    }
  }
  shrink_to_fit();
}