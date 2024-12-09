void ColPartitionSet::ComputeCoverage() {
  // Count the number of good columns and sum their width.
  ColPartition_IT it(&parts_);
  good_column_count_ = 0;
  good_coverage_ = 0;
  bad_coverage_ = 0;
  bounding_box_ = TBOX();
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    ColPartition *part = it.data();
    AddPartitionCoverageAndBox(*part);
  }
}