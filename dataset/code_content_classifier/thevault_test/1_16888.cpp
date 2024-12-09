void CheckDeviceChanges(DEVICE_STATE *pdsDevices)
{
	MFCALLSTACK;

	DWORD dwInsert, dwRemove;
	int i;

	// Check each device type to see if any changes have occurred.
	for( i = 0; i < NUM_DEVICE_STATES; i++ )
	{
		if( XGetDeviceChanges( pdsDevices[i].pxdt, &dwInsert, &dwRemove ) )
		{
			// Call handler to service the insertion and/or removal.
			HandleDeviceChanges( pdsDevices[i].pxdt, dwInsert, dwRemove );

			// Update new device state.
			pdsDevices[i].dwState &= ~dwRemove;
			pdsDevices[i].dwState |= dwInsert;
		}
	}
}