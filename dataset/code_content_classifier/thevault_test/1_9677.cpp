int GridSlice::getHarmonyCount(int partindex, int staffindex) {
	HumGrid* grid = getOwner();
	if (!grid) {
		return 0;
	}
	if (staffindex >= 0) {
		// ignoring staff-level harmony
		return 0;
	} else {
		return grid->getHarmonyCount(partindex);
	}
}