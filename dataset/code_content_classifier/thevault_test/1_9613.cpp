void Tool_autoaccid::initialize(void) {
	m_visualQ   = getBoolean("visual");
	m_hiddenQ   = getBoolean("suppressed");
	m_removeQ   = getBoolean("remove");
	m_cautionQ  = getBoolean("keep-cautionary");
}