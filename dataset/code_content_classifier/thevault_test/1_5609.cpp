::FLAC__StreamDecoderReadStatus File::read_callback(FLAC__byte buffer[], size_t *bytes)
		{
			(void)buffer, (void)bytes;
			FLAC__ASSERT(false);
			return ::FLAC__STREAM_DECODER_READ_STATUS_ABORT; // double protection
		}