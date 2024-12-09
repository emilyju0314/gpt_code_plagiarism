void NodeData::readKeyword(ifstream &meshfile) {
  string dummyString;

  meshfile >> dummyString;
  Insist(dummyString == "nodedat", "Invalid mesh file: nodedat block missing");
  std::getline(meshfile, dummyString);
}