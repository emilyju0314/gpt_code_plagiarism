void RecodeBeamSearch::ExtractBestPaths(
    std::vector<const RecodeNode *> *best_nodes,
    std::vector<const RecodeNode *> *second_nodes) const {
  // Scan both beams to extract the best and second best paths.
  const RecodeNode *best_node = nullptr;
  const RecodeNode *second_best_node = nullptr;
  const RecodeBeam *last_beam = beam_[beam_size_ - 1];
  for (int c = 0; c < NC_COUNT; ++c) {
    if (c == NC_ONLY_DUP) {
      continue;
    }
    auto cont = static_cast<NodeContinuation>(c);
    for (int is_dawg = 0; is_dawg < 2; ++is_dawg) {
      int beam_index = BeamIndex(is_dawg, cont, 0);
      int heap_size = last_beam->beams_[beam_index].size();
      for (int h = 0; h < heap_size; ++h) {
        const RecodeNode *node = &last_beam->beams_[beam_index].get(h).data();
        if (is_dawg) {
          // dawg_node may be a null_char, or duplicate, so scan back to the
          // last valid unichar_id.
          const RecodeNode *dawg_node = node;
          while (dawg_node != nullptr &&
                 (dawg_node->unichar_id == INVALID_UNICHAR_ID ||
                  dawg_node->duplicate)) {
            dawg_node = dawg_node->prev;
          }
          if (dawg_node == nullptr ||
              (!dawg_node->end_of_word &&
               dawg_node->unichar_id != UNICHAR_SPACE)) {
            // Dawg node is not valid.
            continue;
          }
        }
        if (best_node == nullptr || node->score > best_node->score) {
          second_best_node = best_node;
          best_node = node;
        } else if (second_best_node == nullptr ||
                   node->score > second_best_node->score) {
          second_best_node = node;
        }
      }
    }
  }
  if (second_nodes != nullptr) {
    ExtractPath(second_best_node, second_nodes);
  }
  ExtractPath(best_node, best_nodes);
}