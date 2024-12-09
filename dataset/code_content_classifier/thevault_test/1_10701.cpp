ColPartition *ColPartitionSet::GetColumnByIndex(int index) {
  ColPartition_IT it(&parts_);
  it.mark_cycle_pt();
  for (int i = 0; i < index && !it.cycled_list(); ++i, it.forward()) {
    ;
  }
  if (it.cycled_list()) {
    return nullptr;
  }
  return it.data();
}