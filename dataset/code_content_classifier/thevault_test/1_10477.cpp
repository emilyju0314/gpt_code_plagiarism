SVMenuNode::SVMenuNode(int command_event, const char *txt, int tv, bool check_box_entry,
                       const char *val, const char *desc)
    : text_(txt), value_(val), description_(desc) {
  cmd_event_ = command_event;

  child_ = nullptr;
  next_ = nullptr;
  parent_ = nullptr;
  toggle_value_ = tv != 0;
  is_check_box_entry_ = check_box_entry;
}