void Player_SetNextCommand(UNIVERSE *u, PLAYER_COMMAND *cmd)
{
	ASSERT( u != NULL );
	ASSERT( cmd != NULL );
	ASSERT( u->player != NULL );

	u->player->cmd = *cmd;
}