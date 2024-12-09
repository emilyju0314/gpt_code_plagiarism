void TESSLINE::CopyFrom(const TESSLINE &src) {
  Clear();
  topleft = src.topleft;
  botright = src.botright;
  start = src.start;
  is_hole = src.is_hole;
  if (src.loop != nullptr) {
    EDGEPT *prevpt = nullptr;
    EDGEPT *newpt = nullptr;
    EDGEPT *srcpt = src.loop;
    do {
      newpt = new EDGEPT(*srcpt);
      if (prevpt == nullptr) {
        loop = newpt;
      } else {
        newpt->prev = prevpt;
        prevpt->next = newpt;
      }
      prevpt = newpt;
      srcpt = srcpt->next;
    } while (srcpt != src.loop);
    loop->prev = newpt;
    newpt->next = loop;
  }
}