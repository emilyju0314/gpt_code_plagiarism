BOOLEAN ValidateEntryPointGridNo( INT16 *sGridNo )
{
	INT16 sWorldX, sWorldY;
	INT16 sTopLimit, sBottomLimit;

	if( *sGridNo < 0 )
		return FALSE; //entry point is non-existant

	sTopLimit = 80;
	sBottomLimit = gsBottomY - gsTopY - 40;

	//Get screen coordinates for current gridno
	GetAbsoluteScreenXYFromMapPos(*sGridNo, &sWorldX, &sWorldY);

	if( sWorldY < sTopLimit )
	{
		*sGridNo = GetMapPosFromAbsoluteScreenXY(sWorldX, sTopLimit);
	}
	else if( sWorldY > sBottomLimit )
	{
		*sGridNo = GetMapPosFromAbsoluteScreenXY(sWorldX, sBottomLimit);
	}
	else
	{
		return FALSE; //already valid
	}

	return TRUE; //modified
}