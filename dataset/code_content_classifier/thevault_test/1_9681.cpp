void GridSlice::transferSides(HumdrumLine& line, GridPart& sides,
		int partindex, const string& empty, int maxxcount, int maxvcount,
		int maxhcount, int maxdcount, int maxfcount) {

	int xcount = sides.getXmlidCount();
	int hcount = sides.getHarmonyCount();
	int vcount = sides.getVerseCount();

	HTp newtoken;

	if (xcount > 0) {
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
			sides.detachHarmony();
		} else {
			newtoken = new HumdrumToken(empty);
			line.appendToken(newtoken);
		}
	}

	for (int i=vcount; i<maxvcount; i++) {
		newtoken = new HumdrumToken(empty);
		line.appendToken(newtoken);
	}

	if (maxdcount > 0) {
		HTp dynamics = sides.getDynamics();
		if (dynamics) {
			line.appendToken(dynamics);
			sides.detachDynamics();
		} else {
			newtoken = new HumdrumToken(empty);
			line.appendToken(newtoken);
		}
	}

	if (maxfcount > 0) {
		HTp figuredbass = sides.getFiguredBass();
		if (figuredbass) {
			line.appendToken(figuredbass);
			sides.detachFiguredBass();
		} else {
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

	for (int i=hcount; i<maxhcount; i++) {
		newtoken = new HumdrumToken(empty);
		line.appendToken(newtoken);
	}
}