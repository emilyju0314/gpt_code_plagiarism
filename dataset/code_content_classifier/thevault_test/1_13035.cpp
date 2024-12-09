void CPlayer::setStream(const Uint8 *stream, const unsigned streamLen)
{
	cleanStream();

	m_StreamLen = streamLen;
	m_Stream = new Uint8 [m_StreamLen];

	if (memcpy_s(m_Stream, m_StreamLen, stream, m_StreamLen)) {
		cleanStream();
	}
}