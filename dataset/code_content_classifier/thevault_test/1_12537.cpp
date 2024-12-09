int ztlsContextImpl::Send(const uint8_t * buffer, size_t size, uint8_t type)
{
	if (!isReady())
		return 0;

	//### check for key expiring
	uint8_t * workBuf = SendBuffer();
	CIPHER * enc_context = (CIPHER*)Ciphers(0);
	int res = 0;
	do {
		uint32_t l = size > sendBufferSize ? sendBufferSize : size;

		//### check for buffer size

		uint8_t * begin = align(workBuf + 16, 16) - CIPHER::lead;
		//### check (CIPHER::lead + 5 < 16)

		int32_t pl = enc_context->WrapPacket(begin, type, buffer, l);

		// space for the header
		begin -= 5;

		TlsHead *sendHead = (TlsHead*)begin;
		sendHead->type = type;
		sendHead->version_major = 3;
		sendHead->version_minor = 3;
		sendHead->length = bswap16(pl);

		int r = ::ztlsLinkSend(socket, (const uint8_t*)begin, pl + 5);
		if (r <= 0)
			return r;

		size -= l;
		buffer += l;
	} while (size > 0);

	return 1;
}