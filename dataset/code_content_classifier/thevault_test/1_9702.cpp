int MuseRecordBasic::isEmpty(void) {
	for (int i=0; i<(int)m_recordString.size(); i++) {
		if (!std::isprint(m_recordString[i])) {
			continue;
		}
		if (!std::isspace(m_recordString[i])) {
			return 0;
		}
	}
	return 1;
}