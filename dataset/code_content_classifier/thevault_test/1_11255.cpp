void write_msg(const char* buffer, size_t bufferLen) {
  // Write the message length as a signed int
  // guard against integer wrap around for large arrays
  assert(bufferLen <= std::numeric_limits<uint32_t>::max()); 
  uint32_t msgLen = bufferLen;
  std::cout.write(reinterpret_cast<char*>(&msgLen), sizeof(uint32_t));
  // Write the message bytes
  std::cout.write(buffer, msgLen);
  if (!std::cout.good()) {
    log_and_throw("Fail writing to standard output");
  }
}