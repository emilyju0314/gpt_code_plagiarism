int GridSlice::getFiguredBassCount(int partindex, int staffindex) {
	HumGrid* grid = getOwner();
	if (!grid) {
		return 0;
	}
	if (staffindex >= 0) {
		// ignoring staff-level figured bass
		return 0;
	} else {
		return grid->getFiguredBassCount(partindex);
	}
}