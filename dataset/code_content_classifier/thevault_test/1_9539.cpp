void Tool_strophe::initialize(void) {
	m_listQ     = getBoolean("list");
	m_markQ     = getBoolean("m");
	m_marker    = getString("marker");
	m_color     = getString("color");
}