void TESSLINE::ComputeBoundingBox() {
  int minx = INT32_MAX;
  int miny = INT32_MAX;
  int maxx = -INT32_MAX;
  int maxy = -INT32_MAX;

  // Find boundaries.
  start = loop->pos;
  EDGEPT *this_edge = loop;
  do {
    if (!this_edge->IsHidden() || !this_edge->prev->IsHidden()) {
      if (this_edge->pos.x < minx) {
        minx = this_edge->pos.x;
      }
      if (this_edge->pos.y < miny) {
        miny = this_edge->pos.y;
      }
      if (this_edge->pos.x > maxx) {
        maxx = this_edge->pos.x;
      }
      if (this_edge->pos.y > maxy) {
        maxy = this_edge->pos.y;
      }
    }
    this_edge = this_edge->next;
  } while (this_edge != loop);
  // Reset bounds.
  topleft.x = minx;
  topleft.y = maxy;
  botright.x = maxx;
  botright.y = miny;
}