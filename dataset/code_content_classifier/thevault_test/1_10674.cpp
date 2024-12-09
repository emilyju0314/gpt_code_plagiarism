void Wordrec::new_max_point(EDGEPT *local_max, PointHeap *points) {
  int16_t dir;

  dir = direction(local_max);

  if (dir > 0) {
    add_point_to_list(points, local_max);
    return;
  }

  if (dir == 0 && point_priority(local_max) < 0) {
    add_point_to_list(points, local_max);
    return;
  }
}