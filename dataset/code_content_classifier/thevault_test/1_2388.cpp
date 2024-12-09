std::vector<std::vector<unsigned>> Hex_Mesh_Reader::get_element_nodes() const {
  // Collate the interior, vacuum, and reflective mesh elements into one
  // vector. Note that the order is important as we will rely on it later to
  // output the element set data.

  // Alternatively, the private data of the class could be changed so that the
  // work done here is done in the constructor.  This would be more efficient if
  // this is going to be used repetitively.
  std::vector<std::vector<unsigned>> result;
  for (unsigned i = 0; i < ncells; i++)
    result.push_back(ipar[i]);
  for (size_t i = 0; i < nvb_faces; i++)
    result.push_back(ipar_vb[i]);
  for (size_t i = 0; i < nrb_faces; i++)
    result.push_back(ipar_rb[i]);
  return result;
}