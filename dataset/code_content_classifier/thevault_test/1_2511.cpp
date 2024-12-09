void SideDataIDs::readEndKeyword(ifstream &meshfile) {
  string dummyString;

  meshfile >> dummyString;
  Insist(dummyString == "end_side_data_ids", "Invalid mesh file: side_data_ids block missing end");
  std::getline(meshfile, dummyString); // read and discard blank line.
}