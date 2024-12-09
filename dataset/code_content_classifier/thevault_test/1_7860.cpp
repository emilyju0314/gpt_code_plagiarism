ORGANISM *Organism_Make(int x, int y, int strain, int energy, const char *program_text, char *errbuf)
{
	ORGANISM *o;
	CELL *c;
	KFORTH_PROGRAM *kfp;
	KFORTH_MACHINE *kfm;

	ASSERT( x >= 0 );
	ASSERT( y >= 0 );
	ASSERT( strain >= 0 && strain < EVOLVE_MAX_STRAINS );
	ASSERT( energy > 0 );
	ASSERT( program_text != NULL );
	ASSERT( errbuf != NULL );

	kfp = kforth_compile(program_text, EvolveOperations(), errbuf);
	if( kfp == NULL )
		return NULL;

	o = (ORGANISM *) CALLOC(1, sizeof(ORGANISM));
	ASSERT( o != NULL );

	c = (CELL *) CALLOC(1, sizeof(CELL));
	ASSERT( c != NULL );

	/*
	 * Initialize organism
	 */
	o->strain = strain;
	o->energy = energy;
	o->ncells = 1;
	o->cells = c;
	o->next = NULL;
	o->universe = NULL;
	o->program = kfp;

	/*
	 * Initialize cell
	 */
	kfm = kforth_machine_make(kfp, c);
	c->kfm = kfm;
	c->x = x;
	c->y = y;
	c->next = NULL;
	c->organism = o;

	return o;
}