void RTT_Format_Reader::readMesh(const string &RTT_File) {
  const char *file = RTT_File.c_str();
  ifstream meshfile(file, std::ios::in);
  if (!meshfile) {
    std::ostringstream buffer;
    buffer << "File " << RTT_File << " could not be opened\n";
    throw std::invalid_argument(buffer.str());
  }

  try {
    readKeyword(meshfile);
    header.readHeader(meshfile);
    dims.readDims(meshfile);
    createMembers();
    readFlagBlocks(meshfile);
    readDataIDs(meshfile);
    spCellDefs->readCellDefs(meshfile);
    spNodes->readNodes(meshfile);
    spSides->readSides(meshfile);
    spCells->readCells(meshfile);
    spNodeData->readNodeData(meshfile);
    spSideData->readSideData(meshfile);
    spCellData->readCellData(meshfile);
    readEndKeyword(meshfile);
  } catch (rtt_dsxx::assertion &as) {
    std::cout << "Assertion thrown: " << as.what() << std::endl;
    Insist(false, as.what());
  }
}