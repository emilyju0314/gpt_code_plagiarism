SamSiteModel::SamSiteModel(uint8_t sectorId_, std::array<GridNo, 2> gridNos_)
	: sectorId(sectorId_), gridNos(gridNos_) 
{
	Assert(gridNos[0] > gridNos[1]);
	graphicIndex = (gridNos[0] - gridNos[1] == WORLD_COLS) ? SAM_GRAPHIC_INDEX_NE_SW : SAM_GRAPHIC_INDEX_NW_SE;
}