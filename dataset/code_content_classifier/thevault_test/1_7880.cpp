void Player_Remove(UNIVERSE *u)
{
	PLAYER *player;

	ASSERT( u != NULL );
	ASSERT( u->player != NULL );
	ASSERT( u->player->terminated == 0 );

	player = u->player;
	u->player = NULL;

	if( player->energy > 0 ) {
		Grid_SetOrganic(u, player->x, player->y, player->energy);
	} else {
		Grid_Clear(u, player->x, player->y);
	}
	Player_delete(player);
}