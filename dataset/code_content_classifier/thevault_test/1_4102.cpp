bool HugeInteger::isZero() {
  if (size == 1 && elems[0] == 0)
    return true;
  return false;
}