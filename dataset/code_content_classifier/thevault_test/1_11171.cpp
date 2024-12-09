bool ReadMemBoxes(int target_page, bool skip_blanks, const char *box_data, bool continue_on_failure,
                  std::vector<TBOX> *boxes, std::vector<std::string> *texts,
                  std::vector<std::string> *box_texts, std::vector<int> *pages) {
  std::string box_str(box_data);
  std::vector<std::string> lines = split(box_str, '\n');
  if (lines.empty()) {
    return false;
  }
  int num_boxes = 0;
  for (auto &line : lines) {
    int page = 0;
    std::string utf8_str;
    TBOX box;
    if (!ParseBoxFileStr(line.c_str(), &page, utf8_str, &box)) {
      if (continue_on_failure) {
        continue;
      } else {
        return false;
      }
    }
    if (skip_blanks && (utf8_str == " " || utf8_str == "\t")) {
      continue;
    }
    if (target_page >= 0 && page != target_page) {
      continue;
    }
    if (boxes != nullptr) {
      boxes->push_back(box);
    }
    if (texts != nullptr) {
      texts->push_back(utf8_str);
    }
    if (box_texts != nullptr) {
      std::string full_text;
      MakeBoxFileStr(utf8_str.c_str(), box, target_page, full_text);
      box_texts->push_back(full_text);
    }
    if (pages != nullptr) {
      pages->push_back(page);
    }
    ++num_boxes;
  }
  return num_boxes > 0;
}