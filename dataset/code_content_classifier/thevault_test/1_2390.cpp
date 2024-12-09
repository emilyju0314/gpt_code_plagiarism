std::vector<Element_Definition::Element_Type> Hex_Mesh_Reader::get_unique_element_types() const {
  std::vector<Element_Definition::Element_Type> tmp;
  tmp.push_back(Element_Definition::NODE);
  tmp.push_back(Element_Definition::BAR_2);
  switch (ndim) {
  case (1):
    break;
  case (2):
    tmp.push_back(Element_Definition::QUAD_4);
    break;
  case (3):
    tmp.push_back(Element_Definition::QUAD_4);
    tmp.push_back(Element_Definition::HEXA_8);
    break;
  default:
    Insist(false, "Dimension index out of range!");
  }
  return tmp;
}