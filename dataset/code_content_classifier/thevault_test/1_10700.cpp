int ColPartitionSet::GoodColumnCount() const {
  int num_good_cols = 0;
  // This is a read-only iteration of the list.
  ColPartition_IT it(const_cast<ColPartition_LIST *>(&parts_));
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    if (it.data()->good_width()) {
      ++num_good_cols;
    }
  }
  return num_good_cols;
}