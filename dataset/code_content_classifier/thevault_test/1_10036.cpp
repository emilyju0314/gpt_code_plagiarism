static bool ValidateBitRate(const char* flagname, int32_t value) {
  if (value >= 6 && value <= 510)
    return true;
  printf("Invalid bit rate, should be between 6 and 510 kbps.");
  return false;
}