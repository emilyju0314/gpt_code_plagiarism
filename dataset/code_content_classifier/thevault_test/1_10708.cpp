bool ColPartitionSet::LegalColumnCandidate() {
  ColPartition_IT it(&parts_);
  if (it.empty()) {
    return false;
  }
  bool any_text_parts = false;
  for (it.mark_cycle_pt(); !it.cycled_list(); it.forward()) {
    ColPartition *part = it.data();
    if (BLOBNBOX::IsTextType(part->blob_type())) {
      if (!part->IsLegal()) {
        return false; // Individual partition is illegal.
      }
      any_text_parts = true;
    }
    if (!it.at_last()) {
      ColPartition *next_part = it.data_relative(1);
      if (next_part->left_key() < part->right_key()) {
        return false;
      }
    }
  }
  return any_text_parts;
}