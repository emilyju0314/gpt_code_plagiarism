void ColPartitionSet::RelinquishParts() {
  ColPartition_IT it(&parts_);
  while (!it.empty()) {
    it.extract();
    it.forward();
  }
}