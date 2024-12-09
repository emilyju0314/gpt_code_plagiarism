int GridSlice::getXmlidCount(int partindex, int staffindex) {
	HumGrid* grid = getOwner();
	if (!grid) {
		return 0;
	}
	// should probably adjust to staffindex later:
	return grid->getXmlidCount(partindex);
}