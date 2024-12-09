bool ReadAllBoxes(int target_page, bool skip_blanks, const char *filename, std::vector<TBOX> *boxes,
                  std::vector<std::string> *texts, std::vector<std::string> *box_texts,
                  std::vector<int> *pages) {
  std::ifstream input(BoxFileName(filename).c_str(), std::ios::in | std::ios::binary);
  std::vector<char> box_data(std::istreambuf_iterator<char>(input), {});
  if (box_data.empty()) {
    return false;
  }
  // Convert the array of bytes to a string, so it can be used by the parser.
  box_data.push_back('\0');
  return ReadMemBoxes(target_page, skip_blanks, &box_data[0],
                      /*continue_on_failure*/ true, boxes, texts, box_texts, pages);
}