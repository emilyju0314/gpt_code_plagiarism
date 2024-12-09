void ColPartitionSet::AccumulateColumnWidthsAndGaps(int *total_width,
                                                    int *width_samples,
                                                    int *total_gap,
                                                    int *gap_samples) {
  ColPartition_IT it(&parts_);
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    ColPartition *part = it.data();
    *total_width += part->ColumnWidth();
    ++*width_samples;
    if (!it.at_last()) {
      ColPartition *next_part = it.data_relative(1);
      int part_left = part->right_key();
      int part_right = next_part->left_key();
      int gap = part->KeyWidth(part_left, part_right);
      *total_gap += gap;
      ++*gap_samples;
    }
  }
}