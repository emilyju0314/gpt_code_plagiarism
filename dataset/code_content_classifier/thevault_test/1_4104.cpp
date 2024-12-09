bool HugeInteger::less(HugeInteger &hugeInt2) {
  if (isZero() && hugeInt2.isZero())
    return false;

  if (isZero())
    return true;

  if (hugeInt2.isZero())
    return false;

  if (size < hugeInt2.size)
    return true;
  if (size > hugeInt2.size)
    return false;

  return arrayLess(hugeInt2, size - 1);
}