void ColPartitionSet::ImproveColumnCandidate(const WidthCallback &cb,
                                             PartSetVector *src_sets) {
  int set_size = src_sets->size();
  // Iterate over the provided column sets, as each one may have something
  // to improve this.
  for (int i = 0; i < set_size; ++i) {
    ColPartitionSet *column_set = src_sets->at(i);
    if (column_set == nullptr) {
      continue;
    }
    // Iterate over the parts in this and column_set, adding bigger or
    // new parts in column_set to this.
    ColPartition_IT part_it(&parts_);
    ASSERT_HOST(!part_it.empty());
    int prev_right = INT32_MIN;
    part_it.mark_cycle_pt();
    ColPartition_IT col_it(&column_set->parts_);
    for (col_it.mark_cycle_pt(); !col_it.cycled_list(); col_it.forward()) {
      ColPartition *col_part = col_it.data();
      if (col_part->blob_type() < BRT_UNKNOWN) {
        continue; // Ignore image partitions.
      }
      int col_left = col_part->left_key();
      int col_right = col_part->right_key();
      // Sync-up part_it (in this) so it matches the col_part in column_set.
      ColPartition *part = part_it.data();
      while (!part_it.at_last() && part->right_key() < col_left) {
        prev_right = part->right_key();
        part_it.forward();
        part = part_it.data();
      }
      int part_left = part->left_key();
      int part_right = part->right_key();
      if (part_right < col_left || col_right < part_left) {
        // There is no overlap so this is a new partition.
        AddPartition(col_part->ShallowCopy(), &part_it);
        continue;
      }
      // Check the edges of col_part to see if they can improve part.
      bool part_width_ok = cb(part->KeyWidth(part_left, part_right));
      if (col_left < part_left && col_left > prev_right) {
        // The left edge of the column is better and it doesn't overlap,
        // so we can potentially expand it.
        int col_box_left = col_part->BoxLeftKey();
        bool tab_width_ok = cb(part->KeyWidth(col_left, part_right));
        bool box_width_ok = cb(part->KeyWidth(col_box_left, part_right));
        if (tab_width_ok || (!part_width_ok)) {
          // The tab is leaving the good column metric at least as good as
          // it was before, so use the tab.
          part->CopyLeftTab(*col_part, false);
          part->SetColumnGoodness(cb);
        } else if (col_box_left < part_left &&
                   (box_width_ok || !part_width_ok)) {
          // The box is leaving the good column metric at least as good as
          // it was before, so use the box.
          part->CopyLeftTab(*col_part, true);
          part->SetColumnGoodness(cb);
        }
        part_left = part->left_key();
      }
      if (col_right > part_right &&
          (part_it.at_last() ||
           part_it.data_relative(1)->left_key() > col_right)) {
        // The right edge is better, so we can possibly expand it.
        int col_box_right = col_part->BoxRightKey();
        bool tab_width_ok = cb(part->KeyWidth(part_left, col_right));
        bool box_width_ok = cb(part->KeyWidth(part_left, col_box_right));
        if (tab_width_ok || (!part_width_ok)) {
          // The tab is leaving the good column metric at least as good as
          // it was before, so use the tab.
          part->CopyRightTab(*col_part, false);
          part->SetColumnGoodness(cb);
        } else if (col_box_right > part_right &&
                   (box_width_ok || !part_width_ok)) {
          // The box is leaving the good column metric at least as good as
          // it was before, so use the box.
          part->CopyRightTab(*col_part, true);
          part->SetColumnGoodness(cb);
        }
      }
    }
  }
  ComputeCoverage();
}