void MuseRecordBasic::shrink(void) {
	int i = (int)m_recordString.size() - 1;
	while (i >= 0 && m_recordString[i] == ' ') {
		m_recordString.resize((int)m_recordString.size()-1);
		i--;
	}
}