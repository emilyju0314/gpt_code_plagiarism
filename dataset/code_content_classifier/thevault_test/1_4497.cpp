int CEncoder::GetBlockAligned(const unsigned char ** pblock, int* piBufferSize, const long& cbAlign)
{
	ASSERT(piBufferSize);
    if (!pgf || !m_outFrameBuf || !pblock)
        return -1;

	int iBlockLen = m_outOffset - m_outReadOffset;
	ASSERT(iBlockLen >= 0);
	
	if(!m_bFinished)
	{
		if(cbAlign > 0)
			iBlockLen-=iBlockLen%cbAlign;
		*piBufferSize = iBlockLen;
	}
	else
	{
		if(cbAlign && iBlockLen%cbAlign)
		{
			*piBufferSize = iBlockLen + cbAlign - iBlockLen%cbAlign;
		}
		else
		{
			*piBufferSize = iBlockLen;
		}
	}

	if(iBlockLen) {
		*pblock = m_outFrameBuf + m_outReadOffset;
		m_outReadOffset+=iBlockLen;
	}

	return iBlockLen;
}