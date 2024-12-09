int Phascii_Eof(PHASCII_FILE phf)
{
	CONFIG_FILE *cf;

	cf = (CONFIG_FILE*) phf;

	if( cf->error[0] )
		return FALSE;
	else
		return feof( cf->fp );
}