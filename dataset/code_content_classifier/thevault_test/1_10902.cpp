bool divisible_blob(TBLOB *blob, bool italic_blob, TPOINT *location) {
  if (blob->outlines == nullptr || blob->outlines->next == nullptr) {
    return false; // Need at least 2 outlines for it to be possible.
  }
  int max_gap = 0;
  TPOINT vertical = italic_blob ? kDivisibleVerticalItalic : kDivisibleVerticalUpright;
  for (TESSLINE *outline1 = blob->outlines; outline1 != nullptr; outline1 = outline1->next) {
    if (outline1->is_hole) {
      continue; // Holes do not count as separable.
    }
    TPOINT mid_pt1((outline1->topleft.x + outline1->botright.x) / 2,
                   (outline1->topleft.y + outline1->botright.y) / 2);
    int mid_prod1 = mid_pt1.cross(vertical);
    int min_prod1, max_prod1;
    outline1->MinMaxCrossProduct(vertical, &min_prod1, &max_prod1);
    for (TESSLINE *outline2 = outline1->next; outline2 != nullptr; outline2 = outline2->next) {
      if (outline2->is_hole) {
        continue; // Holes do not count as separable.
      }
      TPOINT mid_pt2((outline2->topleft.x + outline2->botright.x) / 2,
                     (outline2->topleft.y + outline2->botright.y) / 2);
      int mid_prod2 = mid_pt2.cross(vertical);
      int min_prod2, max_prod2;
      outline2->MinMaxCrossProduct(vertical, &min_prod2, &max_prod2);
      int mid_gap = abs(mid_prod2 - mid_prod1);
      int overlap = std::min(max_prod1, max_prod2) - std::max(min_prod1, min_prod2);
      if (mid_gap - overlap / 4 > max_gap) {
        max_gap = mid_gap - overlap / 4;
        *location = mid_pt1;
        *location += mid_pt2;
        *location /= 2;
      }
    }
  }
  // Use the y component of the vertical vector as an approximation to its
  // length.
  return max_gap > vertical.y;
}