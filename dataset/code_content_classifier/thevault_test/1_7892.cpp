char *Phascii_Error(PHASCII_FILE phf)
{
	CONFIG_FILE *cf;

	cf = (CONFIG_FILE*) phf;

	if( cf )
		return cf->error;
	else
		return cf_errorbuf;
}