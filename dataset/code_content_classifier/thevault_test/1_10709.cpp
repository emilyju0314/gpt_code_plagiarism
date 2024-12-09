ColPartitionSet *ColPartitionSet::Copy(bool good_only) {
  ColPartition_LIST copy_parts;
  ColPartition_IT src_it(&parts_);
  ColPartition_IT dest_it(&copy_parts);
  for (src_it.mark_cycle_pt(); !src_it.cycled_list(); src_it.forward()) {
    ColPartition *part = src_it.data();
    if (BLOBNBOX::IsTextType(part->blob_type()) &&
        (!good_only || part->good_width() || part->good_column())) {
      dest_it.add_after_then_move(part->ShallowCopy());
    }
  }
  if (dest_it.empty()) {
    return nullptr;
  }
  return new ColPartitionSet(&copy_parts);
}