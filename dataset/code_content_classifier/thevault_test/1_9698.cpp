bool Tool_chantize::hasDiamondNotes(HumdrumFile& infile) {
	for (int i=0; i<infile.getLineCount(); i++) {
		HumNum duration = infile[i].getDuration();
		if (duration < 1) {
			return true;
		}
	}
	return false;
}