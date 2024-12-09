static int is_kforth_operand(char *word)
{
	int len;
	char *w;

	ASSERT( word != NULL );

	len = 0;
	w = word;

	if( *w == '-' ) {
		len++;
		w++;
	}

	while( *w ) {
		if( isdigit(*w) ) {
			len++;
		}
		w++;
	}

	return ( strlen(word) == len );
}