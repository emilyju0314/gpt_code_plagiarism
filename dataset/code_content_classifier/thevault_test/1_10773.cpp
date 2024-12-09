char *ScrollView::AddEscapeChars(const char *input) {
  const char *nextptr = strchr(input, '\'');
  const char *lastptr = input;
  char *message = new char[kMaxMsgSize];
  int pos = 0;
  while (nextptr != nullptr) {
    strncpy(message + pos, lastptr, nextptr - lastptr);
    pos += nextptr - lastptr;
    message[pos] = '\\';
    pos += 1;
    lastptr = nextptr;
    nextptr = strchr(nextptr + 1, '\'');
  }
  strcpy(message + pos, lastptr);
  return message;
}