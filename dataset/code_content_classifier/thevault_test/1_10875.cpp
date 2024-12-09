void TESSLINE::Scale(float factor) {
  EDGEPT *pt = loop;
  do {
    pt->pos.x = static_cast<int>(floor(pt->pos.x * factor + 0.5));
    pt->pos.y = static_cast<int>(floor(pt->pos.y * factor + 0.5));
    pt = pt->next;
  } while (pt != loop);
  SetupFromPos();
}