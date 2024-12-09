static bool ValidateApplication(const char* flagname, int32_t value) {
  if (value != 0 && value != 1) {
    printf("Invalid application mode, should be 0 or 1.");
    return false;
  }
  return true;
}