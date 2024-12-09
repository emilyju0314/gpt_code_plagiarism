bool HumTool::hasError(void) {
	if (hasParseError()) {
		return true;
	}
	return m_error_text.str().empty() ? false : true;
}