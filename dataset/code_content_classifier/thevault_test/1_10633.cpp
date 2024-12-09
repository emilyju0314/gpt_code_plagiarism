DIR128::DIR128(     // from fcoord
    const FCOORD fc // vector to quantize
) {
  int high, low, current; // binary search

  low = 0;
  if (fc.y() == 0) {
    if (fc.x() >= 0) {
      dir = 0;
    } else {
      dir = MODULUS / 2;
    }
    return;
  }
  high = MODULUS;
  do {
    current = (high + low) / 2;
    if (dirtab[current] * fc >= 0) {
      low = current;
    } else {
      high = current;
    }
  } while (high - low > 1);
  dir = low;
}