void Wordrec::vertical_projection_point(EDGEPT *split_point, EDGEPT *target_point,
                                        EDGEPT **best_point, EDGEPT_CLIST *new_points) {
  EDGEPT *p;           /* Iterator */
  EDGEPT *this_edgept; /* Iterator */
  EDGEPT_C_IT new_point_it(new_points);
  int x = split_point->pos.x;     /* X value of vertical */
  int best_dist = LARGE_DISTANCE; /* Best point found */

  if (*best_point != nullptr) {
    best_dist = edgept_dist(split_point, *best_point);
  }

  p = target_point;
  /* Look at each edge point */
  do {
    if (((p->pos.x <= x && x <= p->next->pos.x) || (p->next->pos.x <= x && x <= p->pos.x)) &&
        !same_point(split_point->pos, p->pos) && !same_point(split_point->pos, p->next->pos) &&
        !p->IsChopPt() && (*best_point == nullptr || !same_point((*best_point)->pos, p->pos))) {
      if (near_point(split_point, p, p->next, &this_edgept)) {
        new_point_it.add_before_then_move(this_edgept);
      }

      if (*best_point == nullptr) {
        best_dist = edgept_dist(split_point, this_edgept);
      }

      this_edgept = pick_close_point(split_point, this_edgept, &best_dist);
      if (this_edgept) {
        *best_point = this_edgept;
      }
    }

    p = p->next;
  } while (p != target_point);
}