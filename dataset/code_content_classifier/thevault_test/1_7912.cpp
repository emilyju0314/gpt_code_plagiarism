static void write_prolog(FILE *fp)
{
	int i;

	ASSERT( fp != NULL );

	for(i=0; i < sizeof(prolog)/sizeof(prolog[0]); i++) {
		fprintf(fp, "%s\n", prolog[i]);
	}
}