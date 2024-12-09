void TESSLINE::Normalize(const DENORM &denorm) {
  EDGEPT *pt = loop;
  do {
    denorm.LocalNormTransform(pt->pos, &pt->pos);
    pt = pt->next;
  } while (pt != loop);
  SetupFromPos();
}