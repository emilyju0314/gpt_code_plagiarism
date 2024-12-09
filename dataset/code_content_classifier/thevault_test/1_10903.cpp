void divide_blobs(TBLOB *blob, TBLOB *other_blob, bool italic_blob, const TPOINT &location) {
  TPOINT vertical = italic_blob ? kDivisibleVerticalItalic : kDivisibleVerticalUpright;
  TESSLINE *outline1 = nullptr;
  TESSLINE *outline2 = nullptr;

  TESSLINE *outline = blob->outlines;
  blob->outlines = nullptr;
  int location_prod = location.cross(vertical);

  while (outline != nullptr) {
    TPOINT mid_pt((outline->topleft.x + outline->botright.x) / 2,
                  (outline->topleft.y + outline->botright.y) / 2);
    int mid_prod = mid_pt.cross(vertical);
    if (mid_prod < location_prod) {
      // Outline is in left blob.
      if (outline1) {
        outline1->next = outline;
      } else {
        blob->outlines = outline;
      }
      outline1 = outline;
    } else {
      // Outline is in right blob.
      if (outline2) {
        outline2->next = outline;
      } else {
        other_blob->outlines = outline;
      }
      outline2 = outline;
    }
    outline = outline->next;
  }

  if (outline1) {
    outline1->next = nullptr;
  }
  if (outline2) {
    outline2->next = nullptr;
  }
}