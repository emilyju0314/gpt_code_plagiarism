static void legalizeFileName(char *fileName) {
  // tprintf("fileName: %s\n", fileName);
  const char *invalidChars = "/\?:*\"><| "; // space is valid but can cause headaches
  // for each invalid char
  for (unsigned i = 0; i < strlen(invalidChars); i++) {
    char invalidStr[4];
    invalidStr[0] = invalidChars[i];
    invalidStr[1] = '\0';
    // tprintf("eliminating %s\n", invalidStr);
    // char *pos = strstr(fileName, invalidStr);
    // initial ./ is valid for present directory
    // if (*pos == '.') pos++;
    // if (*pos == '/') pos++;
    for (char *pos = strstr(fileName, invalidStr); pos != nullptr;
         pos = strstr(pos + 1, invalidStr)) {
      // tprintf("\tfound: %s, ", pos);
      pos[0] = '_';
      // tprintf("fileName: %s\n", fileName);
    }
  }
}