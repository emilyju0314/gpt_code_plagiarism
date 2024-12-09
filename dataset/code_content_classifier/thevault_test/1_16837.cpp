void FindOutputEntries(Graph* g,
                       const std::vector<SimpleNodePtr>& simple_nodes,
                       const std::vector<SimpleNode*>& subgraph_nodes,
                       const std::unordered_map<const nnvm::NodeEntry*, size_t>&
                         entry_top_order_map,
                       std::vector<nnvm::NodeEntry*>* output_entries) {
  if (subgraph_nodes.empty()) return;
  const auto& indexed_graph = g->indexed_graph();
  int label = -1;
  for (auto subgraph_node : subgraph_nodes) {
    if (label == -1) {
      label = subgraph_node->label;
    } else {
      CHECK_EQ(subgraph_node->label, label);
    }
    for (auto &output_node : subgraph_node->outputs) {
      if (indexed_graph.exist(output_node.first)) {
        // if the output node is a normal graph node (not a subgraph node)
        const auto nid = indexed_graph.node_id(output_node.first);
        // this is a node not belonging to the current subgraph
        if (simple_nodes[nid]->label != label) {
          for (auto idx : output_node.second) {
            auto& e = simple_nodes[nid]->node->inputs[idx];
            output_entries->push_back(&e);
          }
        }
      } else {
        // if the output node is a subgraph node
        // two graphs are adjacent
        for (auto idx : output_node.second) {
          output_entries->push_back(&(output_node.first->inputs[idx]));
        }
      }
    }
  }
  // Check if current subgraph contains a node which is the last node
  // of the whole graph. If so, save its corresponding entry as well.
  for (auto &entry : g->outputs) {
    // The entry might has been updated as an output of
    // a subgraph node. In this case, no need
    // to check its source for the current subgraph. Otherwise,
    // do the following.
    if (indexed_graph.exist(entry.node.get())) {
      const auto nid = indexed_graph.node_id(entry.node.get());
      if (simple_nodes[nid]->label == label) {
        output_entries->push_back(&entry);
      }
    }
  }
  SortEntries(entry_top_order_map, output_entries);
}