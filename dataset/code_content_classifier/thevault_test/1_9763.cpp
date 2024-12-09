void HumdrumFileBase::clear(void) {
	// delete memory allocation:
	for (int i=0; i<(int)m_lines.size(); i++) {
		if (m_lines[i] != NULL) {
			delete m_lines[i];
			m_lines[i] = NULL;
		}
	}
	m_lines.clear();

	// clear state variables which are now invalid:
	m_trackstarts.clear();
	m_trackends.clear();
	m_barlines.clear();
	m_ticksperquarternote = -1;
	m_idprefix.clear();
	m_strand1d.clear();
	m_strand2d.clear();
	m_strophes1d.clear();
	m_strophes2d.clear();
	m_filename.clear();
	m_segmentlevel = 0;
	m_analyses.clear();
}