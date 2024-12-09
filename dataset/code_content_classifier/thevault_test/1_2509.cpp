void SideDataIDs::readKeyword(ifstream &meshfile) {
  string dummyString;

  meshfile >> dummyString;
  Insist(dummyString == "side_data_ids", "Invalid mesh file: side_data_ids block missing");
  std::getline(meshfile, dummyString);
}