HANDLE GetFirstController()
{
	MFCALLSTACK;

	HANDLE hPad = 0;
	int i;

	// Check the global gamepad state for a connected device.
	for( i = 0; i < 4; i++ )
	{
		if( dsDevices[DS_GAMEPAD].dwState & 1 << i && hPads[i] )
		{
			hPad = hPads[i];
			break;
		}
	}

	return hPad;
}