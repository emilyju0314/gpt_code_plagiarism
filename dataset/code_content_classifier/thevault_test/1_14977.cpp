INT16 CenterY( INT16 sGridNo )
{
	INT16 sYPos;

	sYPos = sGridNo / WORLD_COLS;

	return( ( sYPos * CELL_Y_SIZE ) + ( CELL_Y_SIZE / 2 ) );
}