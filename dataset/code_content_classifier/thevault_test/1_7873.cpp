static int check_sum(UNIVERSE *u)
{
	int x, y;
	UNIVERSE_GRID ugrid;
	int i;
	KFORTH_INTEGER value;
	KFORTH_STACK_NODE *curr;

	ASSERT( u != NULL );

	value = 0;
	for(x=0; x < u->width; x++) {
		for(y=0; y < u->height; y++) {
			Universe_Query(u, x, y, &ugrid);
			switch(ugrid.type) {
			case GT_BLANK:
				value += (x+y) * 5;
				break;

			case GT_BARRIER:
				value += (x+y) * 12;
				break;

			case GT_ORGANIC:
				value += (x+y) * 7 + ugrid.u.energy;
				break;

			case GT_CELL:
				value += (x+y) * ugrid.u.cell->organism->energy;
				i = 7;
				for(curr=ugrid.u.cell->kfm->data_sp; curr; curr=curr->prev) {
					value += curr->u.data.value * i;
					i += 7;
				}
				break;

			case GT_SPORE:
				value += (x+y) * ugrid.u.spore->energy;
				break;

			default:
				ASSERT(0);
			}

			value = value & 0x00FFFFFF;
		}
	}

	value = value & 0x00FFFFFF;

	return (int)value;
}