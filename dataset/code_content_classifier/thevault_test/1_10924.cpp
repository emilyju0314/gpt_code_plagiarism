void RecodeBeamSearch::ExtractPath(
    const RecodeNode *node, std::vector<const RecodeNode *> *path) const {
  path->clear();
  while (node != nullptr) {
    path->push_back(node);
    node = node->prev;
  }
  std::reverse(path->begin(), path->end());
}