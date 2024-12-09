bool Mailbox::ReadValueString(const std::string& in_file, std::string *value_str) {
  std::ifstream file;
  file.open(in_file.c_str(), std::ios::in);
  if (file.is_open()) {
    std::getline(file, *value_str);
    file.close();
    return true;
  }
  *value_str = "ERROR";
  LOG(LS_ERROR) << "ReadValueString: Failed to open: " << in_file;
  return false;
}