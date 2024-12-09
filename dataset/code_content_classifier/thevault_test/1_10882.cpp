void TBLOB::CopyFrom(const TBLOB &src) {
  Clear();
  TESSLINE *prev_outline = nullptr;
  for (TESSLINE *srcline = src.outlines; srcline != nullptr; srcline = srcline->next) {
    auto *new_outline = new TESSLINE(*srcline);
    if (outlines == nullptr) {
      outlines = new_outline;
    } else {
      prev_outline->next = new_outline;
    }
    prev_outline = new_outline;
  }
  denorm_ = src.denorm_;
}