void Player_Simulate(PLAYER *p)
{
	UNIVERSE *u;
	UNIVERSE_GRID ugrid;
	GRID_TYPE type;
	int x, y, xoffset, yoffset;

	ASSERT( p != NULL );
	ASSERT( ! p->terminated );

	p->age += 1;

	u = p->universe;

	switch( p->cmd.type ) {
	case PCMD_NOP:
		/*
		 * no operation:
		 */
		break;

	case PCMD_OMOVE:
		/*
		 * Move player object to the new location, specified
		 * by the vector (pc->x, pc->y). If blocked, don't move.
		 *
		 * Perhaps implement "sliding behavior"????
		 */
		xoffset = NORMALIZE_OFFSET( p->cmd.x );
		yoffset = NORMALIZE_OFFSET( p->cmd.y );

		x = p->x + xoffset;
		y = p->y + yoffset;

		if( x < 0 || x >= u->width )
			break;

		if( y < 0 || y >= u->height )
			break;

		type = Grid_Get(u, x, y, &ugrid);
		if( type != GT_BLANK )
			break;

		Grid_Clear(u, p->x, p->y);

		p->x = x;
		p->y = y;
		Grid_SetPlayer(u, x, y, p);
		break;

	case PCMD_EAT:
		/*
		 * directional "eat" instruction
		 */
		xoffset = NORMALIZE_OFFSET( p->cmd.x );
		yoffset = NORMALIZE_OFFSET( p->cmd.y );

		if( xoffset != 0 || yoffset != 0 ) {
			// vector cannot be (0, 0)
			player_eat(u, p, p->x + xoffset, p->y + yoffset);
		}
		break;

	case PCMD_EAT_ALL:
		/*
		 * execute "eat" instruction for all cells surrounding
		 * us.
		 */
		player_eat(u, p, p->x+1, p->y+1 );
		player_eat(u, p, p->x+1, p->y+0 );
		player_eat(u, p, p->x+1, p->y-1 );

		player_eat(u, p, p->x-1, p->y+1 );
		player_eat(u, p, p->x-1, p->y );
		player_eat(u, p, p->x-1, p->y-1 );

		player_eat(u, p, p->x, p->y+1 );
		player_eat(u, p, p->x, p->y-1 );
		break;

	default:
		ASSERT(0);
	}

	/*
	 * Reset command to be no operation.
	 */
	p->cmd.type = PCMD_NOP;
	p->cmd.x = 0;
	p->cmd.y = 0;
}