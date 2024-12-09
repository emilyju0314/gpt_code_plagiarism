compressed_sparse_row_graph(construct_inplace_from_sources_and_targets_t,
                              std::vector<vertex_descriptor>& sources,
                              std::vector<vertex_descriptor>& targets,
                              vertices_size_type numverts,
                              const GraphProperty& prop = GraphProperty())
    : inherited_vertex_properties(numverts), m_property(prop)
  {
    m_forward.assign_sources_and_targets_global(sources, targets, numverts, boost::identity_property_map());
  }