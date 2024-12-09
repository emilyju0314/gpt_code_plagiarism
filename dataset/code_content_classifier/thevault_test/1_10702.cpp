ColPartition *ColPartitionSet::ColumnContaining(int x, int y) {
  ColPartition_IT it(&parts_);
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    ColPartition *part = it.data();
    if (part->ColumnContains(x, y)) {
      return part;
    }
  }
  return nullptr;
}