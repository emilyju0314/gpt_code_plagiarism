static bool ValidateOutFilename(const char* flagname, const string& value) {
  FILE* fid = fopen(value.c_str(), "wb");
  if (fid != NULL) {
    fclose(fid);
    return true;
  }
  printf("Invalid output filename.");
  return false;
}