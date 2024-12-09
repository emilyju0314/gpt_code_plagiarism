std::map<std::string, std::set<unsigned>> RTT_Mesh_Reader::get_node_sets() const {
  std::map<string, set_uint> node_sets;
  string flag_types_and_names;

  // loop over the number of node flag types.
  for (size_t type = 0; type < rttMesh->get_dims_nnode_flag_types(); type++) {
    // loop over the number of node flags for this type.
    for (size_t flag = 0; flag < rttMesh->get_dims_nnode_flags(type); flag++) {
      set_uint node_flags;
      flag_types_and_names = rttMesh->get_node_flags_flag_type(type);
      flag_types_and_names.append("/");
      flag_types_and_names += rttMesh->get_node_flags_flag_name(type, flag);
      int flag_number = rttMesh->get_node_flags_flag_number(type, flag);
      // loop over the nodes.
      for (unsigned node = 0; node < rttMesh->get_dims_nnodes(); node++) {
        if (flag_number == rttMesh->get_nodes_flags(node, type))
          node_flags.insert(node);
      }
      node_sets.insert(std::make_pair(flag_types_and_names, node_flags));
    }
  }
  return node_sets;
}