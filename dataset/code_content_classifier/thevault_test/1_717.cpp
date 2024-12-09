int NyxCmdBatteryRegisterStatus::Execute(const char *deviceId, int argc,
        char **argv)
{
	nyx_device_handle_t device = NULL;
	nyx_error_t error = NYX_ERROR_NONE;

	error = nyx_init();

	if (error == NYX_ERROR_NONE)
	{
		error = nyx_device_open(NYX_DEVICE_BATTERY, deviceId, &device);

		if (device != NULL)
		{
			error = nyx_battery_register_battery_status_callback(device, status_cb, NULL);

			if (error == NYX_ERROR_NONE)
			{
				mainloop = g_main_loop_new(NULL, FALSE);
				g_timeout_add(100, check_cb_fired, NULL);
				g_main_loop_run(mainloop);
				g_main_loop_unref(mainloop);
			}
			else
			{
				cerr << "Error in registering for battery status change" << endl;
			}

			nyx_device_close(device);
		}
		else
		{
			cerr << "Error in opening battery device" << endl;
		}
	}
	else
	{
		cerr << "Error: Error initializing Nyx" << endl;
	}

	nyx_deinit();
	return (NYX_ERROR_NONE == error) ? 0 : -1;
}