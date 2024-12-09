static int player_eat(UNIVERSE *u, PLAYER *p, int x, int y)
{
	GRID_TYPE type;
	UNIVERSE_GRID ugrid;
	SPORE *spore;
	CELL *eatc;
	ORGANISM *eato;
	int energy, energy1, energy2;

	ASSERT( u != NULL );
	ASSERT( p != NULL );

	if( x < 0 || x >= u->width )
		return 0;

	if( y < 0 || y >= u->height )
		return 0;

	type = Grid_Get(u, x, y, &ugrid);

	if( type == GT_ORGANIC ) {
		energy = ugrid.u.energy;
		p->energy += energy;
		Grid_Clear(u, x, y);
		return energy;

	} else if( type == GT_SPORE ) {
		spore = ugrid.u.spore;
		energy = spore->energy;
		p->energy += energy;
		Grid_Clear(u, x, y);
		Spore_delete(spore);
		return energy;

	} else if( type == GT_CELL  ) {
		/*
		 * Energy transfer between living organisms
		 *
		 * 1. Make sure cell isn't one of ours
		 * 2. Make sure cell isn't already dead
		 * 3. Set cell kfm to terminated (this kills the cell)
		 * 4. convert cell stack nodes to energy and add to us.
		 * 5. add 1/n amount of energy from eaten organism.
		 *
		 */
		eatc = ugrid.u.cell;
		eato = eatc->organism;

		if( eatc->kfm->terminated ) {
			return 0;
		}

		energy1 = (eatc->kfm->call_stack_size + eatc->kfm->data_stack_size) - NOCOST_STACK;
		if( energy1 < 0 ) {
			energy1 = 0;
		}

		kforth_machine_reset(eatc->kfm);
		eatc->kfm->terminated = 1;

		ASSERT( eato->ncells > 0 );

		energy2 = (eato->energy / eato->ncells)
			+ (eato->energy % eato->ncells);

		eato->energy -= energy2;

		energy = energy1 + energy2;

		p->energy += energy;

		return energy;

	} else if( type == GT_PLAYER ) {
		ASSERT(0);
		return 0;

	} else {
		return 0;
	}
}