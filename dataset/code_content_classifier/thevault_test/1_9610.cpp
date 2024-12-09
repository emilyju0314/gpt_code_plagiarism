string HumTool::getError(void) {
	string output = getParseError();
	output += m_error_text.str();
	return output;
}