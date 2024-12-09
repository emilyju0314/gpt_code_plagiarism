void TESSLINE::SetupFromPos() {
  EDGEPT *pt = loop;
  do {
    pt->vec.x = pt->next->pos.x - pt->pos.x;
    pt->vec.y = pt->next->pos.y - pt->pos.y;
    pt = pt->next;
  } while (pt != loop);
  start = pt->pos;
  ComputeBoundingBox();
}