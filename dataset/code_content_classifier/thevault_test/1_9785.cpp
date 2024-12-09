bool HumdrumFileBase::analyzeSpines(void) {
	vector<string> datatype;
	vector<string> sinfo;
	vector<vector<HTp> > lastspine;
	m_trackstarts.resize(0);
	m_trackends.resize(0);
	addToTrackStarts(NULL);

	bool init = false;
	int i, j;
	for (i=0; i<getLineCount(); i++) {
		if (!m_lines[i]->hasSpines()) {
			m_lines[i]->token(0)->setFieldIndex(0);
			continue;
		}
		if ((init == false) && !m_lines[i]->isExclusive()) {
			stringstream err;
			err << "Error on line: " << (i+1) << ':' << endl;
			err << "   Data found before exclusive interpretation" << endl;
			err << "   LINE: " << *m_lines[i];
			return setParseError(err);
		}
		if ((init == false) && m_lines[i]->isExclusive()) {
			// first line of data in file.
			init = true;
			datatype.resize(m_lines[i]->getTokenCount());
			sinfo.resize(m_lines[i]->getTokenCount());
			lastspine.resize(m_lines[i]->getTokenCount());
			for (j=0; j<m_lines[i]->getTokenCount(); j++) {
				datatype[j] = m_lines[i]->getTokenString(j);
				addToTrackStarts(m_lines[i]->token(j));
				sinfo[j]    = to_string(j+1);
				m_lines[i]->token(j)->setSpineInfo(sinfo[j]);
				m_lines[i]->token(j)->setFieldIndex(j);
				lastspine[j].push_back(m_lines[i]->token(j));
			}
			continue;
		}
		if ((int)datatype.size() != m_lines[i]->getTokenCount()) {
			stringstream err;
			err << "Error on line " << (i+1) << ':' << endl;
			err << "   Expected " << datatype.size() << " fields,"
			    << "    but found " << m_lines[i]->getTokenCount();
			err << "\nLine is: " << m_lines[i] << endl;
			if (i > 0) {
				cerr << "Previous line is: " << m_lines[i-1] << endl;
			}
			return setParseError(err);
		}
		for (j=0; j<m_lines[i]->getTokenCount(); j++) {
			m_lines[i]->token(j)->setSpineInfo(sinfo[j]);
			m_lines[i]->token(j)->setFieldIndex(j);
		}
		if (!m_lines[i]->isManipulator()) {
			continue;
		}
		if (!adjustSpines(*m_lines[i], datatype, sinfo)) { return isValid(); }
	}
	return isValid();
}