int Tool_autostem::getVoice(HumdrumFile& infile, int row, int col) {
	int output = 0;
	int tcount = 0;
	int track = infile.token(row, col)->getTrack();
	int j;
	int testtrack;
	for (j=0; j<infile[row].getFieldCount(); j++) {
		testtrack = infile.token(row, j)->getTrack();
		if (testtrack == track) {
			tcount++;
		}
		if (col == j) {
			output = tcount;
		}
	}
	if (tcount == 1) {
		output = 0;
	}
	return output;
}