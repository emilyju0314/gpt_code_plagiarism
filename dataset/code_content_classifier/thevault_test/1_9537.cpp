void Tool_humsheet::initialize(void) {
	m_idQ         = getBoolean("id");
	m_htmlQ       = getBoolean("html");
	m_zebraQ      = getBoolean("zebra");
	m_zebra2Q     = getBoolean("zebra2");
	m_exinterpQ   = !getBoolean("no-exinterp");
	m_javascriptQ = !getBoolean("no-javascript");
	m_tabindexQ   = getBoolean("tab-index");
}