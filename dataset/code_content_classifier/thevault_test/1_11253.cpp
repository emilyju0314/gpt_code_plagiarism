bool read_msg(std::string& buffer) {
  const int msgLen = read_int();
  //std::cerr << "Reading message of length: " << msgLen << std::endl;
  if (msgLen >= 0) {
    // Resize the buffer and fill it with data  
    buffer.resize(msgLen);
    std::cin.read(&buffer[0], msgLen);
    if (!std::cin.good()) {
      log_and_throw("Fail reading from standard input");
    }
    return true;
  }
  return false;
}