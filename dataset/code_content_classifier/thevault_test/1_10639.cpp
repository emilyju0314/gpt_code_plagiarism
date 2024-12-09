void BoxChar::ReorderRTLText(std::vector<BoxChar *> *boxes) {
  // Ideally we need the inverse of the algorithm used by ResultIterator.
  // For now, let's try a sort that reverses original positions for RTL
  // characters, otherwise by x-position. This should be much closer to
  // correct than just sorting by x-position.
  size_t num_boxes = boxes->size();
  for (size_t i = 0; i < num_boxes; ++i) {
    int num_rtl = 0, num_ltr = 0;
    (*boxes)[i]->GetDirection(&num_rtl, &num_ltr);
    if (num_rtl > num_ltr) {
      (*boxes)[i]->set_rtl_index(i);
      (*boxes)[i]->ReverseUnicodesInBox();
    }
  }
  BoxCharPtrSort sorter;
  size_t end = 0;
  for (size_t start = 0; start < boxes->size(); start = end + 1) {
    end = start + 1;
    while (end < boxes->size() && (*boxes)[end]->ch_ != "\t") {
      ++end;
    }
    std::sort(boxes->begin() + start, boxes->begin() + end, sorter);
  }
}