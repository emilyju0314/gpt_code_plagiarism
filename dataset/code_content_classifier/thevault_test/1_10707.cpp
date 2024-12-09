int ColPartitionSet::UnmatchedWidth(ColPartitionSet *part_set) {
  int total_width = 0;
  ColPartition_IT it(&part_set->parts_);
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    ColPartition *part = it.data();
    if (!BLOBNBOX::IsTextType(part->blob_type())) {
      continue; // Non-text partitions are irrelevant to column compatibility.
    }
    int y = part->MidY();
    BLOBNBOX_C_IT box_it(part->boxes());
    for (box_it.mark_cycle_pt(); !box_it.cycled_list(); box_it.forward()) {
      const TBOX &box = it.data()->bounding_box();
      // Assume that the whole blob is outside any column iff its x-middle
      // is outside.
      int x = (box.left() + box.right()) / 2;
      ColPartition *col = ColumnContaining(x, y);
      if (col == nullptr) {
        total_width += box.width();
      }
    }
  }
  return total_width;
}