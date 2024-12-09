void RTT_Format_Reader::readFlagBlocks(ifstream &meshfile) {
  spNodeFlags->readNodeFlags(meshfile);
  spSideFlags->readSideFlags(meshfile);
  spCellFlags->readCellFlags(meshfile);
}