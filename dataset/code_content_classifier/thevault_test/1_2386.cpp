void NodeData::readEndKeyword(ifstream &meshfile) {
  string dummyString;

  meshfile >> dummyString;
  Insist(dummyString == "end_nodedat", "Invalid mesh file: nodedat block missing end");
  std::getline(meshfile, dummyString); // read and discard blank line.
}