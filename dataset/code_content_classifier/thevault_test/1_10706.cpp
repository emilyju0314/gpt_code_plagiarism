bool ColPartitionSet::CompatibleColumns(bool debug, ColPartitionSet *other,
                                        const WidthCallback &cb) {
  if (debug) {
    tprintf("CompatibleColumns testing compatibility\n");
    Print();
    other->Print();
  }
  if (other->parts_.empty()) {
    if (debug) {
      tprintf("CompatibleColumns true due to empty other\n");
    }
    return true;
  }
  ColPartition_IT it(&other->parts_);
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    ColPartition *part = it.data();
    if (part->blob_type() < BRT_UNKNOWN) {
      if (debug) {
        tprintf("CompatibleColumns ignoring image partition\n");
        part->Print();
      }
      continue; // Image partitions are irrelevant to column compatibility.
    }
    int y = part->MidY();
    int left = part->bounding_box().left();
    int right = part->bounding_box().right();
    ColPartition *left_col = ColumnContaining(left, y);
    ColPartition *right_col = ColumnContaining(right, y);
    if (right_col == nullptr || left_col == nullptr) {
      if (debug) {
        tprintf("CompatibleColumns false due to partition edge outside\n");
        part->Print();
      }
      return false; // A partition edge lies outside of all columns
    }
    if (right_col != left_col && cb(right - left)) {
      if (debug) {
        tprintf("CompatibleColumns false due to good width in multiple cols\n");
        part->Print();
      }
      return false; // Partition with a good width must be in a single column.
    }

    ColPartition_IT it2 = it;
    while (!it2.at_last()) {
      it2.forward();
      ColPartition *next_part = it2.data();
      if (!BLOBNBOX::IsTextType(next_part->blob_type())) {
        continue; // Non-text partitions are irrelevant.
      }
      int next_left = next_part->bounding_box().left();
      if (next_left == right) {
        break; // They share the same edge, so one must be a pull-out.
      }
      // Search to see if right and next_left fall within a single column.
      ColPartition *next_left_col = ColumnContaining(next_left, y);
      if (right_col == next_left_col) {
        // There is a column break in this column.
        // This can be due to a figure caption within a column, a pull-out
        // block, or a simple broken textline that remains to be merged:
        // all allowed, or a change in column layout: not allowed.
        // If both partitions are of good width, then it is likely
        // a change in column layout, otherwise probably an allowed situation.
        if (part->good_width() && next_part->good_width()) {
          if (debug) {
            int next_right = next_part->bounding_box().right();
            tprintf("CompatibleColumns false due to 2 parts of good width\n");
            tprintf("part1 %d-%d, part2 %d-%d\n", left, right, next_left,
                    next_right);
            right_col->Print();
          }
          return false;
        }
      }
      break;
    }
  }
  if (debug) {
    tprintf("CompatibleColumns true!\n");
  }
  return true;
}