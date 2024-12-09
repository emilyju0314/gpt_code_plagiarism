void LMPainPoints::RemapForSplit(int index) {
  for (auto &pain_points_heap : pain_points_heaps_) {
    std::vector<MatrixCoordPair> &heap = pain_points_heap.heap();
    for (auto entry : heap) {
      entry.data().MapForSplit(index);
    }
  }
}