void NodeData::readData(ifstream &meshfile) {
  string dummyString;
  size_t nodeNum;

  for (size_t i = 0; i < dims.get_nnodes(); ++i) {
    meshfile >> nodeNum;
    Insist(nodeNum == i + 1, "Invalid mesh file: node data index out of order");
    for (size_t j = 0; j < dims.get_nnode_data(); ++j)
      meshfile >> data[i][j];
    std::getline(meshfile, dummyString);
  }
}