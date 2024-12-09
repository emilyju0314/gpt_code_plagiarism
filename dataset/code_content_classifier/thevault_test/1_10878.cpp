void TESSLINE::MinMaxCrossProduct(const TPOINT vec, int *min_xp, int *max_xp) const {
  *min_xp = INT32_MAX;
  *max_xp = INT32_MIN;
  EDGEPT *this_edge = loop;
  do {
    if (!this_edge->IsHidden() || !this_edge->prev->IsHidden()) {
      int product = this_edge->pos.cross(vec);
      UpdateRange(product, min_xp, max_xp);
    }
    this_edge = this_edge->next;
  } while (this_edge != loop);
}