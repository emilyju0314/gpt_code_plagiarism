RTT_Mesh_Reader::vector_vector_uint RTT_Mesh_Reader::get_element_nodes() const {
  vector_vector_uint element_nodes(rttMesh->get_dims_nsides() + rttMesh->get_dims_ncells());

  for (size_t i = 0; i < rttMesh->get_dims_nsides(); i++)
    element_nodes[i] = rttMesh->get_sides_nodes(i);

  size_t const nsides = rttMesh->get_dims_nsides();
  for (size_t i = 0; i < rttMesh->get_dims_ncells(); i++) {
    element_nodes[i + nsides] = rttMesh->get_cells_nodes(i);
  }

  return element_nodes;
}