INT16 CenterX( INT16 sGridNo )
{
	INT16 sXPos;

	sXPos = sGridNo % WORLD_COLS;

	return( ( sXPos * CELL_X_SIZE ) + ( CELL_X_SIZE / 2 ) );
}