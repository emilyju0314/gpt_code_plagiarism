int NyxCmdBatteryRead::Execute(const char *deviceId, int argc, char **argv)
{
	nyx_device_handle_t device = NULL;
	nyx_error_t error = NYX_ERROR_NONE;
	string operation;

	operation = resolveArguments(argc, argv);

	if (!operation.empty())
	{
		error = nyx_init();

		if (error == NYX_ERROR_NONE)
		{
			error = nyx_device_open(NYX_DEVICE_BATTERY, deviceId, &device);

			if (device != NULL)
			{
				if ("status" == operation)
				{
					nyx_battery_status_t battStatus;
					error = nyx_battery_query_battery_status(device, &battStatus);

					if (NYX_ERROR_NONE == error)
					{
						cout << "Battery_present=\"" << battStatus.present << "\"" << endl;
						cout << "Battery_charging=\"" << battStatus.charging << "\"" << endl;
						cout << "Battery_percentage=\"" << battStatus.percentage << "\"" << endl;
						cout << "Battery_temperature=\"" << battStatus.temperature << "\"" << endl;
						cout << "Battery_current=\"" << battStatus.current << "\"" << endl;
						cout << "Battery_voltage=\"" << battStatus.voltage << "\"" << endl;
						cout << "Battery_capacity=\"" << battStatus.capacity << "\"" << endl;
						cout << "Battery_avg_current=\"" << battStatus.avg_current << "\"" << endl;
						cout << "Battery_capacity_raw=\"" << battStatus.capacity_raw << "\"" << endl;
						cout << "Battery_capacity_full40=\"" << battStatus.capacity_full40 << "\"" <<
						     endl;
						cout << "Battery_age=\"" << battStatus.age << "\"" << endl;
					}
				}
				else if ("ctia" == operation)
				{
					nyx_battery_ctia_t ctiaStatus;

					error = nyx_battery_get_ctia_parameters(device, &ctiaStatus);

					if (NYX_ERROR_NONE == error)
					{
						cout << "CTIA_charge_min_temp_c=\"" << ctiaStatus.charge_min_temp_c << "\"" <<
						     endl;
						cout << "CTIA_charge_max_temp_c=\"" << ctiaStatus.charge_max_temp_c << "\"" <<
						     endl;
						cout << "CTIA_battery_crit_max_temp=\"" << ctiaStatus.battery_crit_max_temp <<
						     "\"" << endl;
						cout << "CTIA_skip_battery_authentication=\"" <<
						     ctiaStatus.skip_battery_authentication << "\"" << endl;
					}
				}
				else
				{
					cerr << "Error: Unknown argument" << endl;
					// force return to be -1
					error = NYX_ERROR_INVALID_VALUE;
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