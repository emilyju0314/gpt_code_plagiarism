UNIVERSE *CreateUniverse(NewUniverseOptions *nuo, char *errbuf)
{
	int i, xpos, ypos;
	ORGANISM *o[8];
	UNIVERSE *u;
	int x[8], y[8];
	int wa, wb, wc;
	int ha, hb, hc;
	char buf[3000];
	CString source_code;
	FILE *fp;
	bool failed;
	int posi;
	size_t len;

	ASSERT( nuo != NULL );
	ASSERT( errbuf != NULL );

	if( nuo->num_strains == 0 ) {
		sprintf(errbuf, "No starting population was specified.");
		return NULL;
	}

	/*
 	 * Compute starting positions for each possible strain
	 */
	wa = nuo->width/4;
	wb = nuo->width/2;
	wc = nuo->width - nuo->width/4;

	ha = nuo->height/4;
	hb = nuo->height/2;
	hc = nuo->height - nuo->height/4;

	if( nuo->num_strains > 1 ) {
		x[0] = wb;
		y[0] = ha;

		x[1] = wb;
		y[1] = hc;

		x[2] = wa;
		y[2] = hb;

		x[3] = wc;
		y[3] = hb;

		x[4] = wa;
		y[4] = ha;

		x[5] = wc;
		y[5] = ha;

		x[6] = wa;
		y[6] = hc;

		x[7] = wc;
		y[7] = hc;
	} else {
		/*
		 * If just 1 strain in sim, then put it in the middle.
		 */
		for(i=0; i<8; i++) {
			x[i] = wb;
			y[i] = hb;
		}
	}

	for(i=0; i<8; i++) {
		o[i] = NULL;
	}

	posi = 0;
	failed = FALSE;
	for(i=0; i<8; i++) {
		if( ! nuo->has_strain[i] )
			continue;

		xpos = x[posi];
		ypos = y[posi];

		fp = fopen(nuo->filename[i], "r");
		if( fp == NULL ) {
			sprintf(errbuf, "%s: %s", nuo->filename[i], strerror(errno));
			failed = TRUE;
			break;
		}

		source_code = "";
		while( fgets(buf, sizeof(buf), fp) != NULL ) {
			len = strlen(buf)-1;
			if( buf[len-1] == '\n' )
				buf[ strlen(buf)-1 ] = '\0';
			strcat(buf, "\r\n");
			source_code += buf;
		}
		fclose(fp);

		o[i] = Organism_Make(xpos, ypos, i, nuo->energy[i], source_code, errbuf);
		if( o[i] == NULL ) {
			failed = TRUE;
			break;
		}

		if( nuo->sexonly[i] ) {
			o[i]->oflags |= ORGANISM_FLAG_SEXONLY;
		}

		posi++;
	}

	if( failed ) {
		for(i=0; i<8; i++) {
			if( o[i] == NULL ) {
				continue;
			}
			Organism_delete(o[i]);
		}
		return NULL;
	}

	u = Universe_Make(nuo->seed, nuo->width, nuo->height, &nuo->kfmo);
	ASSERT( u != NULL );

	if( nuo->want_barrier ) {
		create_barrier_ellipse(u);
	}

	for(i=0; i<8; i++) {
		if( o[i] == NULL )
			continue;

		create_population(u, nuo->population[i], nuo->energy[i], o[i]);
	}

	return u;
}