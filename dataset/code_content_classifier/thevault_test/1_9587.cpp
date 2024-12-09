string MuseRecord::getTimeModificationLeftField(void) {
	string output = getTimeModificationField();
	output.resize(1);
	return output;
}