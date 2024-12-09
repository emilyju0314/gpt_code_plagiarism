void Tool_flipper::initialize(void) {
	m_allQ         = getBoolean("all");
	m_keepQ        = getBoolean("keep");
	m_kernQ        = true;
	m_stropheQ     = getBoolean("strophe");
	m_interp       = getString("interp");
	if (m_interp != "kern") {
		m_kernQ = false;
	}
}