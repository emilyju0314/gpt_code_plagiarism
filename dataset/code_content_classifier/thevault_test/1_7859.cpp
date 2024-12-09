int Organism_Simulate(ORGANISM *o)
{
	CELL *c, *nxt;
	UNIVERSE *u;
	int energy, energy_stack, energy_per_cell, energy_residue;
	int i;
	int first_x, first_y;

	ASSERT( o != NULL );
	ASSERT( o->ncells > 0 );

	o->age += 1;

	u = o->universe;

	/*
	 * This location will recieve ALL organism energy if
	 * organism's cells are all dead.
	 */
	first_x = o->cells->x;
	first_y = o->cells->y;

	/*
	 * Kill cells that are disconnected from main
	 * body mass. These are any cells destroyed by other
	 * organisms. (or died when their KFORTH program terminated).
	 */
	kill_dead_cells(o);

	/*
	 * Simulate each cell in the organism.
	 */
	for(c=o->cells; c && (o->energy > 0); c=c->next) {
		ASSERT( ! c->kfm->terminated );

		Cell_Simulate(c);
	}

	if( o->energy > 0 && o->ncells > 0 ) {
		/*
		 * we're still alive
		 */
		return 1;
	}

	/*
	 * We must be dead, so clean up organism and return 0.
	 */
	if( o->ncells > 0 ) {
		energy_per_cell = o->energy / o->ncells;
		energy_residue = o->energy % o->ncells;

		i = 0;
		for(c=o->cells; c; c=nxt) {
			nxt = c->next;

			if( i == 0 )
				energy = energy_per_cell + energy_residue;
			else
				energy = energy_per_cell;

			energy_stack = (c->kfm->data_stack_size + c->kfm->call_stack_size) - NOCOST_STACK;
			if( energy_stack < 0 ) {
				energy_stack = 0;
			}

			energy += energy_stack;

			append_organic(u, c->x, c->y, energy);

			Cell_delete(c);
			i++;
		}
		o->cells = NULL;
	} else {
		append_organic(u, first_x, first_y, o->energy);
	}

	return 0;
}