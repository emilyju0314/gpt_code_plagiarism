void fmtSaveLine(char *output, const char *placeholder, void (*converter)(float, char[10]), float value) {
  char temp[10];
  (*converter)(value, temp);
  sprintf_P(output, placeholder, temp);
}