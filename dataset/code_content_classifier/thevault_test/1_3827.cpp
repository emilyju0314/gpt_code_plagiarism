bool V_TokenWaiting( const char *buffer )
{
	const char *p = buffer;
	while ( *p && *p != '\n' )
	{
		if ( !V_isspace( *p ) || V_isalnum( *p ) )
			return true;
		p++;
	}

	return false;
}