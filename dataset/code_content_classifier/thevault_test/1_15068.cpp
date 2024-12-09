UINT32 SoundPlayFromSmackBuff(const char* name, UINT8 channels, UINT8 depth, UINT32 rate, std::vector<UINT8>& buf, UINT32 volume, UINT32 pan, UINT32 loop, void (*end_callback)(void*), void* data)
{
	ma_format format;

	if (buf.empty()) return SOUND_ERROR;

	//Originaly Sound Blaster could only play mono unsigned 8-bit PCM data.
	//Later it became capable of playing 16-bit audio data, but needed to be signed and LSB.
	//They were the de facto standard so I'm assuming smacker uses the same.
	if (depth == 8) format = ma_format_u8;
	else if (depth == 16) format = ma_format_s16;
	else return SOUND_ERROR;

	UINT32 uiBufferSize = buf.size();
	UINT8* inMemoryBuffer = new UINT8[uiBufferSize]{};
	memcpy(inMemoryBuffer, buf.data(), uiBufferSize);
	if (format == ma_format_s16) {
		// We expect the Endianess for the Smacker buffer to be little endian, but ma_format_s16 is native endian, so we need to do some conversion
		convertLittleEndianBufferToNativeEndianU16(inMemoryBuffer, uiBufferSize);
	}

	SAMPLETAG* s = SoundLoadBuffer(inMemoryBuffer, uiBufferSize, format, channels, rate);
	if (s == NULL) return SOUND_ERROR;

	s->pName           = name;
	s->uiPanMax        = 64;
	s->uiMaxInstances  = 1;

	SOUNDTAG* const channel = SoundGetFreeChannel();
	if (channel == NULL) return SOUND_ERROR;

	return SoundStartSample(s, channel, volume, pan, loop, end_callback, data);
}