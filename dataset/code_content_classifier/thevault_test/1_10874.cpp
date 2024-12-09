void TESSLINE::Move(const ICOORD vec) {
  EDGEPT *pt = loop;
  do {
    pt->pos.x += vec.x();
    pt->pos.y += vec.y();
    pt = pt->next;
  } while (pt != loop);
  SetupFromPos();
}