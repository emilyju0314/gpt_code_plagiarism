SquishedDawg *Trie::trie_to_dawg() {
  root_back_freelist_.clear(); // Will be invalided by trie_to_dawg.
  if (debug_level_ > 2) {
    print_all("Before reduction:", MAX_NODE_EDGES_DISPLAY);
  }
  std::vector<bool> reduced_nodes(nodes_.size());
  this->reduce_node_input(0, reduced_nodes);

  if (debug_level_ > 2) {
    print_all("After reduction:", MAX_NODE_EDGES_DISPLAY);
  }
  // Build a translation map from node indices in nodes_ vector to
  // their target indices in EDGE_ARRAY.
  std::vector<NODE_REF> node_ref_map(nodes_.size() + 1);
  unsigned i;
  for (i = 0; i < nodes_.size(); ++i) {
    node_ref_map[i + 1] = node_ref_map[i] + nodes_[i]->forward_edges.size();
  }
  int num_forward_edges = node_ref_map[i];

  // Convert nodes_ vector into EDGE_ARRAY translating the next node references
  // in edges using node_ref_map. Empty nodes and backward edges are dropped.
  auto edge_array = new EDGE_RECORD[num_forward_edges];
  EDGE_ARRAY edge_array_ptr = edge_array;
  for (i = 0; i < nodes_.size(); ++i) {
    TRIE_NODE_RECORD *node_ptr = nodes_[i];
    int end = node_ptr->forward_edges.size();
    for (int j = 0; j < end; ++j) {
      EDGE_RECORD &edge_rec = node_ptr->forward_edges[j];
      NODE_REF node_ref = next_node_from_edge_rec(edge_rec);
      ASSERT_HOST(static_cast<size_t>(node_ref) < nodes_.size());
      UNICHAR_ID unichar_id = unichar_id_from_edge_rec(edge_rec);
      link_edge(edge_array_ptr, node_ref_map[node_ref], false, FORWARD_EDGE,
                end_of_word_from_edge_rec(edge_rec), unichar_id);
      if (j == end - 1) {
        set_marker_flag_in_edge_rec(edge_array_ptr);
      }
      ++edge_array_ptr;
    }
  }

  return new SquishedDawg(edge_array, num_forward_edges, type_, lang_, perm_, unicharset_size_,
                          debug_level_);
}