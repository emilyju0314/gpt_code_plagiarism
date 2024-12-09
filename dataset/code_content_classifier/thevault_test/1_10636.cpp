void BoxChar::PrepareToWrite(std::vector<BoxChar *> *boxes) {
  bool rtl_rules = ContainsMostlyRTL(*boxes);
  bool vertical_rules = MostlyVertical(*boxes);
  InsertNewlines(rtl_rules, vertical_rules, boxes);
  InsertSpaces(rtl_rules, vertical_rules, boxes);
  for (size_t i = 0; i < boxes->size(); ++i) {
    if ((*boxes)[i]->box_ == nullptr) {
      tprintf("Null box at index %zu\n", i);
    }
  }
  if (rtl_rules) {
    ReorderRTLText(boxes);
  }
}