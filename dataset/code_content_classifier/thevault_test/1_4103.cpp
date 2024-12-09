bool HugeInteger::equal(HugeInteger &hugeInt2) {
  if (isZero() && hugeInt2.isZero())
    return true;

  if (size != hugeInt2.size)
    return false;

  return arrayEqual(hugeInt2, size - 1);
}