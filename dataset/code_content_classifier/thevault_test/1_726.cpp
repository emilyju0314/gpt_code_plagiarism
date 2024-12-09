int NyxCmdKeysEvents::Execute(const char *deviceId, int argc, char **argv)
{
	mDevice = NULL;
	nyx_error_t error = nyx_init();

	if (error == NYX_ERROR_NONE)
	{
		error = nyx_device_open(mDeviceType, deviceId, &mDevice);

		if (mDevice != NULL)
		{
			waitForEvent();
		}
		else
		{
			cerr << "Error: Failed to open device Keys" << endl ;
		}

		nyx_device_close(mDevice);
	}
	else
	{
		cerr << "Error: Error initializing Nyx" << endl;
	}

	nyx_deinit();
	return (NYX_ERROR_NONE == error) ? 0 : -1;
}