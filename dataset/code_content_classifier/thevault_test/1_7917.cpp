UNIVERSE *Universe_ReadAscii(const char *filename, char *errbuf)
{
	PHASCII_FILE phf;
	PHASCII_INSTANCE pi;
	char errmsg[1000];
	int success;
	UNIVERSE *u;

	ASSERT( filename != NULL );
	ASSERT( errbuf != NULL );

	phf = Phascii_Open(filename, "r");
	if( phf == NULL ) {
		strcpy(errbuf, Phascii_GetError());
		return NULL;
	}

	u = NULL;

	while( pi = Phascii_GetInstance(phf) ) {

		if( Phascii_IsInstance(pi, "ORGANIC") ) {
			success = read_organic(pi, u, errmsg);

		} else if( Phascii_IsInstance(pi, "BARRIER") ) {
			success = read_barrier(pi, u, errmsg);

		} else if( Phascii_IsInstance(pi, "ER") ) {
			success = read_er(pi, u, errmsg);

		} else if( Phascii_IsInstance(pi, "KFMO") ) {
			success = read_kfmo(pi, u, errmsg);

		} else if( Phascii_IsInstance(pi, "KEYLIST") ) {
			success = read_keylist(pi, u, errmsg);

		} else if( Phascii_IsInstance(pi, "SPORE") ) {
			success = read_spore(pi, u, errmsg);

		} else if( Phascii_IsInstance(pi, "CELL") ) {
			success = read_cell(pi, u, errmsg);

		} else if( Phascii_IsInstance(pi, "ORGANISM") ) {
			success = read_organism(pi, u, errmsg);

		} else if( Phascii_IsInstance(pi, "PLAYER") ) {
			success = read_player(pi, u, errmsg);

		} else if( Phascii_IsInstance(pi, "UNIVERSE") ) {
			success = read_universe(pi, &u, errmsg);

		} else {
			success = 1;
		}

		Phascii_FreeInstance(pi);

		if( ! success ) {
			sprintf(errbuf, "%s", errmsg);
			Phascii_Close(phf);
			return NULL;
		}
	}

	if( ! Phascii_Eof(phf) ) {
		sprintf(errbuf, "%s\n", Phascii_Error(phf));
		Phascii_Close(phf);
		return NULL;
	}

	Phascii_Close(phf);

	if( u == NULL ) {
		sprintf(errbuf, "%s: No UNIVERSE instance", filename);
		return NULL;
	}

	return u;
}