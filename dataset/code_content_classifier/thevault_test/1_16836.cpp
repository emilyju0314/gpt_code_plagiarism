void FindInputEntries(const Graph& g,
                      const std::vector<SimpleNodePtr>& simple_nodes,
                      const std::vector<SimpleNode*>& subgraph_nodes,
                      const std::unordered_map<const nnvm::NodeEntry*, size_t>& entry_top_order_map,
                      std::vector<nnvm::NodeEntry*>* input_entries) {
  const auto& indexed_graph = g.indexed_graph();
  int label = -1;
  for (auto subgraph_node : subgraph_nodes) {
    if (label == -1) {
      label = subgraph_node->label;
    } else {
      CHECK_EQ(subgraph_node->label, label);
    }
    auto& inputs = subgraph_node->node->inputs;
    for (auto &e : inputs) {
      if (indexed_graph.exist(e.node.get())) {
        // e's source node is not a subgraph node
        const auto nid = indexed_graph.node_id(e.node.get());
        // this is a node not belonging to the subgraph
        if (simple_nodes[nid]->label != label) {
          input_entries->push_back(&e);
        }
      } else {
        // e's source node is a subgraph node.
        // In this case, two subgraphs are adjacent.
        input_entries->push_back(&e);
      }
    }
  }
  SortEntries(entry_top_order_map, input_entries);
}