void MIME_Entity::DecodeDataLine(int len, const char* data, bool trailing_CRLF)
	{
	if ( ! mime_submit_data )
		return;

	switch ( content_encoding )
		{
		case CONTENT_ENCODING_QUOTED_PRINTABLE:
			DecodeQuotedPrintable(len, data);
			break;

		case CONTENT_ENCODING_BASE64:
			DecodeBase64(len, data);
			break;

		case CONTENT_ENCODING_7BIT:
		case CONTENT_ENCODING_8BIT:
		case CONTENT_ENCODING_BINARY:
		case CONTENT_ENCODING_OTHER:
			DecodeBinary(len, data, trailing_CRLF);
			break;
		}
	FlushData();
	}