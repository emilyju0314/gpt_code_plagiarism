void Tool_shed::initialize(void) {
	if (getBoolean("expression")) {
		string value = getString("expression");
		parseExpression(value);
	}
	m_exclusion = getString("exclusion-expression");

	if (getBoolean("X")) {
		m_xInterp = getExInterp(getString("X"));
	}
	if (getBoolean("Y")) {
		m_yInterp = getExInterp(getString("Y"));
	}
	if (getBoolean("Z")) {
		m_zInterp = getExInterp(getString("Z"));
	}
}