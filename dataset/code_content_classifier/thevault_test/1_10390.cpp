void FreeMFOutline(void *arg) { // MFOUTLINE Outline)
  auto Outline = static_cast<MFOUTLINE>(arg);

  /* break the circular outline so we can use std. techniques to deallocate */
  MFOUTLINE Start = Outline->list_rest();
  set_rest(Outline, NIL_LIST);
  while (Start != nullptr) {
    delete reinterpret_cast<MFEDGEPT *>(Start->first_node());
    Start = pop(Start);
  }

}