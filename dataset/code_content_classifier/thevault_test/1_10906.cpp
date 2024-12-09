void RecodeBeamSearch::ExtractBestPathAsLabels(
    std::vector<int> *labels, std::vector<int> *xcoords) const {
  labels->clear();
  xcoords->clear();
  std::vector<const RecodeNode *> best_nodes;
  ExtractBestPaths(&best_nodes, nullptr);
  // Now just run CTC on the best nodes.
  int t = 0;
  int width = best_nodes.size();
  while (t < width) {
    int label = best_nodes[t]->code;
    if (label != null_char_) {
      labels->push_back(label);
      xcoords->push_back(t);
    }
    while (++t < width && !is_simple_text_ && best_nodes[t]->code == label) {
    }
  }
  xcoords->push_back(width);
}