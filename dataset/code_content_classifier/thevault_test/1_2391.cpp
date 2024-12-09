bool Hex_Mesh_Reader::invariant() const {
  bool ldum = check_dims() && (point_coords.size() == npoints) && (ipar.size() == ncells) &&
              (imat_index.size() == ncells) && (irgn_vb_index.size() == nvb_faces) &&
              (ipar_vb.size() == nvb_faces) && (ipar_rb.size() == nrb_faces);

  for (unsigned i = 0; i < ncells; ++i) {
    ldum = ldum && ipar[i].size() == nvrtx;
    for (size_t j = 0; j < nvrtx; ++j)
      ldum = ldum && ipar[i][j] < npoints;
  }
  for (size_t i = 0; i < nvb_faces; ++i) {
    ldum = ldum && ipar_vb[i].size() == nvrpf;
    for (size_t j = 0; j < nvrpf; ++j)
      ldum = ldum && ipar_vb[i][j] < npoints;
  }
  for (size_t i = 0; i < nrb_faces; ++i) {
    ldum = ldum && ipar_rb[i].size() == nvrpf;
    for (size_t j = 0; j < nvrpf; ++j)
      ldum = ldum && ipar_rb[i][j] < npoints;
  }
  return ldum;
}