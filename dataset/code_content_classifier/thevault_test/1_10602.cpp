void Trie::clear() {
  for (auto node : nodes_) {
    delete node;
  }
  nodes_.clear();
  root_back_freelist_.clear();
  num_edges_ = 0;
  new_dawg_node(); // Need to allocate node 0.
}