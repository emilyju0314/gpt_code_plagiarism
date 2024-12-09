void ColPartitionSet::Print() {
  ColPartition_IT it(&parts_);
  tprintf(
      "Partition set of %d parts, %d good, coverage=%d+%d"
      " (%d,%d)->(%d,%d)\n",
      it.length(), good_column_count_, good_coverage_, bad_coverage_,
      bounding_box_.left(), bounding_box_.bottom(), bounding_box_.right(),
      bounding_box_.top());
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    ColPartition *part = it.data();
    part->Print();
  }
}