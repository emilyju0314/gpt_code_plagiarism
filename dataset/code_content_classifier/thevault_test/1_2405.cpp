bool RTT_Mesh_Reader::invariant() const {
  bool test = (rttMesh->get_dims_ndim() > 0) && (rttMesh->get_dims_nnodes() > 0) &&
              (rttMesh->get_dims_nsides() > 0) && (rttMesh->get_dims_ncells() > 0) &&
              (rttMesh->get_dims_ncell_defs() > 0) && (rttMesh->get_dims_nside_types() > 0) &&
              (rttMesh->get_dims_ncell_types() > 0) &&
              (rttMesh->get_dims_ncell_defs() >= rttMesh->get_dims_nside_types()) &&
              (rttMesh->get_dims_ncell_defs() >= rttMesh->get_dims_ncell_types());
  return test;
}