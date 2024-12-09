std::string MuseRecord::getDirectionText(void) {
	int length = (int)m_recordString.size();
	if (length < 25) {
		// no text
		return "";
	}
	return trimSpaces(m_recordString.substr(24));
}