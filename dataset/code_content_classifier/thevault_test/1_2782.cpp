std::vector<std::pair<std::string, std::string>> ReadPatchMatchConfig(
    const std::string& config_path) {
  std::ifstream file(config_path);
  CHECK(file.is_open()) << config_path;

  std::string line;
  std::string ref_image_name;
  std::vector<std::pair<std::string, std::string>> images;
  while (std::getline(file, line)) {
    StringTrim(&line);

    if (line.empty() || line[0] == '#') {
      continue;
    }

    if (ref_image_name.empty()) {
      ref_image_name = line;
    } else {
      images.emplace_back(ref_image_name, line);
      ref_image_name.clear();
    }
  }

  return images;
}