LABELEDLIST FindList(LIST List, const std::string &Label) {
  LABELEDLIST LabeledList;

  iterate(List) {
    LabeledList = reinterpret_cast<LABELEDLIST>(List->first_node());
    if (LabeledList->Label == Label) {
      return (LabeledList);
    }
  }
  return (nullptr);

}