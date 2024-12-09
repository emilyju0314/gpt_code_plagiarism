void ColPartitionSet::AddPartition(ColPartition *new_part,
                                   ColPartition_IT *it) {
  AddPartitionCoverageAndBox(*new_part);
  int new_right = new_part->right_key();
  if (it->data()->left_key() >= new_right) {
    it->add_before_stay_put(new_part);
  } else {
    it->add_after_stay_put(new_part);
  }
}