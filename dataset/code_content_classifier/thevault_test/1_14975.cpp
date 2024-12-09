void FloatFromCellToScreenCoordinates( FLOAT dCellX, FLOAT dCellY, FLOAT *pdScreenX, FLOAT *pdScreenY )
{
	FLOAT dScreenX, dScreenY;

	dScreenX = ( 2 * dCellX ) - ( 2 * dCellY );
	dScreenY = dCellX + dCellY;

	*pdScreenX = dScreenX;
	*pdScreenY = dScreenY;
}