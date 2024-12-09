std::map<unsigned, std::vector<unsigned>> Draco_Mesh::compute_node_indx_map(
    const std::vector<unsigned> &indx_type,
    const std::vector<unsigned> &indx_to_node_linkage) const {

  // map to return
  std::map<unsigned, std::vector<unsigned>> node_to_indx_map;

  // push node index to vector for each node
  unsigned node_offset = 0;
  const size_t num_indxs = indx_type.size();
  for (unsigned indx = 0; indx < num_indxs; ++indx) {

    // push the indx onto indx vectors for each node
    for (unsigned i = 0; i < indx_type[indx]; ++i) {

      Check(indx_to_node_linkage[node_offset + i] < num_nodes);

      node_to_indx_map[indx_to_node_linkage[node_offset + i]].push_back(indx);
    }

    // increment offset
    node_offset += indx_type[indx];
  }

  Ensure(node_offset == indx_to_node_linkage.size());

  return node_to_indx_map;
}