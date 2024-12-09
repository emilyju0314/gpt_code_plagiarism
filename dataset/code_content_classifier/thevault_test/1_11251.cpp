int read_int() {
  int msgLen = 0;
  std::cin.read(reinterpret_cast<char*>(&msgLen), 4);
  /// @todo: test cost of verifying cin is good.
  // if (!std::cin.good()) {
  //   log_and_throw("Fail reading from standard input");
  // }
  return msgLen;
}