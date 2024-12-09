void Wordrec::new_min_point(EDGEPT *local_min, PointHeap *points) {
  int16_t dir;

  dir = direction(local_min);

  if (dir < 0) {
    add_point_to_list(points, local_min);
    return;
  }

  if (dir == 0 && point_priority(local_min) < 0) {
    add_point_to_list(points, local_min);
    return;
  }
}