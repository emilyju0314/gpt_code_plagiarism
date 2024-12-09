PLAYER *Player_make(UNIVERSE *u, int x, int y)
{
	PLAYER *player;

	ASSERT( u  != NULL );
	ASSERT( x >= 0 && x < u->width );
	ASSERT( y >= 0 && y < u->height );

	player = (PLAYER *) CALLOC(1, sizeof(PLAYER));
	ASSERT( player != NULL );

	player->terminated = 0;
	player->x = x;
	player->y = y;
	player->energy = 0;
	player->age = 0;
	player->cmd.type = PCMD_NOP;
	player->cmd.x = 0;
	player->cmd.y = 0;
	player->universe = u;

	return player;
}