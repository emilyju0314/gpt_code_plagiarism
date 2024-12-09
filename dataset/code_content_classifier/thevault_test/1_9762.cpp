HumdrumFileBase::HumdrumFileBase(HumdrumFileBase& infile) {

	m_filename = infile.m_filename;
	m_segmentlevel = infile.m_segmentlevel;
	m_trackstarts.clear();
	m_trackends.clear();
	m_barlines.clear();
	m_ticksperquarternote = infile.m_ticksperquarternote;
	m_idprefix = infile.m_idprefix;
	m_strand1d.clear();
	m_strand2d.clear();
	m_strophes1d.clear();
	m_strophes2d.clear();
	m_quietParse = infile.m_quietParse;
	m_parseError = infile.m_parseError;
	m_displayError = infile.m_displayError;

	m_lines.resize(infile.m_lines.size());
	for (int i=0; i<(int)m_lines.size(); i++) {
		m_lines[i] = new HumdrumLine(infile.m_lines[i]->getText());
		m_lines[i]->setOwner(this);
	}

	analyzeBaseFromLines();
}