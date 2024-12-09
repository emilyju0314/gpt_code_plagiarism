static bool TestWeakIntersectedPart(const TBOX &im_box, ColPartition_LIST *part_list,
                                    ColPartition *part) {
  if (part->flow() < BTFT_STRONG_CHAIN) {
    // A weak partition intersects the box.
    const TBOX &part_box = part->bounding_box();
    if (im_box.contains(part_box)) {
      int area = part_box.area();
      int intersect_area = IntersectArea(part_box, part_list);
      if (area < 2 * intersect_area) {
        return true;
      }
    }
  }
  return false;
}