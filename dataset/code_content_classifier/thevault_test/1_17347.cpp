int Match::getDifference() {
	int difference = 0;
	if (offsets != NULL) {
		for (int offsetIndex = 0; offsetIndex < offsets->size; offsetIndex++) {
			difference += offsets->firstOffset[offsetIndex].difference;
		}
	}
	return difference;
}