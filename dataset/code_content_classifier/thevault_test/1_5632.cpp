::FLAC__StreamEncoderWriteStatus File::write_callback(const FLAC__byte buffer[], size_t bytes, unsigned samples, unsigned current_frame)
		{
			(void)buffer, (void)bytes, (void)samples, (void)current_frame;
			FLAC__ASSERT(false);
			return ::FLAC__STREAM_ENCODER_WRITE_STATUS_FATAL_ERROR; // double protection
		}