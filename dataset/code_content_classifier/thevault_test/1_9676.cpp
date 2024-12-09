HumNum GridSlice::getMeasureTimestamp(void) {
	GridMeasure* measure = getMeasure();
	if (!measure) {
		return -1;
	} else {
		return measure->getTimestamp();
	}
}