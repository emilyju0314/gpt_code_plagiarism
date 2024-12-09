static int IncreaseInOverlap(const ColPartition *merge1,
                             const ColPartition *merge2, int ok_overlap,
                             ColPartition_CLIST *parts) {
  ASSERT_HOST(merge1 != nullptr && merge2 != nullptr);
  int total_area = 0;
  ColPartition_C_IT it(parts);
  TBOX merged_box(merge1->bounding_box());
  merged_box += merge2->bounding_box();
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    ColPartition *part = it.data();
    if (part == merge1 || part == merge2) {
      continue;
    }
    TBOX part_box = part->bounding_box();
    // Compute the overlap of the merged box with part.
    int overlap_area = part_box.intersection(merged_box).area();
    if (overlap_area > 0 &&
        !part->OKMergeOverlap(*merge1, *merge2, ok_overlap, false)) {
      total_area += overlap_area;
      // Subtract the overlap of merge1 and merge2 individually.
      overlap_area = part_box.intersection(merge1->bounding_box()).area();
      if (overlap_area > 0) {
        total_area -= overlap_area;
      }
      TBOX intersection_box = part_box.intersection(merge2->bounding_box());
      overlap_area = intersection_box.area();
      if (overlap_area > 0) {
        total_area -= overlap_area;
        // Add back the 3-way area.
        intersection_box &= merge1->bounding_box(); // In-place intersection.
        overlap_area = intersection_box.area();
        if (overlap_area > 0) {
          total_area += overlap_area;
        }
      }
    }
  }
  return total_area;
}