EDGEPT *Wordrec::pick_close_point(EDGEPT *critical_point, EDGEPT *vertical_point, int *best_dist) {
  EDGEPT *best_point = nullptr;
  int this_distance;
  bool found_better;

  do {
    found_better = false;

    this_distance = edgept_dist(critical_point, vertical_point);
    if (this_distance <= *best_dist) {
      if (!(same_point(critical_point->pos, vertical_point->pos) ||
            same_point(critical_point->pos, vertical_point->next->pos) ||
            (best_point && same_point(best_point->pos, vertical_point->pos)) ||
            is_exterior_point(critical_point, vertical_point))) {
        *best_dist = this_distance;
        best_point = vertical_point;
        if (chop_vertical_creep) {
          found_better = true;
        }
      }
    }
    vertical_point = vertical_point->next;
  } while (found_better == true);

  return (best_point);
}