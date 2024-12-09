bool Util::SystemToUTF8(const char* system, std::string* utf8) {
  utf8->clear();
  utf8->append(system);
  return true;
}