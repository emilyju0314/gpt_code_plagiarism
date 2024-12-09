std::vector<Element_Definition::Element_Type> Hex_Mesh_Reader::get_element_types() const {
  Element_Definition::Element_Type d1, d2;
  switch (ndim) {
  case (1):
    d1 = Element_Definition::BAR_2;
    d2 = Element_Definition::NODE;
    break;
  case (2):
    d1 = Element_Definition::QUAD_4;
    d2 = Element_Definition::BAR_2;
    break;
  case (3):
    d1 = Element_Definition::HEXA_8;
    d2 = Element_Definition::QUAD_4;
    break;
  default:
    Insist(false, "Dimension index out of range!");
  }
  std::vector<Element_Definition::Element_Type> tmp;
  for (unsigned i = 0; i < ncells; i++)
    tmp.push_back(d1);
  for (size_t i = 0; i < nvb_faces + nrb_faces; i++)
    tmp.push_back(d2);
  return tmp;
}