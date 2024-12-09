bool IndexMapBiDi::Merge(int compact_index1, int compact_index2) {
  // Find the current master index for index1 and index2.
  compact_index1 = MasterCompactIndex(compact_index1);
  compact_index2 = MasterCompactIndex(compact_index2);
  // Be sure that index1 < index2.
  if (compact_index1 > compact_index2) {
    int tmp = compact_index1;
    compact_index1 = compact_index2;
    compact_index2 = tmp;
  } else if (compact_index1 == compact_index2) {
    return false;
  }
  // To save iterating over all sparse_map_ entries, simply make the master
  // entry for index2 point to index1.
  // This leaves behind a potential chain of parents that needs to be chased,
  // as above.
  sparse_map_[compact_map_[compact_index2]] = compact_index1;
  if (compact_index1 >= 0) {
    compact_map_[compact_index2] = compact_map_[compact_index1];
  }
  return true;
}