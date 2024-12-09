static bool RandBool(const double prob, TRand *rand) {
  if (prob == 1.0) {
    return true;
  }
  if (prob == 0.0) {
    return false;
  }
  return rand->UnsignedRand(1.0) < prob;
}