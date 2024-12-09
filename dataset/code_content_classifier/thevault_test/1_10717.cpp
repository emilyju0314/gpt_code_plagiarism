void ColPartitionSet::AddPartitionCoverageAndBox(const ColPartition &part) {
  bounding_box_ += part.bounding_box();
  int coverage = part.ColumnWidth();
  if (part.good_width()) {
    good_coverage_ += coverage;
    good_column_count_ += 2;
  } else {
    if (part.blob_type() < BRT_UNKNOWN) {
      coverage /= 2;
    }
    if (part.good_column()) {
      ++good_column_count_;
    }
    bad_coverage_ += coverage;
  }
}