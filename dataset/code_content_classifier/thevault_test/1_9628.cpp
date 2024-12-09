void Tool_gasparize::fixTies(HumdrumFile& infile) {
	int strands = infile.getStrandCount();
	for (int i=0; i<strands; i++) {
		HTp sstart = infile.getStrandStart(i);
		if (!sstart) {
			continue;
		}
		if (!sstart->isKern()) {
			continue;
		}
		HTp send   = infile.getStrandEnd(i);
		fixTiesForStrand(sstart, send);
	}
	fixTieStartEnd(infile);
}