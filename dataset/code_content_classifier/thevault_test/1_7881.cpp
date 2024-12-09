PLAYER *Player_Get(UNIVERSE *u)
{
	ASSERT( u != NULL );

	return u->player;
}