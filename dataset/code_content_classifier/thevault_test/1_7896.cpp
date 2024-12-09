char *Phascii_MakeString(char *buf)
{
	char *p, *q, *newp;
	int count;

	count = 0;
	for(p=buf; *p; p++) {
		count++;
		if( *p == '\a' ) count++;
		else if( *p == '\b' ) count++;
		else if( *p == '\f' ) count++;
		else if( *p == '\n' ) count++;
		else if( *p == '\r' ) count++;
		else if( *p == '\t' ) count++;
		else if( *p == '\v' ) count++;
		else if( *p == '"' ) count++;
		else if( *p == '\\' ) count++;
	}

	newp = (char*) malloc( count+3 );

	p=buf;
	q=newp;
	*q++ = '"';
	while( *p ) {
		if( strchr("\a\b\f\n\r\t\v\"\\", *p) ) {
			*q++ = '\\';

			switch( *p ) {
			case '\a':	*q++ = 'a'; break;
			case '\b':	*q++ = 'b'; break;
			case '\f':	*q++ = 'f'; break;
			case '\n':	*q++ = 'n'; break;
			case '\r':	*q++ = 'r'; break;
			case '\t':	*q++ = 't'; break;
			case '\v':	*q++ = 'v'; break;
			case '"':	*q++ = '"'; break;
			case '\\':	*q++ = '\\'; break;
			}
			p++;
		} else
			*q++ = *p++;
	}
	*q++ = '"';
	*q = '\0';

	return newp;
}