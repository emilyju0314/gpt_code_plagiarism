void Wordrec::prioritize_points(TESSLINE *outline, PointHeap *points) {
  EDGEPT *this_point;
  EDGEPT *local_min = nullptr;
  EDGEPT *local_max = nullptr;

  this_point = outline->loop;
  local_min = this_point;
  local_max = this_point;
  do {
    if (this_point->vec.y < 0) {
      /* Look for minima */
      if (local_max != nullptr) {
        new_max_point(local_max, points);
      } else if (is_inside_angle(this_point)) {
        add_point_to_list(points, this_point);
      }
      local_max = nullptr;
      local_min = this_point->next;
    } else if (this_point->vec.y > 0) {
      /* Look for maxima */
      if (local_min != nullptr) {
        new_min_point(local_min, points);
      } else if (is_inside_angle(this_point)) {
        add_point_to_list(points, this_point);
      }
      local_min = nullptr;
      local_max = this_point->next;
    } else {
      /* Flat area */
      if (local_max != nullptr) {
        if (local_max->prev->vec.y != 0) {
          new_max_point(local_max, points);
        }
        local_max = this_point->next;
        local_min = nullptr;
      } else {
        if (local_min->prev->vec.y != 0) {
          new_min_point(local_min, points);
        }
        local_min = this_point->next;
        local_max = nullptr;
      }
    }

    /* Next point */
    this_point = this_point->next;
  } while (this_point != outline->loop);
}