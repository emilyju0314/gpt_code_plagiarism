int NoteCell::getFieldIndex(void) {
	if (!m_token) {
		return -1;
	}
	return m_token->getFieldIndex();
}