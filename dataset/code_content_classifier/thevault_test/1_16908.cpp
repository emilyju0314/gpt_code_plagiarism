String* MIME_decode_quoted_pairs(data_chunk_t buf)
	{
	const char* data = buf.data;
	char* dest = new char[buf.length + 1];
	int j = 0;
	for ( int i = 0; i < buf.length; ++i )
		if ( data[i] == '\\' )
			{
			if ( ++i < buf.length )
				dest[j++] = data[i];
			else
				{
				// a trailing '\' -- don't know what
				// to do with it -- ignore it.
				}
			}
		else
			dest[j++] = data[i];
	dest[j] = 0;

	return new String(true, (byte_vec)dest, j);
	}