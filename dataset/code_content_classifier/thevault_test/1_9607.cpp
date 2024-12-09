bool HumTool::hasAnyText(void) {
	if (m_suppress) {
		return true;
	}
	return ((!m_humdrum_text.str().empty())
			|| (!m_free_text.str().empty())
			|| (!m_json_text.str().empty()));
}