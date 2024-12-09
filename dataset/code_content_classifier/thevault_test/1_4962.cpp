std::string processEnumPrefix(std::string_view typeName) {
  // Flag Bits
  std::size_t flagBitsSize = strlen("FlagBits");
  if (typeName.size() > flagBitsSize) {
    if (strncmp(typeName.data() + typeName.size() - flagBitsSize, "FlagBits", flagBitsSize) == 0) {
      typeName = typeName.substr(0, typeName.size() - strlen("FlagBits"));
    }
  }
  // Flags
  std::size_t flagsSize = strlen("Flags");
  if (typeName.size() > flagsSize) {
    if (strncmp(typeName.data() + typeName.size() - flagsSize, "Flags", flagsSize) == 0) {
      typeName = typeName.substr(0, typeName.size() - strlen("Flags"));
    }
  }

  std::string retStr;
  for (auto it = typeName.begin(); it != typeName.end(); ++it) {
    if (it == typeName.begin()) {
      retStr += ::toupper(*it);
    } else if (::isupper(*it)) {
      retStr += '_';
      retStr += *it;
    } else {
      retStr += toupper(*it);
    }
  }
  retStr += '_';

  return retStr;
}