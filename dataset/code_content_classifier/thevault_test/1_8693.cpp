static bool
loadRegionMap(StringMap &m, const String &filename)
{
  static const char *EXPECTED_FORMAT = "<s3-entry-point>:<s3-region>";

  String path(makeConfigPath(filename));

  std::ifstream ifstr;
  String line;

  ifstr.open(path.c_str());
  if (!ifstr) {
    TSError("[%s] failed to load s3-region map from '%s'", PLUGIN_NAME, path.c_str());
    return false;
  }

  TSDebug(PLUGIN_NAME, "loading region mapping from '%s'", path.c_str());

  m[""] = ""; /* set a default just in case if the user does not specify it */

  while (std::getline(ifstr, line)) {
    String::size_type pos;

    // Allow #-prefixed comments.
    pos = line.find_first_of('#');
    if (pos != String::npos) {
      line.resize(pos);
    }

    if (line.empty()) {
      continue;
    }

    std::size_t d = line.find(':');
    if (String::npos == d) {
      TSError("[%s] failed to parse region map string '%s', expected format: '%s'", PLUGIN_NAME, line.c_str(), EXPECTED_FORMAT);
      return false;
    }

    String entrypoint(trimWhiteSpaces(String(line, 0, d)));
    String region(trimWhiteSpaces(String(line, d + 1, String::npos)));

    if (region.empty()) {
      TSDebug(PLUGIN_NAME, "<s3-region> in '%s' cannot be empty (skipped), expected format: '%s'", line.c_str(), EXPECTED_FORMAT);
      continue;
    }

    if (entrypoint.empty()) {
      TSDebug(PLUGIN_NAME, "added default region %s", region.c_str());
    } else {
      TSDebug(PLUGIN_NAME, "added entry-point:%s, region:%s", entrypoint.c_str(), region.c_str());
    }

    m[entrypoint] = region;
  }

  if (m.at("").empty()) {
    TSDebug(PLUGIN_NAME, "default region was not defined");
  }

  ifstr.close();
  return true;
}