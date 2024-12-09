string HumTool::getAllText(void) {
	return  m_humdrum_text.str()
	      + m_json_text.str()
	      + m_free_text.str();
}