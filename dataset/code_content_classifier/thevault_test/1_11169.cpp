static std::string BoxFileName(const char *image_filename) {
  std::string box_filename = image_filename;
  size_t length = box_filename.length();
  std::string last = (length > 8) ? box_filename.substr(length - 8) : "";
  if (last == ".bin.png" || last == ".nrm.png") {
    box_filename.resize(length - 8);
  } else {
    size_t lastdot = box_filename.find_last_of('.');
    if (lastdot < length) {
      box_filename.resize(lastdot);
    }
  }
  box_filename += ".box";
  return box_filename;
}