bool GridSlice::hasSpines(void) {
	SliceType type = getType();
	if (type < SliceType::_Spined) {
		return true;
	} else {
		return false;
	}
}