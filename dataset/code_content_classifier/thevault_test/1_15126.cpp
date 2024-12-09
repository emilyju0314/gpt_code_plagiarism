void    ShutdownGame(void)
{
	// handle shutdown of game with respect to preloaded mapscreen graphics
	HandleRemovalOfPreLoadedMapGraphics( );

	ShutdownJA2( );

	//Save the general save game settings to disk
	SaveGameSettings();

	InitTacticalSave();
}