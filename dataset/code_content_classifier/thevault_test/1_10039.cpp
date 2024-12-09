static bool ValidateSubPackets(const char* flagname, int32_t value) {
  if (value >= 1 && value <= 3)
    return true;
  printf("Invalid number of sub packets, should be between 1 and 3.");
  return false;
}