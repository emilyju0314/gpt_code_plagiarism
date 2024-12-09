void SideDataIDs::readData(ifstream &meshfile) {
  int dataIDNum;
  string dummyString;

  for (unsigned i = 0; i < static_cast<unsigned int>(dims.get_nside_data()); ++i) {
    Check(i < names.size() && i < units.size());
    meshfile >> dataIDNum >> names[i] >> units[i];
    Insist(static_cast<unsigned int>(dataIDNum) == i + 1,
           "Invalid mesh file: side data ID out of order");
    std::getline(meshfile, dummyString);
  }
}