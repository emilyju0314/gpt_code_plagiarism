void GridSlice::transferSides(HumdrumLine& line, GridStaff& sides,
		const string& empty, int maxxcount, int maxvcount, int maxhcount, int maxfcount) {

	// existing verses:
	int vcount = sides.getVerseCount();

	// int xcount = sides.getXmlidCount();
	int fcount = sides.getFiguredBassCount();

	// there should not be any harmony attached to staves
	// (only to parts, so hcount should only be zero):
	int hcount = sides.getHarmonyCount();
	HTp newtoken;

	if (maxxcount > 0) {
		HTp xmlid = sides.getXmlid();
		if (xmlid) {
			line.appendToken(xmlid);
			sides.detachXmlid();
		} else {
			newtoken = new HumdrumToken(empty);
			line.appendToken(newtoken);
		}
	}

	for (int i=0; i<vcount; i++) {
		HTp verse = sides.getVerse(i);
		if (verse) {
			line.appendToken(verse);
			sides.setVerse(i, NULL); // needed to avoid double delete
		} else {
			newtoken = new HumdrumToken(empty);
			line.appendToken(newtoken);
		}
	}

	if (vcount < maxvcount) {
		for (int i=vcount; i<maxvcount; i++) {
			newtoken = new HumdrumToken(empty);
			line.appendToken(newtoken);
		}
	}

	for (int i=0; i<hcount; i++) {
		HTp harmony = sides.getHarmony();
		if (harmony) {
			line.appendToken(harmony);
			sides.detachHarmony();
		} else {
			newtoken = new HumdrumToken(empty);
			line.appendToken(newtoken);
		}
	}

	for (int i=0; i<fcount; i++) {
		HTp figuredbass = sides.getFiguredBass();
		if (figuredbass) {
			line.appendToken(figuredbass);
			sides.detachFiguredBass();
		} else {
			newtoken = new HumdrumToken(empty);
			line.appendToken(newtoken);
		}
	}

	if (hcount < maxhcount) {
		for (int i=hcount; i<maxhcount; i++) {
			newtoken = new HumdrumToken(empty);
			line.appendToken(newtoken);
		}
	}

	if (fcount < maxfcount) {
		for (int i=fcount; i<maxfcount; i++) {
			newtoken = new HumdrumToken(empty);
			line.appendToken(newtoken);
		}
	}

}