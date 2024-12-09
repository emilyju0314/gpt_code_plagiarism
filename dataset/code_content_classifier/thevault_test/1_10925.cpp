void RecodeBeamSearch::DebugPath(
    const UNICHARSET *unicharset,
    const std::vector<const RecodeNode *> &path) const {
  for (unsigned c = 0; c < path.size(); ++c) {
    const RecodeNode &node = *path[c];
    tprintf("%u ", c);
    node.Print(null_char_, *unicharset, 1);
  }
}