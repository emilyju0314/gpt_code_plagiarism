void Tool_strophe::markWithColor(HumdrumFile& infile) {
	int counter = 0;
	for (int i=0; i<infile.getStropheCount(); i++) {
		HTp strophestart = infile.getStropheStart(i);
		HTp stropheend = infile.getStropheEnd(i);
		counter += markStrophe(strophestart, stropheend);
	}
	if (counter) {
		string rdf = "!!!RDF**kern: ";
		rdf += m_marker;
		rdf += " = marked note, strophe";
		if (m_color != "red") {
			rdf += ", color=\"";
			rdf += m_color;
			rdf += "\"";
		}
		infile.appendLine(rdf);
		infile.createLinesFromTokens();
	}
}