void* findFunc(const std::string& func, const std::string& soPath) {
#endif
  if (func.empty() || soPath.empty()) {
    throw std::invalid_argument("Function or .so path empty");
  }