int NyxCmdSystemErase::Execute(const char *deviceId, int argc, char **argv)
{
	nyx_device_handle_t device = NULL;
	nyx_system_erase_type_t eraseType;
	nyx_error_t error = NYX_ERROR_NONE;

	eraseType = resolveArguments(argc, argv);

	if (eraseType != -1)
	{
		error = nyx_init();

		if (error == NYX_ERROR_NONE)
		{
			error = nyx_device_open(NYX_DEVICE_SYSTEM, deviceId, &device);

			if (device != NULL)
			{
				error = nyx_system_erase_partition(device, eraseType);

				if (error != NYX_ERROR_NONE)
				{
					cerr << "Error: Error in rebooting the device." << endl;
				}

				nyx_device_close(device);
			}
		}
		else
		{
			cerr << "Error: Error initializing Nyx" << endl;
		}

		nyx_deinit();
	}

	return (NYX_ERROR_NONE == error) ? 0 : -1;
}