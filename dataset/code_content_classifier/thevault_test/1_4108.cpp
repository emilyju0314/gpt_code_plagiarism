void HugeInteger::division(HugeInteger &divisor, HugeInteger &quotient,
                           HugeInteger &remainder) {
  if (isZero()) {
    quotient.reset();
    remainder.reset();
    return;
  }

  if (less(divisor)) {
    quotient.reset();
    remainder.size = size;
    delete[] remainder.elems;
    remainder.elems = new int[remainder.size];
    for (unsigned int i = 0; i < size; i++) {
      remainder.elems[i] = elems[i];
    }
    return;
  }

  int n = size - divisor.size;
  HugeInteger buffer;
  buffer.size = size;
  buffer.elems = new int[buffer.size];
  for (int i = 0; i < size; i++) {
    buffer.elems[i] = (i < n) ? 0 : divisor.elems[i - n];
  }
  quotient.size = n;
  if (less(buffer)) {
    buffer.divideByTen();
  } else {
    quotient.size++;
  }
  delete[] quotient.elems;
  quotient.elems = new int[quotient.size]();
  // std::fill_n(quotient.elems, quotient.size, 0);
  remainder.size = size;
  delete[] remainder.elems;
  remainder.elems = new int[remainder.size];
  for (unsigned int i = 0; i < size; i++) {
    remainder.elems[i] = elems[i];
  }

  for (int k = quotient.size - 1; k >= 0; k--) {
    while (buffer.equal(remainder) || buffer.less(remainder)) {
      remainder.subtraction(buffer);
      quotient.elems[k]++;
      if (remainder.isZero()) {
        delete[] buffer.elems;
        return;
      }
    }
    buffer.divideByTen();
    remainder.shrink_to_fit();
  }
  delete[] buffer.elems;
}