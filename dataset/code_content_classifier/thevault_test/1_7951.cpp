static void create_population(UNIVERSE *u, int population, int total_energy, ORGANISM *o)
{
	int energy_per_organism;
	int energy_remainder;
	int i;
	ORGANISM *no;
	SPIRALPATH *sp;

	ASSERT( u != NULL );
	ASSERT( population >= 1 && population <= 100 );
	ASSERT( total_energy > 0 );
	ASSERT( o != NULL );

	energy_per_organism = total_energy / population;
	energy_remainder = total_energy % population;

	if( energy_per_organism == 0 ) {
		population		= 1;
		energy_per_organism	= total_energy;
		energy_remainder	= 0;
	}

	sp = spiralpath_make(o->cells->x, o->cells->y, 5);

	for(i=0; i < population; i++) {

		if( i == 0 ) {
			no = o;
			no->energy = energy_per_organism + energy_remainder;
		} else {
			no = Universe_CopyOrganism(u);
			Universe_ClearSelectedOrganism(u);
			no->energy = energy_per_organism;
		}

		no->cells->x = sp->x;
		no->cells->y = sp->y;
		Universe_PasteOrganism(u, no);

		spiralpath_next(sp);
	}

	Universe_ClearSelectedOrganism(u);

	spiralpath_delete(sp);

}