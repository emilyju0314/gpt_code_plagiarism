void Tool_extract::extractFields(HumdrumFile& infile, vector<int>& field,
		vector<int>& subfield, vector<int>& model) {

	HumRegex hre;
	int start = 0;
	int target;
	int subtarget;
	int modeltarget;
	string spat;

	for (int i=0; i<infile.getLineCount(); i++) {
		if (!infile[i].hasSpines()) {
			m_humdrum_text << infile[i] << '\n';
			continue;
		}

		if (infile[i].isManipulator()) {
			dealWithSpineManipulators(infile, i, field, subfield, model);
			continue;
		}

		start = 0;
		for (int t=0; t<(int)field.size(); t++) {
			target = field[t];
			subtarget = subfield[t];
			modeltarget = model[t];
			if (modeltarget == 0) {
				switch (subtarget) {
					 case 'a':
					 case 'b':
					    modeltarget = submodel;
					    break;
					 case 'c':
					    modeltarget = comodel;
				}
			}
			if (target == 0) {
				if (start != 0) {
					 m_humdrum_text << '\t';
				}
				start = 1;
				if (!infile[i].isManipulator()) {
					if (infile[i].isLocalComment()) {
						m_humdrum_text << "!";
					} else if (infile[i].isBarline()) {
						m_humdrum_text << infile[i].token(0);
					} else if (infile[i].isData()) {
				       m_humdrum_text << ".";
					    // interpretations handled in dealWithSpineManipulators()
					    // [obviously not, so adding a blank one here
					} else if (infile[i].isInterpretation()) {
					    m_humdrum_text << "*";
					 }
				}
			} else {
				for (int j=0; j<infile[i].getFieldCount(); j++) {
					 if (infile[i].token(j)->getTrack() != target) {
					    continue;
					 }
					 switch (subtarget) {
					 case 'a':
					    getSearchPat(spat, target, "a");
					    if (hre.search(infile.token(i,j)->getSpineInfo(), spat) ||
					          !hre.search(infile.token(i, j)->getSpineInfo(), "\\(")) {
					       if (start != 0) {
					          m_humdrum_text << '\t';
					       }
					       start = 1;
					       m_humdrum_text << infile.token(i, j);
					    }
					    break;
					 case 'b':
					    getSearchPat(spat, target, "b");
					    if (hre.search(infile.token(i, j)->getSpineInfo(), spat)) {
					       if (start != 0) {
					          m_humdrum_text << '\t';
					       }
					       start = 1;
					       m_humdrum_text << infile.token(i, j);
					    } else if (!hre.search(infile.token(i, j)->getSpineInfo(),
					          "\\(")) {
					       if (start != 0) {
					          m_humdrum_text << '\t';
					       }
					       start = 1;
					       dealWithSecondarySubspine(field, subfield, model, t,
					             infile, i, j, modeltarget);
					    }
					    break;
					 case 'c':
					    if (start != 0) {
					       m_humdrum_text << '\t';
					    }
					    start = 1;
					    dealWithCospine(field, subfield, model, t, infile, i, j,
					       modeltarget, modeltarget, cointerp);
					    break;
					 default:
					    if (start != 0) {
					       m_humdrum_text << '\t';
					    }
					    start = 1;
					    m_humdrum_text << infile.token(i, j);
					 }
				}
			}
		}
		if (start != 0) {
			m_humdrum_text << endl;
		}
	}
}