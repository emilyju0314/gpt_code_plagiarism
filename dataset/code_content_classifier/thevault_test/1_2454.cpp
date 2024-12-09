void RTT_Format_Reader::createMembers() {
  spNodeFlags = std::make_shared<NodeFlags>(dims);
  spSideFlags = std::make_shared<SideFlags>(dims);
  spCellFlags = std::make_shared<CellFlags>(dims);
  spNodeDataIds = std::make_shared<NodeDataIDs>(dims);
  spSideDataIds = std::make_shared<SideDataIDs>(dims);
  spCellDataIds = std::make_shared<CellDataIDs>(dims);
  spCellDefs = std::make_shared<CellDefs>(dims);
  spNodes = std::make_shared<Nodes>(*spNodeFlags, dims);
  spSides = std::make_shared<Sides>(*spSideFlags, dims, *spCellDefs);
  spCells = std::make_shared<Cells>(*spCellFlags, dims, *spCellDefs);
  spNodeData = std::make_shared<NodeData>(dims);
  spSideData = std::make_shared<SideData>(dims);
  spCellData = std::make_shared<CellData>(dims);
}