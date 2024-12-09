void RecodeBeamSearch::DebugBeamPos(const UNICHARSET &unicharset,
                                    const RecodeHeap &heap) const {
  std::vector<const RecodeNode *> unichar_bests(unicharset.size());
  const RecodeNode *null_best = nullptr;
  int heap_size = heap.size();
  for (int i = 0; i < heap_size; ++i) {
    const RecodeNode *node = &heap.get(i).data();
    if (node->unichar_id == INVALID_UNICHAR_ID) {
      if (null_best == nullptr || null_best->score < node->score) {
        null_best = node;
      }
    } else {
      if (unichar_bests[node->unichar_id] == nullptr ||
          unichar_bests[node->unichar_id]->score < node->score) {
        unichar_bests[node->unichar_id] = node;
      }
    }
  }
  for (auto &unichar_best : unichar_bests) {
    if (unichar_best != nullptr) {
      const RecodeNode &node = *unichar_best;
      node.Print(null_char_, unicharset, 1);
    }
  }
  if (null_best != nullptr) {
    null_best->Print(null_char_, unicharset, 1);
  }
}