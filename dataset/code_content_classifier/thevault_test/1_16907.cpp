int MIME_skip_lws_comments(int len, const char* data)
	{
	int i = 0;
	while ( i < len )
		{
		if ( is_lws(data[i]) )
			++i;
		else
			{
			if ( data[i] == '(' )
				i += MIME_skip_comments(len - i, data + i);
			else
				return i;
			}
		}

	return len;
	}