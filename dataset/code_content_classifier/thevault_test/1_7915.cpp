int Universe_WriteAscii(UNIVERSE *u, const char *filename, char *errbuf)
{
	FILE *fp;

	ASSERT( u != NULL );
	ASSERT( filename != NULL );
	ASSERT( errbuf != NULL );

	fp = fopen(filename, "w");
	if( fp == NULL ) {
		sprintf(errbuf, "%s: %s", filename, strerror(errno));
		return 0;
	}

	write_prolog(fp);
	write_universe(fp, u);
	write_evolve_random(fp, u->er);
	write_kforth_mutate_options(fp, u->kfmo);
	write_barriers(fp, u);
	write_keylist(fp, u);
	write_organic(fp, u);
	write_spores(fp, u);
	write_organisms(fp, u);
	write_player(fp, u);

	fclose(fp);
	return 1;
}