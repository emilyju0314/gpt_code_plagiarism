int Universe_WriteBinary9(UNIVERSE *u, const char *filename, char *errbuf)
{
	FILE *fp;
	bool success;

	ASSERT( u != NULL );
	ASSERT( filename != NULL );
	ASSERT( errbuf != NULL );

	fp = fopen(filename, "wb");
	if( fp == NULL ) {
		sprintf(errbuf, "%s: %s", filename, strerror(errno));
		return 0;
	}

	success = write_magic(fp);
	if( ! success ) {
		sprintf(errbuf, "%s: cannot write magic number (%s)", filename, strerror(errno));
		fclose(fp);
		return 0;
	}

	success = write_universe(fp, u);
	if( ! success ) {
		sprintf(errbuf, "%s: cannot write universe (%s)", filename, strerror(errno));
		fclose(fp);
		return 0;
	}

	success = write_organisms(fp, u);
	if( ! success ) {
		sprintf(errbuf, "%s: cannot write organisms (%s)", filename, strerror(errno));
		fclose(fp);
		return 0;
	}

	success = write_spores(fp, u);
	if( ! success ) {
		sprintf(errbuf, "%s: cannot write spores (%s)", filename, strerror(errno));
		fclose(fp);
		return 0;
	}

	success = write_organics(fp, u);
	if( ! success ) {
		sprintf(errbuf, "%s: cannot write organic (%s)", filename, strerror(errno));
		fclose(fp);
		return 0;
	}

	success = write_barriers(fp, u);
	if( ! success ) {
		sprintf(errbuf, "%s: cannot write barriers (%s)", filename, strerror(errno));
		fclose(fp);
		return 0;
	}

	fclose(fp);

	return 1;
}