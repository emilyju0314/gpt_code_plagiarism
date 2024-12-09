RTT_Format_Reader::RTT_Format_Reader(string RTT_File)
    : header(), dims(), spNodeFlags(), spSideFlags(), spCellFlags(), spNodeDataIds(),
      spSideDataIds(), spCellDataIds(), spCellDefs(), spNodes(), spSides(), spCells(), spNodeData(),
      spSideData(), spCellData() {
  readMesh(std::move(RTT_File));
}