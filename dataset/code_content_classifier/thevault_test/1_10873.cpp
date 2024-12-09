void TESSLINE::Rotate(const FCOORD rot) {
  EDGEPT *pt = loop;
  do {
    int tmp = static_cast<int>(floor(pt->pos.x * rot.x() - pt->pos.y * rot.y() + 0.5));
    pt->pos.y = static_cast<int>(floor(pt->pos.y * rot.x() + pt->pos.x * rot.y() + 0.5));
    pt->pos.x = tmp;
    pt = pt->next;
  } while (pt != loop);
  SetupFromPos();
}