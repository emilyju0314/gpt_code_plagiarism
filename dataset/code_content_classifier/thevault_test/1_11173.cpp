void MakeBoxFileStr(const char *unichar_str, const TBOX &box, int page_num, std::string &box_str) {
  box_str = unichar_str;
  box_str += " " + std::to_string(box.left());
  box_str += " " + std::to_string(box.bottom());
  box_str += " " + std::to_string(box.right());
  box_str += " " + std::to_string(box.top());
  box_str += " " + std::to_string(page_num);
}