bool StringIsBlank(const char *str)
{
	const char *p;
	ASSERT( str != NULL );

	p = str;
	while( *p ) {
		if( ! isspace(*p) )
			return FALSE;
		p++;
	}

	return TRUE;
}