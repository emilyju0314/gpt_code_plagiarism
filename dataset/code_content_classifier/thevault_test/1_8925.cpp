const char * firelog_lastMessage(int level) {
  int i;
  for (i = 0; i<FIRELOG_TRACE; i++) {
    if (lastMessage[i]) {
      return lastMessage[i];
    }
  }
  return "";
}