void Tool_extract::dealWithSecondarySubspine(vector<int>& field, vector<int>& subfield,
		vector<int>& model, int targetindex, HumdrumFile& infile, int line,
		int spine, int submodel) {

	int& i = line;
	int& j = spine;

	HumRegex hre;
	string buffer;
	if (infile[line].isLocalComment()) {
		if ((submodel == 'n') || (submodel == 'r')) {
			m_humdrum_text << "!";
		} else {
			m_humdrum_text << infile.token(i, j);
		}
	} else if (infile[line].isBarline()) {
		m_humdrum_text << infile.token(i, j);
	} else if (infile[line].isInterpretation()) {
		if ((submodel == 'n') || (submodel == 'r')) {
			m_humdrum_text << "*";
		} else {
			m_humdrum_text << infile.token(i, j);
		}
	} else if (infile[line].isData()) {
		if (submodel == 'n') {
			m_humdrum_text << ".";
		} else if (submodel == 'r') {
			if (*infile.token(i, j) == ".") {
				m_humdrum_text << ".";
			} else if (infile.token(i, j)->find('q') != string::npos) {
				m_humdrum_text << ".";
			} else if (infile.token(i, j)->find('Q') != string::npos) {
				m_humdrum_text << ".";
			} else {
				buffer = *infile.token(i, j);
				if (hre.search(buffer, "{")) {
					m_humdrum_text << "{";
				}
				// remove secondary chord notes:
				hre.replaceDestructive(buffer, "", " .*");
				// remove unnecessary characters (such as stem direction):
				hre.replaceDestructive(buffer, "",
						"[^}pPqQA-Ga-g0-9.;%#nr-]", "g");
				// change pitch to rest:
				hre.replaceDestructive(buffer, "[A-Ga-g#n-]+", "r");
				// add editorial marking unless -Y option is given:
				if (editorialInterpretation != "") {
					if (hre.search(buffer, "rr")) {
						 hre.replaceDestructive(buffer, editorialInterpretation, "(?<=rr)");
						 hre.replaceDestructive(buffer, "r", "rr");
					} else {
						 hre.replaceDestructive(buffer, editorialInterpretation, "(?<=r)");
					}
				}
				m_humdrum_text << buffer;
			}
		} else {
			m_humdrum_text << infile.token(i, j);
		}
	} else {
		m_error_text << "Should not get to this line of code" << endl;
		return;
	}
}