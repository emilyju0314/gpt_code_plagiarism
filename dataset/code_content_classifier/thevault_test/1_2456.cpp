void RTT_Format_Reader::readDataIDs(ifstream &meshfile) {
  spNodeDataIds->readDataIDs(meshfile);
  spSideDataIds->readDataIDs(meshfile);
  spCellDataIds->readDataIDs(meshfile);
}