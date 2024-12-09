bool RecodeBeamSearch::UpdateHeapIfMatched(RecodeNode *new_node,
                                           RecodeHeap *heap) {
  // TODO(rays) consider hash map instead of linear search.
  // It might not be faster because the hash map would have to be updated
  // every time a heap reshuffle happens, and that would be a lot of overhead.
  std::vector<RecodePair> &nodes = heap->heap();
  for (auto &i : nodes) {
    RecodeNode &node = i.data();
    if (node.code == new_node->code && node.code_hash == new_node->code_hash &&
        node.permuter == new_node->permuter &&
        node.start_of_dawg == new_node->start_of_dawg) {
      if (new_node->score > node.score) {
        // The new one is better. Update the entire node in the heap and
        // reshuffle.
        node = *new_node;
        i.key() = node.score;
        heap->Reshuffle(&i);
      }
      return true;
    }
  }
  return false;
}