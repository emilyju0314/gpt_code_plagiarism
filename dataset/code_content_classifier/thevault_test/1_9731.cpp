void Tool_semitones::showCount(void) {
	m_humdrum_text << "!!semitone_count: " << m_markCount;
	if (m_repeatQ) {
		m_humdrum_text << " REPEAT";
	}
	if (m_upQ) {
		m_humdrum_text << " UP";
	}
	if (m_downQ) {
		m_humdrum_text << " DOWN";
	}
	if (m_stepQ) {
		m_humdrum_text << " STEP";
	}
	if (m_leapQ) {
		m_humdrum_text << " LEAP";
	}
	if ((m_stepQ || m_leapQ) && (m_leap != 3)) {
		m_humdrum_text << " JUMP:" << m_leap;
	}
	if (m_marker != "@") {
		m_humdrum_text << " MARK:" << m_marker;
	}
	m_humdrum_text << '\n';
}