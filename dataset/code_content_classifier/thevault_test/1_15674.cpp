static bool ValidateInFilename(const char* flagname, const string& value) {
  FILE* fid = fopen(value.c_str(), "rb");
  if (fid != NULL) {
    fclose(fid);
    return true;
  }
  printf("Invalid input filename.");
  return false;
}