std::string read_string_msg(const char * & iter) {
  const int strlen = read_int(iter);
  // std::cerr << "reading string of length: " << strlen << std::endl;
  std::string text(iter, strlen);
  // std::cerr << "string: " << text << std::endl;
  iter += strlen;
  return text;
}