HumNum NoteCell::getDuration(void) {
	if (!m_owner) {
		return Convert::recipToDuration(m_token);
	}
	return m_owner->getNoteDuration(getVoiceIndex(), getSliceIndex());
}