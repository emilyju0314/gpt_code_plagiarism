static int is_ident(char *tok)
{
	char *p;

	if( !isalpha(tok[0]) )
		return FALSE;

	for(p=tok+1; *p; p++) {
		if( !isalnum(*p) && strchr("_-", *p)==NULL )
			return FALSE;
	}
	return TRUE;
}