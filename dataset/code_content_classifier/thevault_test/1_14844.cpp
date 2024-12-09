UINT16 GetRandomIndexByRange( UINT16 usRangeStart, UINT16 usRangeEnd )
{
	UINT16	usPickList[50];
	UINT16	usNumInPickList;
	UINT16	usWhich;
	UINT16	usObject;
	// Get a list of valid object to select from
	usNumInPickList = 0;
	for ( usWhich = 0; usWhich < *pNumSelList; usWhich++ )
	{
		usObject = (UINT16)pSelList[ usWhich ].uiObject;
		if ( (usObject >= usRangeStart) && (usObject <= usRangeEnd) )
		{
			usPickList[ usNumInPickList ] = usObject;
			usNumInPickList++;
		}
	}
	return ( usNumInPickList ) ? usPickList[ Random(usNumInPickList) ] : 0xffff;
}