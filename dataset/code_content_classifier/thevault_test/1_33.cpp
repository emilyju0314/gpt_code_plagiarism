bool hasTerminalAtIdx(std::string terminals, int position) {
  if (position < 0 || position >= terminals.length()) {
    return false;
  }
  return terminals[position] == '1';
}