static void LogWithPriority(int priority, uint8_t indent, const char* format, va_list args) {
  std::string real_format;
  if (indent > 0) {
    real_format = android::base::StringPrintf("%*s%s", 2 * indent, " ", format);
  } else {
    real_format = format;
  }
  LOG_PRI_VA(priority, LOG_TAG, real_format.c_str(), args);
}