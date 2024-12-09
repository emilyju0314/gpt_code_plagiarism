void Opcode_CMOVE(KFORTH_MACHINE *kfm)
{
	CELL *cell, *c;
	ORGANISM *o;
	UNIVERSE *u;
	int x, y, xoffset, yoffset;
	int save_x, save_y;
	KFORTH_INTEGER value;
	int cnt;

	if( kfm->data_stack_size < 2 )
		return;

	cell = (CELL*) kfm->client_data;
	o = cell->organism;
	u = o->universe;

	value = kforth_data_stack_pop(kfm);
	yoffset = NORMALIZE_OFFSET(value);

	value = kforth_data_stack_pop(kfm);
	xoffset = NORMALIZE_OFFSET(value);

	x = cell->x + xoffset;
	y = cell->y + yoffset;

	if( ! grid_is_blank(u, x, y) ) {
		kforth_data_stack_push(kfm, 0);
		return;
	}

	/*
	 * Move cell to new location
	 */
	save_x = cell->x;
	save_y = cell->y;

	Grid_Clear(u, cell->x, cell->y);

	cell->x = x;
	cell->y = y;
	Grid_SetCell(u, cell);

	/*
	 * Make sure all cells in organism have at least 1 neighbor in the
	 * N, S, E, or W direction
	 */
	for(c=o->cells; c; c=c->next) {
		c->color = 0;
	}

	//cnt = mark_reachable_cells_recur(o->cells);
	cnt = mark_reachable_cells(o->cells);

	if( cnt != o->ncells ) {
		/*
		 * connectivity requirement is not true, so undo the move,
		 * and push 0 on data stack.
		 */
		Grid_Clear(u, cell->x, cell->y);
		cell->x = save_x;
		cell->y = save_y;
		Grid_SetCell(u, cell);
		kforth_data_stack_push(kfm, 0);
	} else {
		/* success! */
		kforth_data_stack_push(kfm, 1);
	}
}