string MuseRecord::getTimeModificationRightField(void) {
	string output = getTimeModificationField();
	output = output[2];
	return output;
}