void CPlayer::cleanStream()
{
	if (m_Stream != NULL) {
		delete [] m_Stream;
		m_Stream = NULL;
		m_StreamLen = 0;
	}
}