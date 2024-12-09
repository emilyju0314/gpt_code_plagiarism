void Tool_modori::initialize(void) {
	m_infoQ = getBoolean("info");
	m_modernQ = getBoolean("modern");
	m_originalQ = getBoolean("original");
	if (m_modernQ && m_originalQ) {
		// if both options are used, ignore -m:
		m_modernQ = false;
	}
	m_nokeyQ         = getBoolean("no-key");
	m_noclefQ        = getBoolean("no-clef");
	m_nomensurationQ = getBoolean("no-mensuration");
}