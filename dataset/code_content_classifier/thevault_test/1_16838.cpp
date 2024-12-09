void CreateSubgraphNode(Graph* g,
                        const std::vector<SimpleNodePtr>& simple_nodes,
                        const std::vector<SimpleNode*>& subgraph_nodes,
                        const size_t subgraph_id,
                        std::unordered_map<const nnvm::NodeEntry*, size_t>* entry_top_order_map) {
#if DEBUG_SUBGRAPH
  LOG(INFO) << "Searching for input entries...";
#endif
  std::vector<nnvm::NodeEntry*> input_entries;
  FindInputEntries(*g, simple_nodes, subgraph_nodes, *entry_top_order_map, &input_entries);
  std::vector<nnvm::NodeEntry> orig_input_entries;
  CutGraphInputs(input_entries, &orig_input_entries, false);
#if DEBUG_SUBGRAPH
  PrintNodeEntries(input_entries);
  LOG(INFO) << "Searching for output entries...";
#endif
  std::vector<nnvm::NodeEntry*> output_entries;
  FindOutputEntries(g, simple_nodes, subgraph_nodes, *entry_top_order_map, &output_entries);

  // Create a subgraph for the subgraph node
  nnvm::Symbol sym;
  sym.outputs.resize(output_entries.size());
  for (size_t i = 0; i < output_entries.size(); ++i) {
    sym.outputs[i] = *output_entries[i];
  }
  const SubgraphPropertyPtr& subg_prop = g->GetAttr<SubgraphPropertyPtr>("subgraph_property");
  nnvm::NodePtr n = subg_prop->CreateSubgraphNode(sym, subgraph_id);

  // Connect the external nodes to the subgraph node.
  subg_prop->ConnectSubgraphOutputs(n, &output_entries);
  subg_prop->ConnectSubgraphInputs(n, &input_entries, &orig_input_entries);

  const auto& indexed_graph = g->indexed_graph();
  for (size_t i = 0; i < n->inputs.size(); ++i) {
    auto& e = n->inputs[i];
    // update entry_top_order_map with newly created orig_input_entries
    auto it = entry_top_order_map->find(input_entries[i]);
    CHECK(it != entry_top_order_map->end());
    entry_top_order_map->emplace(&e, it->second);
    // update input entries' source simple nodes' outputs map
    nnvm::Node* node = e.node.get();
    if (indexed_graph.exist(node)) {
      const auto nid = indexed_graph.node_id(node);
      SimpleNode* sn = simple_nodes[nid].get();
      for (SimpleNode* dest_node : subgraph_nodes) {
        sn->outputs.erase(dest_node->node);
      }
      sn->outputs[n.get()].push_back(i);
    }
  }
#if DEBUG_SUBGRAPH
  PrintNodeEntries(output_entries);
#endif
}