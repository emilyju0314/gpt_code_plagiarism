static void MSYS_TrashRegList(void)
{
	while( MSYS_RegList )
	{
		if( MSYS_RegList->uiFlags & MSYS_REGION_EXISTS )
		{
			MSYS_RemoveRegion(MSYS_RegList);
		}
		else
		{
			MSYS_RegList = MSYS_RegList->next;
		}
	}
}