void AppendVersion(const char *version_string, std::string *result) {
  result->append("#")
      .append(kVersionTag)
      .append(" ")
      .append(version_string)
      .append("\n");
}