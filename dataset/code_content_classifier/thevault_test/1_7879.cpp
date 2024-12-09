void Player_Add(UNIVERSE *u, int x, int y)
{
#ifndef NDEBUG
	UNIVERSE_GRID ugrid;
#endif
	PLAYER *player;

	ASSERT( u != NULL );
	ASSERT( u->player == NULL );
	ASSERT( x >= 0 && x < u->width );
	ASSERT( y >= 0 && y < u->height );
	ASSERT( Grid_Get(u, x, y, &ugrid) == GT_BLANK );

	player = Player_make(u, x, y);
	u->player = player;
	Grid_SetPlayer(u, x, y, player);
}